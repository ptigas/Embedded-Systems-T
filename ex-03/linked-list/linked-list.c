#include <stdio.h>
#include <stdlib.h>
#include "../../mini-assert/mini-assert.h"

typedef struct list_node{
	int val;
	struct list_node * next;
} node_t;

typedef struct{
	
	node_t *head;
	unsigned int count;
	
} list_t;


/**
 *  Creates and initialises a list.
 **/
list_t *create_list(){
  //TODO
}

/**
 *  Destroys the list, including the stored nodes.
 **/
void destroy_list(list_t *list){
  //TODO
}

/**
 *  Appends to the end of the list
 **/
void append_list(list_t *list, int new_val){
  //TODO
}

/**
 *  Removes the first node with value rem_val (if exists).
 **/
void remove_list(list_t *list, int rem_val){
  //TODO
}

/**
 *  Returns the ith value in the list
 **/
int get_ith_value(list_t *list, int i){
  //TODO
}

int main(void) {

  list_t *list = create_list();
  list.append_list(list, 5);
  list.append_list(list, 6);
  list.append_list(list, 1);
  
  assert_equal_integer(list->count, 3);
  
  list.append_list(list, 3);
  remove_list(list, 6);
  assert_equal_integer(list->count, 3);
  assert_equal_integer(get_ith_value(list, 1), 1);

  destroy_list(list);
  
  return 0;
}
