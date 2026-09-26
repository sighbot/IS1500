
## Assignment 1 ##

- How many “seconds” in theory have passed after the start sequence developed in part (d)?
- In the generated assembly code, in which RISC-V register will the return values from
functions get_btn and get_sw be placed? You should be able to answer this question
without debugging the generated assembly code.

## Assignment 2 ##

- When the time-out event-flag is a “1”, how does your code reset it to “0”?
- What would happen if the time-out event-flag was not reset to “0” by your code? Why?
- Which device-register (or registers) must be written to define the time between time-out
events? Describe the function of that register (or of those registers).
- If you press BTN1 quickly, does the time update reliably? Why, or why not? If not, would
that be easy to change? If so, how?

## Assignment 3 ##

- When the time-out event-flag is a “1”, how does your code reset it to “0”?
- What would happen if the time-out event-flag was not reset to “0” by your code? Why?
- From which part of the code is the function handle_interrupt called? Why is it called
from there?
- Why are registers saved before the call to handle_interrupt?
- Which device-register (or registers), and which processor-register (or registers) must be
written to enable interrupts from the timer? Describe the functions of the relevant regis
ters.
