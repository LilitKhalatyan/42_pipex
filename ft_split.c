/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalaty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:44:43 by lkhalaty          #+#    #+#             */
/*   Updated: 2021/09/23 18:44:48 by lkhalaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

unsigned int	nb_ns(char const *s, char c)
{
	unsigned int	i;
	unsigned int	nb;

	if (!s[0])
		return (0);
	i = 0;
	nb = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
			i++;
		nb++;
	}
	if (s[--i] == c)
		nb--;
	return (nb);
}

unsigned int	ns_len(char const *s, char c)
{
	unsigned int	i;
	unsigned int	s_len;

	i = 0;
	s_len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		s_len++;
	}
	return (s_len);
}

char			**ft_free(char **str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char				**ft_split(char const *s, char c)
{
	char			**array;
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;
	unsigned int	nb;

	nb = nb_ns(s, c);
	
	i = 0;
	if (!s || !(array = (char**)malloc(sizeof(char*) * (nb + 1))))
		return (NULL);
	while (i < nb)
	{
		while (*s == c)
			s++;
		len = ns_len(s, c);
		if (!(array[i] = (char *)malloc((len + 1) * sizeof(char))))
			return (ft_free(array));
		j = 0;
		while (j < len)
			array[i][j++] = *(s++);
		array[i][j] = '\0';
		i++;
	}
	array[i] = NULL;
	return (array);
}
