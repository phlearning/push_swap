#include "get_next_line.h"

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str || !s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

static int	ft_line_save(int fd, char **line, char **stat_str)
{
	size_t	i;
	char	*buf;

	i = 0;
	buf = 0;
	while (stat_str[fd][i] != '\n' && stat_str[fd][i] != 0)
		i++;
	if (stat_str[fd][i] == '\n')
	{
		buf = ft_strdup(stat_str[fd] + i + 1);
		if (!buf)
			return (-1);
	}
	*line = ft_substr(stat_str[fd], 0, i);
	if (!*line)
		return (-1);
	free(stat_str[fd]);
	stat_str[fd] = buf;
	if (buf)
		return (1);
	return (0);
}

static int	ft_isempty(int fd, int rf, char **line, char **stat_str)
{
	if (rf < 0)
		return (-1);
	if (rf == 0 && stat_str[fd] == 0)
	{
		*line = ft_strdup("");
		if (!*line)
			return (-1);
		return (0);
	}
	return (ft_line_save(fd, line, stat_str));
}

static int	ft_rbuf(int fd, char **line, char *buf, char **stat_str)
{
	char		*buf2;
	int			response;

	response = read(fd, buf, BUFFER_SIZE);
	while (response > 0)
	{
		buf[response] = '\0';
		if (!stat_str[fd])
			stat_str[fd] = (ft_strdup(""));
		if (!stat_str[fd])
			return (-1);
		buf2 = stat_str[fd];
		stat_str[fd] = ft_strjoin(stat_str[fd], buf);
		if (!stat_str[fd])
			return (-1);
		free(buf2);
		if (ft_strchr(stat_str[fd], '\n'))
			break ;
		response = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (ft_isempty(fd, response, line, stat_str));
}

int	get_next_line(int fd, char **line)
{
	static char	*stat_str[2048];
	char		*buf;

	if (!line || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	return (ft_rbuf(fd, line, buf, stat_str));
}
