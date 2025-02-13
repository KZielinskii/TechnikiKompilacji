	jump.i #lab0	 ;jump.i  lab0
lab0:
lab2:
	jl.r	16,#10,#lab3	 ; jl.r a,10,lab3
	mov.i	#0,24	 ; mov.i 0,t0
	jump.i	#lab4	 ; jump.i lab4
lab3:
	mov.i	#1,24	 ; mov.i 1,t0
lab4:
	je.i	24,#0,#lab1	 ; je.i t0,0,lab1
	add.r	16,#1.1,28	 ; add.r a,1.1,t1
	mov.r	28,16	 ; mov.r t1,a
	jump.i	#lab2	 ; jump.i lab2
lab1:
	write.r	16	 ; write.r a
	exit	;exit
