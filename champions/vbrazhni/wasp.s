.name		"Lisbeth Salander"
.comment	"I will hack you"

# Executable code

ld	%1,			r2	# Store operator code of live
ld	%151122944,	r3	# Store zjmp %500
ld	%0,			r16	# Change carry to 1

st	r2, 500
st	r1, 499
st	r3, 498
