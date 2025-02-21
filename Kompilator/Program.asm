	jump.i #lab0	 ;jump.i  lab0
lab0:
	read.i	8	 ; read.i x
	read.i	12	 ; read.i y
	jl.i	8,12,#lab1	 ; jl.i x,y,lab1
	mov.i	#0,16	 ; mov.i 0,t0
	jump.i	#lab2	 ; jump.i lab2
lab1:
	mov.i	#1,16	 ; mov.i 1,t0
lab2:
	je.i	16,#0,#lab3	 ; je.i t0,0,lab3
	mov.i	12,8	 ; mov.i y,x
	jump.i	#lab4	 ; jump.i lab4
lab3:
	mov.i	8,12	 ; mov.i x,y
lab4:
	write.i	12	 ; write.i y
	exit	;exit
