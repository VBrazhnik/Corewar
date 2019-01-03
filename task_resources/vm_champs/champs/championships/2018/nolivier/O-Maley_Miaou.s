.name "O'Maly Miaou"
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

#__________________________________________________________________________________________#
# a funny champ to try
#.name "One process"
#.comment "Jan-ken-pon (じゃんけんぽん)"

#start:
#ld -4, r16
#zjmp %:loadtarace
#go:
#ld %1879375380, r2        # 70 04 fe 14
#st r2, 6
#st r4, -508
#add r2, r3, r2
#and r2, r1, r16
#zjmp %-20
#xor r16, r16, r16
#zjmp %-510
#id:
#live %42
#ld %42, r16
#loadtarace:
#st r1, -11
#ld -14, r6                # ff fX 02 90
#ld %2414870915, r1        # 8f f0 01 83
#ld %65540, r3            # 00 01 00 04
#ld %252645135, r4        # 0f 0f 0f 0f
#ld %251789311, r5        # 0f 01 ff ff

#ld %1879375380, r7        # 70 04 fe 14
#ld %33779714, r8        # 02 03 70 02
#ld %394096, r9            # 00 06 03 70
#ld %83760132, r10        # 04 fe 14 04
#ld %1409417986, r11        # 54 02 03 02
#ld %106168833, r12        # 06 54 02 01
#ld %269090796, r13        # 10 09 ff ec
#ld %139726864, r14        # 08 54 10 10
#ld %269090306, r15        # 10 09 fe 02
#ld %0, r16
#zjmp %:go

#__________________________________________________________________________________________#
#another like previoous with fork
#.name "DoubleWhile"
#.comment "Jan-ken-pon (じゃんけんぽん)"

#start:
#ld %252645135, r9        # 0f 0f 0f 0f
#ld -11, r16
#zjmp %:double
#go:
#st r2, r3
#boucle:
#st r3, 6
#st r9, -511
#add r3, r4, r3
#and r3, r1, r16
#zjmp %:boucle
#xor r3, r3, r16
#zjmp %-511
#id:
#live %42
#st r2, r16
#double:
#fork %:p1
#p2:
#ld %139723525, r10        # 08 54 03 05
#ld %106169089, r11        # 06 54 03 01
#ld %151005700, r12        # 09 00 2a 04    // 09 XX XX 04
#ld %50556931, r13        # 03 03 70 03
#ld %33554431, r14        # 01 ff ff ff
#st r9, r15                # 0f 0f 0f 0f

#ld %2414870528, r1      # 8f f0 00 00           # 7
#ld %1879703104, r2      # 70 09 fe 40           # 7
#ld %65528, r4           # 00 00 ff f8           # 7
#ld %1880161800, r5      # 70 10 fe 08            # 7
#ld 119, r16                                        # 5
#zjmp %:go                                        # 3
#p1:
#ld %55574786, r10        # 03 50 01 02            # 7
#ld %394096, r12            # 00 06 03 70            # 7
#ld %1409483779, r13        # 54 03 04 03            # 7
#ld %269090796, r14        # 10 09 ff ec            # 7
#ld %269090305, r15      # 10 09 fe 01            # 7        TO VERIFY & TEST & MODIFY

#ld %187911779, r8        # 70 01 00 33            # 7
#st r1, 52                                        # 5
#st r8, -4                                        # 5
#ld 45, r11                # fX 03 50 02            # 5
#ld %2414870976, r1      # 8f f0 01 c0            # 7
#ld %1879703052, r2      # 70 09 fe 0c            # 7
#ld %65544, r4           # 00 01 00 08            # 7
#ld %1880161860, r5        # 70 10 fe 44            # 7
#ld 21, r16                                        # 5
#zjmp %:go                                        # 3
#id:
#live %42                                        # 5
#st r2, r16                                        # 4


#__________________________________________________________________________________________#

start:
	ld %8, r3
	ld %11, r5
	ld %14, r7
	ld %409, r14	# r 0e					BEGIN STORE			pading MAX = 504
	ld %312, r16	# r 10										pading MAX = 507 
	fork %:p2
p1:
	st r1, 89
	st r2, -5											# 5
	#ld %0, r1					# 				TO CARRY
	ld %17, r9
	ld %14, r12		# r 0c

	ld %83954516, r2				# 05 01 0b 54
	ld %1409812737, r4				# 54 08 09 01
	ld 54, r6						# fX 0b 54 0a		# 7		GO SEEK ID
	ld %185336075, r8				# 0b 0c 01 0b		# 7
	ld %1410141697, r10	# r 0a		# 54 0d 0e 01		# 7
	ld %17367347, r11	# r 0b		# 01 09 01 XX		# 7		pading MAX = 502 = 1f6
	ld %33554431, r13	# r 0d		# 01 ff ff ff		# 7
	ld %190054915, r15	# r 0f		# 0b 54 02 03		# 7

	ld %0, r1											# 7
	zjmp %:go1											# 3
id1:
	lfork %0						# 0f 00 00			# 3
	live %742410					# 00 0b 54 0a		
p2:
	st r1, 89
	st r2, -5
	ld %4, r1
	ld %457, r9 	# 511 - 4		FREE STORE
	ld %406, r12	# r 0c			BEGIN STORE					pading MAX = 501

	ld %101122315, r2				# 06 07 01 0b
	ld %33554431, r4				# 01 ff ff ff
	ld %83954516, r6				# 05 01 0b 54
			# ld %0, r8				# 00 00 00 00	TO CARRY
	ld %190058256, r10	# r 0a		# 0b 54 0f 10
	ld %139723009, r11	# r 0b		# 08 54 01 01
			# ld %1, r13	# r 0d				# fX 09 ff fb	GO SEEK ID
	ld 26, r13						# fX 09 ff fb		# 5
	ld %17519620, r15	# r 0f		# 01 0b 54 04		# 7

	ld %0, r8											# 7
	zjmp %:go2											# 3
id2:
	lfork %0						# 0f 00 00
	live %655355					# 00 09 ff fb
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
go1:
	st r15, 511		# 5
	zjmp %506		# 3
go2:
	st r15, 507		# 5
	zjmp %498		# 3

