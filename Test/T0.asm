；点灯程序

.org $8000
lda	#$ff	;将65c22port A，B设置为输出
sta	#$7f02	;IO0的Port B
lda	#$ff	;
sta	#$7f03	;IO0的Port A
lda	#$00	;IO0的Port A，Port B 全输出低电平
sta	#$7f00	;向IO0的Port B写数据
lda	#$00	;
sta	#$7f01	;向IO0的Port A写数据
jmp	#$8000	;跳转到eeprom起始地址

times $7ffa-($-$$)	db 00	;中间全部填充00

.org $fffa
dw	$8000	;NMI中断向量
dw	$8000	;reset向量
dw	$8000	;IRQ/BRK向量

