//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <cstring>
#include <iostream>
using namespace std;
bool checkIfValid(string c, int numArg, int &N);
void forkThree(int N);

int main(int argc, char* argv[])
{
	int N;

	if(argc < 2){cout<<"Please enter a parameter\n"; return 0;}

	string c = argv[1];
	
	if(!checkIfValid(c, argc, N))
		{return 0;}

	
	cout<< N<< "\n";
	forkThree(N);
	 
	return 0;
}

void forkThree(int N)
{
	int pid, pid1, pid2;


	//value retured from fork() system call
	//creates 1 parent and 1 child
	pid = fork();

	//if fork() == 0 then it is a child process
	//first child
	if(pid == 0)
	{
		for(int x = 0; x <N; x++)
		{
			cout<<"This is child process 1, my PID is: "<< getpid()<< " My Parents PID is: "<< getppid()<< "\n";
			sleep(2);
		}
	}
	else//if its not the first child then its the parent
	{
		//creates another child
		//second child
		pid1 = fork();
		if(pid1 == 0)
		{
			for(int x = 0; x <N; x++)
			{
				cout<<"This is child process 2, my PID is: "<< getpid()<< " My Parents PID is: "<< getppid()<< "\n";
				sleep(2);
			}
		}
		else //if its not the second child then it is the parent
		{
			//creates another child
			//third child
			pid2 = fork();
			if(pid2 == 0)
			{
				for(int x = 0; x <N; x++)
				{
					cout<<"This is child process 3, my PID is: "<< getpid()<< " My Parents PID is: "<< getppid()<< "\n";
					sleep(2);
				}	
			}
			else//if it is not the third child then it is the parent
			{
				for(int x = 0; x <N; x++)
				{
					cout<<"This is the main process, my PID is: "<< getpid() <<"\n";
					sleep(2);					
				}

			}
		}

	}

}

bool checkIfValid(string c, int numArg, int &N)
{
	for(int x = 0; x < c.length();x++ )
	{
		if(!isdigit(c[x]))
		{
			cout<<"Please enter a number as the parameter \n Parameter: "<< c << "\n";
			return false;
		}
	}
	
    if(numArg>2 || numArg < 2)
	{
		cout<<"Please only enter one parameter\n";
		return false;
	}
	N = stoi(c);
	return true;

}
