#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

void userInterface()
{
  char userInput;
  char buf[100];
  puts("Welcome to Project-Tokenizer-");
  while(1){
    puts("Please type one of the following options:");
    printf(" -s- for String, -h- for History, -x- to exit!\n");
    printf(">");
    scanf(" %c", &userInput);
    while(getchar() != '\n');

    switch (userInput){
    case 's':
      puts("Please enter a string");
      if(fgets(buf, sizeof(buf), stdin)){
	printf("Echo String: &s", buf);
      }
      break;
    case 'h':
      puts("History option has been selected: ");
      break;
    case 'x':
      puts("Program Aborted!");
      return;
    default:
      printf("Input '%c', not recognized! \n");
      break;
    }
  
  }
}

int main()
{
  userInterface();//calling ui method
  return 0;
}
