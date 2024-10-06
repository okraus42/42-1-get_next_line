/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:38:33 by okraus            #+#    #+#             */
/*   Updated: 2024/10/06 18:10:40 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

# include <unistd.h>
# include <stdlib.h>

typedef	struct s_gnl
{
	char	leftover[1024][BUFFER_SIZE];
	char	buffer[BUFFER_SIZE];
	int		size_l[1024];	//how many chars in leftover
	int		count_nl[1024];	//how many newlines in leftover
	char	*temp;
	char	*temp2;
	int		fd;
	int		size_temp;		//how big is temp
	int		length_temp;	//how many chars in temp
	char	*line;
} t_gnl;

// char	*read_file(int fd, char *str);
// char	*get(char *str);
// char	*next(char *str);
char	*get_next_line(int fd);
// int		find_char(char *s, char c);
// int		ft_strlen(char *s);
// char	*ft_strjoin(char *s1, char *s2);

#endif
