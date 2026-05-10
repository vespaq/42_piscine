/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muozdemi <muozdemi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 13:41:22 by muozdemi          #+#    #+#             */
/*   Updated: 2026/05/10 13:41:30 by muozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		b_len;
	long	n;

	b_len = check_base(base);
	if (b_len > 1)
	{
		n = nbr;
		if (n < 0)
		{
			ft_putchar('-');
			n *= -1;
		}
		if (n >= b_len)
			ft_putnbr_base(n / b_len, base);
		ft_putchar(base[n % b_len]);
	}
}