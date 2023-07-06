#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	if (src)
	{
		while (src[i])
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = 0;
}

char	*ft_strchr(char *s, char c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	if (s[i] == c)
			return (&s[i]);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	char		*endline;
	static char	*left;
	int			i;
	int			rd;


	if (fd < 0)
		return (NULL);
	i = 0;
	if (!left)
	{
		left = malloc(100000);
		left[0] = 0;
	}
	line = malloc(100000);
	line[0] = 0;
	buffer = malloc(100000);
	while(i <= BUFFER_SIZE)
	{
		buffer[i] = 0;
		i++;	
	}
	i = 0;
	ft_strcpy(line, left);
	endline = ft_strchr(line, '\n');
	if (endline)
	{
		ft_strcpy(left, &endline[1]);
		endline[1] = 0;
		free(buffer);
		return (line);		
	}
	while ((rd = read(fd, buffer, BUFFER_SIZE) > 0))
	{
		buffer[BUFFER_SIZE] = 0;
		endline = ft_strchr(line, '\0');
		ft_strcpy(endline, buffer);
		endline = ft_strchr(line, '\n');
		if (endline)
			break;
	}
	if (rd == 0 && line[0] == 0)
	{
		free(buffer);
		free(left);
		free(line);
		left = NULL;
		return(NULL);
	}
	if (rd < 0)
	{
		free(buffer);
		free(left);
		free(line);
		left = NULL;
		return(NULL);
	}
	if (rd == 0)
	{
		free(buffer);
		free(left);
		left = NULL;	
		return (line);
	}
	endline = ft_strchr(line, '\n');
	ft_strcpy(left, &endline[1]);
	endline[1] = 0;
	free(buffer);
	return (line);
}
