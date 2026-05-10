/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muozdemi <muozdemi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 13:35:03 by muozdemi          #+#    #+#             */
/*   Updated: 2026/05/10 13:35:05 by muozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	d_len;
	unsigned int	s_len;

	i = 0;
	while (dest[i] != '\0')
		i++;
	d_len = i;
	j = 0;
	while (src[j] != '\0')
		j++;
	s_len = j;
	if (size <= d_len)
		return (s_len + size);
	j = 0;
	while (src[j] != '\0' && (d_len + j) < (size - 1))
	{
		dest[d_len + j] = src[j];
		j++;
	}
	dest[d_len + j] = '\0';
	return (d_len + s_len);
}