	jump.i		#program	|	jump.i		program
program:
	mov.i		#1,0		|	mov.i		1,a
	mov.i		#5,4		|	mov.i		5,b
	intoreal.i	#15,24		|	inttoreal.i	15,$t0
	mov.r		24,16		|	mov.r		$t0,tomek
	intoreal.i	4,32		|	inttoreal.i	b,$t1
	mul.r		32,16,40	|	mul.r		$t1,tomek,$t2
	intoreal.i	0,48		|	inttoreal.i	a,$t3
	add.r		48,40,56	|	add.r		$t3,$t2,$t4
	mov.r		56,8		|	mov.r		$t4,ala
	write.r		8		|	write.r		ala
	exit				|	exit
