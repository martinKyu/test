/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlkudino <vlkudino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 22:04:22 by vlkudino          #+#    #+#             */
/*   Updated: 2026/08/17 20:39:35 by mtotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	valider_solution(int sol[4][4], int bordures[4][4],
			int combinaisons[][7]);

int	trouver_combinaison(int left, int right, int combinaisons[][7])
{
	int	row;
	int	*comb_cur;

	row = 0;
	while (combinaisons[row][0] != 0)
	{
		comb_cur = combinaisons[row];
		if (left == comb_cur[0] && right == comb_cur[5])
			return (row);
		row ++;
	}
	return (-1);
}

void	inserer_combinaison(int sol_ligne[4], int comb[7])
{
	int	col;

	col = 0;
	while (col < 4)
	{
		sol_ligne[col] = comb[col + 1];
		col ++;
	}
}

int	trouver_solution_ligne(int row, int sol[4][4], int bord[4][4],
			int combinaisons[][7])
{
	int	comb_num;
	int	n;

	if (row >= 4)
		return (valider_solution(sol, bord, combinaisons));
	comb_num = trouver_combinaison(bord[2][row], bord[3][row], combinaisons);
	if (comb_num < 0)
		return (0);
	n = combinaisons[comb_num][6];
	while (n > 0)
	{
		inserer_combinaison(sol[row], combinaisons[comb_num + n - 1]);
		if (trouver_solution_ligne(row + 1, sol, bord, combinaisons) == 1)
			return (1);
		n --;
	}
	return (0);
}

int	trouver_solution(int sol[4][4], int bord[4][4], int combinaisons[][7])
{
	return (trouver_solution_ligne(0, sol, bord, combinaisons));
}
