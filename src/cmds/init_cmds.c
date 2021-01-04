/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 18:10:44 by marvin            #+#    #+#             */
/*   Updated: 2021/01/04 18:10:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

t_string    *init_cmds_str()
{
    t_string    *cmds_str;

	cmds_str = malloc(sizeof(char*) * CMDS_COUNT);
    cmds_str[0] = "echo";
    cmds_str[1] = "pwd";
    cmds_str[2] = "exit";
    cmds_str[3] = "cd";
    cmds_str[4] = "env";
    cmds_str[5] = "unset";
    cmds_str[6] = "export";
    cmds_str[7] = 0;
    return (cmds_str);
}

t_res (*cmds(int i))(char **args)
{
    t_res    (*builtin_func[CMDS_COUNT]) (char **args);

    builtin_func[0] = &shell_echo;
    builtin_func[1] = &shell_pwd;
    builtin_func[2] = &shell_exit;
    builtin_func[3] = &shell_cd;
    builtin_func[4] = &shell_env;
    builtin_func[5] = &shell_unset;
    builtin_func[6] = &shell_export;
    builtin_func[7] = NULL;
    return (builtin_func[i]);
}