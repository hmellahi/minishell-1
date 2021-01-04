/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:56:35 by marvin            #+#    #+#             */
/*   Updated: 2021/01/04 17:56:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void    init_shell(t_shell *shell)
{
    shell = malloc(sizeof(t_shell));
    shell->cmds_str = init_cmds_str();
    shell->cmds = &cmds;
}