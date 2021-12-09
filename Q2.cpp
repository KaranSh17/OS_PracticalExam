#include <stdio.h>
#include <sys/types.h>
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int main()
{
    pid_t pid;
	/* fork a child process */
	pid = fork();
    if (pid < 0)
    {
		/* error occurred */
		cout<<stderr<< "Fork Failed"<<endl;
        return 1;
    }
    else if (pid == 0)
    {
		/* child process */
		execlp("/bin/ls","ls",NULL);
    }
    else
    {
		/* parent process */
		/* parent will wait for the child to complete */
		wait(NULL);
        cout<<"Parent Complete";
    } 
    return 0;
}
