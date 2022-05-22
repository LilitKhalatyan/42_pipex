/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalaty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:44:56 by lkhalaty          #+#    #+#             */
/*   Updated: 2021/09/23 18:44:59 by lkhalaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int			get_path_index(char **env)
{
	int		i;
	char	*str;

	i = 0;
	while (env[i] != 0)
	{
		str = ft_strnstr(env[i], "PATH=", 5);
		if (str)
			return (i);
		i++;
	}
	return (-1);
}

void		ft_freematrix(char **mtx)
{
	int		i;

	i = 0;
	while (mtx[i])
	{
		free(mtx[i]);
		i++;
	}
	free(mtx);
}

char    	*env_path(char **env, char *ar)
{
	int     path_index;
	int     i;
	char    **path;
	char    *final_path;
	char	*temp1;
	char	*temp2;

	final_path = (NULL);
	path_index = get_path_index(env);
	if (ar[0] == '/')
		return (ar);
	else
	{
		if (access(ar, F_OK) == 0)
			return (ar);
		path = ft_split(env[path_index] + 5, ':');
		i = 0;
		while(path[i])
		{
			temp1 = ft_strjoin(path[i], "/");
			temp2 = ft_strjoin(temp1, ar);
			if (access(temp2, F_OK) == 0)
			{
				final_path = temp2;
				free(temp1);
				ft_freematrix(path);
				return (final_path);
			}
			free(temp2);
			free(temp1);
			i++;
		}
	}
	ft_freematrix(path);
	return (final_path);
}
