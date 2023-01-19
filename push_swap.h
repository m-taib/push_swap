#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
typedef struct s_list
{
	int	content;
	int	index;
	int	pos;
	struct s_list *next;
}t_list;
t_list	*ft_lstnew(int content);
void    sb(t_list **b);
void    sa(t_list **a);
void    ss(t_list   **a,t_list  **b);
void    pb(t_list **a, t_list **b);
void    pa(t_list **a, t_list **b);
void    rb(t_list **b);
void    ra(t_list **a);
void    rr(t_list **a, t_list **b);
void    rrb(t_list **b);
void    rra(t_list **a);
void    rrr(t_list **a, t_list **b);
int     duplicated_sign(char *str);
int     duplicated_number(long long *arr,int    count);
int     not_min_max(long long   *arr,int    count);
int     space(char *str);
void    fill_array(char **av,long long  *arr);
int     count_numbers(char  **av);
int		not_dec(char **av);
long long 	*ft_check(char **av,int	*nb);
char    **ft_split(char *str);
long long   ft_atoi(const char *str);
t_list  *arguments_list(long long   *arr,int nb);
int     is_sorted(long long *arr,long long *arr1,int    nb);

