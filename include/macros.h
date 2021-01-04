
#ifndef MACROS_H
# define MACROS_H

# define PROGRAM_NAME "minishell"

//Macrofication
# define FALSE              0
# define TRUE               1
# define NOT                !
# define AND                &&
# define OR                 ||
# define ELIF               else if
# define FAIL               0
# define UNCOMPLETED        1
# define STDIN              0
# define STDOUT             1
# define DEBUG_MODE         1
# define STATUS             1
# define OUTPUT             0
# define CMDS_COUNT         7
# define DIGITS         "0123456789"
# define ASCII_LOWER    "abcdefghijklmnopqrstuvwxyz"
# define ASCII_UPPER    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# define PUNCTS         "!\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~"
# define WHITESPACES    " \t\n\r\x0b\x0c"
# define SPACE          ' '
# define SINGLE_QT      '\''
# define DOUBLE_QT      '"'
# define BACK_SLASH     '\\'

//Max file descriptors that can be opened simultaneously
# ifndef OPEN_MAX
#  define OPEN_MAX 4096
# endif

//Use safe_malloc()
# define MALLOC(ptr)        (ptr) = malloc(sizeof(*(ptr) ))
# define ARRLLOC(p, l)      (p) = malloc(sizeof(*(p) ) * l)

typedef char* t_string;
//define signal codes


#endif
