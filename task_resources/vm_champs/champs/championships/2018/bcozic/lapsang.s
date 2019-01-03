.name		"Lapsang Souchong Crocodile"
.comment	"Tea Time"

			ld		%-107, r8
			live	%0
nb:			sti		r1, %:attack, %1
			sti		r8, %:nb, %0
			fork	%:fork1
			fork	%:run3
			ldi		%0, %:attack, r4
			ld		%0, r9
			ld		%0, r2
			zjmp	%:attack
			aff		r2
			aff		r2
			aff		r2
			aff		r2
			aff		r2
			aff		r2
			aff		r2
			aff		r2
			aff		r2
			aff		r2
fork1:		fork	%:run2
			ldi		%4, %:attack, r4
			ld		%4, r9
			ld		%0, r2
			zjmp	%:attack
			aff		r2
			aff		r2
			aff		r2
			aff		r2
			aff		r2
			aff		r2
			aff		r2
			aff		r2
			aff		r2
			aff		r2
			aff		r2
run2:		ldi		%8, %:attack, r4
			ld		%8, r9
			ld		%0, r2
			zjmp	%:attack
			aff		r2
			aff		r2
			aff		r2
			aff		r2
			aff		r2
			aff		r2
			aff		r2
			aff		r2
			aff		r2
run3:		ldi		%12, %:attack, r4
			ld		%12, r9
			ld		%0, r2
			zjmp	%:attack
attack:		live	%0
			sti		r4, r8, r9
			zjmp	%-112
