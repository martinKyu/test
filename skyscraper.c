/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscraper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlkudino <vlkudino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 12:48:54 by mtotier           #+#    #+#             */
/*   Updated: 2026/08/17 20:52:54 by mtotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	valider_bordures(int bordures[4][4]);
int	trouver_solution(int sol[4][4], int bord[4][4], int combinaisons[][7]);
int	valider_solution(int sol[4][4], int bordures[4][4],
			int combinaisons[][7]);

static int	g_combinaisons[][7] = {
{4, 1, 2, 3, 4, 1, 1},
{1, 4, 3, 2, 1, 4, 1},
{3, 2, 3, 4, 1, 2, 3},
{3, 1, 3, 4, 2, 2, 2},
{3, 1, 2, 4, 3, 2, 1},
{2, 1, 4, 3, 2, 3, 3},
{2, 2, 4, 3, 1, 3, 2},
{2, 3, 4, 2, 1, 3, 1},
{2, 3, 4, 1, 2, 2, 6},
{2, 3, 2, 4, 1, 2, 5},
{2, 2, 4, 1, 3, 2, 4},
{2, 2, 1, 4, 3, 2, 3},
{2, 1, 4, 2, 3, 2, 2},
{2, 3, 1, 4, 2, 2, 1},
{2, 3, 2, 1, 4, 1, 2},
{2, 3, 1, 2, 4, 1, 1},
{1, 4, 1, 2, 3, 2, 2},
{1, 4, 2, 1, 3, 2, 1},
{3, 2, 3, 1, 4, 1, 3},
{3, 2, 1, 3, 4, 1, 2},
{3, 1, 3, 2, 4, 1, 1},
{1, 4, 1, 3, 2, 3, 3},
{1, 4, 3, 1, 2, 3, 2},
{1, 4, 2, 3, 1, 3, 3},
{0, 0, 0, 0, 0, 0, 0}
};

void	print_digit(int digit)
{
	char	c;

	c = digit + '0';
	write(1, &c, 1);
}

void	print_solution(int sol[4][4])
{
	int	col;
	int	row;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			print_digit(sol[row][col]);
			if (col != 3)
				write(1, " ", 1);
			col++;
		}
		write (1, "\n", 1);
		row++;
	}
}

int	parse_bordures(char *argv, int bordures[4][4])
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (argv[i])
	{
		if (argv[i] < '1' || argv[i] > '4' || nb >= 16)
			return (0);
		bordures[nb / 4][nb % 4] = argv[i] - '0';
		nb ++;
		i ++;
		if (argv[i] == '\0')
			break ;
		if (argv[i] != ' ')
			return (0);
		i ++;
	}
	if (nb != 16)
		return (0);
	return (1);
}

int	print_error(void)
{
	write(1, "Error\n", 6);
	return (1);
}

int	main(int argc, char *argv[])
{
	int	bordures[4][4];
	int	sol[4][4];

	if (argc != 2)
		return (print_error());
	if (parse_bordures(argv[1], bordures) != 1)
		return (print_error());
	if (valider_bordures(bordures) != 1)
		return (print_error());
	if (trouver_solution(sol, bordures, g_combinaisons) != 1)
		return (print_error());
	print_solution(sol);
	return (0);
}
