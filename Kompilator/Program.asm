	jump.i #lab0	 ;jump.i  lab0
lab0:
	realtoint.r	#12.12,40	 ; realtoint.r 12.12,t0
	mov.i	40,32	 ; mov.i t0,a
	realtoint.r	#31.12,44	 ; realtoint.r 31.12,t1
	mov.i	44,36	 ; mov.i t1,b
	mov.r	#12.21,16	 ; mov.r 12.21,x
	mov.r	#42.123,24	 ; mov.r 42.123,y
	write.i	32	 ; write.i a
	write.i	36	 ; write.i b
	write.r	16	 ; write.r x
	write.r	24	 ; write.r y
	je.i	#0,#0,#lab1	 ; je.i 0,0,lab1
	mov.i	#0,48	 ; mov.i 0,t2
	jump.i	#lab2	 ; jump.i lab2
lab1:
	mov.i	#1,48	 ; mov.i 1,t2
lab2:
	mov.i	48,32	 ; mov.i t2,a
	write.i	32	 ; write.i a
	je.i	#112,#0,#lab3	 ; je.i 112,0,lab3
	mov.i	#0,52	 ; mov.i 0,t3
	jump.i	#lab4	 ; jump.i lab4
lab3:
	mov.i	#1,52	 ; mov.i 1,t3
lab4:
	mov.i	52,32	 ; mov.i t3,a
	write.i	32	 ; write.i a
	exit	;exit
