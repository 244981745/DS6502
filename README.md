# DS6502
8bit computer system base on W65C02</br>

能力不够，用的自动布线，有不合理的地方请issues一下，尽管我可能改不动</br>

待升级：</br>
<s>1.CPU地址线总线和数据总线引出</s></br>
2.接入SD卡</br>

基础功能完善：</br>
1.点亮GPIO0和GPIO1   [√]</br>
2.lcd1602驱动        [-]</br>
3.6551串口驱动       [√]</br>
4.bootloader        [-]</br>

2020-10-26：
调通STC15写EEPROM</br>
待完成：PC上位机</br>

2020-11-8：
已完成部分上位机，已调试一个用命令行下串口与STC通信的简单DEMO，没有gui不是挺满意，</br>
趁机把windows api编程学习了一下，开始着手写，只是vs2019用着非常不顺手，经常会报</br>
奇怪的错误，直接用纯api构建界面。</br>

2021-1-26：</br>
改用ATmega EEPROM开源下载器：https://oshwhub.com/Oleg533/atmega-eeprom-programmer</br>
安装python后，需要pip install pySerial</br>

2021-2-6：</br>
增加点灯程序</br>
增加关于地址映射的说明文档</br>
增加挂载在0x7f00-0x7fff上的65c22的说明文档</br>

2021-2-9: </br>
增加整理的指令表 </br>

2021-3-13:</br>
硬件调整：</br>
    1:复位电路调整，ne555的4脚经3.3K电阻到5V，撤销R3,REST按键与ne555的2脚相连</br>
    2:撤销CPU的IRQ连接</br>
    3:撤销R6551A的C8，C7改22p为27p</br>
    4:R6551A的RS0改与CPU的addr0相连，R6551A的RS1改与CPU的addr1相连</br>
    5:R6551A的DSR接地</br>
    6:R6551A的晶振改1.8432Mhz</br>
    7:EEPROM的OE脚接地
    
</br>
参考：</br>
1.https://eater.net/6502</br>
2.https://github.com/grappendorf/homecomputer-6502</br>
3.https://www.grappendorf.net/projects/6502-home-computer/#table-of-contents</br>
4.http://wilsonminesco.com/6502primer/</br>

