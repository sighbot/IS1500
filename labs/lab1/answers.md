
## Assignments ##

### 4.1 Analyzing Assembly Code ###
- Which lines of code had to be changed? Why?
  - Only line 16 *had* to be changed, as the constant value determines the rate of incrementation through ASCII-characters. Changing it from 0x01 to 0x03 printed every third character instead of every character.
### 4.2  Writing Your First Assembly Language Function ###
- Your subroutine hexasc is called with an integer value as an argument in register a0 and
returns a value in register a0. If the argument is 17, what is the return value? Why?
  - If the argument is 17, the sub-routine will treat it as 1 and will thus return 17 as 1. That is because the subroutine will only use the 4 least significant bits as an input and all other higher bits are discarded. In our case, we used bit-shift to discard anything other than the 4 least significant bits. 
  
- If your solution contains a conditional-branch instruction: which input values cause the
instruction to branch to another location? This is called a taken branch.
  - Anything less than register t0, which we put as ASCII number 58, cause the instruction to branch to another location. In other words, any input value equal to or less than 9 (ASCII number 57) cause the instruction to branch.

### 4.3 Printing the Time ###
- Which registers are saved and restored by your subroutine? Why?
  - The return address (ra register) is saved by time2string because we need to store the return address to timetemplate as ra will be updated once time2string calls hexasc. After hexasc is run and we have returned to time2string, we can safely restore the return address to timetemplate by popping off the previously stored value off from the stack. 
- Which registers are used but not saved? Why are these not saved?
  - The subroutine uses a0, a1 and t1. The contents of a0 is saved temporarily into t1 for the remainder of the lifetime of time2string so a0 can be used as an argument for hexasc. We use a1 but it is never modified during time2string, thus it does need to be saved. 
- Assume the time is 16:53. Which lines of your code handle the ‘5’?
  - In time2string, lines 158-161 handle the '5' of 16:53.

### 4.4 Programming a Simple Delay ###
- If the argument value in register a0 is zero, which instructions in your subroutine are
executed? How many times each? Why?
  - If a0 is zero, none of the instructions in the delay subroutine are executed expected for the initial loadings as well as the branch jump to label done.
- Repeat the previous question for a negative number: −1.
  - Since the branch instruction is specifically less or equal to zero, the same as mentioned above will happen for negative numbers. 

### 4.5  Move to the Development Board ###
-  What is the effect of the assembler directive .global? Why is the directive particularly
important in this assignment?
  - The .global assembler directive makes labels created in one file accessible to other files, which is important in this assignment because one file calls sub-routines from others.
