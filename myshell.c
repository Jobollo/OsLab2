/*
 * MyShell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2017, <GROUP MEMBERS>
 * All rights reserved.
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include "utility.h"
#include "myshell.h"
#include <errno.h>

// Put macros or constants here using #define
#define BUFFER_LEN 256

// Put global environment variables here

// Define functions declared in myshell.h here

int main(int argc, char *argv[])
{
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };
    char command[BUFFER_LEN] = { 0 };
    char arg[BUFFER_LEN] = { 0 };

    // Parse the commands provided using argc and argv

    // Perform an infinite loop getting command input from users
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
        // Perform string tokenization to get the command and argument	
	buffer[strcspn(buffer, "\n")] = '\0';
	strcat(command, buffer);
	char* token = strtok(command, " ");
        // Check the command and execute the operations for each command
        // cd command -- change the current directory
        if (strcmp(token, "cd") == 0)
        {
        	token = strtok(NULL, " ");
		char *directory = token;
		int ret;
		ret = chdir (directory);	
        }
	// clr command -- clear the screen
	else if (strcmp(token, "clr") == 0)
	{
		system("clear");
	}
	// dir command -- list contents of directory
	else if (strcmp(token, "dir") == 0)
	{
		char cwd[256];
    		if (getcwd(cwd, sizeof(cwd)) == NULL)
      			perror("getcwd() error");
    		else
      			printf("current working directory is: %s\n", cwd);
	}
	// environ command -- list environmental strings
	else if (strcmp(token, "environ") == 0)
	{
		extern char **environ;
		int i = 0;
		while(environ[i]) {
  			printf("%s\n", environ[i++]); // prints in form of "variable=value"
}
	}
	// echo command -- display user comments
	else if (strcmp(token, "echo") == 0)
	{
		token = strtok(NULL, " ");
		while( token != NULL ) {
      			printf( "%s ", token );
      			token = strtok(NULL, " ");
  		}
		printf("\n");
	}
	// help command -- display user manual
	else if (strcmp(token, "help") == 0)
	{
		int c;
		FILE *file;
		file = fopen("README.md", "r");
		if (file) 
		{
	    		while ((c = getc(file)) != EOF)
	       			putchar(c);
	    		fclose(file);
		}
	}
	// pause command -- pause operations until "Enter" is pressed
	else if (strcmp(token, "pause") == 0)
	{
		char enter = 0;
		while (enter != '\n') 
		{ 
		enter = getchar(); 
		}	
	}
        // quit command -- exit the shell
        else if (strcmp(token, "quit") == 0)
        {
            return EXIT_SUCCESS;
        }

        // Unsupported command
        else
        {
            fputs("Unsupported command, use help to display the manual\n", stderr);
        }
	memset(command, 0, sizeof command);
    }
    return EXIT_SUCCESS;
}
