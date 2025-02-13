	jump.i #lab0	 ;jump.i  lab0
funname:
	enter.i	#28	 ; enter.i 28
	add.i	*BP+16,#1,BP-12	 ; add.i a,1,t0
	mov.i	BP-12,BP-8	 ; mov.i t0,la
	jg.i	*BP+16,#5,#lab1	 ; jg.i a,5,lab1
	mov.i	#0,BP-16	 ; mov.i 0,t1
	jump.i	#lab2	 ; jump.i lab2
lab1:
	mov.i	#1,BP-16	 ; mov.i 1,t1
lab2:
	je.i	BP-16,#0,#lab3	 ; je.i t1,0,lab3
	mov.i	#2,*BP+12	 ; mov.i 2,b
	jump.i	#lab4	 ; jump.i lab4
lab3:
	add.i	*BP+16,#2,BP-20	 ; add.i a,2,t2
	add.i	*BP+12,#2,BP-24	 ; add.i b,2,t3
	push.i	#BP-20	 ; push.i &t2
	push.i	#BP-24	 ; push.i &t3
	push.i	#BP-28	 ; push.i &t4
	call.i	#funname	 ; call.i &funname
	incsp.i	#12	 ; incsp.i 12
	mov.i	BP-28,BP-8	 ; mov.i t4,la
lab4:
	mov.i	BP-8,#funname	 ; mov.i la,funname
	leave		 ; leave 
	return		 ; return 
lab0:
	read.i	8	 ; read.i x
	read.i	12	 ; read.i y
	push.i	#8	 ; push.i &x
	realtoint.r	#12,20	 ; realtoint.r 12,t6
	mov.i	20,16	 ; mov.i t6,t5
	push.i	#16	 ; push.i &t5
	push.i	#24	 ; push.i &t7
	call.i	#funname	 ; call.i &funname
	incsp.i	#12	 ; incsp.i 12
	mov.i	24,12	 ; mov.i t7,y
	write.i	12	 ; write.i y
	exit	;exit
