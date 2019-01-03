.name "ForgottenOne"
.comment "I've forget this guy. Sorry."

init:
		sti			r1, %:alive, %1
		sti			r1, %:alive, %9
		sti			r1, %:wall, %1
		sti			r1, %:clear, %1
		sti			r1, %:clear18, %1
		sti			r1, %:clear916, %1
		sti			r1, %:rush, %1
		ld			%0, r16
		fork		%:rush
		zjmp		%:alive

initwall:
		ld			%42991616, r2
		ld			%265, r3
		ld			%4261478400, r16
		ld			%0, r15

wall:
		live		%1344483
		st			r16, -30
		st			r3, -39
		st			r2, -48
		st			r16, -57
		st			r3, -66
		st			r2, -75
		st			r16, -84
		st			r3, -93
		st			r2, -102
		st			r16, -111
		st			r3, -120
		st			r2, -129
		st			r16, -138
		st			r3, -147
		st			r2, -156
		st			r16, -165
		st			r3, -174
		st			r2, -183
		st			r16, -192
		st			r3, -201
		st			r2, -210
		st			r16, -219
		st			r3, -228
		st			r2, -237
		st			r16, -246
		st			r3, -255
		st			r2, -264
		st			r16, -273
		st			r3, -282
		st			r2, -291
		st			r16, -300
		st			r3, -309
		st			r2, -318
		st			r16, -327
		st			r3, -336
		st			r2, -345
		st			r16, -354
		st			r3, -363
		st			r2, -372
		st			r16, -381
		st			r3, -390
		st			r2, -399
		st			r16, -408
		st			r3, -417
		st			r2, -426
		st			r16, -435
		st			r3, -444
		st			r2, -453
		st			r16, -462
		st			r3, -471
		st			r2, -480
		st			r16, -489
		st			r3, -498
		st			r2, -507
		zjmp		%:wall

alive:
		live		%2863311530
		fork		%:initwall
		live		%637485
		fork		%:alive
		live		%62243211
		fork		%:clear
		zjmp		%:alive

circup:
		live		%756436893
		zjmp		%:circup

clear:
		live		%534675876
		add			r16, r1, r2
		ld			%8, r3
		fork		%:clear916

clear18:
		live		%64732221
		fork		%:clear58

clear14:
		ld			%0, r4
		ld			%150994945, r2
		st			r2, 110
		ld			%0, r16
		zjmp		%101

clear58:
		ld			%4, r4
		ld			%0, r16
		st			r2, 85
		ld			%0, r16
		zjmp		%72

clear916:
		live		%-3245
		fork		%:clear1316

clear912:
		ld			%8, r4
		ld			%190054915, r2
		st			r2, 52
		ld			%0, r16
		zjmp		%35

clear1316:
		ld			%12, r4
		ld			%67698694, r2
		st			r2, 27
		ld			%0, r16
		zjmp		%6

rush:
		live		%23145789
		ld			%190054917, r2
		ld			%67699190, r3
		ld			%507, r5
		ld			%16, r6
		st			r2, 511
		st			r3, 510
		fork		%:rush58

rush14:
		ld			%190055173, r2
		ld			%190056198, r3
		ld			%190056198, r7
		ld			%0, r4
		ld			%0, r16
		zjmp		%463

rush58:
		ld			%67699190, r2
		ld			%67698699, r3
		ld			%67698699, r7
		ld			%4, r4
		ld			%0, r16
		zjmp		%425
