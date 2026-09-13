/*
 prime.c
 By David Broman.

 Modified by Lovisa Wicklander

 Last modified: 2026-09-13
 This file is in the public domain.
*/


#include <stdio.h>

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
int main(void){
  printf("%d\n", is_prime(11)); // 11 is a prime.     Should print 1.
  printf("%d\n", is_prime(383)); // 383 is a prime.     Should print 1.
  printf("%d\n", is_prime(987)); // 987 is not a prime. Should print 0.
}
