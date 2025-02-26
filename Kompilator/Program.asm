	jump.i #lab0	 ;jump.i  lab0
lab0:
lab1:
	jl.r	0,#10,#lab2			 ; jl.r a,10,lab2
	mov.i	#0,8			 ; mov.i 0,t0
	jump.i	#lab3			 ; jump.i lab3
lab2:
	mov.i	#1,8			 ; mov.i 1,t0
lab3:
	je.i	8,#0,#lab4			 ; je.i t0,0,lab4
	add.r	0,#1.1,12			 ; add.r a,1.1,t1
	mov.r	12,0			 ; mov.r t1,a
	jump.i	#lab1			 ; jump.i lab1
lab4:
	write.r	0			 ; write.r a
	exit	;exit
