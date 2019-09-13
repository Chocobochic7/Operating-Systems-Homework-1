//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include <sys/wait.h>
using namespace std;
bool checkIfValid(int numArg);
void forkThree(string txtFile);

int main(int argc, char* argv[])
{
	if(argc < 2){cout<<"Please enter a parameter\n"; return 0;}
	string c = argv[1];
	
	if(!checkIfValid(argc))
		{return 0;}

	
	
	forkThree(c);
	//cout<<"testing\n";
	 
	return 0;

}

void forkThree(string txtFile)
{
	int pid, pid1, pid2;


	//value retured from fork() system call
	//creates 1 parent and 1 child
	pid = fork();

	//if fork() == 0 then it is a child process
	//first child
	if(pid == 0)
	{
		
			cout<<"Displaying file '" << txtFile <<  "' \n";
			
			execl("/bin/more", "more " , "testing.txt", (char*) NULL); exit(0);
			//sleep(2);
		
	}
	else//if its not the first child then its the parent
	{
		//creates another child
		//second child
		pid1 = fork();
		if(pid1 == 0)
		{
			
				cout<<"Showing processes..." << "\n";
				execl("/bin/ps", "ps -ef", (char *) NULL); exit(0);
				//sleep(2);
			
		}
		else //if its not the second child then it is the parent
		{
			//creates another child
			//third child
			pid2 = fork();
			if(pid2 == 0)
			{
				
					cout<<"showing current Directory..."<< "\n";
					execl("/ls", "ls -l", (char*) NULL); exit(0);
					//sleep(2);
					
			}
			else//if it is not the third child then it is the parent
			{
				
					cout<<"This is the main process, my PID is: "<< getpid() <<"\n";
					//sleep(2);	
					wait(NULL);
					wait(NULL);
					wait(NULL);

					cout<<"The main process terminates.";
					//exit(0);			
				

			}
		}

	}

}

bool checkIfValid(int numArg)
{
	if(numArg>2 || numArg < 1)
	{
		cout<<"Please only enter one parameter\n";
		return false;
	}
	return true;

}