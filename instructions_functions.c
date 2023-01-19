#include "push_swap.h"

#include <stdio.h>

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

void	sb(t_list **b)
{
	t_list *tmp;
	
	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	write(1,"sb\n",3);
}

void	sa(t_list **a)
{
	t_list *tmp;
	
	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	write(1,"sa\n",3);
}

void	ss(t_list	**a,t_list	**b)
{
	sa(a);
	sb(b);
	write(1,"ss\n",3);
}

void	pb(t_list **a, t_list **b)
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
	write(1,"pb\n",3);
}

void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;
	
	if (!*b)
		return ;
	tmp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = tmp;
	/*t_list	*tmp;

	if (*b == 0)
		return ;
	tmp = (*b)->next;
	if (*a != 0)
	{
		(*b)->next = *a;
		*a = *b;
	}
	else
	{
		(*b)->next = NULL;
		*a = *b;
	}
	*b = tmp;*/
	write(1,"pa\n",3);
}

void	rb(t_list **b)
{
	t_list	*tmp;
	
	if (!*b)
		return ;
	tmp = *b;
	tmp = ft_lstlast(tmp);
	tmp->next = *b;
	*b = (*b)->next;
	tmp->next->next = NULL;
	write(1,"rb\n",3);
}

void	ra(t_list **a)
{
	t_list	*tmp;
	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	tmp = ft_lstlast(tmp);
	tmp->next = *a;
	*a = (*a)->next;
	tmp->next->next = NULL;
	write(1,"ra\n",3);
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
	write(1,"rr\n",3);
}

void	rrb(t_list **b)
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
	write(1,"rrb\n",4);
}

void	rra(t_list **a)
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
	write(1,"rra\n",4);
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
	write(1,"rrr\n",4);
}

/*int	main()
{
	t_list *node1;
	t_list *node2;
	t_list *node3;
	t_list **head;
	t_list **head1;
	t_list *node4;
	t_list *node5;
	t_list *node6;
	//node1 = ft_lstnew(3);
	node2 = ft_lstnew(2);
	node3 = ft_lstnew(1);
	

	node4 = ft_lstnew(5);
	node5 = ft_lstnew(6);
	node6 = ft_lstnew(8);
	
	node1->next = node2;
	node2->next = node3;
	node4->next = node5;
	node5->next = node6;
	head = &node4;
	node1= NULL;
	head1 = NULL;
	//sa(&head1);
	//rrb(&head1);

	while (*head)
	{
		printf("%d->",(*head)->content);
		*head = (*head)->next;
	}
	printf("\n");
	pb(head,head1);
	pb(head,head1);
	pb(head,head1);
	while (*head1)
	{
		printf("%d->",(*head1)->content);
		(*head1) = (*head1)->next;
	}
	
}*/

