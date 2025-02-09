jump.i #lab0	 ;jump.i  lab0
lab0:
	mov.i	#1,0	 ; mov.i 1,a
	mov.i	#5,4	 ; mov.i 5,b
	mul.i	4,#12,12	 ; mul.i b,12,t0
	div.i	12,#2,16	 ; div.i t0,2,t1
	div.i	16,#1,20	 ; div.i t1,1,t2
	add.i	0,20,24	 ; add.i a,t2,t3
	mov.i	24,8	 ; mov.i t3,result
	write.i	8	 ; write.i result
	exit	;exit
