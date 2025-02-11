	jump.i #lab0	 ;jump.i  lab0
lab0:
	sub.i	#0,#1,16	 ; sub.i 0,1,t0
	mov.i	16,8	 ; mov.i t0,x
	mov.i	#1,12	 ; mov.i 1,y
	write.i	8	 ; write.i x
	exit	;exit
