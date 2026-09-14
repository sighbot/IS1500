/*
 pointers.c
 By David Broman.
 Modified by Tobias Wicklander.
 Last modified: 2026-09-14
 This file is in the public domain.
*/


#include <stdio.h>
#include <stdlib.h>

#define LIST_SIZE_BYTES 80

void copycodes(char* txt1, int* lst1, int* counter);
void work();

char* text1 = "This is a string.";
char* text2 = "Yet another thing.";

int* list1 = NULL;
int* list2 = NULL;

int counter = 0;

void printlist(const int* lst){
  printf("ASCII codes and corresponding characters.\n");
  while(*lst != 0){
    printf("0x%03X '%c' ", *lst, (char)*lst);
    lst++;
  }
  printf("\n");
}

void endian_proof(const char* c){
  printf("\nEndian experiment: 0x%02x,0x%02x,0x%02x,0x%02x\n", 
         (int)*c,(int)*(c+1), (int)*(c+2), (int)*(c+3));
  
}

int main(void){
  list1 = malloc(LIST_SIZE_BYTES);
  list2 = malloc(LIST_SIZE_BYTES);
 
  work();
  printf("\nlist1: ");
  printlist(list1);
  printf("\nlist2: ");
  printlist(list2);
  printf("\nCount = %d\n", counter);

  endian_proof((char*) &counter);

  free(list1);
  free(list2);
}

void work(){
  copycodes(text1, list1, &counter);
  copycodes(text2, list2, &counter);
}

void copycodes(char* txt1, int* lst1, int* counter){
  while(1){
    char t0 = *txt1;
    if (t0 != 0){
      *lst1 = t0;

      txt1++; // moves sizeof(char) bytes in memory
      lst1++; // moves sizeof(int) bytes in memory
      
      *counter += 1; // increments counter
    }
    else {
      break;
    }
  }
}
