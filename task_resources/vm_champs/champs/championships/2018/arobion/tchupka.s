.name "katch upper"
.comment "do you like mirror ?"


 # gap between code = abs0

beg:
    ld %-508, r7 
    ld %-62, r15 
    ld %0, r8
first_jmp:
    zjmp %:start

launch:
	sti r1, r7, r11
	sti r2, r7, r12
	sti r8, r7, r6
	zjmp %-506    ## synchronize with size of the jump 0

live %252645135
zjmp %-65 # value of the little jump  here to change the size of the loop size loop - trois
live %252645135
zjmp %-511 # value of the big jump  here to  change the size of the jump size jump -trois
start:
	fork %:p2

p1:
	st r1, -10
    st r8, -4
	ld -21, r8
	ld -26, r3
	ld %16, r11
	ld %19, r12
	ld %22, r6
	ld %252400644, r1
	ld %84347915, r2
	ld %252400653, r4
	ld %235342859, r5
	ld %252400653, r13
	ld %235867147, r14
	ld %0, r16
	zjmp %:launch

p2:
    st r1, -111
    st r8, -4
    ld -118, r3
    ld -115, r8
	ld %20, r11
	ld %23, r12
	ld %26, r6
	ld %118164308, r1
	ld %1409812230, r2
	ld %118164308, r4
	ld %1409484550, r5
	ld %252382036, r13
	ld %1409486598, r14
	ld %0, r16
	zjmp %:launch
