
## Assignment 1 ##

- How many “seconds” in theory have passed after the start sequence developed in part (d)?
In theory, 16 seconds have passed after the completion of the start sequence.

- In the generated assembly code, in which RISC-V register will the return values from
functions get_btn and get_sw be placed? You should be able to answer this question
without debugging the generated assembly code.
The return values of these two functions will be placed in a0.

## Assignment 2 ##

- When the time-out event-flag is a “1”, how does your code reset it to “0”?
It dereferences the pointer to the TO bit and writes a 0 to it, which only occurs once the timer period has elapsed.  

- What would happen if the time-out event-flag was not reset to “0” by your code? Why?
If the time-out bit was not cleared the program would it would always be set to 1. That would in turn make the code execute as quickly as possible rather than follow the timing of the timer.

- Which device-register (or registers) must be written to define the time between time-out
events? Describe the function of that register (or of those registers).
The PeriodL and PeriodH registers of the timer are used to define the time intervals between time-out events by loading a value (the desired time for the intervals) into these registers. 

- If you press BTN1 quickly, does the time update reliably? Why, or why not? If not, would
that be easy to change? If so, how?
BTN1 is currently not updating the time as reliably as possible. That is because the value of BTN1 is only used once for every 10 time-outs and is reset/overwritten otherwise. This could quite easily be fixed by having an if-statement in the beginning that checks if BTN1 has been pressed or not. If it has been pressed, BTN1 does not overwrite until it has been used.

## Assignment 3 ##

- When the time-out event-flag is a “1”, how does your code reset it to “0”?
It dereferences the pointer to the TO bit and writes a 0 to it, which only occurs once the timer period has elapsed. 

- What would happen if the time-out event-flag was not reset to “0” by your code? Why?
If the time-out bit was not cleared the program would it would always be set to 1. That in turn stops the timer entirely since the ITO bit has been enabled, the TO being 1 sends a constant IRQ until TO has been cleared.

- From which part of the code is the function handle_interrupt called? Why is it called
from there?
It is called from the assembly file boot.S by the function for the isr_routine. The isr_routine checks if the interrupt is external and if it is, which it is in our case, it calls the external_irq which is the function that actually calls handle_interrupt. It is called from there, only after assembly has reserved the register integrity by saving all current values to the stack.

- Why are registers saved before the call to handle_interrupt?
See above.

- Which device-register (or registers), and which processor-register (or registers) must be
written to enable interrupts from the timer? Describe the functions of the relevant registers.
As for device-registers, the only new register we have to change is the ITO in the control register in order to enable interrupts. As for processor-registers we must write to the control and status register (mie and mstatus) in order to enable interrupts from the timer. The function of the CSR:s is to control local interrupts handled by a unit called CLINT, e.g. mie enables external interrupts while mstatus controls the machine status.
