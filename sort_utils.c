/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaib <mtaib@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:00:34 by mtaib             #+#    #+#             */
/*   Updated: 2023/01/29 15:27:39 by mtaib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_list(long long *arr,int nb)
{
	int		i;
	int		j;
	long long		tmp;

	tmp = 0;
	i = 0;
	while (i < nb)
	{
		j = i + 1;
		while (j < nb)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	refresh_position(t_list *head1, int j)
{

	while (head1)
	{
		head1->pos = j;
		head1 = head1->next;
		j--;
	}
}

t_list	*move_elements_to_sb(t_list **head, t_list *head1, int nb, int r)
{
	int		i;

	i = 0;
	while (1)
	{
		if (i > 1 && (*head)->index <= i)
		{
			pb(head, &head1, 1);
			rb(&head1, 1);
			if (i == nb - 1)
				break ;
			i++;
		}
		else if ((*head)->index <= (i + r))
		{
			pb(head, &head1, 1);
			if (i == nb - 1)
				break ;
			i++;
		}
		else
			ra(head, 1);
	}
	return (head1);
}

void	sort_elements(t_list **head, t_list *head1, int nb)
{
	t_list *tmp;
	int		j;
	int		i;

	i = --nb;
	while (1)
	{
		tmp = head1;
		while (tmp->index != i)
			tmp = tmp->next;
		if (tmp->pos <= ((nb - 1) / 2))
			while (head1->index != i)
				rrb(&head1, 1);
		else if (tmp->pos > ((nb - 1) / 2))
			while (head1->index != i)
				rb(&head1, 1);
		pa(head, &head1, 1);
		j = --nb;
		refresh_position(head1, j);
		if (i <= 0)
			break;
		nb = ft_lstsize(head1);
		i--;
	}
}

void	sorting_process(t_list **head,t_list *head1, int nb)
{
	t_list *tmp;
	int		r;
	int		i;
	
	r = 0;
	if (nb <= 100)
		r = 15;
	else if (nb > 100)
		r = 30;
	tmp = move_elements_to_sb(head, head1, nb, r);
	head1 = tmp;
	nb = ft_lstsize(head1);
	i = nb - 1;
	while (head1)
	{
		head1->pos = i;
		head1 = head1->next;
		i--;
	}
	head1 = tmp;
	sort_elements(head, head1, nb);
}
