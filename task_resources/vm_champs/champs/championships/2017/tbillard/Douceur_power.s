.name "Douceur-power"
.comment "La douceur de la quenelle"

sl:
st		r1, 7
ld		%4242, r1
st 		r2, :sl
sti		r2, %:sl, %1
fork 		%:ff1
sti		r1, %:l1, %1
sti		r1, %:a3, %1
ld		%252645135, r9
ld 		%4294967041, r10
ld 		%655202, r12
ld 		%17432564, r15
ld 		%42991616, r16
ld 		%0, r2

l1:
live		%12345

fork		%:a0

wall:
live		%12345
st		r15, -467
st		r16, -478
st 		r1, -487
st		r10, -496
st		r2, -491
st		r9, -45
st		r9, -60
st		r9, -75
st		r9, -90
st		r9, -105
st		r9, -120
st		r9, -135
st		r9, -150
zjmp 		%:wall

ff2:
live 		%12345
sti		r2, r3, r3
zjmp		%-509

ff1:
live		%12345
fork		%:pp2

pp1:
ld		%-252, r3
ld		%190055683, r2
ld		%190056451, r5
ld		%-12, r9
ld		%190056457, r8
ld		%0, r16
zjmp		%:ff2

pp2:
ld		%-250, r3
ld		%50986499, r2
ld		%50986499, r5
ld		%-10, r9
ld		%151650275, r8
ld		%0, r16
zjmp		%:ff2

a0:
live		%12345
fork		%:f1
zjmp		%:a3

a1:
live		%12345
fork		%:a3

a2:
live		%12345
fork		%:a3

ttt:
live		%12345
fork		%:a8
zjmp		%:a1

a3:
live		%12345
fork		%:a5

a4:
live		%12345
fork		%:a7
ld		%0, r9
zjmp		%:a1

a5:
live		%12345
fork 		%:a6
live		%12345

ld		%190054658, r1
ld		%6, r2
ld		%4, r3
ld		%0, r9
zjmp		%:final

a6:
live		%12345
ld		%8, r2
ld		%4, r2
ld		%2, r3
ld		%0, r9
zjmp		%:final

a7:
live		%12345
ld		%50397184, r1
ld		%7, r2
ld		%7, r3
ld		%0, r9
zjmp		%:final

a8:
live		%12345
ld		%1111638594, r1
ld		%254, r2
ld		%254, r3
ld		%0, r9
zjmp		%:final

final:
sti		r1, r2, r3


f1:
fork		%:p2

p1:
ld		%242, r3
ld		%190055683, r2
ld		%190056451, r5
ld		%12, r9
ld		%190056457, r8
ld		%0, r16
zjmp		%:f2

p2:
ld		%244, r3
ld		%50921951, r2
ld		%50921951, r5
ld		%14, r9
ld		%151584787, r8
ld		%0, r16
zjmp		%:f2

f2:
live 		%12345
sti		r2, r3, r3
zjmp		%479
