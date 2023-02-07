#include "get_next_line.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (dst[x] && x < size)
		x++;
	while ((x + y + 1) < size && src[y])
	{
		dst[x + y] = src[y];
		y++;
	}
	if (x < size)
		dst[x + y] = '\0';
	return (x + ft_strlen(src));
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i++] = s2[j];
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == c)
			return ((char *)(s + i));
	if (!c && !s[i])
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	size_t	len;
	size_t	i;

	i = -1;
	len = ft_strlen(s1);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (NULL);
	while (++i < len)
		tmp[i] = s1[i];
	tmp[i] = '\0';
	return (tmp);
}
