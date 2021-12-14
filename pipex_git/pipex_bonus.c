/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:55:19 by kdominic          #+#    #+#             */
/*   Updated: 2021/12/14 17:22:09 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_pr(char *limiter, char **envp, int *pip)
{
	char **line;

	if (ft_strnstr(get_next_line(line), limiter, ft_strlen(limiter)))
	{

	}
	else
	{

	}
}

void	parent_pr(int fd2, char *argv, char **envp, int *pip)
{
	char	**cmd;

	dup2(pip[0], 0);
	dup2(fd2, 1);
	close(pip[1]);
	cmd = ft_split(argv, ' ');
	if (execve(fnd_path(cmd[0], envp), cmd, envp) == -1)
	{
		write(2, "Command not found\n", 16);
		exit(EXIT_FAILURE);
	}
}

void	here_doc(int fd2, int argc, char *limiter, char **envp)
{
	int	pip[2];
	int	pid;

	if (argc < 6)
	{
		write(2, "Not enough arguments\n", 21);
		exit(EXIT_SUCCESS);
	}
	if (pipe(pip) == -1)
	{
		write(2, "Pipe error\n", 11);
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		write(2, "Fork error\n", 11);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		child_pr(limiter, envp, pip);
	else
		waitpid(pid, NULL, 0);
	close(pip[0]);
	close(pip[1]);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd1;
	int	fd2;
	int i;

	if (argc >= 6)
	{
		if (ft_strncmp(argv[1], "here_doc", 8))
		{
			i = 3;
			fd2 = open(argv[argc - 1], O_CREAT | O_APPEND | O_RDWR, 0644);
			here_doc(fd2, argc, argv[2], envp);
		}
		else
		{
			i = 2;
			fd1 = open(argv[1], O_RDONLY);
			fd2 = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
			if (fd1 < 0)
			{
				write(2, "Error open file1\n", 17);
				return (1);
			}
			if (fd2 < 0)
				write(2, "Error open file2\n", 17);
		}
		while(i < argc - 2)
		{

		}
		dup2(, 0);
		execve();
	}
	else
		write(2, "Not enough arguments\n", 21);
	return (0);
}
