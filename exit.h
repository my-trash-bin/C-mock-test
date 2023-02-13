/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:45:54 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/02/14 00:03:47 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H

# include <stdbool.h>
# include <setjmp.h>

bool	exit_mock_enabled(void);
bool	exit_mock(jmp_buf *buf, int *out_status);

void	exit(int status);

#endif
