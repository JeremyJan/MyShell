/**
Jeremy Manandic
TCSS422
MyShell.c
**/

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ARGS 20
#define BUF 255

/**
@brief Fork a child to execute the command using execvp. The parent
should wait for the child to terminate
@param args Null terminated list of arguments (including program).
@return returns 1, to continue execution and 0 to terminate the MyShell
prompt.
Function code was inspired by the example textbook code in chapter 5
*/
int execute(char **args) {
	int exeExit = 1;
	int rc = fork();
	if (args[0] == NULL) {
		exeExit = 1;
	}
	if (strcmp(args[0], "exit") == 0) {
		exeExit = 0;
	} else {
		if (rc < 0) {
			fprintf(stderr, "fork failed\n");
			exit(1);
		} else if (rc == 0) {
		  execvp(args[0], args);
			printf("error executing command...\n");
			exit(1);
		 } else {
		  int wc = wait(NULL);
		 }
	}
	 return exeExit;
}

/**
@brief gets the input from the prompt and splits it into tokens.
Prepares the arguments for execvp
@return returns char** args to be used by execvp
*/
char** parse(void) {
	char lineIn[BUF];
	char *token;
	char **args = (char**) malloc(MAX_ARGS * sizeof(char));;
	int i, j;
	if (args != NULL) {

		for (j = 0; j < MAX_ARGS; j++)
		{
			args[j] = (char *) malloc(BUF * sizeof(char));
		}
	}

	printf("MyShell>");

	fgets(lineIn, BUF, stdin);
	if (lineIn[0] == '\n') {
		strcpy(args[0], " ");

	} else {
		strcpy(args[0], strtok(lineIn, " \n"));
		i = 1;
		while((token = strtok(NULL, " \n")) != NULL) {
			strcpy(args[i], token);
			i++;
		}
		if (i > 0) {
			args[i] = '\0';
		}
	}

	return args;
}

/*
@brief This function free up memory from the malloc used. (Most likely did
incorrectly but I tried)
*/
void freeMem(char **args) {
	free(args);
}

/**
@brief Main function should run infinitely until terminated manually
using CTRL+C or typing in the exit command
It should call the parse() and execute() functions
@param argc Argument count.
@param argv Argument vector.
@return status code
*/
int main(int argc, char *argv[])
{
	char **args;
	int exeExit = 1;
	while (exeExit) {
		args = parse();
		if (strcmp(args[0], " ") == 0) {
		}  else {
			exeExit = execute(args);
		}
		freeMem(args);
	}
	return EXIT_SUCCESS;
}
