#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/*1.) return true a 1, if c is a whitespace char ('\t' or ' ').
  Zero terminators are not printable so return 0.
 */
int space_chars(char c){
  return (c == '\t' || c == ' ' && c != '\0');
}
/*2.) return true a 1, if c is a nonwhitespace so no tab or space,
  Zero terminators are not printable so return 0.
 */

int non_space_char(char c){
  return (c != '\t' && c !=' ' && c !='\0');
}
/*3.) return a pointer to the first character of the next space-separated token in zero terminated str. Return a zero pointer if str does not contain any tokens.
 */

char *token_start(char *str){//find start of token 
  while(space_char(*str)&&*str != '\0'){//skip whitespaces,move pointer
      str++;
  }
  return str;
}
/*return a pointer terminator char following *token
 */

char *token_terminator(char *token){
  while(*token != '\0'){//check not null 
    token++;
  }
  return token;
}
/*counts the number of tokens in the string argument.
 */
int count_tokens(char *str){
  int count = 0;
  
  while(*str != '\0'){//while not pointing to end of string
    str = token_start(str);
    if(*str == '\0'){
      break;//has reached end of string
    }
    str = token_terminator(str);
    count++;
  }
  return count;
}
/*return a freshly allocated new zero terminated string containing <len> chars from <inStr>.
 */
char *copy_str(char *inStr, short len){
  char *string_copy = (char *)malloc(len + 1);
  for (int i =0; i< len;i++){
    string_copy[i] = inStr[i];
  }
  string_copy[len] = '\0';//put null at the end 
  return string_copy;
}

char **tokenize(char* str){
}

void print_tokens(char **tokens){
}

void free_tokens(char **tokens){
}
