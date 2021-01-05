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

#include "minishell.h"

/*
** shell loop
** 
*/

int	ft_strcmp(char *s1, const char *s2)
{
	int x;

	x = 0;
	while (s1[x] == s2[x] && s1[x] != '\0' && s2[x] != '\0')
		x++;
	return (s1[x] - s2[x]);
}

t_string *parse(t_string line)
{
    t_string *args;

    args = malloc(sizeof(t_string) + 1);
    args[0] = line;
    args[1] = NULL;
    return (args);
}

t_res shell_launch(t_string *args)
{
    pid_t pid;
    int status;
    t_res   res;

    pid = fork();
    if (pid == 0)
    {
        // Child process
        if (execvp(args[0], args) == -1)
            handle_error(UNDEFINED_CMD);
    }
    else if (pid < 0)
        // Error forking
        handle_error(COULDNT_FORK);
    res.status = 1;
    res.output = "";
    return res;
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
    ft_putstr_fd("ss", 2);
    return (shell_launch(args));
}

void loop(t_shell   *shell)
{
    int status;
    t_string line;
    t_string *args;
    t_res result;

    status = TRUE;
    ft_putstr_fd("Welcome to wowo shell!\n", 2);
    while (status)
    {
        ft_putstr_fd("wowo$", 2);
        /*
        ** read the input then store it in line
        */
        read_line(STDIN, &line);
        ft_putstr_fd(line, STDOUT);
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
        status = result.status;

        /*
        **  print the output if the command executed has an output
        */
        ft_putstr_fd(result.output, STDOUT);
    }
}