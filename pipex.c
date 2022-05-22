/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalaty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:13:26 by lkhalaty          #+#    #+#             */
/*   Updated: 2021/09/20 15:13:40 by lkhalaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void 		ft_child(int infile, char **argv, char **env, int *fd)
{
	char 	**cmd1;

	cmd1 = ft_split(argv[2], ' ');
	close(fd[0]);
	if (dup2(infile, 0) == -1)
	{
		perror("An error has occured with Dupliating in Child Process\n");
		exit (-1);
	}
	if (dup2(fd[1], 1) == -1)
	{
		perror("An error has occured with Dupliating in Child Process\n");
		exit (-1);
	}
	close(infile);
	if (execve(env_path(env, cmd1[0]), cmd1, env) == -1)
	{
		perror("Cant Ececve\n");
		exit (-1);
	}
}

void 		ft_child2(int outfile, char **argv, char **env, int *fd)
{
	char 	**cmd2;

	cmd2 = ft_split(argv[3], ' ');
	wait(NULL);
	//close(fd[1]);
	if (dup2(fd[0], 0) == -1)
	{
		perror("An error has occured with Dupliating in Parent Process\n");
		exit (-1);
	}
	close(fd[0]);
	if (dup2(outfile, 1) == -1)
	{
		perror("An error has occured with Dupliating in Parent Process\n");
		exit (-1);
	}
	close(outfile);
	if (execve(env_path(env, cmd2[0]), cmd2, env) == -1)
	{
		perror("Cant Ececve\n");
		exit (-1);
	}
}

void 		ft_pipex(int infile, int outfile, char **argv, char **env)
{
	int		fd[2];
	pid_t 	pid1;
	pid_t 	pid2;
	int 	status;

	if (pipe(fd) == -1)
	{
		perror("An error has occured with opening the Pipe\n");
		exit (-1);
	}
	pid1 = fork();
	if (pid1 == -1)
	{
		perror("An error has occured with Fork\n");
		exit (-1);
	}
	else if (pid1 == 0)
		ft_child(infile, argv, env, fd);
	else
	{
		close(fd[1]);
		pid2 = fork();
		if (pid2 == -1)
		{
			perror("An error has occured with Fork\n");
			exit (-1);
		}
		else if (pid2 == 0)
			ft_child2(outfile, argv, env, fd);
		else
			close(fd[0]);
	}
	wait(&status);
}

int 		main(int argc, char **argv, char **env)
{
	int 	infile;
	int 	outfile;

	if (argc != 5)
	{
		perror("Error: Wrong Formatting");
		return (-1);
	}
	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (infile < 0 || outfile < 0)
	{
		perror("Error: Oppening file error");
		return (-1);
	}
	ft_pipex(infile, outfile, argv, env);
	return (0);
}