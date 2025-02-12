	jump.i #lab0	 ;jump.i  lab0
funname:
	mov.i	16,#funname	 ; mov.i a,funname


	enter.i	#0	 ; enter.i 0
lab0:
	call.i	#funname	 ; call.i funname
	exit	;exit
