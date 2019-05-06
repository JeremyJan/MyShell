/**
Jeremy Manandic
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAXCHAR 255

/**
@brief Fork a child to execute the command using execvp. The parent
should wait for the child to terminate
@param args Null terminated list of arguments (including program).
@return returns 1, to continue execution and 0 to terminate the MyShell
prompt.
*/
int execute(char **args)
{
  printf("args in exe 0 = %s\n", args[0]);
  printf("args in exe 1 = %s\n", args[1]);

  printf("MYSHELL (pid:%d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("hello, I am child (pid:%d)\n", (int) getpid());
        execvp(*args, args);  // runs word count
        printf("this shouldn't print out");
    } else {
        // parent goes down this path (original process)
        int wc = wait(NULL);
        printf("hello, I am parent of %d (wc:%d) (pid:%d)\n",
	       rc, wc, (int) getpid());
    }
return 0;
}
/**
@brief gets the input from the prompt and splits it into tokens.
Prepares the arguments for execvp
@return returns char** args to be used by execvp
*/
char** parse(void)
{
  char **args;
  args = (char **) malloc(64);
  // args[0] = (char *) malloc(100);
  // args[1] = (char *) malloc(100);
  // args[2] = (char *) malloc(100);
  //
  char lineIn[MAXCHAR];
  //
  printf("MyShell>");
  //
  fgets(lineIn, MAXCHAR, stdin);
  //
  printf("This is lineIn: %s\n", lineIn);
  //
  // args[0] = strdup(strtok(lineIn, " "));
  //
  // printf("args 0 = %s\n", args[0]);
  //
  // args[1] = strdup(strtok(NULL, " "));
  //
  // printf("args 1 = %s\n", args[1]);
  //
  // args[2] = NULL;
  int i = 0;
  char *p = strtok(lineIn, " ");
  while(p) {
    args[i++] = strdup(p);
    p = strtok(NULL, " ");
  }

  args[i] = NULL;

  for (i = 0; i < 2; i++) {
    printf("%s\n", args[i]);
  }

  printf("about to return");
  return args;
}
/**
@brief Main function should run infinitely until terminated manually
using CTRL+C or typing in the exit command
It should call the parse() and execute() functions
@param argc Argument count.
@param argv Argument vector.
@return status code
*/
int main(int argc, char **argv)
{
  char **args;
  char *pArr;
  args = parse();
  printf("returned home\n");
  // printf("args in main 0 = %s\n", args[0]);
  // printf("args in main 1 = %s\n", args[1]);
  execute(args);

}
