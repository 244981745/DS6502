;2021-12-13 实现软件延时,测得一个脉冲约21.3ms，也就是调用20次延时函数，约得10.6ms
IO_0_SETA	=	$7f03
IO_0_SETB	=	$7f02
IO_0_PORTA	=	$7f01
IO_0_PORTB	=	$7f00

IO_1_SETA	=	$7f83
IO_1_SETB	=	$7f82
IO_1_PORTA	=	$7f81
IO_1_PORTB	=	$7f80


	org	$8000
Start:	
Set_gpio0_portA_out_put:
	lda	#$ff
	sta	IO_0_SETA
Set_gpio0_portB_out_put:	
	lda	#$ff
	sta	IO_0_SETB
	jmp	main

;延时0.5ms函数
delay_ms:
	pha
	txa
	pha
	tya
	pha
	nop
	ldx	#$70
delay_ms_loop:
	nop
	dex
	beq	delay_ms_return
	jmp	delay_ms_loop
	nop
	nop
delay_ms_return:
	nop
	pla
	tay
	pla
	tax
	pla
	rts

;子函数测试
fun_sun:
	nop
	ldx	#$70
fun_sun_loop:
	nop
	dex
	beq	fun_sun_return
	jmp	fun_sun_loop
	nop
	nop
fun_sun_return:
	nop
	rts

;延时Nms函数，使用Y寄存器传参
delay_n_ms:
	pha
	txa
	pha
	tya
	pha
delay_n_ms_loop:
	nop
	jsr	delay_ms
	dey
	beq	delay_n_ms_return
	jmp	delay_n_ms_loop
	nop
delay_n_ms_return:
	nop
	pla
	tay
	pla
	tax
	pla
	rts

;主函数入口
main:
loop:
	lda	#$00
	sta	IO_0_PORTA
	ldy	#$14
	jsr	delay_n_ms
;	jsr	fun_sun
;	jsr	delay_ms
;	sta	IO_0_PORTB
;	nop
	lda	#$ff
	sta IO_0_PORTA
	ldy	#$14
	jsr	delay_n_ms
;	jsr	fun_sun
;	jsr	delay_ms
;	sta IO_0_PORTB
;	nop
	jmp	loop





	org		$fffa
	word	$8000
	word	Start
	word	$8000