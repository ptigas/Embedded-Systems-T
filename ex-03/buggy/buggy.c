#include <stdlib.h>
#include <stdio.h>

int parse(char *arg){

  puts("Converting str arg to int");
  strtol(arg, NULL, 10);
}

int perform_div(int i, int y){
	
  return i /y;
}

void run_functionality(int i){
	
  int input;
  puts("Please give me a number!\n");
  scanf("%d", &input);

  int ans = perform_div(input, i);

  printf("The output is (We exclude decimal pts) %d", ans);
}


void main(int argc, char **argv){

  if (argc == 1){
    puts("Incorrect argument. Please provide 1 number");  
    return;
  }

  int arg = parse(argv[1]);
  run_functionality(arg);
}




