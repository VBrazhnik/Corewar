.name "The Forktologist"
.comment "Pimp My Fork"

start_alive:
	live			%0
	st				r1, r5
	st				r1, -6
	fork            %:proc_2

prep:
	live			%0
	ld				%4,r1
	sub             r16, r16, r16
	zjmp            %:prep_2
	live			%0
	live			%0
	live			%0
	live			%0
	live			%0
	live			%0
	live			%0
	live			%0
	live			%0

proc_2:
	sub     r16, r16, r16
	ld		%0, r1
	zjmp            %:prep_3
	live			%0
	live			%0
	live			%0
	live			%0
	live			%0
	live			%0
	live			%0

prep_2:
	fork	%:proc_3
	ld		%190055684, r5
	ld		%190055684, r9
	ld		%190056708, r10
	ld		%10, r4
	sub		r16, r16, r16
	zjmp	%:start_tchu_tchu
	live			%0
	live			%0
	live			%0
	live			%0
	live			%0
	live			%0
	live			%0
	live			%0

prep_3:
	fork	%:ghost_writer
	ld		%84149761, r5
	ld		%151259145, r10
	st		r5, r9
	ld		%12, r4
	sub		r16, r16, r16
	zjmp	%:start_tchu_tchu
	live			%0
	live			%0
	live			%0
	live			%0
	live			%0
	live			%0
	live			%0
	live			%0

proc_3:
	ld		%0000, r7
	st		r5, r9
	ld		%29818880, r10
	aff		r1
	ld		%16, r4
	sub		r16, r16, r16
	zjmp	%:start_tchu_tchu
	live			%0
	live			%0
	live			%0
	live			%0
	live			%0
	live			%0
	live			%0
	live			%0

start_tchu_tchu:
	ld		%450, r8
	add		r16, r16, r16
	sti		r10, r8, r4
	zjmp	%455
	live			%0
	live			%0
	live			%0
	live			%0
	live			%0
	live			%0
	live			%0
	live			%0

ghost_writer:
	live	%42
	ld		%269025280, r5
	ld		%511, r4
	ld		%251823361, r15
	st		r15, 511
	ld		%42, r15
	st		r15, 503
	ld		%42992980, r15
	st		r15, 495
	ld		%269485314, r15
	st		r15, 487
	ld		%2415919105, r15
	st		r15, 479
	ld		%4211347203, r15
	st		r15, 471
	ld		%2432761856, r15
	st		r15, 463
	ld		%2753168, r15
	st		r15, 455
	ld		%4294966831, r15
	st		r15, 447
	ld		%67276816, r15
	st		r15, 439
	ld		%150994949, r15
	st		r15, 431
	ld		%201434369, r15
	st		r15, 423
	ld		%42, r15
	st		r15, 415
	ld		%43057151, r15
	st		r15, 407
	ld		%4265542658, r15
	st		r15, 399
	ld		%2416268304, r15
	st		r15, 391
	ld		%268764500, r15
	st		r15, 383
	ld		%269488137, r15
	st		r15, 375
	ld		%59375616, r15
	st		r15, 367
	sub		r16, r16, r16
	zjmp	%285
	