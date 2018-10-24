#include "main.h"

int main(void)
{
    int namespaces = CLONE_NEWUTS | CLONE_NEWPID | CLONE_NEWIPC | CLONE_NEWNS | CLONE_NEWNET;
    pid_t container;

    container = clone(child, malloc(4096) + 4096, SIGCHLD | namespaces, NULL);
    if (container == -1) {
        perror("clone");
        exit(1);
    }
    waitpid(container, NULL, 0);
    return 0;
}

int create_container(void)
{
    char *cmd[] = { "/bin/bash", NULL };

    chroot("/home/rootfs");
    chdir("/");
    mount("proc", "proc", "proc", 0, "");
    execv("/bin/bash", cmd);
    perror("exec");
    exit(EXIT_FAILURE);
}

int child(void *args)
{
    (void)args;
    create_container();
    return (0);
}