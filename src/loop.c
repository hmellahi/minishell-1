/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:11:59 by marvin            #+#    #+#             */
/*   Updated: 2021/01/04 15:11:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

/*
** shell loop
** 
*/

void read_line(int fd, t_string *line)
{
    gnl(fd, &line);
}

t_string *parse(t_string line)
{
    t_string args[1];

    args[0] = line;
    return (args);
}

t_res shell_launch(t_string *args)
{
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0)
    {
        // Child process
        if (execvp(args[0], args) == -1)
            handle_error(INDEFINED_CMD, FAIL);
    }
    else if (pid < 0)
        // Error forking
        handle_error(COULDNT_FORK, FAIL);
}
/*
**  execute the command given 
** in case that command is buildin then 
** ==> fork and run in on other shell
*/

t_res execute(t_string *args, t_shell *shell)
{
    t_string cmd;
    int i;

    cmd = args[0];
    // if (cmd == NULL)
    //     return "1";
    i = -1;
    while (++i < CMDS_COUNT)
        if (ft_strcmp(cmd, shell->cmds_str[i]) == 0)
            return ((*shell->cmds)(i))(args);
    return (shell_launch(args));
}

void ft_putstr_fd(char *s, int fd)
{
    if (!s)
        return;
    while (*s)
    {
        ft_putchar_fd(*s, fd);
        s++;
    }
}

void loop(t_shell   *shell)
{
    int status;
    t_string line;
    t_string args;
    t_string *result;

    status = TRUE;
    ft_putstr_fd("Welcome to wowo shell!\n", 2);
    while (status)
    {
        ft_putstr_fd("wowo$", 2);
        /*
        ** read the input then store it in line
        */
        read_line(STDIN, &line);

        /*
        **  Parse the line into args and store it
        */

        args = parse(line);

        /*
        **  execute the command
        */

        result = execute(args, shell);

        /*
        **  Update the status
        ** which indicate when the shell will stop
        */
        status = result[STATUS];

        /*
        **  print the output if the command executed has an output
        */
        ft_putstr_fd(result[OUTPUT], 2);
    }
}