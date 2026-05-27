/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chrono.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenais <mobenais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 10:01:28 by mobenais          #+#    #+#             */
/*   Updated: 2026/05/26 11:37:57 by mobenais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_main
{
	int		i;
	int		j;
	int		k;
	int		h;
	int		m;
	int		s;
	char	clav;
}			t_main;

int			check_nb(char *nb);
// char	*strjoin(char **argv, int argc);
int kbhit(void);
int getch(void);