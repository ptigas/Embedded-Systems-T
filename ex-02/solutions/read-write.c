#include "../mini-assert/mini-assert.h"

#define DATA_SIZE 10
static int writeIndex = 0;
static int readIndex = 0;
static char data[DATA_SIZE];

void update_circular_index(int *index){
	
	if (*index == (DATA_SIZE-1)){
	  *index = 0;
	  printf("Refresh!");
	}else
	  (*index)++;
}

void write(const char *buffer, unsigned int size) {

  unsigned int i;
  for (i = 0; i <size; i++){
	
	data[writeIndex] = buffer[i];
	update_circular_index(&writeIndex);
  }  
}

void read(char *buffer, unsigned int size) {

  printf("Reading!\n");
  
  int i;
  for (i = 0; i <size; i++){
	printf("%d", readIndex);
	buffer[i] = data[readIndex];
	update_circular_index(&readIndex);
  }  
}

void run_read_write_exercise(void) {
  puts("Read/Write exercises");
  puts("------------------------------\n");

  write("Hello World!", 10);
  char buffer[8];
  read(buffer, sizeof(buffer));
  assert_equal_buffer("Hello Wo", buffer, sizeof(buffer));
  write("Goodbye", 7);
  read(buffer, sizeof(buffer));
  assert_equal_buffer("rlGoodby", buffer, sizeof(buffer));
  puts("\n");
}
