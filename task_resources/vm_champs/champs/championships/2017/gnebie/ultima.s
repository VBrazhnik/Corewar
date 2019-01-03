.name "Ultima"

.comment "
Je suis l'Alpha
Je suis Le destructeur
Je suis Omega
Je suis La raison de ta peur

Ta puissance est ma puissance
Ton pouvoir est sans défence
Ma seule crainte est ta faiblesse
De mourrir d'une maladresse

Les plus puissants combattants
S'ront détruits d'un coup de dent
Les plus vifs et combatifs
S'ront finis d'un coup de griffe

Je suis un puits sans fond
Qui t'aspire dans ses tréfonds
La plaie sanglante et cruelle
Qui déchire tes organes frèles

La haine pur qui se diffuse
Sur ton code et le déturit
Prétrifié comme la méduse
Tu vivras son agonie

un poison ronge ton âme
L'obscurité noie tes flammes
Une mort glacée se répends
Le long d' tes veines et ton sang

Mais déjà tu m'appartients
Ton destin est dans mes mains
Pleur de rage, pleur de douleur
Noie tes larmes dans ton aigreur

Que mes attaques te pénêtre
A moi tu ne peux que te soumettre
Qu' ma puissance abime ton etre
Que j' te brise, petite soubrette

Mon pouvoir aspire tes forces
Aspire ton ame, et se renforce
Ma présence est ta souffrance
Ma raison d'etre ta défaite

Imposer, gifler tes tactiques
Abuser d' ton code heuristique
Dénuder ton code d'ses méthodes
Déchirer toutes tes ruses informes

Contraindre ton code aux pires outrages
Forcer, détruire tes stratégies
Tromper, corrompre tes algorithmes
Vicier, souiller tes procédés

Jusqu'a mon souffle je suis letal
Meme mon regard détruit ton âme
T'emporte au vent comme une pétale
Puis te consumme un vrai lance flammes

Tu viens pour ton exécution
Pas un combat une pendaison
Pas un proces, une mise a mort
Toi le taureau, moi l'matador

A tout jamais le championnat
Lesté de mon ADN, changera
Inséminé dans l'corps de mes proies
Etrange héritage sortira
Nées du tréfond de tes abats

Mais viens ici, entre mes griffes
Entre mes cros, t'ecorcher vif
Pour me repaitre de tes lambeaux
Pour te détruire en quelques mots

Abandonne tout idée osée,
de m'échapper, de me défier
car les roles sont deja figées.
Je Suis le Prédateur, tu est Ma Proie"


begin_coromp2:
	st				r1, :stock
	ld				%151068160,r1
	st				r1, :begin_coromp2
	ld				%506,r2
	ld				%100,r3
	live			%0
	fork            %:corruption_second2

corruption_first2:
	ld				%34144757,r4
	st				r4,r5
	ld				%50921567,r6
	st				r6,r7
	st				r6,r12
	st				r6,r13
	st				r6,r14
	st				r6,r15
	st				r4,r8
	st				r4,r9
	st				r4,r10
	ld				%167685120,r11
	ld				%4,r1
	sub             r16, r16, r16
	zjmp            %:end2

corruption_second2:
	ld		%190055681,r4
	ld		%190055937,r5
	ld		%190057473,r6
	ld		%190057729,r12
	ld		%190057985,r13
	ld		%190058241,r14
	ld		%190056193,r15
	ld		%190056449,r7
	ld		%190056705,r8
	ld		%190056961,r9
	ld		%151087617,r10
	ld		%151035392,r11
	ld		%0, r1

	zjmp	%:end2
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	aff		r2

stock:
	aff		r2
	live	%0
	live	%0
	live	%0

rebond:
	zjmp	%:atterissage
	aff		r2
	aff		r2
	aff		r2
	aff		r2
	live	%0
	live	%0
	live	%0

atterissage:
	ld		:stock,r5
	st		r5,6

llll:
	live	%1
	st		r16, :begin_coromp2
	ld		%0,r6
	ld		%0,r7
	ld		%0,r8
	ld		%0,r11
	ld		%0,r12
	ld		%0,r13
	ld		%0,r14
	ld		%0,r15
	and		r1,r1,r16
	zjmp	%:part2

part1:
	fork	%:part3
	ld		%190055684, r5
	ld		%190055684, r9
	ld		%190056708, r10
	ld		%10, r4
	sub		r16, r16, r16
	zjmp	%:end

part2:
	fork	%:part4
	ld		%84149761, r5
	ld		%151259145, r10
	st		r5, r9
	ld		%12, r4
	sub		r16, r16, r16
	zjmp	%:end

part3:
	ld		%0000, r7
	st		r5, r9
	ld		%32768000, r10
	aff		r1
	ld		%16, r4
	sub		r16, r16, r16
	zjmp	%:end

part4:
	live	%1
	ld		%151587073, r5
	st		r5, r9
	st		r9, r10
	ld		%511, r4
	sub		r16, r16, r16
	zjmp	%:end

end:
	ld		%495, r8
	add		r16, r16, r16
	sti		r10, r8, r4
	zjmp	%500
	aff		r4
	aff		r4
	aff		r4
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0

end2:
	sti		r4,r1,%505
	zjmp	%499

#deux jump a 500
