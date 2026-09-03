  # hexmain.S
  # Written 2015-09-04 by F Lundevall
  # Copyright abandonded - this file is in the public domain.

	.text
	# Declare hexasc global too so it can be called from another file
	# (e.g. timetemplate.S, or the auto-grader's test harness).
	.globl hex2asc, hexasc

hex2asc:
	li	a0, 17		# test number (from 0 to 15)
	
	addi    sp,sp,-4
	sw      ra,0(sp)
	
	jal	hexasc		# call hexasc
	
	li	a7, 11	# write a0 to stdout
	ecall

	lw      ra,0(sp)
	addi    sp,sp,4
	jr      ra	

  # You can write your own code for hexasc here
  #
 hexasc:
 	slli a0, a0, 28 # bit shift to preserve only the 4 lsb.
 	srli a0, a0, 28
 	
 	addi t0, zero, 58 # ASCII-code for character after '9'
 	
 	addi a0, a0, 48 # add 58 to convert number to ASCII-code
 	
 	blt a0, t0, lessthan # If ASCII-code exceeds 57, add offset to reach ASCII-codes for letters.
 		addi a0, a0, 7
 	
 	lessthan:
 	jr ra
