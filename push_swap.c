#include "push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
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

int		ft_check_split(char c)
{
	if (c == ' ' || c == '\t')
		return (0);
	return (1);
}

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

int		duplicated_sign(char *str)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			j++;
		i++;
	}
	if (j > 1)
		return (0);
	return (1);
}

int		not_dec(char **av)
{
	int		i;
	int		j;
	
	i = 0;
	while (av[i])
	{
		j = 0;
		if (!duplicated_sign(av[i]))
			return (0);
		if (!(av[i][j]))
			return (0);
		while (av[i][j])
		{
			while (av[i][j] && av[i][j] == ' ')
				j++;
			if (av[i][j] == '-' || av[i][j] == '+')
				if (av[i][j+1] == '\0')
						return (0);
			if (av[i][j] && (!(av[i][j] >= '0' && av[i][j] <= '9') && av[i][j] != '-' && av[i][j] != '+'))
				return (0);
			if (av[i][j+1] && av[i][j+1] == ' ')
				while (av[i][j+1] && av[i][j+1] == ' ')
					j++;
			if (av[i][j] >= '0' && av[i][j] <= '9')
				if (av[i][j+1] == '-' || av[i][j+1] == '+')
					return (0);
			j++;
		}
		i++;
	}
	return (1);
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
			free(str);
		}
		i++;
		c++;
	}
	return (c);
}

void	fill_array(char **av,long long	*arr)
{
	int		i[3];
	char 	**str;

	i[0] = 0;
	i[1] = 0;
	while (av[i[0]])
	{
		if (!(space(av[i[0]])))
		{
			i[2] = 0;
			str = ft_split(av[i[0]]);
			while (str[i[2]])
			{
				arr[i[1]] = ft_atoi(str[i[2]++]);
				i[1]++;
			}
			i[1]--;
			free(str);
		}
		else
			arr[i[1]] =  ft_atoi(av[i[0]]);
		i[1]++;
		i[0]++;
	}
}

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

long long 	*ft_check(char **av,int	*nb)
{
	long long	*arr;
	
	if (!not_dec(av))	
		return (0);
	if (!(count_numbers(av)))
		return (0);
	arr = malloc(sizeof(long long) * count_numbers(av));
	if (!arr)
		return (0);
	fill_array(av,arr);
	if (!not_min_max(arr,count_numbers(av)))
		return (0);
	if (!duplicated_number(arr, count_numbers(av)))
		return (0);
		*nb = count_numbers(av);
	return (arr);
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

int		is_sorted(long long *arr,long long *arr1,int	nb)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		if (arr[i] != arr1[i])
			return (0);
		i++;
	}
	return (1);

}

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

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*tmp;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

#include <stdio.h>

void	sort_3_elements(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	if (tmp->index > tmp->next->index && tmp->next->index < tmp->next->next->index
			&& tmp->index < tmp->next->next->index)
		sa(a);
	else if (tmp->index > tmp->next->index && tmp->next->index < tmp->next->next->index
			&& tmp->index > tmp->next->next->index)
		ra(a);
	else if (tmp->index > tmp->next->index && tmp->next->index > tmp->next->next->index
			&& tmp->index > tmp->next->next->index)
	{
		sa(a);
		rra(a);
	}
	else if (tmp->index < tmp->next->index && tmp->next->index > tmp->next->next->index
			&& tmp->index < tmp->next->next->index)
	{
		sa(a);
		ra(a);
	}
	else if (tmp->index < tmp->next->index && tmp->next->index > tmp->next->next->index
			&& tmp->index > tmp->next->next->index)
		rra(a);
}

void	sort_5_elements(t_list **a,t_list **b, int nb)
{
	t_list	*tmp;
	int		i;
	int		j;
	j = i = nb;
	--i;
	tmp = *a;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i--;
	}
	i = 0;
	while (nb - 3)
	{
		tmp = *a;
		while (tmp->index != i)
			tmp = tmp->next;
		if (tmp->pos <= (nb / 2))
			while ((*a)->index != i)
				rra(a);
		else if (tmp->pos > (nb / 2))
			while ((*a)->index != i)
				ra(a);
		pb(a,b);
		i++;
		nb--;
	}
	if (j == 2 && (*b)->index < (*b)->next->index)
		sb(b);
	sort_3_elements(a);
	while (j - 3)
	{
		pa(a,b);
		j--;
	}
}

int		main(int	ac,char	**av)
{
	int		nb;
	long long *arr;
	long long *arr1;
	t_list 	**head;
	t_list 	*node;
	t_list 	*head1;
	t_list 	*tmp;
	t_list 	*tmp1;
	int		i;
	int		r;
	i = 0;
	if (!ft_check(&av[1], &nb))
	{
		write(1,"Error",5);
		return (0);
	}
	arr = ft_check(&av[1], &nb);
	arr1 = ft_check(&av[1], &nb);
	node = arguments_list(arr, nb);
	head = &node;
	tmp = node;
	sort_list(arr,nb);
	if (is_sorted(arr,arr1,nb))
		return (0);
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
	head1 = 0;
	head = &node;
	if (nb == 2)
	{
		if ((*head)->index > (*head)->next->index)
			sa(head);
	}
	else if (nb == 3)
		sort_3_elements(head);
	else if (nb >= 3 && nb <= 5)
		sort_5_elements(head,&head1, nb);
	i = 0;
	head1 = 0;
	
	head = &node;
	if (nb <= 100)
		r = 15;
	else if (nb <= 500)
		r = 30;
	while (1)
	{
		if (i > 1 && (*head)->index <= i)
		{
			pb(head,&head1);
			rb(&head1);
			if (i == nb - 1)
				break ;
			i++;
		}
		else if ((*head)->index <= (i + r))
		{
			pb(head,&head1);
			if (i == nb - 1)
				break ;
			i++;
		}
		else
			ra(head);
	}
	tmp = head1;
	tmp1 = head1;
	t_list *tmp2;
	nb = ft_lstsize(head1);
	while (head1)
	{
		head1->pos = i;
		head1 = head1->next;
		i--;
	}
	i = --nb;
	int		j;
	j = 0;
	head1 = tmp1;
	while (1)
	{
		tmp = head1;
		while (tmp->index != i)
			tmp = tmp->next;
		if (tmp->pos <= ((nb - 1) / 2))
			while (head1->index != i)
				rrb(&head1);
		else if (tmp->pos > ((nb - 1) / 2))
			while (head1->index != i)
				rb(&head1);
		pa(head,&head1);
		j = --nb;
		tmp2 = head1;
		while (tmp2)
		{
			tmp2->pos = j;
			tmp2 = tmp2->next;
			j--;
		}	
		if (i <= 0)
			break;
		nb = ft_lstsize(head1);
		i--;
	}
	free(arr);
	free(arr1);
	while (1);
	return (0);
}
