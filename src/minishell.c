
#include "minishell.h"

void throw_garbage()
{
}

int main(int argc, char **argv, char **env)
{
    t_shell shell;

    /*
    **  initialize shell variables
    ** shell structure : 
    **      cmds_str : array of string stores the name of functions
    **      cmds     : func that return a function depend on the [i] arg 
    **                ( cool right? instead of doing tons of if & else spaghetti code..)
    */

    init_shell(&shell);

    /*
    **  shell Loop u know...
    */
    loop(&shell);

    /*
    **  free  everything before exiting
    */
    throw_garbage();
    return (FALSE);
}