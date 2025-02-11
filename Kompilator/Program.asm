	jump.i #lab0	 ;jump.i  lab0
lab0:
	mov.i	#1,8	 ; mov.i 1,x
	je.i	8,#0,#lab1	 ; je.i x,0,lab1
	mov.i	#0,16	 ; mov.i 0,t0
	jump.i	#lab2	 ; jump.i lab2
lab1:
	mov.i	#1,16	 ; mov.i 1,t0
lab2:
	mov.i	16,12	 ; mov.i t0,y
	write.i	12	 ; write.i y
	exit	;exit
