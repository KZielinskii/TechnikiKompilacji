	jump.i #lab0	 ;jump.i  lab0
lab0:
	mov.i	#1,8	 ; mov.i 1,a
	mov.i	#0,12	 ; mov.i 0,b
	and.i	8,12,24	 ; and.i a,b,t0
	mov.i	24,16	 ; mov.i t0,c
	or.i	8,12,28	 ; or.i a,b,t1
	mov.i	28,20	 ; mov.i t1,d
	write.i	16	 ; write.i c
	write.i	20	 ; write.i d
	exit	;exit
