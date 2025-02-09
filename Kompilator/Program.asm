jump.i #lab0	 ;jump.i  lab0
lab0:
	mov.i	#3,8	 ; mov.i 3,a
	mov.i	#12,12	 ; mov.i 12,b
	mov.r	#16.15,16	 ; mov.r 16.15,c
	mov.r	#4.25,24	 ; mov.r 4.25,d
	inttoreal.i	8,32	 ; inttoreal.i a,t0
	add.r	32,16,40	 ; add.r t0,c,t1
	sub.r	40,24,48	 ; sub.r t1,d,t2
	inttoreal.i	12,56	 ; inttoreal.i b,t3
	add.r	48,56,64	 ; add.r t2,t3,t4
	realtoint.r	64,72	 ; realtoint.r t4,t5
	mov.i	72,12	 ; mov.i t5,b
	write.i	12	 ; write.i b
	exit	;exit
