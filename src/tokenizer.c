#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_chars(char c){
  return (c == '\t' || c == ' ' && c != '\0');
}

int non_space_char(char c){
  return (c != '\t' || c == ' ' && c !='\0');
}

char *token_start(char *str){
  while(space_char(*str)){
      str++;
  }
  return str;
}

char *token_terminator(char *token){
  //while()
}

int count_tokens(char *str){
  int count;
  while(non_space_char(*str)){
      str++;
      count++;
}
    return count;
}

char *copy_str(char *inStr, short len){
}

char **tokenize(char* str){
}

void print_tokens(char **tokens){
}

void free_tokens(char **tokens){
}
