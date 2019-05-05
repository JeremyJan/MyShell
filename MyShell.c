/**
MyShell.C
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

}
/**
@brief gets the input from the prompt and splits it into tokens.
Prepares the arguments for execvp
@return returns char** args to be used by execvp
*/
char** parse(void)
{
  char *args[10];
  char lineIn[MAXCHAR];
  char *token;
  char **ptrArgs;
  int i = 0;
  //get input
  printf("MyShell>");
  fgets(lineIn, MAXCHAR, stdin);
  printf("the string: %s\n", lineIn);

  args[i] = strtok(lineIn, " ");
  for (i = 1; i < 10; i++) {
    args[i] = strtok(NULL, " ");
    if(args[i] == NULL) {
      break;
    }
  }

  printf("approaching seccond while loop\n");
  for (i = 0; i < 10; i++) {
    if (args[i] == NULL) {
      break;
    }
    printf("Item %d is %s\n",i,args[i]);
  }


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



}
