.name "Izi Miaou"
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
	xor r1, r1, r2
	zjmp %:begin
go1:
	st r15, -479     # 5
	zjmp %-484       # 3
go2:
	st r15, -483     # 5
	zjmp %-492      # 3
begin:
	ld %8, r3
	ld %11, r5
	ld %14, r7
	ld %-458, r14	# r 0e			BEGIN STORE					pading MAX = -509 modifiable -511
	ld %-326, r16	# r 10										pading MAX = -506 
	fork %:p2
p1:
	st r1, 89
	st r2, -5											# 5
	ld %17, r9
	ld %14, r12		# r 0c

	ld %83954516, r2				# 05 01 0b 54
	ld %1409812737, r4				# 54 08 09 01
	ld 54, r6						# fX 0b 54 0a		# 7		GO SEEK ID
	ld %185336075, r8				# 0b 0c 01 0b		# 7
	ld %1410141697, r10	# r 0a		# 54 0d 0e 01		# 7
	ld %17432245, r11	# r 0b		# 01 09 fe ??		# 7		pading MAX = -511 = fe 01
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
	ld %-515, r9 	# - 511 - 4		FREE STORE
	ld %-461, r12	# r 0c			BEGIN STORE					pading MAX = -511

	ld %101122315, r2				# 06 07 01 0b
	ld %33554431, r4				# 01 ff ff ff
	ld %83954516, r6				# 05 01 0b 54
	ld %190058256, r10	# r 0a		# 0b 54 0f 10
	ld %139723009, r11	# r 0b		# 08 54 01 01
	ld 26, r13						# fX 09 ff fb		# 5
	ld %17519620, r15	# r 0f		# 01 0b 54 04		# 7

	ld %0, r8											# 7
	zjmp %:go2											# 3
id2:
	lfork %0						# 0f 00 00
	live %655355					# 00 09 ff fb
