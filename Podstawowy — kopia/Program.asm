	jump.i		#program	|	jump.i		program
program:
	mov.i		#1,0		|	mov.i		1,a
	mov.i		#5,4		|	mov.i		5,b
	mul.i		4,#2,12		|	mul.i		b,2,$t0
	add.i		0,12,16		|	add.i		a,$t0,$t1
	mov.i		16,8		|	mov.i		$t1,result
	write.i		8		|	write.i		result
	exit				|	exit
