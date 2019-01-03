.name "🍌🍍 Le Pet de Nonne arrangé 🍍🍌"

.comment " Il est également appelé « beignet de vent », « beignet venteux » ou « soupir de nonne », « pet de putain », « pet de vieille » dans l'Aveyron.

Ingrédients : 150 g de farine, 3 oeufs, 50 g de beurre, 40 g de sucre, du Rhum, Fleur d'oranger, 1 pincée de sel, Huile de friture (tournesol ou arachide).

Etape 1
Mettre 1/4 l d'eau à chauffer avec le beurre, le sel, le sucre, quand çà bout retirer du feu, ajouter d'un seul coup la farine, mélanger énergiquement.
🍹 Buvez un verre de Rhum.

Etape 2
Remettre sur le feu, mélanger jusqu'à ce que la pâte se détache du fond de la casserole.
🍹 Buvez un verre de Rhum.

Etape 3
Hors du feu ajouter les œufs, un par un en battant fortement puis ajouter le parfum.
🍹 Buvez un verre de Rhum.

Etape 4
Faire chauffer la friture, y mettre la pâte par morceaux gros comme des noix.
🍹 Buvez un verre de Rhum.

Etape 5
Retournez les pets s'ils ne le font pas d'eux mêmes.
🍹 Buvez un verre de Rhum.

Etape 6
Lorsqu'ils sont dorés, les égoutter, les saupoudrer de sucre et servir
🍹 Buvez un verre de Rhum.

Note de l'auteur
les beignets ne gonfleront bien que si l'on a vigoureusement battu la pâte en ajoutant les oeufs.
🍶 Buvez un verre d'eau."


vanille_banane:
	zjmp			%:piment_gingembre
	zjmp			%:piment_gingembre
	zjmp			%:piment_gingembre
	ld				%506,r2


ananas_coco:
	fork            %:piment_gingembre
	ld				%34144757,r4
	st				r4,r5
	ld				%67305472,r6
	ld				%262144,r9
	ld				%4,r1
	ld				%0,r16
	zjmp            %:boire_de_l_eau
	live			%3134197165
	live			%3134197165
	live			%3134197165
	zjmp            %:boire_de_l_eau
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165

piment_gingembre:
	ld				%190055681,r4
	ld				%190055937,r5
	ld				%57673984,r6
	ld				%134443017,r9
	st				r1, 345
	ld				%0, r1

	zjmp			%:boire_de_l_eau
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	aff				r2

boire_de_l_eau:
	st		r1, -333
	sti		r4,r1,%505
	live 	%42
	zjmp	%494
