jump.i #lab0	 ;jump.i  lab0
lab0:
	mov.i	#1,8	 ; mov.i 1,x
	mov.i	#2,12	 ; mov.i 2,y
	eq.i	8,#1,20	 ; eq.i x,1,t0
	mov.i	12,16	 ; mov.i y,z
	mov.i	#3,16	 ; mov.i 3,z
	je.i	20,#0,#lab2	 ; je.i t0, 0, lab2
lab1:
	jump.i	#lab3	 ; jump.i lab3
lab2:
lab3:
	write.i	16	 ; write.i z
	exit	;exit
