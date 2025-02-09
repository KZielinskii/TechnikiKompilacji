jump.i #lab0	 ;jump.i  lab0
lab0:
	mov.i	#3,8	 ; mov.i 3,a
	mov.i	#12,12	 ; mov.i 12,b
	mov.r	#16.15,16	 ; mov.r 16.15,c
	mov.r	#4.25,24	 ; mov.r 4.25,d
	add.i	8,12,32	 ; add.i a,b,t0
	mov.i	32,8	 ; mov.i t0,a
	add.r	16,24,36	 ; add.r c,d,t1
	mov.r	36,16	 ; mov.r t1,c
	add.r	8,16,44	 ; add.r a,c,t2
	mov.i	44,12	 ; mov.i t2,b
	write.i	8	 ; write.i a
	write.i	12	 ; write.i b
	write.r	16	 ; write.r c
	exit	;exit
