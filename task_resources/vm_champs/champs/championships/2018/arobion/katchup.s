.name "katchup"
.comment "Do you like ketchup?"

# r1	...
# r2	jump value - big
# r3	jump value - small
# r4	jump fixing - first
# r5	jump fixing - second
# r6	jump fixing - third
# r7	sti content - first 1
# r8	sti content - first 2
# r9	sti content - second 1
# r10	sti content - second 2
# r11	sti content - third 1
# r12	sti content - third 2
# r13	live and jump - big
# r14	live and jump - small
# r15	...
# r16	...

# first: write second with big verson, big jump
# r7, r2, r4
# r8, r2, r5
# r13 r2, r6

# second, write third with big version, big jump
# r9, r2, r4
# r10, r2, r5
# r13 r2, r6

# third, write fourth with small version, big jump
# r7, r2, r4
# r8, r2, r5
# r14 r2, r6

# fourth, write fourth with small version, small jump
# r7, r3, r4
# r8, r3, r5
# r14 r3, r6





prepare:
	live %252645135
    ld %478, r2
    ld %21, r3
    ld %0, r16
    zjmp %:fork

filling1:
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135

live_and_jump:
	live %252645135
	zjmp %482 # jump + jump_cmd_len + 0f
	live %252645135
	zjmp %25 # small + jump_cmd_len + 0f

fork:
	fork %:p2

p1:
	st r1, -10
    st r16, -4
	ld -21, r13
	ld -26, r14
	ld %23, r4
	ld %26, r5
	ld %29, r6
	ld %252400649, r7
	ld %167904523, r8
	ld %252400651, r9
	ld %201458955, r10
	ld %252400651, r11
	ld %201524491, r12
	ld %0, r16
	zjmp %:launch

p2:
    st r1, -111
    st r16, -4
    ld -118, r13
    ld -115, r14
	ld %27, r4
	ld %30, r5
	ld %33, r6
	ld %33819476, r7
	ld %1410138630, r8
	ld %33819476, r9
	ld %1410204166, r10
	ld %50596692, r11
	ld %1410204422, r12
	ld %0, r16
	zjmp %:launch

filling2:
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135
	live %252645135

launch:
	sti r7, r2, r4
	sti r8, r2, r5
	sti r13, r2, r6
	zjmp %487 # jump + jump_cmd_len + live_cmd_len + 0f
