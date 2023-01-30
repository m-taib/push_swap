/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaib <mtaib@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:46:00 by mtaib             #+#    #+#             */
/*   Updated: 2023/01/30 12:26:13 by mtaib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_split(char c)
{
	if (c == ' ')
		return (0);
	return (1);
}

t_list	*arguments_list(long long	*arr,int nb)
{
	int		i;
	t_list 	*newnode;
	t_list	*nextnode;
	t_list	*head;

	i = 0;
	if (!nb)
		return (0);
	newnode = ft_lstnew(arr[i++]);
	head = newnode;
	while (i < nb)
	{
		nextnode = ft_lstnew(arr[i++]);
		newnode->next = nextnode;
		newnode = nextnode;
	}
	return (head);
}

int		is_sorted(long long *arr, char **av, int	nb)
{
	int		i;
	long long *arr1;

	i = 0;
	arr1 = ft_check(av, &nb);
	while (i < nb)
	{
		if (arr[i] != arr1[i])
		{
			free(arr1);
			return (0);
		}
		i++;
	}
	free(arr1);
	return (1);

}

void	index_elements(t_list **head,int nb,long long *arr)
{
	int		i;
	t_list	*tmp;

	tmp = *head;
	i = 0;
	while (i < nb)
	{
		while(*head && (*head)->content != arr[i])
			*head = (*head)->next;
		if (*head)
		{
			(*head)->index = i;
			*head = tmp;
		}
		i++;
	}
}

void	free_list(t_list **head)
{
	t_list *tmp;

	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
	free(*head);
}
