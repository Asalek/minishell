#include "minishell.h"

t_list	*ft_lstnew(char *v_name, char *v_value)
{
	t_command	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->cmd = v_name;
	new->arg = v_value;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

t_list	*creat_list(char **str)
{
	t_list	*p;
	char	**splited;
	int		i;

	i = 0;
	p = NULL;
	while (str[i])
	{
		splited = ft_split(str, '=');
		ft_lstadd_back(&p, ft_lstnew(splited[0], splited[1]));
		i++;
	}
	return (p);
}