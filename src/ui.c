#include <stdio.h>

void userInterface()
{
  int c;
  while(1){
    printf("> ");
    while ((c = getchar()) != EOF){//read next char check EOF
      putchar(c);
      if (c == '\n'){//break loop when enter
	break;
      }
    }
    if (c== EOF){
      break;//stop first loop if EOF by user
    }
  }
}

int main()
{
  userInterface();//calling ui method
  return 0;
}
