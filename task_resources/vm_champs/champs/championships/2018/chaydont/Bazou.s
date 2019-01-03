.name "Bazou"
.comment "C'est comme un petit lapin mais en plus peureux et avec des moins grandes oreilles."

	ld %0, r14
start:
i:	zjmp %:first

live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %4278415366
live %33424240
live %117571081
live %31197694
live %402653184

two:
	ld %167645961, r16
	ld %-22, r14
	ld %1880097301, r15

	ld %72617742, r1
	ld %252204042, r2
	ld %17630064, r3
	ld %251659779, r4
	ld %57675520, r5 # +4
	ld %100859904, r6 # -2
	ld %655330, r7 # +3
	ld -511, r8
	st r1, r10
	zjmp %:z

first:
	st r1, 13
	ld %33554431, r1
	live %0
	zjmp %-5
	ld -4, r2
	st r1, :start
	st r2, -451
	st r1, 511
	st r2, 510
	ld 86, r1
	ld 85, r2
	ld 84, r3
	ld 83, r4
	ld 82, r5
	ld 81, r6
	ld 80, r7
	ld 79, r8
	ld 78, r9
	ld 77, r10
	ld 76, r11
	ld 75, r12
	ld 74, r13
	ld %184677641, r14
	ld %4265281793, r15
	ld %3305766750, r16

	st r1, 511
	st r2, 510
	st r3, 509
	st r4, 508
	st r5, 507
	st r6, 506
	st r7, 505
	st r8, 504
	st r9, 503
	st r10, 502
	st r11, 501
	st r12, 500
	st r13, 499
	st r14, 498
	st r15, 497
	st r16, 496

	ld -317, r7
	ld -317, r8
	ld -317, r9
	ld -317, r10
	ld -317, r11

	ld 100, r16
	zjmp %401
	zjmp %:two
z:	zjmp %453
