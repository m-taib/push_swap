#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if (!newnode)
		return (0);
	newnode->content = content;
	newnode->next = 0;
	return (newnode);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

int		space_tabs(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
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
	while (str[i] && str[i] != ' ' && str[i] != '\t')
			i++;
	return (i);
}

char	*fill_word(char	*str,int *c)
{
	int		i;
	char 	*s;

	i = 0;

	while (str[i] && str[i] != ' ' && str[i] != '\t')
		i++;
	s = malloc(i + 1);
	if (!s)
		return (0);
	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
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
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
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
			while (av[i][j] && (av[i][j] == ' ' || av[i][j] == '\t'))
				j++;
			if (av[i][j] && !(av[i][j] >= '0' && av[i][j] <= '9') && av[i][j] != '-' && av[i][j] != '+')
				return (0);
			if (av[i][j+1] && (av[i][j+1] == ' ' || av[i][j+1] == '\t'))
				while (av[i][j+1] && (av[i][j+1] == ' ' || av[i][j+1] == '\t'))
					j++;
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

int		space_tab(char	*str)
{
	int		i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			return (0);
		i++;
	}
	return (1);
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
		if (!(space_tab(av[i])))
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
#include <stdio.h>
void	fill_array(char **av,long long	*arr)
{
	int		i[3];
	char 	**str;

	i[0] = 0;
	i[1] = 0;
	while (av[i[0]])
	{
		if (!(space_tab(av[i[0]])))
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
int		ft_check(char **av)
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
	return (1);
}
#include <stdio.h>
int		main(int	ac,char **av)
{
	/*
	 * duplicated number
	 * not int
	 * > INT_MAX
	 * < INT_MIN
	 * arguments inside arguments
	 */
	printf("%d",ft_check(&av[1]));
	int		nb;
	//nb = count_numbers(&av[1]);
	/*char **str;
	int		i;
	i = 0;
	str = ft_split("This is the way");
	while (str[i])
	{
		printf("%s\n",str[i]);
		i++;
	}*/
	return (0);
}
