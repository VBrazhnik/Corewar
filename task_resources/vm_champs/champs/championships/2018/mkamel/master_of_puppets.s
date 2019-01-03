.name "The Last Shadow Puppets Master"

.comment "Everything you've come to expect..."

master_prep:
#un live pour survivre le premier cycle to die
live	%3134197165
st              r1, -4

#Prep du zjmp pour revenir sur master_prep
ld      %151121408, r2
st      r2, -511

#Modif pour futur zjmp sur ultima_legacy
ld      %151059712, r2
st      r2, -24

#Prep des futurs live
st      r1, r5 
st      r1, 369
st      r1, 216
st      r1, 175

#effacer ses traces de r1
ld      %47186232, r2
st      r2, -21
ld      %17760421, r2
st      r2, -29
st      r2, -29
st      r2, -29

#Load des registres qui serviront à zjmp
ld      %151037440, r15
ld      %151038720, r13
ld      %151040000, r10

#Preparation du st r3 à 511
ld      %57675777, r2
ld      %4278415376, r16
ld      %33489776, r4
ld      %268566275, r5
ld      %1880097279, r6

#Prep des relais, ex 7>8>9>10>zjmp 
ld      %57673729, r7
ld      %57673985, r8
ld      %57674241, r9
ld      %57674753, r11
ld      %57675009, r12
ld      %57675521, r14
ld      %0, r3
zjmp    %:mach_1



#gonfler le fichier pour ecrire plus loin
faire_le_plein:
zjmp    %:ultima_legacy
fork    %:zork_legacy
zjmp    %:ultima_legacy
fork    %:zork_legacy
zjmp    %:ultima_legacy
fork    %:zork_legacy
zjmp    %:ultima_legacy
fork    %:zork_legacy
zjmp    %:ultima_legacy



#on aime tous zork
zork_legacy:
live	%3134197165    
ld		%0,r6
zjmp    %:zork_legacy

fork    %:zork_legacy
zjmp    %:ultima_legacy
fork    %:zork_legacy
zjmp    %:ultima_legacy
fork    %:zork_legacy
zjmp    %:ultima_legacy
fork    %:zork_legacy



#parce qu ultima etait juste magique
ultima_legacy: 
live	%3134197165    
ld      -4, r5 
ld		%167751168,r6
st      r6, -80
ld		%0,r6
fork    %:part2
live	%3134197165      

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
	ld		%0, r7
	st		r5, r9
	ld		%32768000, r10
	aff		r1
	ld		%16, r4
	sub		r16, r16, r16
	zjmp	%:end

part4:
    live	%3134197165      
	ld		%3134197165, r5
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


faire_le_vide:
fork    %:zork_legacy
zjmp    %:ultima_legacy
fork    %:zork_legacy
zjmp    %:ultima_legacy
fork    %:zork_legacy


mach_1:
#ecritue de st r3 a 511 en boucle
ld              %4278415362, r3
st              r2, 511
st              r16, 510
st              r4, 509
st              r5, 508
st              r6, 507
st              r2, 506
st              r3, 505
st              r4, 504
st              r5, 503
st              r6, 502
st              r2, 501
st              r16, 500
st              r4, 499
st              r5, 498
st              r6, 497
st              r2, 496
st              r16, 495
st              r4, 494
st              r5, 493
st              r6, 492

#ecriture des futurs relais de st
ld              %33489776, r2
#ld              %57672193, r4
st              r7, 484
st              r2, 482
st              r11, 479
st              r2, 477
st              r14, 474
st              r2, 472
ld              %151101440, r2
st              r2, 462

#modif des valeurs de registre avant de sauter sur les st
ld      %57672705, r2
ld      %57672961, r4
ld      %57673217, r5
ld      %151125760, r6

#r16 ne fera que se répliquer lui même
ld              %57675777, r16

ld              %0, r3

top:
zjmp    %320
