jump.i #lab0	 ;jump.i  lab0
lab0:
	mov.i	#1,8	 ; mov.i 1,a
	mov.i	#5,12	 ; mov.i 5,b
	mul.i	12,#12,20	 ; mul.i b,12,t0
	div.i	20,#2,24	 ; div.i t0,2,t1
	div.i	24,#1,28	 ; div.i t1,1,t2
	add.i	8,28,32	 ; add.i a,t2,t3
	mov.i	32,16	 ; mov.i t3,result
	write.i	16	 ; write.i result
	exit	;exit
