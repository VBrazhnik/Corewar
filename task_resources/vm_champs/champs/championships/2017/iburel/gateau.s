.name "🎂"
.comment "🎂"

wall:
	ld		%0, r10
	zjmp	%:debut

def:
	live	%2
	ld		%251658240, r2
	ld		%0, r10
	fork	%:ouais

boucle1:
	st		r2, -511
	st		r2, -505
	st		r2, -499
	st		r2, -493
	st		r2, -487
	st		r2, -481
	st		r2, -475
	st		r2, -469
	zjmp	%:boucle1

ouais:
	live	%2
boucle2:
	st		r2, -471
	st		r2, -465
	st		r2, -459
	st		r2, -453
	st		r2, -447
	st		r2, -441
	st		r2, -435
	zjmp	%:boucle2

aff:
	ld		%71, r1
	aff		r1
	ld		%82, r1
	aff		r1
	ld		%79, r1
	aff		r1
	ld		%83, r1
	aff		r1
	ld		%32, r1
	aff		r1
	ld		%83, r1
	aff		r1
	ld		%65, r1
	aff		r1
	ld		%67, r1
	aff		r1
	ld		%32, r1
	aff		r1
	ld		%71, r1
	aff		r1
	ld		%82, r1
	aff		r1
	ld		%79, r1
	aff		r1
	ld		%83, r1
	aff		r1
	ld		%32, r1
	aff		r1
	ld		%83, r1
	aff		r1
	ld		%65, r1
	aff		r1
	ld		%67, r1
	aff		r1
	ld		%32, r1
	aff		r1
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	lfork	%0
	live	%2

debut:
	st		r1, :wall
	st		r16, -5
	st		r1, 143
	st		r16, -5
	fork	%:def
	live	%2
	fork	%:aaaaah

super:
	live	%2

apocalypse:
	fork	%:super
	live	%2
    fork    %:salut2
    or      r2, %32, r2

salut2:
    live    %2
    fork    %:salut3
    or      r2, %16, r2

salut3:
    live    %2
    fork    %:salut4
    or      r2, %8, r2

salut4:
    live    %2
    fork    %:salut5
    or      r2, %4, r2

salut5:
    ldi     %:prog, r2, r16
    ld      %0, r15

prog:
    sti     r16, %64, r2
    sti     r16, %122, r2
    sti     r16, %180, r2
    sti     r16, %238, r2
    sti     r16, %296, r2
    sti     r16, %354, r2
    live    %2
    live    %2
    sti     r16, %402, r2
    sti     r16, %448, r2
    zjmp    %442
    live    %2

aaaaah:
	live	%2
	ld		%507, r6
	ld		%8, r8
	ld		%139, r10
	fork	%:sjmp

vite:
	live	%2
	ld		%4, r2
	ld		%101253622, r3
	ld		%101253622, r5
	ld		%168362119, r7
	ld		%262144, r9
	ld		%0, r16
	zjmp	%:rush

sjmp:
	live	%2
	ld		%0, r2
	ld		%190055682, r3
	ld		%190056194, r5
	ld		%190056706, r7
	ld		%134443017, r9
	ld		%0, r16
	zjmp	%:rush

rush:
	sti		r3, r2, r6
	zjmp	%502
