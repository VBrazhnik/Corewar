.name "The Harvester"
.comment "L'elevage, puis la domestication de process est une activite
dangereuse mais o combien amusante, attention toutefois a ne pas y perdre la
vie

Labourage, elevage, domestication"

	sub r2, r2, r2

start:
	st r1, 11
	ld 6, r10
	live %0
	st r10, 6
	live %0

fork1:
	ld %507, r3
	fork %:p2

p1:
	ld %50921974, r5
	ld %50921977, r6
	ld %1879113730, r1
	ld %4, r4
	ld %589955, r9 #LA
	st r9, :start
	xor r2, r2, r2
	zjmp %:write

p2:
	ld %190055940, r5
	ld %190054660, r6
	ld %16778755, r1
	ld %0, r4
	st r10, 452 #LA
	live %0
	zjmp %:write

relay1:
	live %0
	zjmp %:fork1

live:
	ld -111, r10 #LA
	st r10, 6
	live %0
	st r10, 6
	live %0
	st r10, 6
	live %0
	st r10, 6
	live %0
	st r10, 6
	live %0
	st r10, 6
	live %0
	st r10, 6
	live %0
	st r10, 6
	live %0
	st r10, 6
	live %0
	st r10, 6
	live %0
	st r10, 6
	live %0
	st r10, 6
	live %0
	st r10, 6
	live %0
	st r10, 6
	live %0
	st r10, 6
	live %0
	st r10, 6
	live %0
	st r10, 6
	live %0
	st r10, 6
	live %0
	st r10, 6
	live %0
	st r10, 6
	live %0
	st r10, 6
	live %0
	st r10, 6
	live %0
	st r10, 6
	live %0
	st r10, 6
	live %0
	st r10, 6
	live %0
	st r10, 6
	live %0
	st r10, 6
	live %0
	st r10, 6
	live %0
	st r10, 6
	live %0
	st r10, 6
	live %0
	st r10, 6
	live %0
	st r10, 6
	live %0
	st r10, 6
	live %0
	st r10, 6
	live %0
	st r10, 6
	live %0
	st r10, 6
	live %0
	st r10, 6
	live %0
	st r10, 6
	live %0
	st r10, 6
	live %0
	xor r2, r2, r2
	fork %:end
	zjmp %:live2

write:
	sti r5, r4, r3
	live %0
	zjmp %497 #PAS LA

relay2:
	zjmp %:live

end:
	live %0
	fork %:relay1
	live %0
	fork %:k2

k1:
	ld %50921974, r5
	ld %50921977, r6
	ld %1879113730, r1
	ld %4, r4
	xor r2, r2, r2
	zjmp %:write2

k2:
	ld %190055940, r5
	ld %190054660, r6
	ld %16778755, r1
	ld %0, r4
	st r10, 12
	zjmp %:write2

live2:
	fork %:relay2
live3:
	live %0
	zjmp %:live3

write2:
	st r1, 2
