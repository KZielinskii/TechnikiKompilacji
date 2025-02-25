	jump.i #lab0	 ;jump.i  lab0
AddInt:
	enter.i	#4			 ; enter.i 4
	add.i	*BP+16,*BP+12,BP-4			 ; add.i n1,n2,t0
	mov.i	BP-4,*BP+8			 ; mov.i t0,AddInt
	leave				 ; leave 
	return				 ; return 
MultiplyReal:
	enter.i	#8			 ; enter.i 8
	mul.r	*BP+16,*BP+12,BP-8			 ; mul.r r1,r2,t1
	mov.r	BP-8,*BP+8			 ; mov.r t1,MultiplyReal
	leave				 ; leave 
	return				 ; return 
PrintInt:
	enter.i	#0			 ; enter.i 0
	write.i	*BP+8			 ; write.i n
	leave				 ; leave 
	return				 ; return 
PrintReal:
	enter.i	#0			 ; enter.i 0
	write.r	*BP+8			 ; write.r r
	leave				 ; leave 
	return				 ; return 
lab0:
	mov.i	#10,0			 ; mov.i 10,a
	mov.i	#20,4			 ; mov.i 20,b
	push.i	#0			 ; push.i &a
	push.i	#4			 ; push.i &b
	push.i	#28			 ; push.i &t2
	call.i	#AddInt	; call.i &AddInt
	incsp.i	#12			 ; incsp.i 12
	mov.i	28,8			 ; mov.i t2,c
	push.i	#8			 ; push.i &c
	call.i	#PrintInt	; call.i &PrintInt
	incsp.i	#4			 ; incsp.i 4
	mov.r	#2.5,12			 ; mov.r 2.5,x
	mov.r	#4.0,20			 ; mov.r 4.0,y
	push.i	#12			 ; push.i &x
	push.i	#20			 ; push.i &y
	push.i	#32			 ; push.i &t3
	call.i	#MultiplyReal	; call.i &MultiplyReal
	incsp.i	#12			 ; incsp.i 12
	mov.r	32,12			 ; mov.r t3,x
	push.i	#12			 ; push.i &x
	call.i	#PrintReal	; call.i &PrintReal
	incsp.i	#4			 ; incsp.i 4
	exit	;exit
