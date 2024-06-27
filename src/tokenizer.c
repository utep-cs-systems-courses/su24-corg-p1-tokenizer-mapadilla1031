#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/*1.) return true a 1, if c is a whitespace char ('\t' or ' ').
  Zero terminators are not printable so return 0.
 */
int space_char(char c){
  return ((c == '\t' || c == ' ') && c != '\0');//operator precedence, && is  first 
}
/*2.) return true a 1, if c is a nonwhitespace so no tab or space,
  Zero terminators are not printable so return 0.
 */

int non_space_char(char c){
  return (c != '\t' && c !=' ' && c !='\0' );//no tab or space 
}
/*3.) return a pointer to the first character of the next space-separated token in zero terminated str. Return a zero pointer if str does not contain any tokens.
 */

char *token_start(char *str){//find start of token 
  while(space_char(*str)&&*str != '\0'){//skip whitespaces,move pointer
      str++;
  }
  return str;
}
/*4.) return a pointer terminator char following *token
 */

char *token_terminator(char *token){
  while(non_space_char(*token) && *token != '\0'){ // check not null and not a space
    token++;//move pointer
  }
  return token;
}

/*5.) counts the number of tokens in the string argument.
 */
int count_tokens(char *str){
  int count = 0;
  
  while(*str != '\0'){//while not pointing to end of string
    str = token_start(str);//call token start to get start of string 
    if(*str == '\0'){
      break;//has reached end of string
    }
    str = token_terminator(str);//call token terminator to get to end of string 
    count++;//increase count after each start and end of string "while not null"
  }
  return count;
}
/*6.) return a freshly allocated new zero terminated string containing <len> chars from <inStr>.
 */
char *copy_str(char *inStr, short len){
  char *string_copy = (char *)malloc(len + 1);//alloc mem, len+1 char and null char
  for (int i =0; i< len;i++){//loop  copy one char from instr to new string
    string_copy[i] = inStr[i];
  }
  string_copy[len] = '\0';//put null at the end 
  return string_copy;
}
/*7.) Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str){
  int num_tokens = count_tokens(str);
  char **array_tokens = (char **)malloc((num_tokens + 1) * sizeof(char *));//alloc mem, array of pointers to chars.
  char *p_start = str;//init pointers.start end of string.
  char *p_terminate;
  int i;
  for (i = 0; i < num_tokens; i++){//loop numtokens times, call start,termi to move pointers.
    p_start = token_start(p_start);
    p_terminate = token_terminator(p_start);
    if (*p_start == '\n'){//check if new line has been reached 
      p_start++;//move pointer 
      if (*p_start == '\0'){//if end of string stop
	break;
      }
    }
    array_tokens[i] = copy_str(p_start, p_terminate - p_start);//use copy_str to copy the token into the array. subtrct pterm-pstart to get lenof token.
    p_start = p_terminate;//move pstart to end of curr token
  }
  array_tokens[i] = NULL; // '\0' zero at the end
  return array_tokens;
}

/*8.) Prints all tokens. */
void print_tokens(char **tokens){
  int i = 0;
  while (tokens[i] != NULL){
    printf("tokens[%d] = \"%s\"\n",i, tokens[i]);//printing index and token from 0 to i.
    i++;
  }
  printf("tokens[%d] = %d\n", i,0);//printing the null pointer at the end. 
}

/*9.) Frees all tokens and the vector containing them. */
void free_tokens(char **tokens){
  for (int i = 0 ; tokens[i] != NULL;i++){//loop tokens in array , then free mem using free.
    free(tokens[i]);//for tokens
  }
  free(tokens);//for array
}
