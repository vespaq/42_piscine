/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muozdemi <muozdemi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 14:08:51 by muozdemi          #+#    #+#             */
/*   Updated: 2026/05/10 14:11:38 by muozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	check_base(char *base);
int	get_nbr_len(long nbr, int base_len);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	n;
	int		b_to_len;
	int		res_len;
	char	*res;

	if (!check_base(base_from) || !check_base(base_to))
		return (NULL);
	n = ft_atoi_base(nbr, base_from);
	b_to_len = check_base(base_to);
	res_len = get_nbr_len(n, b_to_len);
	res = (char *)malloc(sizeof(char) * (res_len + 1));
	if (!res)
		return (NULL);
	res[res_len] = '\0';
	if (n < 0)
		res[0] = '-';
	if (n < 0)
		n = -n;
	if (n == 0)
		res[0] = base_to[0];
	while (n > 0)
	{
		res[--res_len] = base_to[n % b_to_len];
		n /= b_to_len;
	}
	return (res);
}