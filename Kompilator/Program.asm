	jump.i #lab0	 ;jump.i  lab0
lab0:
	mov.i	#1,8	 ; mov.i 1,x
	mov.i	#2,12	 ; mov.i 2,y
	je.i	8,#1,#lab1	 ; je.i x,1,lab1
	mov.i	#0,24	 ; mov.i 0,t0
	jump.i	#lab2	 ; jump.i lab2
lab1:
	mov.i	#1,24	 ; mov.i 1,t0
lab2:
	je.i	24,#0,#lab3	 ; je.i t0,0,lab3
	add.i	12,#1,28	 ; add.i y,1,t1
	inttoreal.i	28,32	 ; inttoreal.i t1,t2
	mov.r	32,16	 ; mov.r t2,z
	inttoreal.i	#2,40	 ; inttoreal.i 2,t3
	mul.r	16,40,48	 ; mul.r z,t3,t4
	mov.r	48,16	 ; mov.r t4,z
	jump.i	#lab4	 ; jump.i lab4
lab3:
	inttoreal.i	#3,56	 ; inttoreal.i 3,t5
	mov.r	56,16	 ; mov.r t5,z
lab4:
	write.r	16	 ; write.r z
	exit	;exit
