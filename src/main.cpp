#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <pwd.h>

//int look_args(char **);
void exec_cmd(int, char **);

#define BUFFER_LEN 1024


void exec_cmd(int argc, char** argv)
{
	pid_t pid;
	pid = fork();
	
	//in neither
	if (pid < 0)
	{
		perror("fork");
		exit(1);
	}

	else if (pid == 0) //in child
	{
		execvp(argv[0], argv);
		perror("execv");
	}
	else if(pid>0) //in parent
	{
		//int status;
		wait(NULL);
		if (wait(0) == -1)
		{
			perror("waitpid");
		}
	}
}

using namespace std;

int main()
{
	const int MAX = 50;
	int argc; //argc count
	char *argv[MAX]; //user command
	
	//login in for host
	char hostname[MAX];
	string login;
	login = getlogin();

	//error checks
	if (getlogin() == NULL)
		perror("getlogin()");

	if ((gethostname(hostname, sizeof(hostname)-1))==-1)
		perror("gethostname()");

	//start
	while (1)
	{
		cout << login << "@" << hostname << "$ "; 

		exec_cmd(argc, argv);
	}
 		return 0;
}
