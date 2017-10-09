#include  <iostream>
#include  <stdio.h>
#include  <unistd.h>
#include  <sys/types.h>
using namespace std;
/*
Note - fork works only on POSIX systems, to run fork on windows, we can use Cygwin terminal 

fork() will create a clone of the process with its new state & data i.e. changing global variables,etc won't affect each other's process.


*/
int main()
{
    fork();
    fork();
    fork();
    printf("hello\n");
    return 0;
}