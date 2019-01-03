.name "stargate0_1"
.comment "infinity"


start:
	and r2,r2,r2
	st r1, 132
	zjmp %:jmp1
	
advanced_wall:
	
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	live %0
	zjmp %:advanced_wall
	live %0

	
	ld		%495, r8
fork %:coreclear
	st r1, 280
	st r1, 283
	st r1, -6
	live %0
	sub r16, r16, r16
	fork %:factory
	live %0
	fork %:advanced_wall
	zjmp %-8

coreclear:
	live            %1
	ld              %20,r11
	ld              %-9,r12
	ld              %420, r13
	ld              %269025348, r14 #ld %369885440, r14 269222120
	fork            %:corruption_second 	# 39000 cycles
	ld              %4,r10

corruption_first:
	ld              %185139215,r9 			#185139211 -> 0B09000B
	ld              %134808042,r7
	ld              %134808042,r6
	ld              %134808042,r15
	sub             r16, r16, r16
	zjmp            %:end1

corruption_second:
	ld              %190056714,r9			# B54090A  -> 0B54090
	ld              %190056714,r7
	ld              %190056202,r6
	ld              %190055946,r15
	sub             r10, r10, r10
	zjmp            %:end1

wall:
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	st r5, -510
	live %0
	zjmp %:wall

factory:
	live %0
	fork %:wall
	live %0
	fork %:coreclear
	add r8, r10, r8
	sub r6, r6, r6
	zjmp %:factory



end1:
	add     r13, r12, r13
	sti     r15,r10,r13 #102
	add     r14, r12, r14
	xor     r1, r1, r1

lancement:
	zjmp    %396

jmp1:
	st r1, 11
	st r1, -2
	live %0

#needed register
ld %83886080, r2		#   07 00 00 00		-> diff for bombing
ld %2752118273, r3       #   06 09 FE 01[b	-> jumper
ld %57673009, r4        # ]b03 70 05 31		-> bomber
ld %16, r12				#	00 00 00 20		-> compteur
ld %1, r13				#	00 00 00 10		-> decrementeur
ld %2,	r11				#	0
ld %1208961039, r5		#	0f 48 0f 48		-> bomb type

#register for first gate

ld %72614658,	r15		#	05 54 03 02		-> decrement modif bomb r3 - r2 ->r3
ld %50615307,	r14		#	03|04 54 0B		-> modif counter
ld %218826324,	r6		#	0D 0B|06 54		-> here too then modifier for xor 
ld %185339651,	r5		# 	0B 0C 0F|03		-> go back home
ld %1879310827,	r16		#	70 04 01 EB		-> load the second gate
ld %57672449,	r10		#	03|70 03 01
ld %3926458848, r9		#	EA 09 01 E0
ld %139725322,	r8		#	08 54 0A 0A
ld %269090305,	r7		#	10 09 FE 01

# load the registers
						# HEXA
st r15, 511				# 03 70 0f 01 ff
st r14, 510				# 03 70 0e 01 fe
st r6, 509				# 03 70 06 01 fd
st r5, 508				# 03 70 05 01 fc
st r16, 507				# 03 70 10 01 fb
st r10, 506				# 03 70 0a 01 fa
st r9,	505				# 03 70 09 01 f9
st r8,	504				# 03 70 08 01 f8
st r7,	503				# 03 70 07 01 f7
ld %252645135, r5
st r7, -20
xor r15, r15, r15
zjmp	%449
