/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:59:38 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/02/14 00:04:00 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

#include <stdio.h>
#include <stdbool.h>
#include <setjmp.h>

int	main(void)
{
	jmp_buf	buf;
	int		status;

	if (exit_mock(&buf, &status))
	{
		printf("Mocked successfully. status: %d\n", status);
		exit_mock(NULL, NULL);
		exit(0);
	}
	exit(1);
}
