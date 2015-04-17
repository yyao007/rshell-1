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
bool quit(string);

using namespace std;

int main()
{
		char hostname[];
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
		}
		return 0;
}
