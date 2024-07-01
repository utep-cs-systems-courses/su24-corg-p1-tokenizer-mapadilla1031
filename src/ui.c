#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

void userInterface()
{
  char userInput;
  char userInputBuff[100];
  int idInput;
  char **tokens;
  List *list = init_history();
  puts("Welcome to Project-Tokenizer-");
  while(1){
    puts("Please type one of the following options:");
    printf(" -s- for String, -h- for History, -i- for ID history search , -x- to exit!\n");
    printf(">");
    scanf(" %c", &userInput);//get address of variable &.to store value in variable.
    while(getchar() != '\n');
    switch (userInput){
    case 's':
      puts("Please enter a string");
      fgets(userInputBuff, sizeof(userInputBuff), stdin);
      printf("Echo String: %s", userInputBuff);
      add_history(list,userInputBuff);
      tokens = tokenize(userInputBuff);
      print_tokens(tokens);
      break;
    case 'h':
      puts("History option has been selected: ");
      print_history(list);
      break;
    case 'i':
      puts("Enter Id to search: ");
      scanf(" !%d", &idInput);//skip ! character read int only. store it in idInput
      char *str = get_history(list, idInput);
      printf("%s\n", str);
      break;
    case 'x':
      puts("Program Aborted!");
      return;
    default:
      printf("Input '%c' not recognized! \n",userInput);
      break;
    }  
  }
}

int main()
{
  userInterface();//calling ui method
  return 0;
}
