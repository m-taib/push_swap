/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaib <mtaib@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:11:26 by mtaib             #+#    #+#             */
/*   Updated: 2023/01/30 13:11:55 by mtaib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	sb(t_list **b, int i)
{
	t_list *tmp;
	
	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	if (i)
		write(1,"sb\n",3);
}

void	sa(t_list **a, int i)
{
	t_list *tmp;
	
	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	if (i)
		write(1,"sa\n",3);
}

void	ss(t_list	**a, t_list	**b, int i)
{
	sa(a, i);
	sb(b ,i);
	if (i)
		write(1,"ss\n",3);
}

void	pb(t_list **a, t_list **b, int i)
{
	t_list	*tmp;

	if (*a == 0)
		return ;
	tmp = (*a)->next;
	if (*b != 0)
	{
		(*a)->next = *b;
		*b = *a;
	}
	else
	{
		(*a)->next = NULL;
		*b = *a;
	}
	*a = tmp;
	if (i)
		write(1,"pb\n",3);
}

void	pa(t_list **a, t_list **b, int i)
{
	t_list	*tmp;
	
	if (!*b)
		return ;
	tmp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = tmp;
	if (i)
		write(1,"pa\n",3);
}

void	rb(t_list **b, int i)
{
	t_list	*tmp;
	
	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	tmp = ft_lstlast(tmp);
	tmp->next = *b;
	*b = (*b)->next;
	tmp->next->next = NULL;
	if (i)
		write(1,"rb\n",3);
}

void	ra(t_list **a, int i)
{
	t_list	*tmp;
	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	tmp = ft_lstlast(tmp);
	tmp->next = *a;
	*a = (*a)->next;
	tmp->next->next = NULL;
	if (i)
		write(1,"ra\n",3);
}

void	rr(t_list **a, t_list **b,int	i)
{
	ra(a, i);
	rb(b, i);
	if (i)
		write(1,"rr\n",3);
}

void	rrb(t_list **b, int i)
{
	t_list	*tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = ft_lstlast(*b);
	(*b)->next = tmp;
	while (tmp->next->next != *b)
		tmp = tmp->next;
	tmp->next->next = NULL;
	if (i)
		write(1,"rrb\n",4);
}

void	rra(t_list **a, int i)
{
	t_list	*tmp;
	
	if (!*a)
		return ;
	tmp = *a;
	 *a = ft_lstlast(*a);
	(*a)->next = tmp;
	while (tmp->next->next != *a)
		tmp = tmp->next;
	tmp->next->next = NULL;
	if (i)
		write(1,"rra\n",4);
}

void	rrr(t_list **a, t_list **b, int i)
{
	rra(a, i);
	rrb(b, i);
	if (i)
		write(1,"rrr\n",4);
}
