# ------------------------------------------------------------------------------
# By: pzarmehr <pzarmehr@student.42.fr> ----------------------------------------
# ------------------------------------------------------------------------------

.name "Overwatch"
.comment "Reinhardt, Pharah, Mercy, Mei, Symmetra & Torbjorn"

# ------------------------------------------------------------------------------
# Defend objective A -----------------------------------------------------------
# ------------------------------------------------------------------------------

	ld  %1, r16
	st  r1, 6
mei:
	live %0
	zjmp %:mei
	st  r15, -12
	st  r16, -22

# ------------------------------------------------------------------------------
# Escort the payload -----------------------------------------------------------
# ------------------------------------------------------------------------------

	fork	%:reinhardt
pharah:
	st		r1, 6
	live	%0
	fork	%:symmetra
	st		r1, 6
	live	%0
	ld		%589824, r13				# r13 = 0x00090000 (0x00 zjmp %0)
	ld		%8, r14
	ld		%-511, r15
	ld		%0, r16
	zjmp	%:payload
payload:
	ld		%190057742, r11				# r11 = 0x0b540d0e (sti r13 r14 ..)
	ld		%269090402, r12				# r12 = 0x1009fe62 (.. r16 zjmp -414)
	ld		%0, r16
	st		r11, -501 #-491
	st		r12, -502 #-492
	#st		r1, 6
	#live	%0
	zjmp	%-511
reinhardt:
	st		r1, 6
	live	%0
	fork	%:mercy
	st		r1, 6
	live	%0
	ld		%190057743, r13				# r13 = 0x0b540d0f (sti r13 r15 ..)
	ld		%-409, r14
	ld		%-21, r15
	ld		%0, r16
	zjmp	%:payload
mercy:
	st		r1, 6
	live	%0
	ld		%269090790, r13				# r13 = 0x1009ffe6 (.. r16 zjmp %-26)
	ld		%-405, r14
	ld		%-17, r15
	ld		%0, r16
	zjmp	%:payload

# ------------------------------------------------------------------------------
# ------------------------------------------------------------------------------
# ------------------------------------------------------------------------------

	lfork	%0	#               .   B@M@B@MMM@B@B@B@MMM@@@M@B
	lfork	%0	#                   @B@B.i@MBB@B@B@@BM@::B@B@
	lfork	%0	#                   B@@@ .B@B.:@B@ :B@B  @B@O
	lfork	%0	#                     :0 r@B@  B@@ .@B@: P:
	lfork	%0	#                         vMB :@B@ :BO7
	lfork	%0	#                             ,B@B
	lfork	%0	#
	lfork	%0	#                            :PB@Bk:
	lfork	%0	#                        ,jB@@B@B@B@BBL.
	lfork	%0	#                     7G@B@B@BMMMMMB@B@B@Nr
	lfork	%0	#                 :kB@B@@@MMOMOMOMOMMMM@B@B@B1,
	lfork	%0	#             :5@B@B@B@BBMMOMOMOMOMOMOMM@@@B@B@BBu.
	lfork	%0	#          70@@@B@B@B@BXBBOMOMOMOMOMOMMBMPB@B@B@B@B@Nr
	lfork	%0	#        G@@@BJ iB@B@@  OBMOMOMOMOMOMOM@2  B@B@B. EB@B@S
	lfork	%0	#        @@BM@GJBU.  iSuB@OMOMOMOMOMOMM@OU1:  .kBLM@M@B@
	lfork	%0	#        B@MMB@B       7@BBMMOMOMOMOMOBB@:       B@BMM@B
	lfork	%0	#        @@@B@B         7@@@MMOMOMOMM@B@:         @@B@B@
	lfork	%0	#        @@OLB.          BNB@MMOMOMM@BEB          rBjM@B
	lfork	%0	#        @@  @           M  OBOMOMM@q  M          .@  @@
	lfork	%0	#        @@OvB           B:u@MMOMOMMBJiB          .BvM@B
	lfork	%0	#        @B@B@J         0@B@MMOMOMOMB@B@u         q@@@B@
	lfork	%0	#        B@MBB@v       G@@BMMMMMMMMMMMBB@5       F@BMM@B
	lfork	%0	#        @BBM@BPNi   LMEB@OMMMM@B@MMOMM@BZM7   rEqB@MBB@
	lfork	%0	#        B@@@BM  B@B@B  qBMOMB@B@B@BMOMBL  B@B@B  @B@B@M
	lfork	%0	#         J@@@@PB@B@B@B7G@OMBB.   ,@MMM@qLB@B@@@BqB@BBv
	lfork	%0	#            iGB@,i0@M@B@MMO@E  :  M@OMM@@@B@Pii@@N:
	lfork	%0	#               .   B@M@B@MMM@B@B@B@MMM@@@M@B
	lfork	%0	#                   @B@B.i@MBB@B@B@@BM@::B@B@
	lfork	%0	#                   B@@@ .B@B.:@B@ :B@B  @B@O
	lfork	%0	#                     :0 r@B@  B@@ .@B@: P:
	lfork	%0	#                         vMB :@B@ :BO7
	lfork	%0	#                             ,B@B
	lfork	%0	#
	lfork	%0	#                            :PB@Bk:
	lfork	%0	#                        ,jB@@B@B@B@BBL.
	lfork	%0	#                     7G@B@B@BMMMMMB@B@B@Nr
	lfork	%0	#                 :kB@B@@@MMOMOMOMOMMMM@B@B@B1,
	lfork	%0	#             :5@B@B@B@BBMMOMOMOMOMOMOMM@@@B@B@BBu.
	lfork	%0	#          70@@@B@B@B@BXBBOMOMOMOMOMOMMBMPB@B@B@B@B@Nr
	lfork	%0	#        G@@@BJ iB@B@@  OBMOMOMOMOMOMOM@2  B@B@B. EB@B@S
	lfork	%0	#        @@BM@GJBU.  iSuB@OMOMOMOMOMOMM@OU1:  .kBLM@M@B@
	lfork	%0	#        B@MMB@B       7@BBMMOMOMOMOMOBB@:       B@BMM@B
	lfork	%0	#        @@@B@B         7@@@MMOMOMOMM@B@:         @@B@B@
	lfork	%0	#        @@OLB.          BNB@MMOMOMM@BEB          rBjM@B
	lfork	%0	#        @@  @           M  OBOMOMM@q  M          .@  @@
	lfork	%0	#        @@OvB           B:u@MMOMOMMBJiB          .BvM@B
	lfork	%0	#        @B@B@J         0@B@MMOMOMOMB@B@u         q@@@B@
	lfork	%0	#        B@MBB@v       G@@BMMMMMMMMMMMBB@5       F@BMM@B
	lfork	%0	#        @BBM@BPNi   LMEB@OMMMM@B@MMOMM@BZM7   rEqB@MBB@
	lfork	%0	#        B@@@BM  B@B@B  qBMOMB@B@B@BMOMBL  B@B@B  @B@B@M
	lfork	%0	#         J@@@@PB@B@B@B7G@OMBB.   ,@MMM@qLB@B@@@BqB@BBv
	lfork	%0	#            iGB@,i0@M@B@MMO@E  :  M@OMM@@@B@Pii@@N:
	lfork	%0	#               .   B@M@B@MMM@B@B@B@MMM@@@M@B
	lfork	%0	#                   @B@B.i@MBB@B@B@@BM@::B@B@
	lfork	%0	#                   B@@@ .B@B.:@B@ :B@B  @B@O
	lfork	%0	#                     :0 r@B@  B@@ .@B@: P:
	lfork	%0	#                         vMB :@B@ :BO7
	lfork	%0	#                             ,B@B
	lfork	%0	#
	lfork	%0	#                            :PB@Bk:
	lfork	%0	#                        ,jB@@B@B@B@BBL.
	lfork	%0	#                     7G@B@B@BMMMMMB@B@B@Nr
	lfork	%0	#                 :kB@B@@@MMOMOMOMOMMMM@B@B@B1,
	lfork	%0	#             :5@B@B@B@BBMMOMOMOMOMOMOMM@@@B@B@BBu.
	lfork	%0	#          70@@@B@B@B@BXBBOMOMOMOMOMOMMBMPB@B@B@B@B@Nr

# ------------------------------------------------------------------------------
# Capture objective B ----------------------------------------------------------
# ------------------------------------------------------------------------------

symmetra:
	ldi		%:mei, %0, r1				# r1 = 0x01?????? (live ?? ?? ?? ..)
	ldi		%:mei, %4, r2				# r2 = 0x??09fffb (..?? zjmp %-5)
	ld		%196608, r3					# r3 = 0x00030000
	add		r2, r3, r3					# r3 = 0x??0cfffb (..?? fork %-5)
torbjorn:
	ld		%57671937, r16				# r16 = 0x03700101 (st r1 0x01 ..)
	st		r16, 511
	ld		%4278415363, r16			# r16 = 0xff037003 (.. 0xff st r3 ..)
	st		r16, 503
	ld		%33424240, r16				# r16 = 0x01fe0370 (.. 0x01fe st ..)
	st		r16, 495
	ld		%16907523, r16				# r16 = 0x0101fd03 (.. r1 0x01fd st..)
	st		r16, 487
	ld		%1879245308, r16			# r16 = 0x700301fc (.. r3 0x01fc)
	st		r16, 479
	ld		%57671937, r16				# r16 = 0x03700101 (st r1 0x01 ..)
	st		r16, 471
	ld		%4211306498, r16			# r16 = 0xfb037002 (.. 0xfb st r2..)
	st		r16, 463
	ld		%33162096, r16				# r16 = 0x01fa0370 (.. 0x01fa st ..)
	st		r16, 455
	ld		%285205251, r16				# r16 = 0x10ffe303 (.. r16 0xffe3 st ..)
	st		r16, 447
	ld		%1880162275, r16			# r16 = 0x7010ffe3 (.. r16 0xffe3)
	st		r16, 439
	ld		%57676031, r16				# r16 = 0x037010ff (st r16 0xff ..)
	st		r16, 431
	ld		%3808653328, r16			# r16 = 0xe3037010 (.. 0xe3 st r16..)
	st		r16, 423
	ld		%4293067632, r16			# r16 = 0xffe30370 (.. 0xffe3 st ..)
	st		r16, 415
	ld		%285205251, r16				# r16 = 0x10ffe303 (.. r16 0xffe3 st ..)
	st		r16, 407
	ld		%1880162275, r16			# r16 = 0x7010ffe3 (.. r16 0xffe3)
	st		r16, 399
	ld		%151110400, r16				# r16 = 0x0901c300 (zjmp %451)
	st		r16, 391
	ld		%0, r16
	zjmp	%319
