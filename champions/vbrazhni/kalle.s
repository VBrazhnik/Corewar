.name		"Mikael Blomkvist"
.comment	"Hans-Erik Wennerstrom is a liar!"

# Executable code

ld	%1,			r2	# Store operator code of live
ld	%655250,	r4	# Store zjmp with arguments
ld	%786932,	r5	# Store fork with arguments
ld	%655275,	r6	# Store zjmp with arguments
ld	%0,			r16	# Change carry to 1

sti	r1, %:sweden,		%1
sti	r1, %:uppsala,		%1
sti	r1, %:hedestad,		%1
sti	r1, %:malmo,		%1
sti	r1, %:stockholm,	%1
sti	r1, %:slussen,		%1
sti	r1, %:gotgatan,		%1
sti	r1, %:mosebacke,	%1
sti	r1, %:bellmansgatan,%1
sti	r1, %:lundagatan,	%1
sti	r1, %:hedeby,		%1
sti	r1, %:gothenburg,	%1

sweden:
	live	%42
	fork	%:stockholm
uppsala:
	live	%42
	fork	%-205
hedestad:
	live	%42
	fork	%:hedeby
malmo:
	live	%42
	fork	%:sweden
	zjmp	%:sweden

stockholm:
	live	%42
	st		r1, -39
	st		r2, -48
	st		r1, -57
	st		r2, -66
	st		r1, -75
	st		r2, -84
	st		r1, -93
	st		r2, -102
	st		r1, -111
	st		r2, -120
slussen:
	live	%42
	st		r1, -134
	st		r2, -143
	st		r1, -152
	st		r2, -161
	st		r1, -170
	st		r2, -179
	st		r1, -188
	st		r2, -197
	st		r1, -206
	st		r2, -215
gotgatan:
	live	%42
	st		r1, -229
	st		r2, -238
	st		r1, -247
	st		r2, -256
	st		r1, -265
	st		r2, -274
	st		r1, -283
	st		r2, -292
	st		r1, -301
	st		r2, -310
mosebacke:
	live	%42
	st		r1, -324
	st		r2, -333
	st		r1, -342
	st		r2, -351
	st		r1, -360
	st		r2, -369
	st		r1, -378
	st		r2, -387
	st		r1, -396
	st		r2, -405
bellmansgatan:
	live	%42
	st		r1, -419
	st		r2, -428
	st		r1, -437
	st		r2, -446
	st		r1, -455
	st		r2, -464
	st		r1, -473
	st		r2, -482
	st		r1, -491
	st		r2, -500
lundagatan:
	live	%42
	zjmp	%:stockholm

hedeby:
	live	%42
	st		r2, 105
	st		r1, 104
	st		r2, 103
	st		r1, 102
	st		r2, 101
	st		r1, 100
	st		r2, 99
	st		r1, 98
	st		r2, 97
	st		r1, 96
gothenburg:
	live	%42
	st		r2, 90
	st		r1, 89
	st		r2, 88
	st		r1, 87
	st		r2, 86
	st		r1, 85
	st		r2, 84
	st		r1, 83
	st		r5, 82
	st		r6, 81
