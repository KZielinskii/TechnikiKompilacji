jump.i #lab0
lab0:
	mov.i	#1,0	 ; mov.i 1,a
	add.i	0,$t12,$t4	 ; add.i a,$t12,$t4
	mov.i	$t4,4	 ; mov.i $t4,b
	write.i	4	 ; write.i b
	exit
