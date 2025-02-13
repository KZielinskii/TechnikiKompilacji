	jump.i #lab0	 ;jump.i  lab0
funname:
	mov.i	*BP+16,#funname	 ; mov.i a,funname
	mov.i	*BP+16,*BP+12	 ; mov.i a,b
	mov.i	*BP+16,BP+16	 ; mov.i a,lo
	enter.i	#0	 ; enter.i 0
	leave		 ; leave 
	return		 ; return 
lab0:
	read.i	8	 ; read.i x
	read.i	12	 ; read.i y
	push.i	#8	 ; push.i &x
	mov.i	#12,20	 ; mov.i 12,t0
	push.i	#20	 ; push.i &t0
	push.i	#24	 ; push.i &t1
	call.i	#funname	 ; call.i &funname
	incsp.i	#12	 ; incsp.i 12
	mov.i	24,12	 ; mov.i t1,y
	write.i	12	 ; write.i y
	exit	;exit
