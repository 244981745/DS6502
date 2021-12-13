;2021-12-13 测试gpio，测得一个脉冲为13.6us
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

loop:
	lda	#$00
	sta	IO_0_PORTA
	sta	IO_0_PORTB
	nop
	lda	#$ff
	sta IO_0_PORTA
	sta IO_0_PORTB
	nop
	jmp	loop

	org		$fffa
	word	$8000
	word	Start
	word	$8000