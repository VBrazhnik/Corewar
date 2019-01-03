.name "Code_eater"
.comment "mnom mnom mnom"

# FONCTIONNEMENT :
# coromp pross ennemi
# fork
#
# charge p1
# charge p2
#
# casse r1 a chaque tp
# live a chaque tp
# tp a chaque tp

#
ld		%0,		r16
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
#zjmp	%0
#zjmp	%0
#zjmp	%0
#zjmp	%0
#zjmp	%0
#zjmp	%0
#zjmp	%0
#zjmp	%0
#zjmp	%0
#zjmp	%0
#zjmp	%0
#zjmp	%0

begin:

st		r16,	-381

st		r1,		0				# protection / corruption
ld		-5,			r14			# protection / corruption

st		r14,		r6			# pour ld ? p1
st		r14,		6
live	%0
fork	%:p1

# --------------------------------------
p2:
st		r14,		6
live	%0

ld		%0,			r15			# 00 00 00 00	= increment
ld		%190317071,	r2			# 0b 58 02 0f	= sti r2, r15, %499 [A debut]
ld		%51315189,	r3			# 03 0f 01 f5	= [B fin]

ld		%190317583,	r4			# 0b 58 04 0f	= sti r4, r15, %499 C[
ld		%84869621,	r5			# 05 0f 01 f4	= D]
ld		%32964609,	r6			# 01 f7 00 01	= E] + 0 + live

ld		%190318351,	r7			# 0b 58 07 0f	= sti r7, r15, %499 F[
ld		%135201269,	r8			# 08 0f 01 f5	= G]

ld		%0,			r16
zjmp	%:start
# --------------------------------------

# --------------------------------------
p1:
st		r14,		6
live	%0

ld		%4,			r15			# 00 00 00 0a	= increment
ld		%32705368,	r2			# 01 F3 0b 58	= [A fin] sti r3, r15, %502 [B debut]
ld		%151109376,	r3			# 09 01 bf 00	= zjmp %447

ld		%32705368,	r4			# 01 f3 0b 58	= C] + sti r5, r15, %501 D[
ld		%190318095,	r5			# 0b 58 06 0f	= sti r6, r15, %503 E[
ld		-39,		r6			# ?? ?? ?? ??	= num joueur

ld		%32705368,	r7			# 01 f3	0b 58	= F] + sti r8, r15, %501 G[
ld		%55575041,	r8			# 03 50 02 01	= st r2, r1

ld		%0,			r16
zjmp	%:start
# --------------------------------------

start:
sti		r7,			r15,		%499 # sti : sti F + sti G[
sti		r8,			r15,		%501 # sti : G] + st
st		r2,			r1

sti		r4,			r15,		%499 # sti : sti C + sti D[
sti		r5,			r15,		%501 # sti : sti D] + sti E[
sti		r6,			r15,		%503 # sti : sti E] + live + num joueur
live	%0

sti		r2,			r15,		%500 # sti : sti A + sti B[
sti		r3,			r15,		%502 # sti : sti B] + zjmp
zjmp	%448
