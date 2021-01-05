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

#include "minishell.h"

t_string    *init_cmds_str()
{
    t_string    *cmds_str;

	cmds_str = malloc(sizeof(t_string) * (CMDS_COUNT + 1));
    cmds_str[0] = "exit";
    // cmds_str[1] = "pwd";
    // cmds_str[2] = "exit";
    // cmds_str[3] = "cd";
    // cmds_str[4] = "env";
    // cmds_str[5] = "unset";
    // cmds_str[6] = "export";
    cmds_str[1] = 0;
    return (cmds_str);
}

t_res (*cmds(int i))(char **args)
{
    t_res    (*funcs[CMDS_COUNT + 1]) (char **args);

    funcs[0] = &cmd_exit;
    // builtin_func[1] = &shell_pwd;
    // builtin_func[2] = &shell_exit;
    // builtin_func[3] = &shell_cd;
    // builtin_func[4] = &shell_env;
    // builtin_func[5] = &shell_unset;
    // builtin_func[6] = &shell_export;
    funcs[1] = NULL;
    return (funcs[i]);
}