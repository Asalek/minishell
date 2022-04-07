#include "minishell.h"

t_list	*ft_lstnew(char *cmd, char *arg)
{
	t_command	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->cmd = cmd;
	new->arg = arg;
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
	int		i;

	i = 0;
	p = NULL;
	while (str[i])
	{
		ft_lstadd_back(&p, ft_lstnew(str[i], str[i + 1]));
		i += 2;
	}
	return (p);
}