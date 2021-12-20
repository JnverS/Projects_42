#include "../include/so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		lens1;
	int		lens2;
	char	*str;
	int		i;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	str = NULL;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = (char *)malloc((lens1 + lens2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < lens1)
	{
		str[i] = s1[i];
		i++;
	}
	lens2 = 0;
	while (s2[lens2])
		str[i++] = s2[lens2++];
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *str)
{
	char	*s;
	int		len;

	len = 0;
	while (str[len])
		len++;
	s = (char *)malloc(len + 1 * sizeof(char));
	len = 0;
	if (!s)
		return (NULL);
	while (str[len])
	{
		s[len] = str[len];
		len++;
	}
	s[len] = '\0';
	return (s);
}