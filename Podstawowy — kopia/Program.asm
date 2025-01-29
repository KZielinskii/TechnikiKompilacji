	jump.i		#program	|	jump.i		program
program:
	mov.i		#1,0		|	mov.i		1,a
	mov.i		#5,4		|	mov.i		5,b
	div.i		0,4,12		|	div.i		a,b,$t0
	mov.i		12,8		|	mov.i		$t0,result
	write.i		8		|	write.i		result
	exit				|	exit
