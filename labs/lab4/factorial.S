
# initial set-up before algorithm
addi t0, zero, 8
addi t0, t0, 1  #increment t0 by one for later comparison
addi t2, zero, 1
addi sp, zero, 1

# main loop
main_loop:
	beq sp, t0, stop # if counter equals n+1, then jump to infinite loop

	addi gp, sp, -1 # initializing how many times it increments
	add t1, t2, zero # remember value to add
	
	addi sp, sp, 1 # increment counter
	
	add_loop:
		beq gp, zero, main_loop # once counter is zero jump back to main loop
		add t2, t2, t1 # increment result by stored value
		addi gp, gp,-1 # decrement counter
		beq zero, zero, add_loop # continue looping until condition in the other branch is met

stop:
	beq zero, zero, stop # infinite loop