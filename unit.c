// Author: Fuat Bölük <mektup@fuatboluk.com.tr>


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>


#define MAXLEN 32768


#define PRG "unit"
#define NRM "\x1b[0m"
#define RED "\x1b[1;31m"
#define YLW "\x1b[1;33m"
#define WHT "\x1b[1;97m"
#define SCR "/scripts"


static char * usage();
static char * list(char * name);
static char * command(char * cmd, char * arg);
static char * script_help(char * dir,char * scr);
static char * script(char * dir, char * scr, char * arg);


static char * usage()
{
    printf("\n");
    printf("The unit is a unifying command line interface that runs all executable\n");
    printf("programs attached to the path on the operating system and user-added scripts\n");
    printf("under a single command, based on user permissions.\n");
    printf("\n");
    printf("By running all the shell files added to the /scripts directory with their arguments\n");
    printf("as if they were included in the same program, it allows you to make the program more\n");
    printf("functional and group many properties.\n");
    printf("\n");
    printf("%s Built-in Scripts Variables:%s\n", YLW, NRM);
    printf("\t$PRG\t\tprogram name (unit)\n");
    printf("\t$RED\t\tred color for %serror%s message\n", RED, NRM);
    printf("\t$YLW\t\tyellow color for %swarning%s message\n", YLW, NRM);
    printf("\t$WHT\t\twhite color for %sbold%s text message\n", WHT, NRM);
    printf("\t$NRM\t\tnormal color to finalize color definitions\n");
    printf("\n");
    printf("%s Options:%s\n", YLW, NRM);
    printf("\t-h | --help\tshow this help message\n");
    printf("\t-l | --list\tunit script list with unit list or <unit_name>\n");
    printf("\n");
}


static char * list(char * name)
{
    struct stat st;
    struct dirent * dir;
    
    if (!strcmp(name, "#"))
    {
        DIR * dr = opendir(SCR);

        if (dr == NULL)
        {
            printf("%s Error:%s Could not open %s directory!\n", RED, NRM, SCR);
            closedir(dr);
            exit(EXIT_SUCCESS);
        }

        printf("\n");
        printf("%s Unit List:%s\n", YLW, NRM);
        
        while ((dir = readdir(dr)) != NULL)
        {
            if (!strcmp(dir->d_name, ".") || !strcmp(dir->d_name, ".."))
            {
                continue;
            }
            else
            {
                char exists[256];
                sprintf(exists, "%s/%s", SCR, dir->d_name);

                stat(exists, &st);
                
                if (S_ISDIR(st.st_mode) == 1)
                {
                    printf("\t%s\n", dir->d_name);
                }
            }
        }
        
        printf("\n");
        closedir(dr);
    }
    else
    {
        char exists[256];
        sprintf(exists, "%s/%s", SCR, name);
        
        DIR * dr = opendir(exists);

        if (dr == NULL)
        {
            printf("%s Error:%s Could not open %s directory!\n", RED, NRM, exists);
            closedir(dr);
            exit(EXIT_SUCCESS);
        }

        printf("\n");
        printf("%s Unit Script List:%s\n", YLW, NRM);
        
        while ((dir = readdir(dr)) != NULL)
        {
            if (!strcmp(dir->d_name, ".") || !strcmp(dir->d_name, "..") || !strcmp(dir->d_name, "_help"))
            {
                continue;
            }
            else
            {
                stat(exists, &st);
                
                if (S_ISDIR(st.st_mode) == 1)
                {
                    printf("\t%s\n", dir->d_name);
                }
            }
        }

        printf("\n");
        closedir(dr);
    }
}


static char * command(char * cmd, char * arg)
{
    char out[MAXLEN];
    sprintf(out, "%s %s", cmd, arg);
    system(out);
}


static char * script_help(char * dir, char * scr)
{
    char cmd[MAXLEN];
    sprintf(cmd, "PRG=\"%s\"; NRM=\"%s\";"
                 "RED=\"%s\"; YLW=\"%s\"; WHT=\"%s\"; source %s/%s/_%s; _help", 
                 PRG, NRM, RED, YLW, WHT, SCR, dir, scr);
    system(cmd);
}


static char * script(char * dir, char * scr, char * arg)
{
    char cmd[MAXLEN];
    sprintf(cmd, "PRG=\"%s\"; NRM=\"%s\";"
                 "RED=\"%s\"; YLW=\"%s\"; WHT=\"%s\"; source %s/%s/%s; %s", 
                 PRG, NRM, RED, YLW, WHT, SCR, dir, scr, arg);
    system(cmd);
}


int main(int argc, char * argv[])
{
    if (argc < 2 || !strcmp(argv[1], "-h") || !strcmp(argv[1], "--help"))
    {
        usage();
        exit(EXIT_SUCCESS);
    }

    if (argc < 2 || !strcmp(argv[1], "-l") || !strcmp(argv[1], "--list"))
    {
        if (argv[2] == NULL)
        {
            list("#");
            exit(EXIT_SUCCESS);
        }
        else
        {
            list(argv[2]);
            exit(EXIT_SUCCESS);
        }
    }

    if (argc < 3 || !strcmp(argv[2], "help") || argv[2] == NULL)
    {
        script_help(argv[1], "help");
        exit(EXIT_SUCCESS);
    }

    if (argv[2] != NULL || argv[2] != "help")
    {
        struct stat st;
        struct dirent * dir;

        char exists[256];
        sprintf(exists, "%s/%s", SCR, argv[1]);

        DIR * dr = opendir(exists);

        if (dr == NULL)
        {
            printf("%s Error:%s Could not open %s directory!\n", RED, NRM, exists);
            exit(EXIT_SUCCESS);
        }

        while ((dir = readdir(dr)) != NULL)
        {
            if (!strcmp(dir->d_name, ".") || !strcmp(dir->d_name, "..") || !strcmp(dir->d_name, "_help"))
            {
                continue;
            }
            else
            {
                stat(exists, &st);
                
                if (S_ISDIR(st.st_mode) == 1)
                {
                    if (!strcmp(argv[2], dir->d_name))
                    {
                        char args[MAXLEN];

                        for (int i = 2; i < argc; i++)
                        {
                            strcat(args, argv[i]);

                            if (i != argc - 1)
                            {
                                strcat(args, " ");
                            }
                        }

                        script(argv[1], argv[2], args);
                    }
                }
            }
        }

        closedir(dr);
    }
    else
    {
        char args[MAXLEN];

        for (int i = 2; i < argc; i++)
        {
            strcat(args, argv[i]);

            if (i != argc - 1)
            {
                strcat(args, " ");
            }
        }

        command(argv[1], args);
    }

    return 0;
}


// End