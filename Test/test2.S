;用串口输出 hello world
ACIA_DATA		=	$7fc0
ACIA_STATUS		=	$7fc1
ACIA_COMMAND	=	$7fc2
ACIA_CONTROL	=	$7fc3
	
	org	$8000
restart:
	jmp	main
NMI:
	jmp	nmi
IRQ:
	jmp	irq

;6551芯片初始化程序
acia_init:
	lda	#$0b			;no parity, no echo, no interrupt
	sta ACIA_COMMAND
	lda	#$1f			;1 stop bit, 8 data bits, 19200 baud
	sta ACIA_CONTROL
	rts

;向6551写一个字节，使用寄存器A传递参数(所要写的字节) void acia_write_byte(reg A)
acia_write_byte:
	sta ACIA_DATA
wait_txd_empty:
	lda	ACIA_STATUS
	and #$10
	beq	wait_txd_empty
	rts

;6551输出helloworld程序
acia_hello:
	pha
	txa
	pha
	ldx	#$00
acia_hello_next_char:
	lda	hello,x
	beq	acia_hello_return
	nop
	jsr	acia_write_byte
	inx
	jmp	acia_hello_next_char
acia_hello_return:
	pla
	tax
	pla
	rts

;从6551里读数据，未测试，未启用
acia_read:
wait_rxd_full:
	lda	ACIA_STATUS
	and #$08
	beq	wait_rxd_full
	lda	ACIA_DATA
	jmp	acia_write_byte
acia_read_return:
	rts

;主函数入口
main:
	jsr	acia_init
loop:
	nop
	jsr	acia_hello
	jmp	loop


nmi:
	rti
irq:
	rti

;字符串
hello:
	text "hello,world!"


vector:
	org	$fffa
	word	NMI
	word	restart
	word	IRQ