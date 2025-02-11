	jump.i #lab0	 ;jump.i  lab0
lab0:
	mov.i	#1,8	 ; mov.i 1,x
	mov.i	#2,12	 ; mov.i 2,y
	je.i	8,#1,#lab1	 ; je.i x,1,lab1
	mov.i	#0,20	 ; mov.i 0,t0
	jump.i	#lab2	 ; jump.i lab2
lab1:
	mov.i	#1,20	 ; mov.i 1,t0
lab2:
	je.i	20,#0,#lab3	 ; je.i t0,0,lab3
	mov.i	12,16	 ; mov.i y,z
	jump.i	#lab4	 ; jump.i lab4
lab3:
	mov.i	#3,16	 ; mov.i 3,z
lab4:
	write.i	16	 ; write.i z
	exit	;exit
