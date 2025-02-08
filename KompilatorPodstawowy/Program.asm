jump.i #lab0	 ;jump.i  lab0
lab0:
	mov.i	#1,8	 ; mov.i 1,example
	add.i	8,$t20,12	 ; add.i example,$t20,b
	mov.i	12,12	 ; mov.i b,b
	write.i	12	 ; write.i b
	exit
