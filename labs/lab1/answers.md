
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
  -
- Which registers are used but not saved? Why are these not saved?
  -
- Assume the time is 16:53. Which lines of your code handle the ‘5’?
  -

### 4.4 Programming a Simple Delay ###


### 4.5  Move to the Development Board ###


### 4.6 At the Lab Session ###
