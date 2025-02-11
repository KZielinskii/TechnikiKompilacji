	jump.i #lab0	 ;jump.i  lab0
lab0:
	mov.i	#1,8	 ; mov.i 1,x
	mov.i	#2,12	 ; mov.i 2,y
lab2:
	jl.i	8,#5,#lab3	 ; jl.i x,5,lab3
	mov.i	#0,16	 ; mov.i 0,t0
	jump.i	#lab4	 ; jump.i lab4
lab3:
	mov.i	#1,16	 ; mov.i 1,t0
lab4:
	je.i	16,#0,#lab1	 ; je.i t0,0,lab1
	add.i	8,#1,20	 ; add.i x,1,t1
	mov.i	20,8	 ; mov.i t1,x
	jump.i	#lab2	 ; jump.i lab2
lab1:
	write.i	12	 ; write.i y
	exit	;exit
