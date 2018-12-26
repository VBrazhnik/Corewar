.name		"error_bot_name not found"
.comment	""

live:
	live %1
	fork %-10
	live %1
	fork %-10
	live %1
	fork %-10
	live %1
	fork %-10

l:
	zjmp %:live
	ld %25, r4
	st r4, -500
	st r4, -500
	st r4, -500
	st r4, -500
	st r4, -500
	st r4, -500
	st r4, -500
	st r4, -500
	st r4, -500
	st r4, -500
	st r4, -500
	st r4, -500
	st r4, -500
	st r4, -500
	st r4, -500
	st r4, -500
	st r4, -500
	st r4, -500
	st r4, -500
	st r4, -500
	zjmp %:l

l1:
	live	%9999999
	sub		r13, r15, r13
	sti		r9, r10, r13
	ld		%0, r16
	zjmp	%:l1

b2:
	live	%9999999
	add		r11, r15, r11
	sti		r7, r10, r11
	sti		r8, r10, r11
	ld		%0, r16
	zjmp	%:b2
