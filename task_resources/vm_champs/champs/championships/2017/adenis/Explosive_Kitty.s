.name "Explosive Kitty"
.comment "Jan-ken-pon (じゃんけんぽん)
Ce qui reste éternellement incompréhensible dans la nature, c’est qu’on puisse la comprendre.
Celui qui ne peut plus éprouver ni étonnement ni surprise, est pour ainsi dire mort : ses yeux sont éteints. – Albert Einstein
Si vous voulez trouver les secrets de l'univers pensez en termes de fréquences, d'énergies et de vibrations. - Nikola Tesla
Pas la pour etre ici. - Silicon Val[list]
Dieu est la plus belle invention.
Tapis dans l'ombre je veille. - Minou"

start:
	ld -42, r2
	zjmp %:begin
first_attack:
	sti r10, r15, r9
	live %42
	zjmp %-410
p2:
	ld %50986512, r10		# 02 90 03 09 fe 10 0a
	ld %-392, r9
	ld %84540929, r2		# 02 90 05 09 fe 01 02
	ld %-487, r3
	ld %118095856, r4		# 02 90 07 09 ff f0 04
	ld %-502, r5
	ld %-7, r7
	ld -511, r1
	zjmp %:first_attack
begin:
	ld %55575553, r8		# 02 90 03 50 04 01 08
	st r1, r15				# 03 50 01 0f
	st r8, -4				# 03 70 08 ff fc
	fork %:def
	live %42
	fork %:p2
p1:
	ld %190054913, r10		# 02 90 0b 54 02 01 0a
	ld %-396, r9
	ld %190055425, r2		# 02 90 0b 54 04 01 02
	ld %-491, r3
	st r2, r4
	ld %-506, r5
	ld %-11, r7
	ld -511, r1
	zjmp %:first_attack
store_def:
	st r4, -37
	st r4, -47
	st r4, -57
	st r4, -67
	st r4, -77
	st r4, -87
	st r4, -97
	st r4, -107
	st r4, -117
	st r4, -127
	st r4, -137
	st r4, -147
	st r4, -157
	st r4, -167
	st r4, -177
	st r4, -187
	st r4, -197
	st r4, -207
	st r4, -217
	st r4, -227
	st r4, -237
	st r4, -247
	st r4, -257
	st r4, -267
	st r4, -277
	st r4, -287
	st r4, -297
	st r4, -307
	st r4, -317
	st r4, -327
	st r4, -337
	st r4, -347
	st r4, -357
	st r4, -367
	st r4, -377
	st r4, -387
	st r4, -397
	st r4, -407
	st r4, -417
	st r4, -427
	st r4, -437
	st r4, -447
	st r4, -457
	st r4, -467
	st r4, -477
	live %42
	zjmp %:store_def
def:
	ld %252645135, r4		# 02 90 0f 0f 0f 0f 04
	live %42
	ld 511, r1
	fork %:second_attack
	st r15, -27
inside:
	live %42
	zjmp %:store_def
second_attack:
#	st r15, 6
	live %42
	fork %:store_def
#	st r15, 104
	live %42
	fork %:second_bis
	live %42
	fork %:s3
s1:
	ld %5, r3
	ld %511, r5
	ld %190055429, r2		# 0b 54 04 05
	ld %33554431, r6		# 01 ff ff ff
	ld 511, r1
	zjmp %:go_erase
second_bis:
	live %42
	fork %:s4
s2:
	ld %9, r3
	ld %506, r5
	ld %17519622, r2		# 01 0b 54 06
#	st r15, 11
	ld 17, r6
	ld 511, r1
	zjmp %:go_erase
unused:
	live %42
	sti r2, r3, r1
s3:
	ld %13, r3
	ld %501, r5
	ld %50401039, r2		# 03 01 0f 0f
	st r2, r6
	ld 511, r1
	zjmp %:go_erase
s4:
	st r15, -42
	ld %511, r3
	ld %496, r5
	st r4, r2
	st r4, r6				# 0f 0f 0f 0f
	zjmp%:go_erase			#just for waiting 20 cycles
go_erase:
	sti r2, r3, r1
