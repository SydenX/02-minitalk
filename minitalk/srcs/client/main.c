/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:34:52 by jtollena          #+#    #+#             */
/*   Updated: 2023/12/19 14:04:34 by jtollena         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int				j;
	int				i;
	int				max;
	unsigned char	bits[8];

	i = 0;
	max = ft_strlen(argv[1]);
	while (i <= max)
	{
		if (argv[1][i] == 0)
			argv[1][i] = '\n';
		char2bits(argv[1][i], bits);
		j = 0;
		while (j < 8)
		{
			kill(ft_atoi(argv[2]), bits[j] + SIGUSR1);
			usleep(65);
			j++;
		}
		usleep(65);
		i++;
	}
	return (0);
}
