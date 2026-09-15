## Assignment 3.2 ##

1. What does it mean when a function does not return a value? How do you state that in
a program? How can the function (or more precisely, the procedure) perform anything
useful?
- It is a void function, which means it does not return values but can modify the values it has access to (e.g. via pointers), so called side-effects. In the program the declaration "void" is used.
  Side effects.
2. How did you implement the side effect needed to make print_number behave correctly?
- We created a global variable called counter to count the columns.

## Assignment 3.3 ##

1. What are the main steps in the algorithm? How have you implemented these steps?
- 
2. What is the largest prime number that you can print within 2 seconds of computa
tion? What is the largest number you can print within 10 seconds? Is it the same for
print_prime.c, sieves.c, and sieves-heap.c? Why or why not?
-

## Assignment 3.4 ##

1. Explain how you get the pointer addresses to the two char arrays (text1 and text2) and
the counter variable (count) in function work().
-
2. What does it mean to increment a pointer? What is the difference between incrementing
the pointer that points to the ASCII text string, and incrementing the pointer that points
to the integer array? In what way is the assembler code and the C code different?
-
3. What is the difference between incrementing a pointer and incrementing a variable that a
pointer points to? Explain how your code is incrementing the count variable.
-
4. Explain a statement in your code where you are dereferencing a pointer. What does this
mean? Explain by comparing it with the corresponding assembler code.
-
5. Is your computer using big-endian or little-endian? How did you come to your conclusion?
Is there any benefit of using either of the two alternatives?
-

## Assignment 3.5 ##
1. Consider AM18, AM19, and AF1. Explain why gv ends up with the incremented value,
but m does not.
- gv and in are initialized to 0 and 3 respectively. Then in main, m is initialized to 0. Still in main but before they're used, gv is assigned 4 and m is assigned gv + in (or 4 + 3 = 7). Then the pointer p is assigned the address of m and m is incremented (via p) to 8. Lastly, during the call to fun(int), m is passed as param. Param is incremented by one, becoming 9 then assigned to gv. As a result, m is still 8 and gv is now 9 by the time they're printed.
2. Pointer cp is a character pointer that points to a sequence of bytes. What is the size of
the cp pointer itself?
- Pointers are sized to hold the address they point to. They can therefore vary in size depending on the system. On the DTEK board, addresses are 4 bytes and so any pointers need to be at least that large.
3. Explain how a C string is laid out in memory. Why does the character string that cp
points to have to be 9 bytes?
-
4. Which addresses have fun and main? Which sections are they located in? What kind of
memory are they stored in? What is the meaning of the data that these symbols points to?
-
5. Which addresses are variables in and gv located at?
-
6. Variables p and m are not global variables. Where are they allocated? Which memory
section is used for these variables? Why are the address numbers for p and m much larger
than for in and gv?
-
7. At print statement AM5, what is the address of pointer p, what is the value of pointer p,
and what value is pointer p pointing to?
-
8. At print statement AM7, what is the address of pointer p, what is the value of pointer p,
and what value is pointer p pointing to?
-
9. Consider AM14 to AM17. Is the RISC-V processor using big-endian or little-endian?
Why?
-
