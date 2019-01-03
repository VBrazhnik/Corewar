.name "Kitty Miaou"
.comment "Ma cherie
Si tu voulais bien etre la bienvenue dans ma vie
Vi vi c'est bien ce que j'ai dis
Je ne penses plus qu'a toi
Mes penses restent sans voix sans toi
Dis moi es-tu la?
Me veux-tu?
Je serais l'esclave de tes desirs
Aime le monde, pour toi, moi je desire tout le Monde avec toi
J'aime bien le voir evoluer, et fleurir avec toi
- Minou
Dieu est la plus belle invention.
Tapis dans l'ombre, je veille
- Minou"

start:
	ld %8, r13
	ld %6, r14
	ld %11, r10
	ld %61947, r15			# ld %507, r15
	fork %:p2
p1:
					#ld %0, r8
	st r8, 104           								# 5
	ld 92, r5          	 								# 7
	ld %190054664, r7               # 0b 54 01 08
	ld %134877312, r1				# 08 0a 10 80			# 7
	st r13, r9		#ld %8, r9		# =8					# 4
	ld %190055176, r2				# 0b 54 03 08			# 7
	ld %134877312, r3				# 08 0a 10 80			# 7
	ld %190055688, r4				# 0b 54 05 08			# 7
	#ld -21, r5				# ff fX 0b 54
	ld %1410009100, r6				# 54 0b 08 0c			# 7
	ld %168853504, r11				# 0a 10 80 00			# 7
	ld %9, r12												# 7
	ld %190054664, r16				# 0b 54 01 08			# 7
	#st r8, 29			
	#ld 17, r5			
	ld %0, r8			# 7
	zjmp %:go1			# 3
id:
	lfork %0
	lfork %0
	lfork %0
	lfork %0
	sti r10, r10, r10	# 5
p2:
	st r1, -9
	ld %4, r8
	ld %151737346, r7				# 09 0b 54 02
	ld %218234879, r4               # 0d 01 ff ff
	ld %507, r9
	ld %151737348, r2				# 09 0b 54 04
	#st r1, -101			# registre mit a 0?
	ld %252645135, r1 			    # 0f 0f 0f 0f
	ld %101191179, r5				# 06 08 0e 0b
	ld %190058504, r6				# 0b 54 10 08
	st r1, r11
	st r9, r12
	ld %151737346, r16				# 09 0b 54 02
	ld %0, r3
	zjmp %:go2
#_______________________________________________________________________#
empty:
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
	lfork %3855
lfork %3855
lfork %3855
lfork %3855
lfork %3855
lfork %3855
lfork %3855
	live %42
	live %42
#_______________________________________________________________________#
go1:
    ld %190056200, r8				# 0b 54 07 08						# 7
	st r8, 511		# ??												# 5
	ld %0, r8															# 7
	zjmp %499              												# 3

go2:
	ld %252248566, r3				# 0f 09 01 f6	# 01 f6 = 502		# 7
	st r3, 493				#Quel registre? r11(0b) not used			# 5
	ld %0, r3															# 7
	zjmp %477              # 

