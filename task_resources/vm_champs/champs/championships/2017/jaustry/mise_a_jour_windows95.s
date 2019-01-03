.name "mise_a_jour_windows95"
.comment "Votre version de windows est obselete, votre mémoire vas être mise jour, veuillez ne pas eteindre vore ordinateur au risque de voir toutes vos donnees se faire ecrasées"

begin:
live            %1
ld              %252645135,r2
ld				%57672449,r3
ld				%16777216,r5
fork            %:begin_coromp2
fork            %:lefork
sub             r4,r4,r4
zjmp            %:live3
live            %1
fork            %-511
st              r4, -100
st              r4, -100
st              r4, -100
st              r4, -100
st              r4, -100
st              r4, -100
st              r4, -100
st              r4, -100
st              r4, -100
st              r4, -100
st              r4, -100
st              r4, -100
st              r4, -100
st              r4, -100
st              r4, -100
st              r4, -100
st              r4, -100
st              r4, -100
st              r4, -100
st              r4, -100
st              r4, -100
st              r4, -100
st              r4, -100
st              r4, -100
st              r4, -100
st              r4, -100
live3:
live    %1
st      r2, -511
st      r2, -510
st      r2, -509
st      r2, -508
st      r2, -507
st      r2, -506
st      r2, -505
st      r2, -504
st      r2, -503
st      r2, -502
st      r2, -501
st      r2, -500
st      r2, -499
st      r2, -498
st      r2, -497
st      r2, -496
st      r2, -495
st      r2, -494
st      r2, -493
st      r2, -492
live2:
live    %1;
st      r16, -262
st      r16, -245
st      r16, -244
st      r16, -243
st      r16, -242
st      r16, -240
st      r16, -238
st      r16, -236
st      r16, -234
st      r16, -232
st      r16, -230
st      r16, -228
st      r16, -226
st      r16, -224
st      r16, -222
st      r16, -220
st      r16, -218
st      r16, -216
st      r16, -214
st      r16, -212
zjmp    %:live3
lefork:
st              r1, -212
st              r1, 69
st              r1, -117
st              r16, -15
st              r16, -15
st              r16, -15
ld				%1879245026, r4
ld				%5,r10
live1:
live    %1;
fork    %:live3
live4:
live    %1
fork    %:live1
live    %1
fork    %:machinerie
sub     r4, r4, r4
live5:
live    %1
zjmp    %-5
begin_coromp2:
live            %1
ld              %495,r08
ld              %16,r11
ld				%-9,r12
ld				%103, r13
ld				%269025348, r14 #ld	%369885440, r14 269222120
ld				%0,r10
fork 			%:corruption_second
ld				%4,r10
corruption_first:
ld              %185139211,r9
ld              %134808042,r7
ld              %134808042,r6
ld              %134808042,r15
sub				r16, r16, r16
zjmp			%:end1
corruption_second:
ld              %190056714,r9
ld              %190056714,r7
ld              %190056202,r6
ld				%190055946,r15
zjmp			%:end1
end1:
add		r13, r12, r13
sti     r15,r10,r13 #102
live    %1
add		r14, r12, r14
st		r14, -109 #-67
st		r13,-121 #-79
st		r14, 9
and		r16, r16, r16
lancement:
zjmp    %258
live    %1
zjmp    %:end1
machinerie:
fork    %:begin_coromp2
live    %0
add		r4, r10, r4
st		r4, 6
st		r3, 200
and		r16, r16, r16
zjmp	%-25

