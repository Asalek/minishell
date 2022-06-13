
#include "minishell.h"

void	free_doublepointer(char **ptr)
{
	int	i;

	i = 0;
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
