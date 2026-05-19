#define _GNU_SOURCE
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char **argv) {
    int valeur_entree = atoi(argv[1]);

    if (valeur_entree == 423) {
        char *shell = strdup("/bin/sh"); 
        
        gid_t egid = getegid();
        uid_t euid = geteuid();

        setresgid(egid, egid, egid);
        setresuid(euid, euid, euid);

        char *exec_args[2];
        exec_args[0] = shell;
        exec_args[1] = NULL;

        execv(shell, exec_args);
    } 
    else {
        fwrite("No !\n", 1, 5, stderr);
    }

    return 0;
}