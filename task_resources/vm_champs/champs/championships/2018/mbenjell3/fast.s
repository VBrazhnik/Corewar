## Champion 1

.name "Fast"
.comment "Training championship"

live:
	live %0
	st r1, -4


load_1:

	# chargement de bouts d'instructions dans les registres
	ld		%57672193, r2
	ld		%4278415363, r3
	ld		%33424240, r4 
	ld		%67239171, r5 
	ld		%1879376380, r6 
	ld		%57673217, r7 
	ld		%4211306503, r8 
	ld		%33162096, r9
	ld		%134347011, r10
	ld		%1879638520, r11
	ld		%57674241, r12
	ld		%4144197643, r13
	ld		%32899952, r14 	
	ld		%590124, r15 # copy zjmp

live:
	live %0
	live %0
	st r1, -14
	st r1, -14

write_1a:

	######################################## LIGNE 1

	st		r2, 468

	st		r3, 467

	st		r4, 466
	st		r5, 465

	st		r6, 464
	st		r7, 463

	st		r8, 462
	st		r9, 461

	st		r10, 460
	st		r11, 459

	st		r12, 458
	st		r13, 457

	st		r14, 456

		######################################## LIGNE 2
	st		r2, 468

	st		r3, 467

	st		r4, 466
	st		r5, 465

	st		r6, 464
	st		r7, 463

	st		r8, 462
	st		r9, 461

	st		r10, 460
	st		r11, 459

	st		r12, 458
	st		r13, 457

	st		r14, 456

	######################################## LIGNE 3

	st		r2, 468

	st		r3, 467

	st		r4, 466
	st		r5, 465

	st		r6, 464
	st		r7, 463

	st		r8, 462
	st		r9, 461

	st		r10, 460
	st		r11, 459

	st		r12, 458
	st		r13, 457

	st		r14, 456


		######################################## LIGNE 4

	st		r2, 468

	st		r3, 467

	st		r4, 466
	st		r5, 465

	st		r6, 464
	st		r7, 463

	st		r8, 462
	st		r9, 461

	st		r10, 460
	st		r11, 459

	st		r12, 458
	st		r13, 457

	st		r14, 456


		######################################## LIGNE 5

	st		r2, 468

	st		r3, 467

	st		r4, 466
	st		r5, 465

	st		r6, 464
	st		r7, 463

	st		r8, 462
	st		r9, 461

	st		r10, 460
	st		r11, 459

	st		r12, 458
	st		r13, 457

	st		r14, 456

	st		r2, 468

	st		r3, 467

	st		r4, 466
	st		r5, 465

	st		r6, 464
	st		r7, 463

	st		r8, 462
	st		r9, 461

	st		r10, 460
	st		r11, 459

	st		r12, 458
	st		r13, 457

	st		r14, 456

	st		r2, 468

	st		r3, 467

	st		r4, 466
	st		r5, 465

	st		r6, 464
	st		r7, 463

	st		r8, 462
	st		r9, 461

	st		r10, 460
	st		r11, 459

	st		r12, 458
	st		r13, 457

	st		r14, 456

		st		r2, 468

	st		r3, 467

	st		r4, 466
	st		r5, 465

	st		r6, 464
	st		r7, 463

	st		r8, 462
	st		r9, 461

	st		r10, 460
	st		r11, 459

	st		r12, 458
	st		r13, 457

	st		r14, 456

	st 		r2, 468

	st		r3, 467

	 st 		r15, 465

	# saute sur la première instruction écrite
	ld		%0, r6
	zjmp	%300
