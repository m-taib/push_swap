/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaib <mtaib@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:10:55 by mtaib             #+#    #+#             */
/*   Updated: 2023/01/29 14:28:49 by mtaib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_elements(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	if (tmp->index > tmp->next->index && tmp->next->index < tmp->next->next->index
			&& tmp->index < tmp->next->next->index)
		sa(a, 1);
	else if (tmp->index > tmp->next->index && tmp->next->index < tmp->next->next->index
			&& tmp->index > tmp->next->next->index)
		ra(a, 1);
	else if (tmp->index > tmp->next->index && tmp->next->index > tmp->next->next->index
			&& tmp->index > tmp->next->next->index)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (tmp->index < tmp->next->index && tmp->next->index > tmp->next->next->index
			&& tmp->index < tmp->next->next->index)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (tmp->index < tmp->next->index && tmp->next->index > tmp->next->next->index
			&& tmp->index > tmp->next->next->index)
		rra(a, 1);
}


void	sort_push(t_list **a, t_list **b, int j)
{
	sort_3_elements(a);
	while (j - 3)
	{
		pa(a, b, 1);
		j--;
	}
}

void	sort_5_elements(t_list **a,t_list **b, int nb)
{
	int		i;
	int		j;
	t_list	*tmp;

	j = nb;
	refresh_position(*a, nb - 1);
	i = 0;
	while (nb - 3)
	{
		tmp = *a;
		while (tmp->index != i)
			tmp = tmp->next;
		if (tmp->pos <= (nb / 2))
			while ((*a)->index != i)
				rra(a, 1);
		else if (tmp->pos > (nb / 2))
			while ((*a)->index != i)
				ra(a, 1);
		pb(a, b, 1);
		i++;
		nb--;
	}
	sort_push(a, b, j);
}

int		sort_less_than_5elements(t_list **head, t_list *head1, int nb)
{

	if (nb >= 2 && nb <= 5)
	{
		if (nb == 2)
		{
			if ((*head)->index > (*head)->next->index)
				sa(head, 1);
		}
		else if (nb == 3)
			sort_3_elements(head);
		else if (nb >= 3 && nb <= 5)
			sort_5_elements(head,&head1, nb);
	}
	free_list(head);
	return (0);
}
