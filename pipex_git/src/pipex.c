/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:55:19 by kdominic          #+#    #+#             */
/*   Updated: 2021/12/18 19:02:08 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	child_pr(int fd1, char *argv, char **envp, int *pip)
{
	char	**cmd;

	dup2(pip[1], 1);
	dup2(fd1, 0);
	close(pip[0]);
	cmd = ft_split(argv, ' ');
	if (execve(fnd_path(cmd[0], envp), cmd, envp) == -1)
	{
		write(2, "Command not found\n", 18);
		close(pip[1]);
		exit(EXIT_FAILURE);
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
		write(2, "Command not found\n", 18);
		close(pip[0]);
		exit(EXIT_FAILURE);
	}
}

void	pipex(int fd1, int fd2, char **argv, char **envp)
{
	int	pip[2];
	int	pid;

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
		child_pr(fd1, argv[2], envp, pip);
	waitpid(pid, NULL, 0);
	parent_pr(fd2, argv[3], envp, pip);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd1;
	int	fd2;

	if (argc == 5)
	{
		fd1 = open(argv[1], O_RDONLY);
		fd2 = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (fd1 < 0)
		{
			write(2, "Error open file1\n", 17);
			return (1);
		}
		if (fd2 < 0)
		{
			write(2, "Error open file2\n", 17);
			return (2);
		}
		pipex(fd1, fd2, argv, envp);
	}
	else
		write(2, "Need 4 arguments\n", 17);
	return (0);
}
