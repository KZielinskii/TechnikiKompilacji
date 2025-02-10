jump.i #lab0	 ;jump.i  lab0
lab0:
	mov.i	#1,8	 ; mov.i 1,x
	mov.i	#2,12	 ; mov.i 2,y
	eq.i	8,#1,20	 ; eq.i x,1,t0
	mov.i	12,16	 ; mov.i y,z
	mov.i	#3,16	 ; mov.i 3,z
	ne.i	8,#1,24	 ; ne.i x,1,t1
	mov.i	12,16	 ; mov.i y,z
	mov.i	#3,16	 ; mov.i 3,z
	gt.i	8,#1,28	 ; gt.i x,1,t2
	mov.i	12,16	 ; mov.i y,z
	mov.i	#3,16	 ; mov.i 3,z
	lt.i	8,#1,32	 ; lt.i x,1,t3
	mov.i	12,16	 ; mov.i y,z
	mov.i	#3,16	 ; mov.i 3,z
	write.i	16	 ; write.i z
	exit	;exit
