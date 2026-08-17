/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlkudino <vlkudino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 20:38:15 by vlkudino          #+#    #+#             */
/*   Updated: 2026/08/17 20:35:58 by mtotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	trouver_combinaison(int left, int right, int combinaisons[][7]);

int	valider_combinaison_colonne(int col, int sol[4][4], int comb[7])
{
	int	row;

	row = 0;
	while (row < 4)
	{
		if (sol[row][col] != comb[row + 1])
		{
			return (0);
		}
		row ++;
	}
	return (1);
}

int	valider_colonne(int col, int sol[4][4], int bordures[4][4],
			int combinaisons[][7])
{
	int	comb_num;
	int	n;
	int	res;

	comb_num = trouver_combinaison(bordures[0][col], bordures[1][col],
			combinaisons);
	if (comb_num < 0)
		return (0);
	n = combinaisons[comb_num][6];
	while (n > 0)
	{
		res = valider_combinaison_colonne(col, sol,
				combinaisons[comb_num + n - 1]);
		if (res == 1)
			return (1);
		n --;
	}
	return (0);
}

int	valider_solution(int sol[4][4], int bordures[4][4],
			int combinaisons[][7])
{
	int	col;
	int	res;

	col = 0;
	while (col < 4)
	{
		res = valider_colonne(col, sol, bordures, combinaisons);
		if (res != 1)
			return (0);
		col ++;
	}
	return (1);
}

int	valider_bordure_axe(int bor1[4], int bor2[4])
{
	int	i;
	int	s;

	i = 0;
	while (i < 4)
	{
		if (bor1[i] < 1 || bor1[i] > 4
			|| bor2[i] < 1 || bor2[i] > 4)
			return (0);
		s = bor1[i] + bor2[i];
		if (s < 3 || s > 5)
			return (0);
		i ++;
	}
	return (1);
}

int	valider_bordures(int bordures[4][4])
{
	return (valider_bordure_axe(bordures[0], bordures[1])
		&& valider_bordure_axe(bordures[2], bordures[3]));
}
