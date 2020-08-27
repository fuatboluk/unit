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


static char * script(char * scr, char * arg);
static char * command(char * cmd, char * arg);
static char * usage();
static char * list();


static char * script(char * scr, char * arg)
{
    char cmd[MAXLEN];
    sprintf(cmd, "PRG=\"%s\"; NRM=\"%s\";"
                 "RED=\"%s\"; YLW=\"%s\"; WHT=\"%s\"; source %s/%s; %s", 
                 PRG, NRM, RED, YLW, WHT, SCR, scr, arg);
    system(cmd);
}


static char * command(char * cmd, char * arg)
{
    char out[MAXLEN];
    sprintf(out, "%s %s", cmd, arg);
    system(out);
}


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
    printf("\t-l | --list\tunit scripts list\n");
    printf("\n");
}


static char * list()
{
    printf("\n");
    printf("%s Unit Scripts List:%s\n", YLW, NRM);

    struct dirent * dir;
    DIR * dr = opendir(SCR);

    if (dr == NULL) {
        printf("%s Error:%s Could not open %s directory!\n", RED, NRM, SCR);
        exit(EXIT_SUCCESS);
    }

    while ((dir = readdir(dr)) != NULL) {
        if (!strcmp(dir->d_name, ".") || !strcmp(dir->d_name, "..")) {
            continue;
        } else {
            printf("\t%s\n", dir->d_name);
        }
    }

    printf("\n");
}


int main(int argc, char * argv[])
{
    if (argc < 2 || !strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")) {
        usage();
        exit(EXIT_SUCCESS);
    }

    if (argc < 2 || !strcmp(argv[1], "-l") || !strcmp(argv[1], "--list")) {
        list();
        exit(EXIT_SUCCESS);
    }

    char exists[256];
    sprintf(exists, "%s/%s", SCR, argv[1]);
    struct stat st;
        
    if (stat(exists, &st) == 0) {
        struct dirent * dir;
        DIR * dr = opendir(SCR);

        if (dr == NULL) {
            printf("%s Error:%s Could not open %s directory!\n", RED, NRM, SCR);
            exit(EXIT_SUCCESS);
        }

        while ((dir = readdir(dr)) != NULL) {
            if (!strcmp(dir->d_name, ".") || !strcmp(dir->d_name, "..")) {
                continue;
            } else {
                if (!strcmp(argv[1], dir->d_name)) {
                    char args[MAXLEN];

                    for (int i = 1; i < argc; i++) {
                        strcat(args, argv[i]);

                        if (i != argc - 1) {
                            strcat(args, " ");
                        }
                    }

                    script(argv[1], args);
                }
            }
        }

        closedir(dr);
    } else {
        char args[MAXLEN];

        for (int i = 2; i < argc; i++) {
            strcat(args, argv[i]);

            if (i != argc - 1) {
                strcat(args, " ");
            }
        }

        command(argv[1], args);
    }

    return 0;
}


// End