.name "Eraser"
.comment "this is a comment"

ld		%0,		r16
zjmp	%:mid

zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0

mid:
zjmp	%:begin

zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0
zjmp	%0

# 01 = TO NOT USE
# 02 = compteur
# 03 = constante
# 04 = constante
# 05 = sti
# 06 = sti + zjmp
# 07 = sti + zjmp
# 08 =
# 09 = st
# 10 =
# 11 =
# 12 =
# 13 =
# 14 = live / num joueur
# 15 =
# 16 = 0

begin:
ld		%504,			r4
st		r1,				0			# et paf ! je met le num champion par terre
ld		%507,			r3			# position sti r5
fork	%:p2

# ------------------------
p1:
	ld		-15,		r14			# ein petite technique gniark gniark gniark

	ld		%4,			r2			# compteur rush [4] / 0

	ld		%67108864,	r5			# 04 00 00 00				= L]
	ld		%50921969,	r6			# 03 09 01 F1 				= A] + zjmp %497

	ld		%50921975,	r7			# 03 09 01 f7				= B] + zjmp %503

	ld		%262144,	r9			# 00 40 00 00				= C]

	ld		%0,			r16
	zjmp	%:launch
# ------------------------

# ------------------------
p2:
	ld		%1,			r14			# instruction live des familles

	ld		%0, 		r2			# compteur rush 4 / [0]

	ld		%190057986,	r5			# 0b 54 0e 02				= sti r14, r2, r4 L[
	ld		%190056194, r6			# 0b 54 07 02 				= sti r7, r2, r3 A[

	ld		%190056706, r7			# 0b 54 09 02				= sti r9, r1, r3 B[

	ld		%134443017, r9			# 08 03 70 09				= C] st r9, 64 C[

	ld		%0,			r16
	zjmp	%:launch
# ------------------------

launch:
	sti		r5,			r2,	r3
	sti		r6,			r2,	r3

	zjmp	%497
