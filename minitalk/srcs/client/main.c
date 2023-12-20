/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:34:52 by jtollena          #+#    #+#             */
/*   Updated: 2023/12/20 11:35:52 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	char2bits(char c, unsigned char bits[8])
{
	int	i;

	i = 0;
	while (i < 8)
	{
		bits[i] = (c >> (7 - i)) & 1;
		i++;
	}
}

void	send_msg(char **argv)
{
	int				j;
	int				i;
	int				max;
	unsigned char	bits[8];

	i = 0;
	max = ft_strlen(argv[2]);
	while (i <= max)
	{
		if (argv[2][i] == 0)
			argv[2][i] = '\n';
		char2bits(argv[2][i], bits);
		j = 0;
		while (j < 8)
		{
			kill(ft_atoi(argv[1]), bits[j] + SIGUSR1);
			usleep(100);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		send_msg(argv);
	else
		ft_printf("Please put 2 arguments, <pid> and <message to send>");
	return (0);
}
