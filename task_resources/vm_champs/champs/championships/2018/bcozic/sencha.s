.name		"Sencha"
.comment	"Tea Time"

				ld %-128, r3
				ld %8, r5
				ld %10, r4
				ld %-500, r15
				ld %0, r2
				sti r1, %:attack, %1
				zjmp %:fork
attack:
				live %0
				sti r2, %:attack, %0
				sti r13, r15, r2
				zjmp	%-505

fork:
				fork %:process_2
process_1:
				ld %0, r2
				ld %190056965, r9
				ld %50465279, r10
				ld %190057477, r11
				ld %67240447, r12
				ld %190056453, r7
				ld %50465279, r8
				ld %190056207, r13
				ld %0, r6
				zjmp %:attack

process_2:
				ld %4, r2
				ld %34296839, r9
				ld %2064584463, r10
				ld %34296841, r11
				ld -115, r12
				ld %34296843, r7
				ld %2064584463, r8
				ld %34209285, r13
				ld %0, r6
				zjmp %:attack
