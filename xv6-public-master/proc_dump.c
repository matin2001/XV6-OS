#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "param.h"
#include "x86.h"
#include "mmu.h"
#include "proc.h"

int main(int argc, char *argv[])
{

    int count = 6;
    int forks[count];
    for(int i=0; i<count;i++){
        forks[i] = fork();
        if (forks[i] == 0){
            char *myfork = malloc(sizeof(char) * i * 74853);
            memset(myfork, 65, sizeof(char) * i * 74853);
            while(1){}
            exit();
        }
    }
    sleep(100);
    proc_dump();

    // for killing zombies, we use wait()
    for(int i=0; i<count ; i++){
        kill(forks[i]);
        wait();
    }
    exit();
}
