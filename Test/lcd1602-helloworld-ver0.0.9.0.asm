.org	$8000
RESET:		JMP main
			NOP
			JMP	nmi
			JMP	irq

.org	$8010
main:		JSR 6522_lcd_init
			JSR lcd1602_init
			LDA #$48				;H
			JSR lcd1602_write_d
			JSR lcd1602_is_busy
			LDA #$65				;e
			JSR lcd1602_write_d
			JSR lcd1602_is_busy
			LDA #$6C				;l
			JSR lcd1602_write_d
			JSR lcd1602_is_busy
			LDA #$6C				;l
			JSR lcd1602_write_d
			JSR lcd1602_is_busy
			LDA #$6F				;o
			JSR lcd1602_write_d
			JSR lcd1602_is_busy
			LDA #$20				
			JSR lcd1602_write_d
			JSR lcd1602_is_busy
			LDA #$57				;W
			JSR lcd1602_write_d
			JSR lcd1602_is_busy
			LDA #$6F				;o
			JSR lcd1602_write_d
			JSR lcd1602_is_busy
			LDA #$72				;r
			JSR lcd1602_write_d
			JSR lcd1602_is_busy
			LDA #$6C				;l
			JSR lcd1602_write_d
			JSR lcd1602_is_busy
			LDA #$64				;d
			JSR lcd1602_write_d
			JSR lcd1602_is_busy
			LDA #$21				;!
			JSR lcd1602_write_d
			JSR lcd1602_is_busy
			NOP
			NOP
			NOP
			NOP
			NOP
			JSR lcd1602_is_busy
			NOP
			NOP

;blink-gpio0-led
			LDA #$01		
			STA $7F03
Q8085:		LDA #$00
			STA $7F01
			JSR delay_ms
			LDA #$FF
			STA $7F01
			JSR delay_ms
			NOP
			NOP
			JMP Q8085


.org	$80a0
nmi:
			RTI

.org	$80b0
irq:
			RTI

.org	$8100
text:
		DB "Hello World!"

.org	$8200
6522_lcd_init:
			LDA #$FF
			STA $7F83	;6522-lcd-port-a-config
			LDA #$E0
			STA $7F82	;6522-lcd-port-b-config
			RTS
			
.org	$8210
lcd1602_init
			LDA #$38
			JSR lcd1602_write_c
			JSR delay_ms
			LDA #$0E
			JSR lcd1602_write_c
			JSR delay_ms
			LDA #$06
			JSR lcd1602_write_c
			JSR delay_ms
			LDA #$01
			JSR lcd1602_write_c
			JSR delay_ms
			RTS

.org	$8240
lcd1602_write_c:		;lcd_write_cmd ,send register A commamd to lcd
			STA $7F81
			LDA #$00
			STA $7F80
			LDA #$80
			STA $7F80
			LDA #$00
			STA $7F80
			NOP
			RTS

.org	$8260
lcd1602_write_d:		;lcd_write_data,send register A data to lcd
			STA $7F81
			LDA #$20
			STA $7F80
			LDA #$A0
			STA $7F80
			LDA #$20
			STA $7F80
			NOP
			RTS
			
.org	$8280
delay_ns
			AND #$FF
			BEQ Q828F
Q8284:		NOP
			SBC #$01
			BEQ Q828F
			JMP Q8284
			NOP
			NOP
			NOP
Q828F: 		RTS


.org	$82c0
lcd1602_is_busy:
			LDA #$00
			STA $7F81
			LDA #$7F
			STA $7F83
Q82CA:		LDA #$40
			STA $7F80
			LDA #$C0
			STA $7F80
			LDA $7F81
			LDA #$00
			STA $7F80
			AND #$80
			BEQ Q82E3
			JMP Q82CA
Q82E3:		LDA #$FF
			STA $7F83
			RTS


.org		#82f0
delay_us:
				LDX #$C8
				LDA #$C8
				JSR Q82C0
				DEX
				BEQ Q82FE
				NOP
				JMP Q82F2
Q82FE:			RTS


.org	$8300
delay_ms:
			LDY #$C8
			JSR delay_us
			DEY
			BEQ Q830B
			JMP Q8302
Q830B:		RTS



.org	$fffa
			DB	$8004	;nmi
			DB	$8000	;reset
			DB	$8008	;irq
