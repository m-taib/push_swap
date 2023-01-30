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
int ft_lstsize(t_list *lst);
void    ft_lstadd_front(t_list **lst, t_list *new);
void	free_elements(char **str);
void    free_list(t_list **head);
void    sb(t_list **b, int i);
void    sa(t_list **a, int i);
void    ss(t_list   **a,t_list  **b, int i);
void    pb(t_list **a, t_list **b, int i);
void    pa(t_list **a, t_list **b, int i);
void    rb(t_list **b, int i);
void    ra(t_list **a, int i);
void    rr(t_list **a, t_list **b, int i);
void    rrb(t_list **b, int i);
void    rra(t_list **a, int i);
void    rrr(t_list **a, t_list **b, int i);
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
int     is_sorted(long long *arr, char **av, int      nb);
int     ft_check_split(char c);
int     count(char *str);
int     count_chars(char *str);
char    *fill_word(char *str,int *c);
void    sort_list(long long *arr,int nb);
void    sort_3_elements(t_list **a);
void    sort_push(t_list **a, t_list **b, int j);
void    sort_5_elements(t_list **a,t_list **b, int nb);
void    index_elements(t_list **head,int nb,long long *arr);
t_list  *move_elements_to_sb(t_list **head, t_list *head1, int nb, int r);
void    refresh_position(t_list *head1, int j);
void    sort_elements(t_list **head, t_list *head1, int nb);
int	    sort_less_than_5elements(t_list **head, t_list *head1, int nb);
void    sorting_process(t_list **head,t_list *head1, int nb);

