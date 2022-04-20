#include "minishell.h"

char **split_path(char *string)
{
    char **path;

    if (string == NULL)
        return NULL;
    
    path = ft_split(string,':');
    return path;
}

char *return_path(char **envp)
{
    int i;
    char *path;

    i = 0;
    while (envp[i])
    {
        if(ft_strnstr(envp[i],"PATH=",ft_strlen(envp[i])) != 0)// in mac PATH=/usr
            path = ft_substr(envp[i],5,ft_strlen(envp[i]));// in mac PATH=/usr
        i++;
    }
	if (!path)
		return (NULL);
    return path;
}

char *concatenate_string(char *original, char *add)
{
    int i = 0;
    int j = 0;

    char *alloc1 = malloc(sizeof(char) *( ft_strlen(original) + ft_strlen(add) + 1));
    
    while (original[j])
    {
        alloc1[j] = original[j];
        j++;
    }
   
   while(add[j])
   {
      alloc1[j] = add[i];
      i++;
      j++;
   }
   alloc1[j] = '\0';
   return alloc1;
}
