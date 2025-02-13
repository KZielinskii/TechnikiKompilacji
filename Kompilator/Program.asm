	jump.i #lab0	 ;jump.i  lab0
lab0:
lab2:
	jl.i	8,#5,#lab3	 ; jl.i a,5,lab3
	mov.i	#0,12	 ; mov.i 0,t0
	jump.i	#lab4	 ; jump.i lab4
lab3:
	mov.i	#1,12	 ; mov.i 1,t0
lab4:
	je.i	12,#0,#lab1	 ; je.i t0,0,lab1
	inttoreal.i	8,16	 ; inttoreal.i a,t1
	add.i	16,#1,24	 ; add.i t1,1,t2
	mov.i	24,8	 ; mov.i t2,a
	jump.i	#lab2	 ; jump.i lab2
lab1:
	write.i	8	 ; write.i a
	exit	;exit
