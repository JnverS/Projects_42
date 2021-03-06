/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:55:19 by kdominic          #+#    #+#             */
/*   Updated: 2021/12/18 19:06:17 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_exec(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	path = fnd_path(cmd[0], envp);
	if (execve(path, cmd, envp) == -1)
	{
		write(2, "Command not found\n", 16);
		exit(EXIT_FAILURE);
	}
}

void	child_pr(char *argv, char **envp)
{
	int	pid;
	int	pip[2];

	if (pipe(pip) == -1)
		err("Pipe error\n");
	pid = fork();
	if (pid == -1)
		err("Fork error\n");
	if (pid == 0)
	{
		close(pip[0]);
		dup2(pip[1], 1);
		ft_exec(argv, envp);
	}
	else
	{
		close(pip[1]);
		dup2(pip[0], 0);
		waitpid(pid, NULL, 0);
	}
}

void	par_here_doc(int pip1, int pip2)
{
	close(pip2);
	dup2(pip1, 0);
	wait(NULL);
}

void	here_doc(int argc, char *limiter)
{
	int		pip[2];
	int		pid;
	char	*line;

	if (argc < 6)
		err("Not enough arguments\n");
	if (pipe(pip) == -1)
		err("Pipe error\n");
	pid = fork();
	if (pid == -1)
		err("Fork error\n");
	if (pid == 0)
	{
		close(pip[0]);
		line = get_next_line(0);
		while (line)
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(EXIT_SUCCESS);
			write(pip[1], line, ft_strlen(line));
			line = get_next_line(0);
		}
	}
	else
		par_here_doc(pip[0], pip[1]);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd1;
	int	fd2;
	int	i;

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			i = 3;
			fd2 = ft_open_file(argv[argc - 1], 0);
			here_doc(argc, argv[2]);
		}
		else
		{
			i = 2;
			fd1 = ft_open_file(argv[1], 2);
			fd2 = ft_open_file(argv[argc - 1], 1);
			dup2(fd1, 0);
		}
		while (i < argc - 2)
			child_pr(argv[i++], envp);
		dup2(fd2, 1);
		ft_exec(argv[argc - 2], envp);
	}
	ft_wrong_arg();
}
