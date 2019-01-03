.name "Horace"
.comment "Le horace qui vaincra les curiaces (bon en vrai c'est vraiment 
a titre historique uniquement, c'est plus vraiment le cas maintenant)"

start: #1177
st r1, :write
ld :read, r2
st r1, 110
st r3, -5

ld %57673217, r3
ld %4261638147, r4
ld %33227632, r5
ld %67238659, r6
ld %1879376379, r7
ld %57673217, r8
ld %4244860935, r9
ld %33489776, r10
ld %134348291, r12
ld %1879835133, r13
ld %57673729, r14
ld %4228448722, r15
ld %0, r16
break:
zjmp %:write1

live %0
live:
live %0
zjmp %:live

write:	aff r12
read:	live %190054656

live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0

write1:
st r16, :break
st r3, 511
st r4, 510
st r5, 509
st r6, 508
st r7, 507
st r8, 506
st r9, 505
st r10, 504
st r12, 503
st r13, 502
st r14, 501
st r15, 500

ld %1770192, r3		#00 1b 02 d0
ld %453051088, r4	#1b 01 02 d0
ld %436339344, r5	#1a 02 02 90
ld %285999760, r6	#11 0C 02 90
ld %302713684, r7	#12 0b 0b 54
ld %17502219, r8	#01 0b 10 0b
ld %1409420297, r12 #54 02 0c 09

ld %268435455, r1
ld %505, r11
ld 256, r9
zjmp %375
