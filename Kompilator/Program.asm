jump.i #lab0	 ;jump.i  lab0
lab0:
	mov.i	#1,8	 ; mov.i 1,x
	mov.i	#2,12	 ; mov.i 2,y
	eq.i	8,#1,20	 ; eq.i x,1,t0
	mov.i	12,16	 ; mov.i y,z
	mov.i	#3,16	 ; mov.i 3,z
	je.i	20,#1,#lab1	 ; je.i t0, 1, lab1
	mov.i	#0,12	 ; mov.i 0, $12
	jump.i	#lab2	 ; jump.i lab2
lab1:
	mov.i	#1,12	 ; mov.i 1, $12
lab2:
	je.i	12,#0,#lab3	 ; je.i 12, 0, lab3
	jump.i	#lab4	 ; jump.i lab4
lab3:
lab4:
	ne.i	8,#1,24	 ; ne.i x,1,t1
	mov.i	12,16	 ; mov.i y,z
	mov.i	#3,16	 ; mov.i 3,z
	je.i	24,#1,#lab5	 ; je.i t1, 1, lab5
	mov.i	#0,12	 ; mov.i 0, $12
	jump.i	#lab6	 ; jump.i lab6
lab5:
	mov.i	#1,12	 ; mov.i 1, $12
lab6:
	je.i	12,#0,#lab7	 ; je.i 12, 0, lab7
	jump.i	#lab8	 ; jump.i lab8
lab7:
lab8:
	gt.i	8,#1,28	 ; gt.i x,1,t2
	mov.i	12,16	 ; mov.i y,z
	mov.i	#3,16	 ; mov.i 3,z
	je.i	28,#1,#lab9	 ; je.i t2, 1, lab9
	mov.i	#0,12	 ; mov.i 0, $12
	jump.i	#lab10	 ; jump.i lab10
lab9:
	mov.i	#1,12	 ; mov.i 1, $12
lab10:
	je.i	12,#0,#lab11	 ; je.i 12, 0, lab11
	jump.i	#lab12	 ; jump.i lab12
lab11:
lab12:
	lt.i	8,#1,32	 ; lt.i x,1,t3
	mov.i	12,16	 ; mov.i y,z
	mov.i	#3,16	 ; mov.i 3,z
	je.i	32,#1,#lab13	 ; je.i t3, 1, lab13
	mov.i	#0,12	 ; mov.i 0, $12
	jump.i	#lab14	 ; jump.i lab14
lab13:
	mov.i	#1,12	 ; mov.i 1, $12
lab14:
	je.i	12,#0,#lab15	 ; je.i 12, 0, lab15
	jump.i	#lab16	 ; jump.i lab16
lab15:
lab16:
	write.i	16	 ; write.i z
	exit	;exit
