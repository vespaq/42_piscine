/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muozdemi <muozdemi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 13:51:00 by muozdemi          #+#    #+#             */
/*   Updated: 2026/05/10 13:51:30 by muozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_safe(int board[10], int row, int col)
{
	int	i;

	i = 0;
	while (i < row)
	{
		if (board[i] == col || board[i] - i == col - row || \
			board[i] + i == col + row)
			return (0);
		i++;
	}
	return (1);
}

void	solve(int board[10], int row, int *count)
{
	int	col;
	int	i;

	if (row == 10)
	{
		i = 0;
		while (i < 10)
			ft_putchar(board[i++] + '0');
		ft_putchar('\n');
		(*count)++;
		return ;
	}
	col = 0;
	while (col < 10)
	{
		if (is_safe(board, row, col))
		{
			board[row] = col;
			solve(board, row + 1, count);
		}
		col++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	count;

	count = 0;
	solve(board, 0, &count);
	return (count);
}
