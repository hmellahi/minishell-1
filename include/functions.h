
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//This header file is only for functions' prototypes

/* 
# Allowed function: #
#####################
    malloc() free() write() open() read() close() fork() wait()
    waitpid() wait3() wait4() signal() kill() exit() getcwd()
    chdir() stat() lstat() fstat() execve() dup() dup2() pipe()
    opendir() readdir() closedir() strerror() errno()
*/
void    init_shell(t_shell *shell);
void    loop(t_shell *shell);
int     gnl(int fd, char **line);

#endif