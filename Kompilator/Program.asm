jump.i #lab0	 ;jump.i  lab0
lab0:
	mov.i	-1,#a	 ; mov.i -1,a
	mov.i	-1,#b	 ; mov.i -1,b
	mov.i	-1,#c	 ; mov.i -1,c
	mov.i	-1,#d	 ; mov.i -1,d
	add.r	#c,#d,#t0	 ; add.r c,d,t0
	mov.i	#t0,#d	 ; mov.i t0,d
	write.i	#d	 ; write.i d
	exit	;exit
