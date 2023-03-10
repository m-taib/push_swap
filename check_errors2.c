/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaib <mtaib@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:10:48 by mtaib             #+#    #+#             */
/*   Updated: 2023/01/30 13:10:52 by mtaib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int		not_min_max(long long	*arr,int	count)
{
	int		i;

	i = 0;
	while (i < count)
	{
		if (arr[i] > INT_MAX || arr[i] < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int		duplicated_number(long long *arr,int	count)
{
	int		i;
	int		j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		space(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (0);
		i++;
	}
	return (1);
}

void	free_elements(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int		count_numbers(char 	**av)
{
	int		i;
	int		j;
	int		c;
	char	**str;

	i = 0;
	c = 0;
	while (av[i])
	{
		if (!(space(av[i])))
		{
			j = 0;
			str = ft_split(av[i]);
			while (str[++j])
					c++;
			free_elements(str);
		}
		i++;
		c++;
	}
	return (c);
}

