
#include "minishell.h"


void	free_doublepointer(char **ptr)
{
	int	i;

	i = 0;
	if (!ptr || !ptr[0] || ptr == NULL || ptr[0][0] == '\0')
		return ;	
	if (ptr)
	{	
		while (ptr[i])
		{
			free(ptr[i]);
			i++;
		}
		free(ptr);
	}
}

void	free_pointer(char *str)
{
	if (!str || !str[0] || str == NULL || str[0] == '\0')
		return ;
	if (str)
	{
		free(str);
	}
}

void	free_all(char *str, char **tab, t_list2 *t)
{
	t_list2	*p;

	free_pointer(str);
	free_doublepointer(tab);
	while (t)
	{
		p = t;
		t = t->next;
		free(p->name);
		free(p->value);
		free(p);
	}
}
