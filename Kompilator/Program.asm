	jump.i #lab0	 ;jump.i  lab0
lab0:
	read.i	8	 ; read.i x
	read.i	12	 ; read.i y
	mov.r	#1.5,24	 ; mov.r 1.5,h
	inttoreal.i	12,32	 ; inttoreal.i y,t0
	mul.r	32,24,40	 ; mul.r t0,h,t1
	inttoreal.i	8,48	 ; inttoreal.i x,t2
	add.r	48,40,56	 ; add.r t2,t1,t3
	mov.r	56,16	 ; mov.r t3,g
	write.r	16	 ; write.r g
	exit	;exit
