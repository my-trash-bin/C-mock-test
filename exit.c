/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:51:43 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/02/14 00:03:41 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnu_source.h"

#include "exit.h"

#include <stddef.h>
#include <stdbool.h>
#include <setjmp.h>
#include <dlfcn.h>

static jmp_buf	*g_jmp_buf = NULL;

bool	exit_mock_enabled(void)
{
	return (!!g_jmp_buf);
}

bool	exit_mock(jmp_buf *buf, int *out_status)
{
	const int	status = setjmp(*buf);

	if (status)
		*out_status = status;
	return (!!status);
}

void	exit(int status)
{
	static void	(*real)(void) = NULL;

	if (!real)
		real = (void (*)(void))dlsym(RTLD_NEXT, "exit");
	if (!g_jmp_buf)
		real();
	else
		longjmp(*g_jmp_buf, status);
}
