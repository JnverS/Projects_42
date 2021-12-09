#include "pipex.h"

char *fnd_path(char *cmd, char **envp)
{
    char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		i++;
	}
	return (0);
}

void child_pr(int fd1, char *argv, char **envp, int *pip)
{
    char **cmd;

    dup2(pip[1], 1);
    dup2(fd1, 0);
    close(pip[0]);
    cmd = ft_split(argv, ' ');
    if (execve(fnd_path(cmd[0], envp), cmd, envp) == -1)
    {   
        write(2, "Command not found\n", 16);
        exit(EXIT_FAILURE);
    }
}

void parent_pr(int fd2, char *argv, char **envp, int *pip)
{
    char **cmd;

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

void pipex (int fd1, int fd2, char **argv, char **envp)
{
    int pip[2];
    int pid;

    if (pipe(pip) == -1)
        write(2, "Pipe error\n", 10);
    pid = fork();
    if (pid == -1)
        write(2, "Fork error\n", 10);
    if (pid == 0)
        child_pr(fd1, argv[2], envp, pip);
    waitpid(pid, NULL, 0);
    parent_pr(fd2, argv[3], envp, pip);
    close(pip[0]);
    close(pip[1]);
}

int main(int argc, char ** argv, char **envp)
{
    int fd1;
    int fd2;

    if (argc == 5)
    {
        fd1 = open(argv[1], O_RDONLY);
        fd2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC);
        if (fd1 < 0 || fd2 < 0)
            write(2, "Error open file\n", 16);
        pipex(fd1, fd2, argv, envp);
        close(fd1);
        close(fd2);
    }
    else
        write(2, "Need 4 arguments\n", 17);
    return 0;
}