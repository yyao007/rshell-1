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

int look_args(char **);
void exec_cmd(int, char **);
bool terminate(string);


int look_args(char **)
{


}

void exec_cmd(int, char**)
{
	pid_t pid;
	pid = fork();

	if (pid < 0)
	{
		perror("pid");
	}
	else if (pid == 0)
	{
		execvp(argv, argv)
		perror("execv");
	}
	else
	{
		waitpid(NULL);
	}

}

bool terminate(string cmd)
{
	for (int i = 0; i < cmd.length(); i++)
	{
		cmd[i] = tolower(cmd[i]);
	}
}

using namespace std;

int main()
{
	const int MAX[50];
	char *argv[MAX]
	int argc;
	

	char hostname[MAX];
	string login;

	login = getlogin();

	if (getlogion() == NULL)
	{

		perror("getlogin()");
	}

	if ((gethostname(hostname, sizeof(hostname)-1))==-1)
	{
		perror("gethostname()");
	}

	while (1)
	{
		cout << login << "@" << hostname << "$ ";
		argc = look_args(argv);
		exec_cmd(argc, argv);

		for (int i = 0; i < argc; i++)
		{
			argv[i] = NULL;
		}
	}
		return 0;
}
