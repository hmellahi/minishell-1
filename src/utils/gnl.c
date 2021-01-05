
#include "minishell.h"

/*
TODO:
	-Make it more readable.
	-
*/

#undef BUFF_SIZE
# define BUFFER_SIZE 128


size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
char		*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != c && *str)
		str++;
	if (*str != c)
		return (0);
	return (str);
}

char		*ft_strdup(const char *str)
{
	int		len;
	char	*dest;

	len = ft_strlen(str);
	if (!(dest = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	dest[len] = 0;
	while (len--)
		dest[len] = ((char*)str)[len];
	return (dest);
}

char		*join(char const *s1, char const *s2)
{
	int		i;
	int		k;
	char	*s12;

	k = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(s12 = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1)))
		return (NULL);
	while (s1[i])
	{
		s12[i] = s1[i];
		i++;
	}
	while (s2[k])
		s12[i++] = s2[k++];
	s12[i] = 0;
	return (s12);
}

int		is_valid(int fd, char **line)
{
	if (BUFFER_SIZE < 0 || !line || read(fd, NULL, 0) < 0)
		return (0);
	return (1);
}

void	free_space(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

int		saveline(char **line, char **rem, char **ptr, char **buff)
{
	char *tmp;

	**ptr = '\0';
	*ptr += 1;
	tmp = *rem;
	*rem = ft_strdup(*ptr);
	free_space(&tmp);
	*line = join(*line, *buff);
	free_space(buff);
	return (1);
}

int		checkremainder(char **remainder, char **line, char **buff)
{
	char *ptr;
	char *tmp;

	ptr = NULL;
	*line = ft_strdup("");
	if (*remainder)
	{
		if ((ptr = ft_strchr(*remainder, '\n')))
		{
			*ptr = '\0';
			*line = join(*remainder, *line);
			tmp = *remainder;
			*remainder = ft_strdup(ptr + 1);
			free_space(&tmp);
			free_space(buff);
			return (1);
		}
		else
		{
			*line = join(*remainder, *line);
			free_space(remainder);
		}
	}
	return (0);
}

int		read_line(int fd, char **line)
{
	char			*buff;
	int				nbytes;
	char			*ptr;
	static char		*rem;

	free(NULL);
	if (!is_valid(fd, line) ||
	!(buff = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	if (checkremainder(&rem, line, &buff))
		return (1);
	while ((nbytes = read(fd, buff, BUFFER_SIZE)))
	{
		buff[nbytes] = '\0';
		if ((ptr = ft_strchr(buff, '\n')))
			return (saveline(line, &rem, &ptr, &buff));
		*line = join(*line, buff);
	}
	free_space(&buff);
	return (0);
}