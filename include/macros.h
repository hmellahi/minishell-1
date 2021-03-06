
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


//define signal codes


#endif
