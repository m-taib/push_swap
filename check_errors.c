#include "push_swap.h"

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
