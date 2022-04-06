#include "minishell.h"


char *ft_strdup(char *str)
{
    size_t len = ft_strlen(str);
    int i = 0;
    char *copy = malloc(sizeof(char) * len + 1);

    while (str[i])
    {
        copy[i] = str[i];
        i++;
    }
    copy[i] = '\0';
    return copy;
    


}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*ptr;

	if (s == NULL)
		return (NULL);
	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (ptr == NULL) // protect
	{
		return (NULL);
	}
	i = 0;
	while (start < ft_strlen(s) && len--)
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}



size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			count++;
			while (*s != '\0' && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static char	**ft_free(char **str, int index)
{
	while (index--)
	{
		free(str[index]);
	}
	free(str);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	len;
	char	**str;

	i = 0;
	if (s == 0)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (str == 0)
		return (0);
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		len = 0;
		while (s[len] != '\0' && s[len] != c)
			len++;
		if (len != 0)
			str[i++] = ft_substr(s, 0, len);
		if (len != 0 && str[i - 1] == NULL)
			return (ft_free(str, i - 1));
		s += len;
	}
	str[i] = NULL;
	return (str);
}


static int	count_digits(int n)
{
	int		i;

	i = 0;
	while (n != 0)
	{
		n = n / 10 ;
		i++;
	}
	return (i);
}

static char	*is_negative(long n)
{
	int		len;
	char	*ptr;
	int		i;
	int		l;

	len = count_digits(n) + 1;
	ptr = malloc(sizeof(char) * len + 1);
	if (ptr == NULL)
		return (NULL);
	n = n * -1;
	i = 0;
	l = len;
	len = len -1;
	while (len > i)
	{
		ptr[len--] = (n % 10) + 48;
		n = n / 10;
	}
	ptr[0] = '-';
	ptr[l] = '\0';
	return (ptr);
}

static char	*is_positive(long n)
{
	int		len;
	char	*ptr;

	len = count_digits(n);
	if (n == 0)
		return (ptr = ft_strdup("0"));
	ptr = malloc(sizeof(char) * len + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[len] = '\0';
	while (len--)
	{
		ptr[len] = (n % 10) + 48;
		n = n / 10;
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	if (n < 0)
	{
		return (is_negative(n));
	}
	else
	{
		return (is_positive(n));
	}
}

int	ft_isdigit(int c)
{
	while (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}

int	ft_isalpha(int c)
{
	while ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	return (0);
}


int	ft_atoi(const char *str)
{
	int		i;
	int		nbr;
	int		n;

	i = 0;
	nbr = 0;
	n = 0;
	while (str[i] != '\0' && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] != '\0' && str[i] == '-')
	{
		n = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
		nbr = (nbr * 10) + (str[i++] - '0');
	if (n == 1)
		return (-nbr);
	return (nbr);
}


size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		len_src;
	size_t		len;
	size_t		i;
	size_t		len_dst;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	len = len_dst;
	i = 0;
	if (dstsize == 0)
		return (len_src);
	if (dstsize > len_dst)
	{
		while (len < dstsize - 1 && src[i] != '\0')
		{
			dst[len] = src[i];
			len++;
			i++;
		}
		dst[len] = '\0';
		return (len_dst + len_src);
	}
	else
		return (dstsize + len_src);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	len;
	char	*ptr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	len = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc(sizeof(char) * len + 1);
	if (ptr == NULL)
	{
		return (NULL);
	}
	ft_memmove(ptr, s1, s1_len);
	ft_memmove(ptr + s1_len, s2, s2_len);
	ptr[len] = '\0';
	return (ptr);
}
 
char	*ft_strchr(const char *str, int c)
{
	const char	*p;
	int			i;
	int			len;

	len = ft_strlen(str);
	i = 0;
	while (i <= len)
	{
		if (str[i] == (char)c)
		{
			p = &str[i];
			return ((char *)p);
		}
		i++;
	}
	return (0);
}


char	*ft_strnstr(const char *s, const char *find, size_t len)
{
	size_t		i;
	size_t		j;

	if (find[0] == '\0')
		return ((char *)s);
	i = 0;
	while (s[i] != '\0' && i < len)
	{
		j = 0;
		if (s[i] == find[j])
		{
			while (i + j < len && s[i + j] == find[j])
			{
				j++;
				if (find[j] == '\0')
					return ((char *)&s[i]);
			}
		}
		i++;
	}
	return (0);
}

int	ft_toupper(int c)
{
	while (c >= 97 && c <= 122)
	{
		return (c = c - 32);
	}
	return (c);
}

char	*ft_strrchr(const char	*str, int c)
{
	const char	*p;
	int			i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == (char)c)
		{
			p = &str[i];
			return ((char *)p);
		}
		i--;
	}
	return (0);
}

int	ft_tolower(int c)
{
	while (c >= 65 && c <= 90)
	{
		return (c = c + 32);
	}
	return (c);
}


int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}



void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*destination;
	const char	*source;

	destination = dest;
	source = src;
	if (dest != 0 || src != 0)
	{
		if (destination > source)
		{
			while (n--)
			{
				destination[n] = source[n];
			}
		}
		else
		{
			ft_memcpy(destination, source, n);
		}
	}
	return (dest);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*destination;
	const char	*source;

	destination = dest;
	source = src;
	if (dest != 0 || src != 0)
	{
		while (n--)
		{
			*destination = *source;
			destination++;
			source++;
		}
	}
	return (dest);
}
int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}