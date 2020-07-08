#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    int pid;
    int childpid, wtime , rtime;

    pid = fork();

    if (pid < 0)
    {
        printf(1, "failed\n");
        exit();
    }

    if (pid == 0)
    {
	exec(argv[1], argv);
        printf(1, "child created %d\n", getpid(), argv[1]);
    }

    else
    {
        for (int i = 0; i < 1000; i++) //delay for waiting for child
        {
            printf(1, "%d\n", i);
        }
        childpid = waitx(&wtime, &rtime);

        printf(1, "\n wait time : %d , RunTime : %d childpid : %d\n", wtime, rtime , childpid);
    }
    exit();
} 
