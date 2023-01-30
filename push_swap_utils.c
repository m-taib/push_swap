/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaib <mtaib@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:59:53 by mtaib             #+#    #+#             */
/*   Updated: 2023/01/24 18:00:04 by mtaib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		count(char *str)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && ft_check_split(str[i]))
			i++;
		count++;
		while (str[i] && !ft_check_split(str[i]))
			i++;
	}
	return (count);
}

int		count_chars(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != ' ')
			i++;
	return (i);
}

char	*fill_word(char	*str,int *c)
{
	int		i;
	char 	*s;

	i = 0;

	while (str[i] && str[i] != ' ')
		i++;
	s = malloc(i + 1);
	if (!s)
		return (0);
	i = 0;
	while (str[i] && str[i] != ' ')
	{
		s[i] = str[i];
		(*c)++;
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	**ft_split(char *str)
{
	char	**newstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	newstr = malloc(sizeof(char *) * (count(str) + 1));
	if (!newstr)
		return (0);
	while (str[i] && j < count(str))
	{
		while (str[i] && str[i] == ' ')
			i++;
		newstr[j] = fill_word(&str[i],&i);
		i++;
		j++;
	}
	newstr[j] = NULL;
	return (newstr);
}

long long	ft_atoi(const char *str)
{
	int	i;
	int	arb;
	long long	res;

	arb = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\t' || str[i] == '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			arb *= -1;
	res = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * arb);
}
