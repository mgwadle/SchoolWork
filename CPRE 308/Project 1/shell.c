#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "errno.h"
#include "unistd.h"
#include "sys/types.h"

int main(int argc, char **argv){
  
        char* prompt = "308sh> ";               // Pointer to Prompt
	char* backgroundCommand;                // Pointer to Background Command

	char command[1024];                       // Array to store entered commands
	char directory[1024];                         // Array to store directory name to change too
	char pwd[1024];                         // Array to store current working directory

	int status;

	int child;                              // First child process
	int child2;                             // Second child process

	int i;                                  // Variable for for loop
	int k;                                  // Variable for for loop

	int argumentCount;                       // Keeps track of the number of arguments if the command is not built-in
	int backgroundProcess = 0;              // Keeps track of whether or not the process is running in the background

	//Initial Setup Given

	if(argc != 3 && argc != 1)
	{
		printf("ERROR");
		return 0;
	}
	if(argc == 3)
	{
		if((strcmp("-p", argv[1]) != 0))
		{
			printf("ERROR");
			return 0;
		}
		else{
		        prompt = argv[2];
		}
	}

	while(1)
	{
	        // Print prompt 308sh>
		printf(prompt);

	        // Gets entered command from user
		fgets (command, 100, stdin);
        	command[strlen(command) - 1] = '\0';		

		// Built-in Commands

		if(strcmp(command, "exit") == 0)                                                             // Built-in command "exit"
		{
			return 0;
		}
		else if(strcmp(command, "pid") == 0)                                                         // Built-in command "pid"
		{
			printf("Process ID: %d\n", getpid());
		}
		else if(strcmp(command, "ppid") == 0)                                                        // Built-in command "ppid"
		{
			printf("Parent Process ID: %d\n", getppid());
		}
		else if(strncmp("cd", command, 2) == 0 && (strlen(command) == 2 || command[2] == ' '))           // Built-in command "cd"
		{
			if(strlen(command) == 2)
			{
				chdir(getenv("HOME"));
			}
			else
			{
				for(i = 0; i < strlen(command) - 3; i++)
				{
					directory[i] = command[i + 3];
					directory[i+1] = '\0';
				}
				if(chdir(directory) == -1)
				{
					printf("Cannot find directory\n");
				}
			}
		}
		else if(strcmp(command, "pwd") == 0)                                                        // Built-in command "pwd"
		{
		  getcwd(pwd, sizeof(pwd));
		  printf("%s\n", pwd);
		}		

	        // Program Commands
		
		else
		{
			argumentCount = 1;  

			for(i = 0; i < strlen(command); i++)     // Count the number of arguments entered
			{
				if (command[i] == ' ')
				{
				  argumentCount++;              // Every time there is a space meaning that end for a argument add one to numArguments
				}
			}
			if(command[strlen(command) - 1] == '&')    // Check to see if it needs to be a background process
			{
			  argumentCount--;                      // The & symbol got counted as an agrument so that needs to be taken off the numArguments
			  backgroundProcess = 1;               // Set background Process flag to 1 to represent that process is running in background
			}

			char x[argumentCount][100];
			char* args[argumentCount + 1];
			argumentCount = 0;
			k = 0;

			for(i = 0; i < strlen(command) + 1; i++)
			{
				if (command[i] == ' ' || command[i] == '\0')
				{
					x[argumentCount][k] = '\0';
					args[argumentCount] = x[argumentCount];
					argumentCount++;
					k = 0;
				}
				else if (command[i] == '&' && i == strlen(command) - 1)
				{
					i = strlen(command) + 1;
				}
				else
				{
					x[argumentCount][k] = command[i];
					k++;
				}
			}
	    
			args[argumentCount] = (char*) NULL;  // NULL pointer at the end of args[] array

			if(backgroundProcess == 1)           // Background processes 
			{
				backgroundProcess = 0;
				child2 = fork();
				if(child2 == 0)
				{
					child = fork();
					if(child == 0)
					{
						printf("[%d] %s\n", getpid(), args[0]);
						execvp(args[0], args);
						perror("\0");
						return 0;
					}
					else
					{
						status = -1;
						waitpid(-1, &status, 0);
						if(1)
						{
							printf("\n[%d] %s Exit %d\n", child, args[0], WEXITSTATUS(status));
							printf(prompt);
						}
						else
						{
							printf("[%d] %s Exit %d\n", child, args[0], WEXITSTATUS(status));
						}
						return 0;
					}
				}
				else
				{
					usleep(1000);
				}
			}
			else                                // Non-Background processes
			{
				child = fork();
				if(child == 0)
				{
					printf("[%d] %s\n", getpid(), args[0]);
					execvp(args[0], args);
					perror("\0");
					return 0;
				}
				else
				{
					usleep(1000);
					status = -1;
					waitpid(child, &status, 0);
					printf("[%d] %s Exit %d\n", child, args[0], WEXITSTATUS(status));
				}
			}
		}
	}

}
