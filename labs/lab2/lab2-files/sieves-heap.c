/*
 Written by Lovisa Wicklander
 2026-09-14
 -----------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define COLUMNS 6
#define ARRAY_SIZE 8

int counter = 0;
char* arr = NULL;

void print_number (int n);
void print_sieves (int n);

// Printed from print-primes.c

// 'argv' is an array of char pointers, where each
// 'argc' contains the number of program arguments, and
// char pointer points to a null-terminated string.
int main(int argc, char *argv[]){
  if(argc == 2)
  {
    print_sieves(atoi(argv[1]));
    printf("\n");
  }
  else
    printf("Please state an integer number.\n");
  return 0;
}

// called by print_sieves
void print_number (int n){
  // print new line char if COLUMNS number of numbers have been printed
  if(counter == COLUMNS){
    counter = 0;
    printf("\n");
  }

  printf("%10d ", n);
  
  counter++;
}

// Assignment 3.3 Code

// implementation of the Sieves of Eratosthenes algorithm
void print_sieves (int n) {
    
    // create an array of consecutive integers from 2–n
    arr = malloc(ARRAY_SIZE + n);

    // let p = 2, starting from the smallest prime number
    int p = 2;

    for(int i = 2; i < n; i++) {
        arr[i-2] = 1;
    }

    // Loop:
    for(int j = 2; j < n; j++) {
        // 1. "Mark" the multiples of p in an array (2 to 2p to n)
        for(int i = p; i < n; i += p) {
            if(i == p) {
                continue;
            }
            arr[i-2] = 0; // multiples of p are not prime numbers; marked with 0.
        }
        // 2. Find the smallest number that is greater than p
        
        for(int y = 2; y < n; y++) {
            if(y <= p || arr[y-2] == 0) {
                continue;
            } else if (y > p && arr[y-2] == 1) {
                p = y;
                break; // b) If there is a number greater than p, let p = the new number and continue while-loop
            } 
        }
    }

    // 3. When the loop finishes, the numbers marked with 1 in the array are all primes <= n
    for(int i = 0; i < n; i++){
        if(arr[i] != 0) {
            print_number(i+2);     // Result = the same output as in 3.2
        }
    }

    free(arr);
}