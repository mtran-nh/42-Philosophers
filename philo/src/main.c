/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:32:49 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/10/09 11:16:05 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	check_input(int ac, char **av)
{
	int	i;
	int	num;

	if (ac < 5 || ac > 6)
		error_msg("Error: expected 4 or 5 arguments\n", 1);
	i = 0;
	while (++i < ac)
	{
		num = av[i];
		if (i == 1 && (num < 1 || num > PHILO_MAX))
			error_msg("Error: Invalid argument\n", 1);
		else if (i == 5 && (num < 0 || num > INT_MAX))
			error_msg("Error: Invalid argument\n", 1);
		else if ((i != 1 && i != 5) && (num < 1 || num > INT_MAX))
			error_msg("Error: Invalid argument", 1);
	}
}

int	main(int ac, char **av)
{
}
