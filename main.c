/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:59:38 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/02/14 00:46:51 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnu_source.h"

#include <stdio.h>
#include <stdbool.h>
#include <setjmp.h>
#include <dlfcn.h>

static jmp_buf	*g_jmp_buf = NULL;

void	exit(int status)
{
	static void	(*real)(int) = NULL;

	if (!real)
		real = (void (*)(int))dlsym(RTLD_NEXT, "exit");
	if (!g_jmp_buf)
		real(status);
	else
		longjmp(*g_jmp_buf, 1);
}

int	main(void)
{
	jmp_buf		buf;
	int			status;

	g_jmp_buf = &buf;
	status = setjmp(buf);
	if (status)
	{
		printf("Mocked successfully. status: %d\n", status);
		g_jmp_buf = NULL;
		exit(0);
	}
	exit(1);
}
