#include <stdio.h>
#include <stdlib.h>
#include "../../mini-assert/mini-assert.h"
#include <pthread.h>
#define THREAD_COUNT 3

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
  
	list_t *list = malloc(sizeof(list_t));
	list->count = 0;
	list->head = NULL;

	return list;
}

/**
 *  Destroys the list, including the stored nodes.
 **/
void destroy_list(list_t *list){
  
	node_t *node = list->head;
	node_t *free_node = NULL;

	while (node) {
		free_node = node;
		node = node->next;
		free(free_node);
	}

	free(list);
}

/**
 *  Appends to the end of the list
 **/
void append_list(list_t *list, int new_val) {

  if (list) {
		
    node_t **node = &(list->head);
		
    while (*node != NULL)
    {
      node = &((*node)->next);
    }

    node_t * new_node = malloc(sizeof(node_t));
    new_node->val = new_val;
    new_node->next = NULL;
    *node = new_node;  
  
	list->count++;
  }

}

void populate(list_t *list, int max) {

	int i;
	for (i = 0; i < max; i++)
		append_list(list, i);
}

int total(list_t *list) {

	// Iterate through the list and calculate the total value.
	return 0;
}

void * get_sum(void *list_opaque){
	list_t *list = (list_t *) list_opaque;
	pthread_exit((void*) total(list));
}

void initialise_threads(list_t **lists, pthread_t *threads) {

  int i;
  for (i = 0; i < THREAD_COUNT; i++)
  { 
    if (pthread_create(&threads[i], NULL, get_sum, (void *)lists[i]))
    {
      printf("Can not create a thread\n");
      exit(1);
    }  }
}

void wait_for_threads(int *total, pthread_t *threads) {
  
  int i;
  for (i = 0; i < THREAD_COUNT; i++)
  {
    int value; 
    pthread_join(threads[i], (void **)&value);
    *total += value;
  }
}

int main(void) {

  pthread_t threads[THREAD_COUNT];
  list_t lists[THREAD_COUNT];
  
  list_t *list1 = create_list();
  populate(list1, 3);
  lists[0] = list1;

  list_t *list2 = create_list();
  populate(list2, 5);
  lists[1] = list2;

  list_t *list3 = create_list();
  populate(list3, 7);
  lists[2] = list3;
  
  pthread_t threads[THREAD_COUNT];
  list_t lists[THREAD_COUNT];
  

  int total = 0;

  // TODO for task 2

  printf("The total of all lists is %d", total);

  destroy_list(list1);
  destroy_list(list2);
  destroy_list(list3);

  return 0;
}
