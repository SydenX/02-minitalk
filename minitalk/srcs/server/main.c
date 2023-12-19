/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:34:52 by jtollena          #+#    #+#             */
/*   Updated: 2023/12/19 13:47:23 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	getfrombit(unsigned char bit[8])
{
	int				i;
	unsigned char	result;

	result = 0;
	i = 0;
	while (i < 8)
	{
		result |= (bit[i] == '1') << (7 - i);
		i++;
	}
	return (result);
}

int	ft_ustrlen(unsigned char *s)
{
	int	ln;

	ln = 0;
	while (s[ln])
		ln++;
	return (ln);
}

void	clearbit(unsigned char *bits)
{
	int	i;

	i = 0;
	while (i < 8)
		bits[i++] = 0;
}

void	handler(int signum)
{
	static unsigned char	bits[8];
	char					c;

	if (signum != SIGUSR1 && signum != SIGUSR2)
		return ;
	if (signum == SIGUSR1)
		c = '0';
	else
		c = '1';
	bits[ft_ustrlen(bits)] = c;
	if (ft_ustrlen(bits) == 8)
	{
		ft_printf("%c", getfrombit(bits));
		clearbit(&bits[0]);
	}
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
