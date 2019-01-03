.name "run Kitty RUN"
.comment "Jan-ken-pon (じゃんけんぽん)
Ce qui reste éternellement incompréhensible dans la nature, c’est qu’on puisse la comprendre.
Celui qui ne peut plus éprouver ni étonnement ni surprise, est pour ainsi dire mort : ses yeux sont éteints. – Albert Einstein
Si vous voulez trouver les secrets de l'univers pensez en termes de fréquences, d'énergies et de vibrations. - Nikola Tesla
Pas la pour etre ici. - Silicon Val[list]
Dieu est la plus belle invention.
Tapis dans l'ombre je veille. - Minou
J'te KHABBAR"

gomugomu:
	fork%:gear_second
	live %252645135
	fork %:gear_fourth
	ld %190056971, r9
	ld %190057744, r10
	ld %506, r11
	ld %139725068, r13
	ld %505, r16
	ld %252645135, r2
	ld %511, r15
	st r2, r5
	st r2, r3
	st r2, r6
	st r2, r4
	st r2, r7
	st r15, r14
	st r2, r1
	st r15, r8
	ld %0, r12
	zjmp %:j_te_khabbar
gear_fourth:
	st r1, 6
	live %42
	ld %1879178767, r1
	st r1, -16
	ld %201916917, r9
	ld %201916916, r10
	ld %510, r11
	ld %151783691, r13
	ld %507, r16
	ld %190055695, r2
	ld %5, r15
	ld %190055183, r5
	ld %190055951, r3
	ld %190055439, r6
	ld %190056206, r4
	ld %160370433, r7
	ld %10, r14
	ld %1409421068, r1
	ld %14, r8
	xor r12, r12, r12
	zjmp %:haki_of_kings
gear_second:
	live %252645135
	fork %:gear_third
	ld %201916917, r9
	ld %201916916, r10
	ld %510, r11
	ld %151737348, r13
	ld %509, r16
	ld %34540555, r2
	ld %2, r15
	ld %84872203, r5
	ld %51317771, r3
	ld %101649419, r6
	ld %68094987, r4
	ld %190054664, r7
	ld %5, r14
	ld 23, r1
	ld %11, r8
	xor r12, r12, r12
	zjmp %:haki_of_kings
	live %42
	sti r15, r1, r1
gear_third:
	st r1, -9
	ld %1879114239, r1
	st r1, -11
	st r15, r15
	st r15, r15
	ld %190056971, r9
	ld %190057744, r10
	ld %506, r11
	ld %1409552140, r13
	ld %511, r16
	ld %1409617676, r2
	ld %6, r15
	ld %1409486604, r5
	ld %1409683212, r3
	ld %1409552140, r6
	ld %1409748492, r4
	ld %1409353740, r7
	st r15, r14
	ld %33554431, r1
	ld %8, r8
	ld %0, r12
	zjmp %:j_te_khabbar
haki_of_kings:
	st r9, 20
	zjmp %11
j_te_khabbar:
	st r9, 8
	zjmp %3
