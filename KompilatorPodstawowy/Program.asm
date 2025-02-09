jump.i #lab0	 ;jump.i  lab0
lab0:
	mov.i	#1,0	 ; mov.i 1,a
	mov.i	#5,4	 ; mov.i 5,b
	mul.i	4,#12,-1	 ; mul.i b,12,-1
	div.i	#2,#2,-1	 ; div.i 2,2,-1
	div.i	-1,#1,-1	 ; div.i -1,1,-1
	add.i	0,-1,-1	 ; add.i a,-1,-1
	mov.i	-1,8	 ; mov.i -1,result
	write.i	8	 ; write.i result
	exit	;exit
