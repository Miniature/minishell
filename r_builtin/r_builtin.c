#include "r_builtin.h"

void builtin_cd(char *path)
{
    if (path == NULL)
	{ // if no argument is given
        path = getenv("HOME"); // use the HOME environment variable as the default path
    }
    if (!strcmp(path, "-"))
	{ // if the argument is -
        path = getenv("OLDPWD"); // use the OLDPWD environment variable as the path
        printf("%s\n", path); // print the path
    }
    if (chdir(path) != 0)
	{ // change the directory and check for errors
        perror("cd"); // print an error message
    }
}