
#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "macros.h"
# include "cmds.h"
# include "errors.h"
# include "functions.h"

typedef char            t_bool;

typedef struct          s_node
{
    void                *data;
    struct s_node       *next;
}                       t_node;

typedef struct          s_btree
{
    void                *data;
    struct s_btree      *r;
    struct s_btree      *l;
}                       t_btree;

typedef struct          s_file
{
    
}                       t_file;

typedef struct          s_res
{
    t_string    output;
    int         status;
}                       t_res;

typedef struct          s_shell
{
    t_string    cmds_str[CMDS_COUNT];
    t_res       *cmds;
}                       t_shell;

#endif
