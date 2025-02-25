	jump.i #lab0	 ;jump.i  lab0
procname:
	enter.i	#8			 ; enter.i 8
	add.i	*BP+16,*BP+12,BP-8			 ; add.i a,b,t0
	mov.i	BP-8,BP-4			 ; mov.i t0,result
	write.i	BP-4			 ; write.i result
	leave				 ; leave 
	return				 ; return 
lab0:
	read.i	0			 ; read.i x
	read.i	4			 ; read.i y
	push.i	#0			 ; push.i &x
	push.i	#4			 ; push.i &y
	call.i	#procname	; call.i &procname
	incsp.i	#8			 ; incsp.i 8
	exit	;exit
