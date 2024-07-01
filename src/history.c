#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

/*Initialize the linked list to keep the history. */
List* init_history(){
  List* list = (List*) malloc(sizeof(List));//allocating mem for hist list.
  list ->root = NULL;//init root node as null
  return list;
}

/*Add a history item to the end of the list.
  List* list - the linked list.
  char* str - the string to store.
*/
void add_history(List *list, char *str ){
  static int id = 1;//start with 1,increment after call.
  Item* itemNode= (Item*) malloc (sizeof(Item));

  int len = 0;//getting length of str for copy_str method. 
  while (str[len] != '\0') {
    len++;
  }
  
  itemNode -> id = id++;
  itemNode -> str = copy_str(str,len);//make copy so one in linked list stays the same
  itemNode -> next = NULL;

  if (list -> root == NULL){
    list -> root = itemNode;//add item at root. 
  }else{
    Item* temp = list -> root;//if root not null traverse to last item in list
    while (temp -> next != NULL){
      temp = temp -> next;
    }
    temp -> next = itemNode;//add itemNode to end of list
  }
}

/*Retrieve the string stored in the node where Item -> id == id.
  List* list - the linked list.
  int id - the id of the Item to find. */
char *get_history(List *list, int id ){
  Item* temp = list -> root;
  while(temp != NULL){
    if (temp->id == id){//look for match in ID.
      return temp -> str;//if found return the str
    }
    temp = temp ->next;
  }
  return NULL;//not found
}

/*Print the entire contents of the list. */
void print_history(List *list ){
  Item* temp = list -> root;
  while (temp != NULL){
    printf("ID: %d, %s\n",temp ->id, temp->str);
    temp = temp->next;//move to next node until while != NULL
  }
}

/*Free the history list and the string it references. */
void free_history(List *list){//free each str,item in list. use free to free list
  Item* temp = list -> root;
  while(temp != NULL){
    Item* next = temp -> next;
    free(temp->str);
    free(temp);
    temp = next;
  }
  free(list);
}
