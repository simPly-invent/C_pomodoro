/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chrono.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenais <mobenais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 10:01:16 by mobenais          #+#    #+#             */
/*   Updated: 2026/05/26 11:40:54 by mobenais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/chrono.h"

int	check_nb(char *nb)
{
	int	i;
	int	len;
	int	len_nb;

	i = 0;
	len = strlen(nb);
	len_nb = 0;
	while (nb[i])
	{
		if (nb[i] >= '0' && nb[i] <= '9')
			len_nb++;
		i++;
	}
	if (len_nb == len)
		return (0);
	return (-1);
}

// char	*strjoin(char **argv, int argc)
// {
// 	int		index_tab;
// 	int		i;
// 	char	*str;

// 	index_tab = 1;
// 	i = 0;
// 	str = malloc(sizeof(argc - 1));
// 	if (!str)
// 		return (NULL);
// 	while (argv[index_tab])
// 	{
// 		while (argv[index_tab][i])
// 		{
// 			str[i] = argv[index_tab][i];
// 			i++;
// 		}
// 		index_tab++;
// 	}
// 	return (str);
// }

int	main(int argc, char **argv)
{
	int i;
	t_main	var;

	if (argc > 3 && check_nb(argv[1]) == 0 && check_nb(argv[2]) == 0
		&& check_nb(argv[3]) == 0)
	{
		var.i = 0;
		var.j = 0;
		var.k = 0;
		var.h = atoi(argv[1]);
		var.m = atoi(argv[2]);
		var.s = atoi(argv[3]);
		while (var.i < var.h || (var.i == var.h && var.j < var.m)
		|| (var.i == var.h && var.j == var.m && var.k < var.s))
		{
			printf("\033c");
			printf("\033[1;35m");
			printf("   ╔═══════════════════════════════════╗\n");
			printf("   ║         \033[1;36m⏱   POMODORO   ⏱\033[1;35m          ║\n");
			printf("   ╠═══════════════════════════════════╣\n");
			printf("   ║   \033[1;33m%02d h\033[1;35m  ┃  \033[1;33m%02d min\033[1;35m  ┃  \033[1;33m%02d sec\033[1;35m      ║ TARGET -> %02d:%02d:%02d\n", var.i, var.j, var.k, var.h, var.m, var.s);
			printf("   ╚═══════════════════════════════════╝\033[0m\n");
			sleep(1);
			var.k++;
			if (var.k == 60)
			{
				var.j++;
				var.k = 0;
			}
			if (var.j == 60)
			{
				var.i++;
				var.j = 0;
			}
		}
		i = 31;
		while (1)
		{
			if (kbhit())
			{
            	var.clav = getch();
				if ((int)var.clav == 32)
				{
					printf("Exiting...");
					break;
				}
			}
			if (i == 37)
				i = 31;
			printf("\033[0m");
			printf("\033[%dm", i);
			printf("   ╔══════════════════════════════════════════╗\n");
			printf("   ║              ⏱   POMODORO   ⏱            ║\n");
			printf("   ║   hope you've finished what you started! ║\n");
			printf("   ╚══════════════════════════════════════════╝\n");
			printf("      PRESS SPACE when you're ready to exit   \n");
			sleep(2);
			printf("\033c");
			if (kbhit())
			{
            	var.clav = getch();
				if ((int)var.clav == 32)
				{
					printf("Exiting...");
					break;
				}
			}
            i++;
        }
	}
	else
	{
		printf("Usage: %s <hours> <minutes> <seconds>\n", argv[0]);
	}
}
