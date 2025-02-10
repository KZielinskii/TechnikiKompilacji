jump.i #lab0	 ;jump.i  lab0
lab0:
	mov.i	#1,8	 ; mov.i 1,x
	mov.i	#2,12	 ; mov.i 2,y
	je.i	8,#1,#lab1	 ; je.i x,1,lab1
	mov.i	12,16	 ; mov.i y,z
	mov.i	#3,16	 ; mov.i 3,z
	write.i	16	 ; write.i z
	exit	;exit
