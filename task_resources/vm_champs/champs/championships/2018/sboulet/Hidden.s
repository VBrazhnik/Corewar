.name "Hidden"
.comment "Now you see me..."

init:
		add			r1, r16, r2
		st			r2, -4
		sti			r2, %:p12, %1
		sti			r2, %:p0, %1
		sti			r2, %:wiz, %1
		ld			%64, r3
		ld			%32, r4
		ld			%16, r5
		ld			%128, r6
		ld			%240, r7
		ld			%0, r15

p58:
		fork		%:p67
		add			r8, r15, r8
		ld			%0, r15
		zjmp		%:p12

p67:
		add			r8, r7, r8
		ld			%0, r15
		zjmp		%:p12

p12:
		live		%456789
		fork		%:p27
		add			r8, r15, r8
		ld			%0, r15
		zjmp		%:wiz

p27:
		add			r8, r6, r8
		ld			%0, r15
		zjmp		%:wiz

wiz:
		live		%654321
		ld			%33554431, r9
		st			r9, 511
		st			r2, 507
		ld			%201341697, r9
		st			r9, 499
		st			r2, 498
		ld			%201333506, r11
		st			r11, 490
		ld			%42991616, r10
		st			r10, 481
		ld			%134808208, r9
		st			r9, 474
		ld			%272630017, r9
		st			r9, 466
		ld			%33722368, r12
		st			r12, 458
		ld			%252248147, r9
		st			r9, 453
		st			r10, 452
		ld			%201917072, r9
		st			r9, 445
		ld			%251826176, r9
		st			r9, 441
		ld			%252248123, r9
		st			r9, 436
		ld			%33554431, r9
		st			r9, 428
		st			r2, 424
		st			r11, 423
		st			r10, 421
		ld			%269025936, r9
		st			r9, 414
		ld			%190054920, r14
		st			r14, 406
		st			r12, 405
		ld			%252248091, r13
		st			r13, 400
		st			r10, 399
		ld			%336134800, r9
		st			r9, 392
		ld			%151585254, r9
		st			r9, 384
		st			r12, 383
		st			r13, 385
		ld			%50462719, r9
		st			r9, 376
		st			r2, 373
		st			r14, 372
		ld			%151584774, r9
		st			r9, 364
		st			r2, 67
		st			r2, 90
		st			r2, 11
		st  		r2, 44

p0:
		live		%45678923
		fork		%:pp
		add			r8, r15, r8
		ld			%0, r15
		zjmp		%:p1

pp:
		add			r8, r3, r8
		ld			%0, r15
		zjmp		%:p1

p1:
		live		%5412876
		fork		%:p2
		live		%864259
		add			r8, r15, r8
		fork		%:p3
		add			r8, r15, r8
		ld			%0, r15
		zjmp		%134

p2:
		live		%987652
		add			r8, r4, r8
		fork		%:p3
		add			r8, r15, r8
		ld			%0, r15
		zjmp		%111

p3:
		add			r8, r5, r8
		ld			%0, r15
		zjmp		%96
