.name       "Wave"
.comment    "I'm coming"

#first ini feast live

del3:   sti     r1,     %:l3,   %1

#put somme magic value

magic:  ld      %57672449,  r3          #magic val 0370301 ->> 03700301

#let's go !!
        st      r3,         450
l3:     live    %0
        fork    %430
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442
        st      r3,         442

#set all live and destor setter
poi:    ld      %655346,    r8
        sti     r8,     %:del3, %0
del:    sti     r1,     %:l1,   %1
        sti     r8,     %:del,  %0
del2:   sti     r1,     %:fl,   %1
        sti     r1,     %:del2, %2
del4:   sti     r1,     %:l2,   %1
        sti     r1,     %:del4, %2
del5:   sti     r1,     %:l4,   %1
        sti     r1,     %:del5, %2

#first liver
l1:     live    %0
        zjmp    %:l1

#seconde liver
l2:     live    %0
        zjmp    %:l2

#set zjmp cond
        and         %0,     %0,         r9
        
#make live
fl:     live    %0
        fork    %:fl
        live    %-1000
        fork    %:l1
        live    %-1000
        fork    %:l2
        live    %-1000
        fork    %:l4
        live    %-1000
        zjmp    %:fl
l4:     live    %0
        zjmp    %:l3
