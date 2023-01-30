/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaib <mtaib@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:11:10 by mtaib             #+#    #+#             */
/*   Updated: 2023/01/30 13:11:20 by mtaib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (0);
		s1[0] = 0;
	}
	if (!s2)
		return (0);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

int		check_newline(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

#include <stdio.h>

char	*get_line()
{
	char	*buffer;
	char 	*line;
	int		i;
	
	i = 1;
	buffer = malloc(2);
	buffer[0] = '\0';
	line = NULL;
	while (i && check_newline(buffer))
	{
		i = read(0,buffer,1);
		if (i < 0)
		{
			free(buffer);
			return (0);
		}
		if (buffer)
			buffer[i] = '\0';
		line = ft_strjoin(line, buffer);
		if (!buffer[0])
		{
			free(buffer);
			free(line);
			return (0);
		}
	}
	if (!line)
	{
		free(buffer);
		free(line);
		return (0);
	}
	i = ft_strlen(line) - 1;
	line[i] = '\0';
	free(buffer);
	return (line);
}

int		check_instructions(char *str, t_list **a, t_list **b)
{
	if (!ft_strcmp(str,"pa"))
		pa(a, b, 0);
	else if (!ft_strcmp(str,"pb"))
		pb(a, b, 0);
	else if (!ft_strcmp(str,"ra"))
		ra(a, 0);
	else if (!ft_strcmp(str,"rb"))
		rb(b, 0);
	else if (!ft_strcmp(str,"rr"))
		rr(a, b, 0);
	else if (!ft_strcmp(str,"sa"))
		sa(a, 0);
	else if (!ft_strcmp(str,"sb"))
		sb(a, 0);
	else if (!ft_strcmp(str,"ss"))
		ss(a, b, 0);
	else if (!ft_strcmp(str,"rra"))
		rra(a, 0);
	else if (!ft_strcmp(str,"rrb"))
		rrb(b, 0);
	else if (!ft_strcmp(str,"rrr"))
		rrr(a, b, 0);
	else
		return (0);
	return (1);
}

int		check_stack(t_list **head,long long	*arr)
{
	int		i;
	t_list *tmp;

	tmp = *head;
	i = 0;
	while (tmp)
	{
		if (arr[i] != tmp->content)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

void	check_algo(long long *arr, t_list **head,t_list *head1)
{
	char	*str;

	while (1)
	{
		str = get_line();
		if (!str)
		{
			free(str);
			break;
		}
		if (!check_instructions(str, head, &head1))
		{
			free(str);
			free_list(head);
			free_list(&head1);
			write(2,"Error\n",6);
			return ;
		}
		free(str);
	}
	if (!check_stack(head, arr))
		write(1,"KO\n",3);
	else
		write(1,"OK\n",3);
}

int	main(int ac,char **av)
{
	int		nb;
	t_list 	**head;
	t_list 	*node;
	t_list 	*head1;
	long long	*arr;

	(void)ac;
	arr = ft_check(&av[1], &nb);
	if (!arr)
	{
		write(2,"Error\n",6);
		free(arr);
		return (0);
	}
	node = arguments_list(arr, nb);
	head = &node;
	sort_list(arr,nb);
	index_elements(head, nb, arr);
	head1 = 0;
	head = &node;	
	check_algo(arr, head, head1);
	free_list(head);
	free_list(&head1);
	free(arr);
	return (0);
}
