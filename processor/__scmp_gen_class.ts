class SCMPOpcodes {
function opcode00():void { 
    ;;this.cycles = this.cycles + 8;
}
function opcode01():void { 
    this.t16 = this.ac;this.ac = this.e;this.e = this.t16;this.cycles = this.cycles + 7;
}
function opcode02():void { 
    this.cyl = 0;this.cycles = this.cycles + 5;
}
function opcode03():void { 
    this.cyl = 1;this.cycles = this.cycles + 5;
}
function opcode04():void { 
    this.status = this.status & 0xF7;;this.cycles = this.cycles + 6;
}
function opcode05():void { 
    this.status = this.status | 8;;this.cycles = this.cycles + 6;
}
function opcode06():void { 
    this.status = (this.status & 0x0F)+(this.senseA() ? 0x10:0x00)+(this.senseB() ? 0x20:0x00)+(this.ov ? 0x40:0x00)+(this.cyl ? 0x80:0x00);;this.ac = this.status;this.cycles = this.cycles + 5;
}
function opcode07():void { 
    this.status = this.ac;this.status = (this.status & 0x0F)+(this.senseA() ? 0x10:0x00)+(this.senseB() ? 0x20:0x00)+(this.ov ? 0x40:0x00)+(this.cyl ? 0x80:0x00);;this.setFlags(this.status & 7);this.cycles = this.cycles + 6;
}
function opcode08():void { 
    ;;this.cycles = this.cycles + 5;
}
function opcode09():void { 
    ;
}
function opcode0a():void { 
    ;
}
function opcode0b():void { 
    ;
}
function opcode0c():void { 
    ;
}
function opcode0d():void { 
    ;
}
function opcode0e():void { 
    ;
}
function opcode0f():void { 
    this.status = (this.status & 0x0F)+(this.senseA() ? 0x10:0x00)+(this.senseB() ? 0x20:0x00)+(this.ov ? 0x40:0x00)+(this.cyl ? 0x80:0x00);;this.cycles = this.cycles + 0;
}
function opcode10():void { 
    ;
}
function opcode11():void { 
    ;
}
function opcode12():void { 
    ;
}
function opcode13():void { 
    ;
}
function opcode14():void { 
    ;
}
function opcode15():void { 
    ;
}
function opcode16():void { 
    ;
}
function opcode17():void { 
    ;
}
function opcode18():void { 
    ;
}
function opcode19():void { 
    this.serialOut(this.e & 1);this.e = (this.e >> 1) | ((this.serialIn() != 0) ? 0x80:0x00);;this.cycles = this.cycles + 5;
}
function opcode1a():void { 
    ;
}
function opcode1b():void { 
    ;
}
function opcode1c():void { 
    this.ac = this.ac >> 1;this.cycles = this.cycles + 5;
}
function opcode1d():void { 
    this.ac = (this.ac >> 1) | (this.cyl << 7);this.cycles = this.cycles + 5;
}
function opcode1e():void { 
    this.ac = ((this.ac >> 1) | (this.ac << 7)) & 0xFF;this.cycles = this.cycles + 5;
}
function opcode1f():void { 
    this.t16 = this.ac | (this.cyl << 8);this.ac = (this.t16 >> 1) & 0xFF;this.cyl = this.t16 & 1;this.cycles = this.cycles + 5;
}
function opcode20():void { 
    ;
}
function opcode21():void { 
    ;
}
function opcode22():void { 
    ;
}
function opcode23():void { 
    ;
}
function opcode24():void { 
    ;
}
function opcode25():void { 
    ;
}
function opcode26():void { 
    ;
}
function opcode27():void { 
    ;
}
function opcode28():void { 
    ;
}
function opcode29():void { 
    ;
}
function opcode2a():void { 
    ;
}
function opcode2b():void { 
    ;
}
function opcode2c():void { 
    ;
}
function opcode2d():void { 
    ;
}
function opcode2e():void { 
    ;
}
function opcode2f():void { 
    ;
}
function opcode30():void { 
    this.t16 = this.ac;this.ac = this.p0 & 0xFF;this.p0 = (this.t16 & 0xFF)|(this.p0 & 0xFF00);this.cycles = this.cycles + 8;
}
function opcode31():void { 
    this.t16 = this.ac;this.ac = this.p1 & 0xFF;this.p1 = (this.t16 & 0xFF)|(this.p1 & 0xFF00);this.cycles = this.cycles + 8;
}
function opcode32():void { 
    this.t16 = this.ac;this.ac = this.p2 & 0xFF;this.p2 = (this.t16 & 0xFF)|(this.p2 & 0xFF00);this.cycles = this.cycles + 8;
}
function opcode33():void { 
    this.t16 = this.ac;this.ac = this.p3 & 0xFF;this.p3 = (this.t16 & 0xFF)|(this.p3 & 0xFF00);this.cycles = this.cycles + 8;
}
function opcode34():void { 
    this.t16 = this.ac;this.ac = (this.p0 >> 8) & 0xFF;this.p0 = (this.p0 & 0x00FF)|(this.t16 << 8);this.cycles = this.cycles + 8;
}
function opcode35():void { 
    this.t16 = this.ac;this.ac = (this.p1 >> 8) & 0xFF;this.p1 = (this.p1 & 0x00FF)|(this.t16 << 8);this.cycles = this.cycles + 8;
}
function opcode36():void { 
    this.t16 = this.ac;this.ac = (this.p2 >> 8) & 0xFF;this.p2 = (this.p2 & 0x00FF)|(this.t16 << 8);this.cycles = this.cycles + 8;
}
function opcode37():void { 
    this.t16 = this.ac;this.ac = (this.p3 >> 8) & 0xFF;this.p3 = (this.p3 & 0x00FF)|(this.t16 << 8);this.cycles = this.cycles + 8;
}
function opcode38():void { 
    ;
}
function opcode39():void { 
    ;
}
function opcode3a():void { 
    ;
}
function opcode3b():void { 
    ;
}
function opcode3c():void { 
    this.t16 = this.p0;this.p0 = this.p0;this.p0 = this.t16;this.cycles = this.cycles + 7;
}
function opcode3d():void { 
    this.t16 = this.p0;this.p0 = this.p1;this.p1 = this.t16;this.cycles = this.cycles + 7;
}
function opcode3e():void { 
    this.t16 = this.p0;this.p0 = this.p2;this.p2 = this.t16;this.cycles = this.cycles + 7;
}
function opcode3f():void { 
    this.t16 = this.p0;this.p0 = this.p3;this.p3 = this.t16;this.cycles = this.cycles + 7;
}
function opcode40():void { 
    this.ac = this.e;this.cycles = this.cycles + 6;
}
function opcode41():void { 
    ;
}
function opcode42():void { 
    ;
}
function opcode43():void { 
    ;
}
function opcode44():void { 
    ;
}
function opcode45():void { 
    ;
}
function opcode46():void { 
    ;
}
function opcode47():void { 
    ;
}
function opcode48():void { 
    ;
}
function opcode49():void { 
    ;
}
function opcode4a():void { 
    ;
}
function opcode4b():void { 
    ;
}
function opcode4c():void { 
    ;
}
function opcode4d():void { 
    ;
}
function opcode4e():void { 
    ;
}
function opcode4f():void { 
    ;
}
function opcode50():void { 
    this.ac = this.ac & this.e;this.cycles = this.cycles + 6;
}
function opcode51():void { 
    ;
}
function opcode52():void { 
    ;
}
function opcode53():void { 
    ;
}
function opcode54():void { 
    ;
}
function opcode55():void { 
    ;
}
function opcode56():void { 
    ;
}
function opcode57():void { 
    ;
}
function opcode58():void { 
    this.ac = this.ac | this.e;this.cycles = this.cycles + 6;
}
function opcode59():void { 
    ;
}
function opcode5a():void { 
    ;
}
function opcode5b():void { 
    ;
}
function opcode5c():void { 
    ;
}
function opcode5d():void { 
    ;
}
function opcode5e():void { 
    ;
}
function opcode5f():void { 
    ;
}
function opcode60():void { 
    this.ac = this.ac ^ this.e;this.cycles = this.cycles + 6;
}
function opcode61():void { 
    ;
}
function opcode62():void { 
    ;
}
function opcode63():void { 
    ;
}
function opcode64():void { 
    ;
}
function opcode65():void { 
    ;
}
function opcode66():void { 
    ;
}
function opcode67():void { 
    ;
}
function opcode68():void { 
    this.mbr = this.e;			this.t16 = (this.ac & 0x0F)+(this.mbr & 0x0F)+this.cyl;			this.cyl = 0;			if (this.t16 > 9) this.t16 = this.t16 + 6;			this.t16 = this.t16 + (this.ac & 0xF0) + (this.mbr & 0xF0);			if (this.t16 > 0x99) { this.t16 = this.t16 + 0x60;this.cyl = 1; }			this.ac = this.t16 & 0xFF;		;this.cycles = this.cycles + 11;
}
function opcode69():void { 
    ;
}
function opcode6a():void { 
    ;
}
function opcode6b():void { 
    ;
}
function opcode6c():void { 
    ;
}
function opcode6d():void { 
    ;
}
function opcode6e():void { 
    ;
}
function opcode6f():void { 
    ;
}
function opcode70():void { 
    this.mbr = this.e;this.t16 = this.ac + this.mbr + this.cyl;this.ac = (this.t16 & 0xFF);this.cyl = (this.t16 >> 8) & 1;;this.cycles = this.cycles + 7;
}
function opcode71():void { 
    ;
}
function opcode72():void { 
    ;
}
function opcode73():void { 
    ;
}
function opcode74():void { 
    ;
}
function opcode75():void { 
    ;
}
function opcode76():void { 
    ;
}
function opcode77():void { 
    ;
}
function opcode78():void { 
    this.mbr = this.e ^ 0xFF;this.t16 = this.ac + this.mbr + this.cyl;this.ac = (this.t16 & 0xFF);this.cyl = (this.t16 >> 8) & 1;;this.cycles = this.cycles + 8;
}
function opcode79():void { 
    ;
}
function opcode7a():void { 
    ;
}
function opcode7b():void { 
    ;
}
function opcode7c():void { 
    ;
}
function opcode7d():void { 
    ;
}
function opcode7e():void { 
    ;
}
function opcode7f():void { 
    ;
}
function opcode80():void { 
    ;
}
function opcode81():void { 
    ;
}
function opcode82():void { 
    ;
}
function opcode83():void { 
    ;
}
function opcode84():void { 
    ;
}
function opcode85():void { 
    ;
}
function opcode86():void { 
    ;
}
function opcode87():void { 
    ;
}
function opcode88():void { 
    ;
}
function opcode89():void { 
    ;
}
function opcode8a():void { 
    ;
}
function opcode8b():void { 
    ;
}
function opcode8c():void { 
    ;
}
function opcode8d():void { 
    ;
}
function opcode8e():void { 
    ;
}
function opcode8f():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();this.delay4cycles = this.ac/2 + 128 * this.mbr;this.ac = 0xFF;this.cycles = this.cycles + 13;
}
function opcode90():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p0+this.t16) & 0xFFFF;;this.p0 = this.mar;;this.cycles = this.cycles + 11;
}
function opcode91():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p1+this.t16) & 0xFFFF;;this.p0 = this.mar;;this.cycles = this.cycles + 11;
}
function opcode92():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p2+this.t16) & 0xFFFF;;this.p0 = this.mar;;this.cycles = this.cycles + 11;
}
function opcode93():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p3+this.t16) & 0xFFFF;;this.p0 = this.mar;;this.cycles = this.cycles + 11;
}
function opcode94():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p0+this.t16) & 0xFFFF;;if ((this.ac & 0x80) == 0x00) { this.p0 = this.mar; };this.cycles = this.cycles + 10;
}
function opcode95():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p1+this.t16) & 0xFFFF;;if ((this.ac & 0x80) == 0x00) { this.p0 = this.mar; };this.cycles = this.cycles + 10;
}
function opcode96():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p2+this.t16) & 0xFFFF;;if ((this.ac & 0x80) == 0x00) { this.p0 = this.mar; };this.cycles = this.cycles + 10;
}
function opcode97():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p3+this.t16) & 0xFFFF;;if ((this.ac & 0x80) == 0x00) { this.p0 = this.mar; };this.cycles = this.cycles + 10;
}
function opcode98():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p0+this.t16) & 0xFFFF;;if (this.ac == 0x00) { this.p0 = this.mar; };this.cycles = this.cycles + 10;
}
function opcode99():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p1+this.t16) & 0xFFFF;;if (this.ac == 0x00) { this.p0 = this.mar; };this.cycles = this.cycles + 10;
}
function opcode9a():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p2+this.t16) & 0xFFFF;;if (this.ac == 0x00) { this.p0 = this.mar; };this.cycles = this.cycles + 10;
}
function opcode9b():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p3+this.t16) & 0xFFFF;;if (this.ac == 0x00) { this.p0 = this.mar; };this.cycles = this.cycles + 10;
}
function opcode9c():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p0+this.t16) & 0xFFFF;;if (this.ac != 0x00) { this.p0 = this.mar; };this.cycles = this.cycles + 10;
}
function opcode9d():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p1+this.t16) & 0xFFFF;;if (this.ac != 0x00) { this.p0 = this.mar; };this.cycles = this.cycles + 10;
}
function opcode9e():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p2+this.t16) & 0xFFFF;;if (this.ac != 0x00) { this.p0 = this.mar; };this.cycles = this.cycles + 10;
}
function opcode9f():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p3+this.t16) & 0xFFFF;;if (this.ac != 0x00) { this.p0 = this.mar; };this.cycles = this.cycles + 10;
}
function opcodea0():void { 
    ;
}
function opcodea1():void { 
    ;
}
function opcodea2():void { 
    ;
}
function opcodea3():void { 
    ;
}
function opcodea4():void { 
    ;
}
function opcodea5():void { 
    ;
}
function opcodea6():void { 
    ;
}
function opcodea7():void { 
    ;
}
function opcodea8():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p0+this.t16) & 0xFFFF;;this.read();this.ac = (this.mbr + 1) & 0xFF;this.mbr = this.ac;this.write();this.cycles = this.cycles + 22;
}
function opcodea9():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p1+this.t16) & 0xFFFF;;this.read();this.ac = (this.mbr + 1) & 0xFF;this.mbr = this.ac;this.write();this.cycles = this.cycles + 22;
}
function opcodeaa():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p2+this.t16) & 0xFFFF;;this.read();this.ac = (this.mbr + 1) & 0xFF;this.mbr = this.ac;this.write();this.cycles = this.cycles + 22;
}
function opcodeab():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p3+this.t16) & 0xFFFF;;this.read();this.ac = (this.mbr + 1) & 0xFF;this.mbr = this.ac;this.write();this.cycles = this.cycles + 22;
}
function opcodeac():void { 
    ;
}
function opcodead():void { 
    ;
}
function opcodeae():void { 
    ;
}
function opcodeaf():void { 
    ;
}
function opcodeb0():void { 
    ;
}
function opcodeb1():void { 
    ;
}
function opcodeb2():void { 
    ;
}
function opcodeb3():void { 
    ;
}
function opcodeb4():void { 
    ;
}
function opcodeb5():void { 
    ;
}
function opcodeb6():void { 
    ;
}
function opcodeb7():void { 
    ;
}
function opcodeb8():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p0+this.t16) & 0xFFFF;;this.read();this.ac = (this.mbr - 1) & 0xFF;this.mbr = this.ac;this.write();this.cycles = this.cycles + 22;
}
function opcodeb9():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p1+this.t16) & 0xFFFF;;this.read();this.ac = (this.mbr - 1) & 0xFF;this.mbr = this.ac;this.write();this.cycles = this.cycles + 22;
}
function opcodeba():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p2+this.t16) & 0xFFFF;;this.read();this.ac = (this.mbr - 1) & 0xFF;this.mbr = this.ac;this.write();this.cycles = this.cycles + 22;
}
function opcodebb():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p3+this.t16) & 0xFFFF;;this.read();this.ac = (this.mbr - 1) & 0xFF;this.mbr = this.ac;this.write();this.cycles = this.cycles + 22;
}
function opcodebc():void { 
    ;
}
function opcodebd():void { 
    ;
}
function opcodebe():void { 
    ;
}
function opcodebf():void { 
    ;
}
function opcodec0():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p0+this.t16) & 0xFFFF;;this.read();this.ac = this.mbr;this.cycles = this.cycles + 18;
}
function opcodec1():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p1+this.t16) & 0xFFFF;;this.read();this.ac = this.mbr;this.cycles = this.cycles + 18;
}
function opcodec2():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p2+this.t16) & 0xFFFF;;this.read();this.ac = this.mbr;this.cycles = this.cycles + 18;
}
function opcodec3():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p3+this.t16) & 0xFFFF;;this.read();this.ac = this.mbr;this.cycles = this.cycles + 18;
}
function opcodec4():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();this.ac = this.mbr;this.cycles = this.cycles + 10;
}
function opcodec5():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;if (this.mbr & 0x80) { this.p1 = (this.p1+(this.mbr|0xFF00)) & 0xFFFF; this.mar = this.p1; } else { this.mar = this.p1;  this.p1 = (this.p1+this.mbr) & 0xFFFF; };this.read();this.ac = this.mbr;this.cycles = this.cycles + 18;
}
function opcodec6():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;if (this.mbr & 0x80) { this.p2 = (this.p2+(this.mbr|0xFF00)) & 0xFFFF; this.mar = this.p2; } else { this.mar = this.p2;  this.p2 = (this.p2+this.mbr) & 0xFFFF; };this.read();this.ac = this.mbr;this.cycles = this.cycles + 18;
}
function opcodec7():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;if (this.mbr & 0x80) { this.p3 = (this.p3+(this.mbr|0xFF00)) & 0xFFFF; this.mar = this.p3; } else { this.mar = this.p3;  this.p3 = (this.p3+this.mbr) & 0xFFFF; };this.read();this.ac = this.mbr;this.cycles = this.cycles + 18;
}
function opcodec8():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p0+this.t16) & 0xFFFF;;this.mbr = this.ac;this.write();this.cycles = this.cycles + 22;
}
function opcodec9():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p1+this.t16) & 0xFFFF;;this.mbr = this.ac;this.write();this.cycles = this.cycles + 22;
}
function opcodeca():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p2+this.t16) & 0xFFFF;;this.mbr = this.ac;this.write();this.cycles = this.cycles + 22;
}
function opcodecb():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p3+this.t16) & 0xFFFF;;this.mbr = this.ac;this.write();this.cycles = this.cycles + 22;
}
function opcodecc():void { 
    ;
}
function opcodecd():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;if (this.mbr & 0x80) { this.p1 = (this.p1+(this.mbr|0xFF00)) & 0xFFFF; this.mar = this.p1; } else { this.mar = this.p1;  this.p1 = (this.p1+this.mbr) & 0xFFFF; };this.mbr = this.ac;this.write();this.cycles = this.cycles + 22;
}
function opcodece():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;if (this.mbr & 0x80) { this.p2 = (this.p2+(this.mbr|0xFF00)) & 0xFFFF; this.mar = this.p2; } else { this.mar = this.p2;  this.p2 = (this.p2+this.mbr) & 0xFFFF; };this.mbr = this.ac;this.write();this.cycles = this.cycles + 22;
}
function opcodecf():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;if (this.mbr & 0x80) { this.p3 = (this.p3+(this.mbr|0xFF00)) & 0xFFFF; this.mar = this.p3; } else { this.mar = this.p3;  this.p3 = (this.p3+this.mbr) & 0xFFFF; };this.mbr = this.ac;this.write();this.cycles = this.cycles + 22;
}
function opcoded0():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p0+this.t16) & 0xFFFF;;this.read();this.ac = this.ac & this.mbr;this.cycles = this.cycles + 18;
}
function opcoded1():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p1+this.t16) & 0xFFFF;;this.read();this.ac = this.ac & this.mbr;this.cycles = this.cycles + 18;
}
function opcoded2():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p2+this.t16) & 0xFFFF;;this.read();this.ac = this.ac & this.mbr;this.cycles = this.cycles + 18;
}
function opcoded3():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p3+this.t16) & 0xFFFF;;this.read();this.ac = this.ac & this.mbr;this.cycles = this.cycles + 18;
}
function opcoded4():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();this.ac = this.ac & this.mbr;this.cycles = this.cycles + 10;
}
function opcoded5():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;if (this.mbr & 0x80) { this.p1 = (this.p1+(this.mbr|0xFF00)) & 0xFFFF; this.mar = this.p1; } else { this.mar = this.p1;  this.p1 = (this.p1+this.mbr) & 0xFFFF; };this.read();this.ac = this.ac & this.mbr;this.cycles = this.cycles + 18;
}
function opcoded6():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;if (this.mbr & 0x80) { this.p2 = (this.p2+(this.mbr|0xFF00)) & 0xFFFF; this.mar = this.p2; } else { this.mar = this.p2;  this.p2 = (this.p2+this.mbr) & 0xFFFF; };this.read();this.ac = this.ac & this.mbr;this.cycles = this.cycles + 18;
}
function opcoded7():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;if (this.mbr & 0x80) { this.p3 = (this.p3+(this.mbr|0xFF00)) & 0xFFFF; this.mar = this.p3; } else { this.mar = this.p3;  this.p3 = (this.p3+this.mbr) & 0xFFFF; };this.read();this.ac = this.ac & this.mbr;this.cycles = this.cycles + 18;
}
function opcoded8():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p0+this.t16) & 0xFFFF;;this.read();this.ac = this.ac | this.mbr;this.cycles = this.cycles + 18;
}
function opcoded9():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p1+this.t16) & 0xFFFF;;this.read();this.ac = this.ac | this.mbr;this.cycles = this.cycles + 18;
}
function opcodeda():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p2+this.t16) & 0xFFFF;;this.read();this.ac = this.ac | this.mbr;this.cycles = this.cycles + 18;
}
function opcodedb():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p3+this.t16) & 0xFFFF;;this.read();this.ac = this.ac | this.mbr;this.cycles = this.cycles + 18;
}
function opcodedc():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();this.ac = this.ac | this.mbr;this.cycles = this.cycles + 10;
}
function opcodedd():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;if (this.mbr & 0x80) { this.p1 = (this.p1+(this.mbr|0xFF00)) & 0xFFFF; this.mar = this.p1; } else { this.mar = this.p1;  this.p1 = (this.p1+this.mbr) & 0xFFFF; };this.read();this.ac = this.ac | this.mbr;this.cycles = this.cycles + 18;
}
function opcodede():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;if (this.mbr & 0x80) { this.p2 = (this.p2+(this.mbr|0xFF00)) & 0xFFFF; this.mar = this.p2; } else { this.mar = this.p2;  this.p2 = (this.p2+this.mbr) & 0xFFFF; };this.read();this.ac = this.ac | this.mbr;this.cycles = this.cycles + 18;
}
function opcodedf():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;if (this.mbr & 0x80) { this.p3 = (this.p3+(this.mbr|0xFF00)) & 0xFFFF; this.mar = this.p3; } else { this.mar = this.p3;  this.p3 = (this.p3+this.mbr) & 0xFFFF; };this.read();this.ac = this.ac | this.mbr;this.cycles = this.cycles + 18;
}
function opcodee0():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p0+this.t16) & 0xFFFF;;this.read();this.ac = this.ac ^ this.mbr;this.cycles = this.cycles + 18;
}
function opcodee1():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p1+this.t16) & 0xFFFF;;this.read();this.ac = this.ac ^ this.mbr;this.cycles = this.cycles + 18;
}
function opcodee2():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p2+this.t16) & 0xFFFF;;this.read();this.ac = this.ac ^ this.mbr;this.cycles = this.cycles + 18;
}
function opcodee3():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p3+this.t16) & 0xFFFF;;this.read();this.ac = this.ac ^ this.mbr;this.cycles = this.cycles + 18;
}
function opcodee4():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();this.ac = this.ac ^ this.mbr;this.cycles = this.cycles + 10;
}
function opcodee5():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;if (this.mbr & 0x80) { this.p1 = (this.p1+(this.mbr|0xFF00)) & 0xFFFF; this.mar = this.p1; } else { this.mar = this.p1;  this.p1 = (this.p1+this.mbr) & 0xFFFF; };this.read();this.ac = this.ac ^ this.mbr;this.cycles = this.cycles + 18;
}
function opcodee6():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;if (this.mbr & 0x80) { this.p2 = (this.p2+(this.mbr|0xFF00)) & 0xFFFF; this.mar = this.p2; } else { this.mar = this.p2;  this.p2 = (this.p2+this.mbr) & 0xFFFF; };this.read();this.ac = this.ac ^ this.mbr;this.cycles = this.cycles + 18;
}
function opcodee7():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;if (this.mbr & 0x80) { this.p3 = (this.p3+(this.mbr|0xFF00)) & 0xFFFF; this.mar = this.p3; } else { this.mar = this.p3;  this.p3 = (this.p3+this.mbr) & 0xFFFF; };this.read();this.ac = this.ac ^ this.mbr;this.cycles = this.cycles + 18;
}
function opcodee8():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p0+this.t16) & 0xFFFF;;this.read();			this.t16 = (this.ac & 0x0F)+(this.mbr & 0x0F)+this.cyl;			this.cyl = 0;			if (this.t16 > 9) this.t16 = this.t16 + 6;			this.t16 = this.t16 + (this.ac & 0xF0) + (this.mbr & 0xF0);			if (this.t16 > 0x99) { this.t16 = this.t16 + 0x60;this.cyl = 1; }			this.ac = this.t16 & 0xFF;		;this.cycles = this.cycles + 23;
}
function opcodee9():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p1+this.t16) & 0xFFFF;;this.read();			this.t16 = (this.ac & 0x0F)+(this.mbr & 0x0F)+this.cyl;			this.cyl = 0;			if (this.t16 > 9) this.t16 = this.t16 + 6;			this.t16 = this.t16 + (this.ac & 0xF0) + (this.mbr & 0xF0);			if (this.t16 > 0x99) { this.t16 = this.t16 + 0x60;this.cyl = 1; }			this.ac = this.t16 & 0xFF;		;this.cycles = this.cycles + 23;
}
function opcodeea():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p2+this.t16) & 0xFFFF;;this.read();			this.t16 = (this.ac & 0x0F)+(this.mbr & 0x0F)+this.cyl;			this.cyl = 0;			if (this.t16 > 9) this.t16 = this.t16 + 6;			this.t16 = this.t16 + (this.ac & 0xF0) + (this.mbr & 0xF0);			if (this.t16 > 0x99) { this.t16 = this.t16 + 0x60;this.cyl = 1; }			this.ac = this.t16 & 0xFF;		;this.cycles = this.cycles + 23;
}
function opcodeeb():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p3+this.t16) & 0xFFFF;;this.read();			this.t16 = (this.ac & 0x0F)+(this.mbr & 0x0F)+this.cyl;			this.cyl = 0;			if (this.t16 > 9) this.t16 = this.t16 + 6;			this.t16 = this.t16 + (this.ac & 0xF0) + (this.mbr & 0xF0);			if (this.t16 > 0x99) { this.t16 = this.t16 + 0x60;this.cyl = 1; }			this.ac = this.t16 & 0xFF;		;this.cycles = this.cycles + 23;
}
function opcodeec():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();;			this.t16 = (this.ac & 0x0F)+(this.mbr & 0x0F)+this.cyl;			this.cyl = 0;			if (this.t16 > 9) this.t16 = this.t16 + 6;			this.t16 = this.t16 + (this.ac & 0xF0) + (this.mbr & 0xF0);			if (this.t16 > 0x99) { this.t16 = this.t16 + 0x60;this.cyl = 1; }			this.ac = this.t16 & 0xFF;		;this.cycles = this.cycles + 15;
}
function opcodeed():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;if (this.mbr & 0x80) { this.p1 = (this.p1+(this.mbr|0xFF00)) & 0xFFFF; this.mar = this.p1; } else { this.mar = this.p1;  this.p1 = (this.p1+this.mbr) & 0xFFFF; };this.read();			this.t16 = (this.ac & 0x0F)+(this.mbr & 0x0F)+this.cyl;			this.cyl = 0;			if (this.t16 > 9) this.t16 = this.t16 + 6;			this.t16 = this.t16 + (this.ac & 0xF0) + (this.mbr & 0xF0);			if (this.t16 > 0x99) { this.t16 = this.t16 + 0x60;this.cyl = 1; }			this.ac = this.t16 & 0xFF;		;this.cycles = this.cycles + 23;
}
function opcodeee():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;if (this.mbr & 0x80) { this.p2 = (this.p2+(this.mbr|0xFF00)) & 0xFFFF; this.mar = this.p2; } else { this.mar = this.p2;  this.p2 = (this.p2+this.mbr) & 0xFFFF; };this.read();			this.t16 = (this.ac & 0x0F)+(this.mbr & 0x0F)+this.cyl;			this.cyl = 0;			if (this.t16 > 9) this.t16 = this.t16 + 6;			this.t16 = this.t16 + (this.ac & 0xF0) + (this.mbr & 0xF0);			if (this.t16 > 0x99) { this.t16 = this.t16 + 0x60;this.cyl = 1; }			this.ac = this.t16 & 0xFF;		;this.cycles = this.cycles + 23;
}
function opcodeef():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;if (this.mbr & 0x80) { this.p3 = (this.p3+(this.mbr|0xFF00)) & 0xFFFF; this.mar = this.p3; } else { this.mar = this.p3;  this.p3 = (this.p3+this.mbr) & 0xFFFF; };this.read();			this.t16 = (this.ac & 0x0F)+(this.mbr & 0x0F)+this.cyl;			this.cyl = 0;			if (this.t16 > 9) this.t16 = this.t16 + 6;			this.t16 = this.t16 + (this.ac & 0xF0) + (this.mbr & 0xF0);			if (this.t16 > 0x99) { this.t16 = this.t16 + 0x60;this.cyl = 1; }			this.ac = this.t16 & 0xFF;		;this.cycles = this.cycles + 23;
}
function opcodef0():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p0+this.t16) & 0xFFFF;;this.read();this.t16 = this.ac + this.mbr + this.cyl;this.ac = (this.t16 & 0xFF);this.cyl = (this.t16 >> 8) & 1;;this.cycles = this.cycles + 19;
}
function opcodef1():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p1+this.t16) & 0xFFFF;;this.read();this.t16 = this.ac + this.mbr + this.cyl;this.ac = (this.t16 & 0xFF);this.cyl = (this.t16 >> 8) & 1;;this.cycles = this.cycles + 19;
}
function opcodef2():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p2+this.t16) & 0xFFFF;;this.read();this.t16 = this.ac + this.mbr + this.cyl;this.ac = (this.t16 & 0xFF);this.cyl = (this.t16 >> 8) & 1;;this.cycles = this.cycles + 19;
}
function opcodef3():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p3+this.t16) & 0xFFFF;;this.read();this.t16 = this.ac + this.mbr + this.cyl;this.ac = (this.t16 & 0xFF);this.cyl = (this.t16 >> 8) & 1;;this.cycles = this.cycles + 19;
}
function opcodef4():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();;this.t16 = this.ac + this.mbr + this.cyl;this.ac = (this.t16 & 0xFF);this.cyl = (this.t16 >> 8) & 1;;this.cycles = this.cycles + 11;
}
function opcodef5():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;if (this.mbr & 0x80) { this.p1 = (this.p1+(this.mbr|0xFF00)) & 0xFFFF; this.mar = this.p1; } else { this.mar = this.p1;  this.p1 = (this.p1+this.mbr) & 0xFFFF; };this.read();this.t16 = this.ac + this.mbr + this.cyl;this.ac = (this.t16 & 0xFF);this.cyl = (this.t16 >> 8) & 1;;this.cycles = this.cycles + 19;
}
function opcodef6():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;if (this.mbr & 0x80) { this.p2 = (this.p2+(this.mbr|0xFF00)) & 0xFFFF; this.mar = this.p2; } else { this.mar = this.p2;  this.p2 = (this.p2+this.mbr) & 0xFFFF; };this.read();this.t16 = this.ac + this.mbr + this.cyl;this.ac = (this.t16 & 0xFF);this.cyl = (this.t16 >> 8) & 1;;this.cycles = this.cycles + 19;
}
function opcodef7():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;if (this.mbr & 0x80) { this.p3 = (this.p3+(this.mbr|0xFF00)) & 0xFFFF; this.mar = this.p3; } else { this.mar = this.p3;  this.p3 = (this.p3+this.mbr) & 0xFFFF; };this.read();this.t16 = this.ac + this.mbr + this.cyl;this.ac = (this.t16 & 0xFF);this.cyl = (this.t16 >> 8) & 1;;this.cycles = this.cycles + 19;
}
function opcodef8():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p0+this.t16) & 0xFFFF;;this.read();this.mbr = this.mbr ^ 0xFF;this.t16 = this.ac + this.mbr + this.cyl;this.ac = (this.t16 & 0xFF);this.cyl = (this.t16 >> 8) & 1;;this.cycles = this.cycles + 20;
}
function opcodef9():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p1+this.t16) & 0xFFFF;;this.read();this.mbr = this.mbr ^ 0xFF;this.t16 = this.ac + this.mbr + this.cyl;this.ac = (this.t16 & 0xFF);this.cyl = (this.t16 >> 8) & 1;;this.cycles = this.cycles + 20;
}
function opcodefa():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p2+this.t16) & 0xFFFF;;this.read();this.mbr = this.mbr ^ 0xFF;this.t16 = this.ac + this.mbr + this.cyl;this.ac = (this.t16 & 0xFF);this.cyl = (this.t16 >> 8) & 1;;this.cycles = this.cycles + 20;
}
function opcodefb():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;this.t16 = (this.mbr & 0x80) ? (this.mbr | 0xFF00) : this.mbr;this.mar = (this.p3+this.t16) & 0xFFFF;;this.read();this.mbr = this.mbr ^ 0xFF;this.t16 = this.ac + this.mbr + this.cyl;this.ac = (this.t16 & 0xFF);this.cyl = (this.t16 >> 8) & 1;;this.cycles = this.cycles + 20;
}
function opcodefc():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();this.mbr = this.mbr ^ 0xFF;this.t16 = this.ac + this.mbr + this.cyl;this.ac = (this.t16 & 0xFF);this.cyl = (this.t16 >> 8) & 1;;this.cycles = this.cycles + 12;
}
function opcodefd():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;if (this.mbr & 0x80) { this.p1 = (this.p1+(this.mbr|0xFF00)) & 0xFFFF; this.mar = this.p1; } else { this.mar = this.p1;  this.p1 = (this.p1+this.mbr) & 0xFFFF; };this.read();this.mbr = this.mbr ^ 0xFF;this.t16 = this.ac + this.mbr + this.cyl;this.ac = (this.t16 & 0xFF);this.cyl = (this.t16 >> 8) & 1;;this.cycles = this.cycles + 20;
}
function opcodefe():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;if (this.mbr & 0x80) { this.p2 = (this.p2+(this.mbr|0xFF00)) & 0xFFFF; this.mar = this.p2; } else { this.mar = this.p2;  this.p2 = (this.p2+this.mbr) & 0xFFFF; };this.read();this.mbr = this.mbr ^ 0xFF;this.t16 = this.ac + this.mbr + this.cyl;this.ac = (this.t16 & 0xFF);this.cyl = (this.t16 >> 8) & 1;;this.cycles = this.cycles + 20;
}
function opcodeff():void { 
    this.p0 = (this.p0 + 1) & 0xFFFF;this.mar = this.p0;this.read();if (this.mbr == 0x80) this.mbr = this.e;;if (this.mbr & 0x80) { this.p3 = (this.p3+(this.mbr|0xFF00)) & 0xFFFF; this.mar = this.p3; } else { this.mar = this.p3;  this.p3 = (this.p3+this.mbr) & 0xFFFF; };this.read();this.mbr = this.mbr ^ 0xFF;this.t16 = this.ac + this.mbr + this.cyl;this.ac = (this.t16 & 0xFF);this.cyl = (this.t16 >> 8) & 1;;this.cycles = this.cycles + 20;
}
function getOpcodeFunctions(): Function[] {
return [this.opcode00,this.opcode01,this.opcode02,this.opcode03,this.opcode04,this.opcode05,this.opcode06,this.opcode07,this.opcode08,this.opcode09,this.opcode0a,this.opcode0b,this.opcode0c,this.opcode0d,this.opcode0e,this.opcode0f,this.opcode10,this.opcode11,this.opcode12,this.opcode13,this.opcode14,this.opcode15,this.opcode16,this.opcode17,this.opcode18,this.opcode19,this.opcode1a,this.opcode1b,this.opcode1c,this.opcode1d,this.opcode1e,this.opcode1f,this.opcode20,this.opcode21,this.opcode22,this.opcode23,this.opcode24,this.opcode25,this.opcode26,this.opcode27,this.opcode28,this.opcode29,this.opcode2a,this.opcode2b,this.opcode2c,this.opcode2d,this.opcode2e,this.opcode2f,this.opcode30,this.opcode31,this.opcode32,this.opcode33,this.opcode34,this.opcode35,this.opcode36,this.opcode37,this.opcode38,this.opcode39,this.opcode3a,this.opcode3b,this.opcode3c,this.opcode3d,this.opcode3e,this.opcode3f,this.opcode40,this.opcode41,this.opcode42,this.opcode43,this.opcode44,this.opcode45,this.opcode46,this.opcode47,this.opcode48,this.opcode49,this.opcode4a,this.opcode4b,this.opcode4c,this.opcode4d,this.opcode4e,this.opcode4f,this.opcode50,this.opcode51,this.opcode52,this.opcode53,this.opcode54,this.opcode55,this.opcode56,this.opcode57,this.opcode58,this.opcode59,this.opcode5a,this.opcode5b,this.opcode5c,this.opcode5d,this.opcode5e,this.opcode5f,this.opcode60,this.opcode61,this.opcode62,this.opcode63,this.opcode64,this.opcode65,this.opcode66,this.opcode67,this.opcode68,this.opcode69,this.opcode6a,this.opcode6b,this.opcode6c,this.opcode6d,this.opcode6e,this.opcode6f,this.opcode70,this.opcode71,this.opcode72,this.opcode73,this.opcode74,this.opcode75,this.opcode76,this.opcode77,this.opcode78,this.opcode79,this.opcode7a,this.opcode7b,this.opcode7c,this.opcode7d,this.opcode7e,this.opcode7f,this.opcode80,this.opcode81,this.opcode82,this.opcode83,this.opcode84,this.opcode85,this.opcode86,this.opcode87,this.opcode88,this.opcode89,this.opcode8a,this.opcode8b,this.opcode8c,this.opcode8d,this.opcode8e,this.opcode8f,this.opcode90,this.opcode91,this.opcode92,this.opcode93,this.opcode94,this.opcode95,this.opcode96,this.opcode97,this.opcode98,this.opcode99,this.opcode9a,this.opcode9b,this.opcode9c,this.opcode9d,this.opcode9e,this.opcode9f,this.opcodea0,this.opcodea1,this.opcodea2,this.opcodea3,this.opcodea4,this.opcodea5,this.opcodea6,this.opcodea7,this.opcodea8,this.opcodea9,this.opcodeaa,this.opcodeab,this.opcodeac,this.opcodead,this.opcodeae,this.opcodeaf,this.opcodeb0,this.opcodeb1,this.opcodeb2,this.opcodeb3,this.opcodeb4,this.opcodeb5,this.opcodeb6,this.opcodeb7,this.opcodeb8,this.opcodeb9,this.opcodeba,this.opcodebb,this.opcodebc,this.opcodebd,this.opcodebe,this.opcodebf,this.opcodec0,this.opcodec1,this.opcodec2,this.opcodec3,this.opcodec4,this.opcodec5,this.opcodec6,this.opcodec7,this.opcodec8,this.opcodec9,this.opcodeca,this.opcodecb,this.opcodecc,this.opcodecd,this.opcodece,this.opcodecf,this.opcoded0,this.opcoded1,this.opcoded2,this.opcoded3,this.opcoded4,this.opcoded5,this.opcoded6,this.opcoded7,this.opcoded8,this.opcoded9,this.opcodeda,this.opcodedb,this.opcodedc,this.opcodedd,this.opcodede,this.opcodedf,this.opcodee0,this.opcodee1,this.opcodee2,this.opcodee3,this.opcodee4,this.opcodee5,this.opcodee6,this.opcodee7,this.opcodee8,this.opcodee9,this.opcodeea,this.opcodeeb,this.opcodeec,this.opcodeed,this.opcodeee,this.opcodeef,this.opcodef0,this.opcodef1,this.opcodef2,this.opcodef3,this.opcodef4,this.opcodef5,this.opcodef6,this.opcodef7,this.opcodef8,this.opcodef9,this.opcodefa,this.opcodefb,this.opcodefc,this.opcodefd,this.opcodefe,this.opcodeff]
}
}
