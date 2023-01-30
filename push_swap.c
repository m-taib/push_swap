/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaib <mtaib@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:00:15 by mtaib             #+#    #+#             */
/*   Updated: 2023/01/30 13:09:59 by mtaib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int		main(int	ac,char	**av)
{
	int		nb;
	t_list 	**head;
	t_list 	*node;
	long long	*arr;
	
	(void)ac;
	arr = ft_check(&av[1], &nb);
	if (!arr)
	{
		write(2,"Error\n",6);
		return (free(arr), 0);
	}
	node = arguments_list(arr, nb);
	head = &node;
	sort_list(arr,nb);
	if (is_sorted(arr, &av[1], nb))
	{
		free(arr);
		return(free_list(head),0);
	}
	index_elements(head, nb, arr);
	if (nb >= 2 && nb <= 5)
		return(sort_less_than_5elements(head, 0, nb));
	sorting_process(&node, 0, nb);
	return(free_list(head),0);
}
