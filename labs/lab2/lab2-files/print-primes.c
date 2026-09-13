/*
 print-primes.c
 By David Broman.
 Modified by Tobias Wicklander.
 Last modified: 20126-09-13
 This file is in the public domain.
*/


#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 6

int counter = 0;

void print_number (int n);
int is_prime (int n);

void print_primes(int n){
  // Should print out all prime numbers less than 'n'
  // with the following formatting. Note that
  // the number of columns is stated in the define
  // COLUMNS
  for(int i=2; i < n; i++){
    if(is_prime(i)){
      print_number(i);
    }
  }
}

// 'argv' is an array of char pointers, where each
// 'argc' contains the number of program arguments, and
// char pointer points to a null-terminated string.
int main(int argc, char *argv[]){
  if(argc == 2)
  {
      print_primes(atoi(argv[1]));
  }
  else
    printf("Please state an integer number.\n");
  return 0;
}

void print_number (int n){
  // print new line char if COLUMNS number of numbers have been printed
  if(counter == COLUMNS){
    counter = 0;
    printf("\n");
  }

  printf("%10d ", n);
  
  counter++;
}

int is_prime(int n){
  if (n <= 1) {
    return 0; // n is not a prime number
  }  

  if (n == 2) {
    return 1; // n is a prime number
  }

  if (n % 2 == 0) {
    return 0; // if divisible by 2, n is not a prime number ("takes out" the even numbers)
  }

  for(int i = 3; i <= n/2; i = i + 2) {
    if(n % i == 0) { 
      return 0; // if divisible by any of the indivisible prime numbers, it is not a prime number
    } 
  }

  return 1; // if not, then it is a prime number
}
