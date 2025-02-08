jump.i #lab0	 ;jump.i  lab0
lab0:
	mov.i	#1,0	 ; mov.i 1,$t-1
	mov.i	#1,4	 ; mov.i 1,$t-1
	add.i	0,4,#1	 ; add.i $t-1,$t-1,1
	mov.i	0,8	 ; mov.i $t-1,$t-1
	write.i	8	 ; write.i $t-1
	exit
