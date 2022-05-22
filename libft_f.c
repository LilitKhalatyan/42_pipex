/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalaty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:45:19 by lkhalaty          #+#    #+#             */
/*   Updated: 2021/09/23 18:45:22 by lkhalaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char		*ft_strnstr(const char *str, const char *needle, size_t len)
{
	size_t 	i;
	size_t 	j;

	i = 0;
	if (needle[i] == '\0')
		return ((char*)str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == needle[j] && (i + j) < len)
		{
			if (needle[j + 1] == '\0')
			{
				return ((char*)str + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

size_t		ft_strlen(const char *s)
{
	size_t 	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strjoin(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*s3;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	if (!(s3 = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1)
		* sizeof(char))))
		return (NULL);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	return (s3);
}
