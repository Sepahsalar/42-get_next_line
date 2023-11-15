/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:35:25 by asohrabi          #+#    #+#             */
/*   Updated: 2023/11/14 16:06:37 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(int fd, char *str)
{
	char	buf[BUFFER_SIZE + 1];
	int		i;

	i = 1;
	while (!ft_strchr(str, '\n') && i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
			return (ft_free(str));
		buf[i] = '\0';
		str = ft_strjoin(str, buf);
		if (!str)
			return (NULL);
	}
	return (str);
}

int	ft_con(char *str)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		j = i + 2;
	else if (!str[i])
		j = i + 1;
	return (j);
}

char	*ft_line(char *str)
{
	int		i;
	char	*line;

	if (!str[0] || !str)
		return (NULL);
	i = ft_con(str);
	line = (char *)malloc(i * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_new_str(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (ft_free(str));
	new_str = malloc((ft_strlen(str) - i + 1) * sizeof(char));
	if (!new_str)
		return (ft_free(str));
	i++;
	while (str[i] != '\0')
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	if (!new_str[0])
	{
		free(new_str);
		return (ft_free(str));
	}
	free(str);
	return (new_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str[TOTAL_FDS + 1];

	if (fd < 0 || BUFFER_SIZE < 1 || fd > TOTAL_FDS)
		return (NULL);
	str[fd] = ft_read(fd, str[fd]);
	if (!str[fd])
	{
		str[fd] = NULL;
		return (NULL);
	}
	line = ft_line(str[fd]);
	if (!line)
	{
		str[fd] = ft_free(str[fd]);
		return (NULL);
	}
	str[fd] = ft_new_str(str[fd]);
	return (line);
}
