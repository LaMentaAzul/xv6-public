#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void)
{
   int fork = fork();
    if (fork != 0)
    {
        fork = fork();
        if (fork != 0)
        {   
	    //int: 4 bytes
            //32 bytes of memory block
            malloc(8 * sizeof(int));
        }
        else
        {
	    //40 bytes of memory block
            malloc(10 * sizeof(int));
        }
        wait();
    }
    else
    {
        fork = fork();
        if (fork != 0)
        {
	    //60 bytes of memory block
            malloc(15 * sizeof(int));
            wait();
        }
        else
        {   
            //20 bytes of memory block
            malloc(5 * sizeof(int)); 

            int maxProcess = 64;
            struct proc_info *processes = malloc( maxProcess * sizeof(struct proc_info));

            int Number = getprocess(maxProcess, processes);
            for (int i = 0; i < Number; i++)
            {
                printf(processes[i].pid, processes[i].memsize);
            }
        }
    }

    wait();
    exit();
}
