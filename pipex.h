
#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h> 


char    	*env_path(char **env, char *ar);
size_t		ft_strlen(const char *s);
char		**ft_split(char const *s, char c);
char		*ft_strnstr(const char *str, const char *needle, size_t len);
char		*ft_strjoin(const char *s1, const char *s2);
void 		ft_pipex(int infile, int outfile, char **argv, char **envp);
void 		ft_child(int infile, char **argv, char **envp, int *fd);
void 		ft_child2(int outfile, char **argv, char **envp, int *fd);

#endif
