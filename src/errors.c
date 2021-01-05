/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 19:19:03 by marvin            #+#    #+#             */
/*   Updated: 2021/01/04 19:19:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void    ft_putchar_fd(int c, int fd)
{
    write(1, &c, fd);
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

void    handle_error(t_string   error)
{
   ft_putstr_fd(error, STDOUT);
   exit(0);
}