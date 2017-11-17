case 0x00: /*** halt ***/
    ;
    ;
    cycles = cycles + 8;
    break;
case 0x01: /*** xae ***/
    t16 = ac;
    ac = e;
    e = t16;
    cycles = cycles + 7;
    break;
case 0x02: /*** ccl ***/
    cyl = 0;
    cycles = cycles + 5;
    break;
case 0x03: /*** scl ***/
    cyl = 1;
    cycles = cycles + 5;
    break;
case 0x04: /*** dint ***/
    status = status & 0xF7;
    ;
    cycles = cycles + 6;
    break;
case 0x05: /*** ien ***/
    status = status | 8;
    ;
    cycles = cycles + 6;
    break;
case 0x06: /*** csa ***/
    status = (status & 0x0F)+(senseA() ? 0x10:0x00)+(senseB() ? 0x20:0x00)+(ov ? 0x40:0x00)+(cyl ? 0x80:0x00);
    ;
    ac = status;
    cycles = cycles + 5;
    break;
case 0x07: /*** cas ***/
    status = ac;
    status = (status & 0x0F)+(senseA() ? 0x10:0x00)+(senseB() ? 0x20:0x00)+(ov ? 0x40:0x00)+(cyl ? 0x80:0x00);
    ;
    setFlags(status & 7);
    cycles = cycles + 6;
    break;
case 0x08: /*** nop ***/
    ;
    ;
    cycles = cycles + 5;
    break;
case 0x09: /*** db 09 ***/
    ;
    break;
case 0x0a: /*** db 0a ***/
    ;
    break;
case 0x0b: /*** db 0b ***/
    ;
    break;
case 0x0c: /*** db 0c ***/
    ;
    break;
case 0x0d: /*** db 0d ***/
    ;
    break;
case 0x0e: /*** db 0e ***/
    ;
    break;
case 0x0f: /*** db 0f ***/
    status = (status & 0x0F)+(senseA() ? 0x10:0x00)+(senseB() ? 0x20:0x00)+(ov ? 0x40:0x00)+(cyl ? 0x80:0x00);
    ;
    cycles = cycles + 0;
    break;
case 0x10: /*** db 10 ***/
    ;
    break;
case 0x11: /*** db 11 ***/
    ;
    break;
case 0x12: /*** db 12 ***/
    ;
    break;
case 0x13: /*** db 13 ***/
    ;
    break;
case 0x14: /*** db 14 ***/
    ;
    break;
case 0x15: /*** db 15 ***/
    ;
    break;
case 0x16: /*** db 16 ***/
    ;
    break;
case 0x17: /*** db 17 ***/
    ;
    break;
case 0x18: /*** db 18 ***/
    ;
    break;
case 0x19: /*** sin ***/
    serialOut(e & 1);
    e = (e >> 1) | ((serialIn() != 0) ? 0x80:0x00);
    ;
    cycles = cycles + 5;
    break;
case 0x1a: /*** db 1a ***/
    ;
    break;
case 0x1b: /*** db 1b ***/
    ;
    break;
case 0x1c: /*** sr ***/
    ac = ac >> 1;
    cycles = cycles + 5;
    break;
case 0x1d: /*** srl ***/
    ac = (ac >> 1) | (cyl << 7);
    cycles = cycles + 5;
    break;
case 0x1e: /*** rr ***/
    ac = ((ac >> 1) | (ac << 7)) & 0xFF;
    cycles = cycles + 5;
    break;
case 0x1f: /*** rrl ***/
    t16 = ac | (cyl << 8);
    ac = (t16 >> 1) & 0xFF;
    cyl = t16 & 1;
    cycles = cycles + 5;
    break;
case 0x20: /*** db 20 ***/
    ;
    break;
case 0x21: /*** db 21 ***/
    ;
    break;
case 0x22: /*** db 22 ***/
    ;
    break;
case 0x23: /*** db 23 ***/
    ;
    break;
case 0x24: /*** db 24 ***/
    ;
    break;
case 0x25: /*** db 25 ***/
    ;
    break;
case 0x26: /*** db 26 ***/
    ;
    break;
case 0x27: /*** db 27 ***/
    ;
    break;
case 0x28: /*** db 28 ***/
    ;
    break;
case 0x29: /*** db 29 ***/
    ;
    break;
case 0x2a: /*** db 2a ***/
    ;
    break;
case 0x2b: /*** db 2b ***/
    ;
    break;
case 0x2c: /*** db 2c ***/
    ;
    break;
case 0x2d: /*** db 2d ***/
    ;
    break;
case 0x2e: /*** db 2e ***/
    ;
    break;
case 0x2f: /*** db 2f ***/
    ;
    break;
case 0x30: /*** xpal p0 ***/
    t16 = ac;
    ac = p0 & 0xFF;
    p0 = (t16 & 0xFF)|(p0 & 0xFF00);
    cycles = cycles + 8;
    break;
case 0x31: /*** xpal p1 ***/
    t16 = ac;
    ac = p1 & 0xFF;
    p1 = (t16 & 0xFF)|(p1 & 0xFF00);
    cycles = cycles + 8;
    break;
case 0x32: /*** xpal p2 ***/
    t16 = ac;
    ac = p2 & 0xFF;
    p2 = (t16 & 0xFF)|(p2 & 0xFF00);
    cycles = cycles + 8;
    break;
case 0x33: /*** xpal p3 ***/
    t16 = ac;
    ac = p3 & 0xFF;
    p3 = (t16 & 0xFF)|(p3 & 0xFF00);
    cycles = cycles + 8;
    break;
case 0x34: /*** xpah p0 ***/
    t16 = ac;
    ac = (p0 >> 8) & 0xFF;
    p0 = (p0 & 0x00FF)|(t16 << 8);
    cycles = cycles + 8;
    break;
case 0x35: /*** xpah p1 ***/
    t16 = ac;
    ac = (p1 >> 8) & 0xFF;
    p1 = (p1 & 0x00FF)|(t16 << 8);
    cycles = cycles + 8;
    break;
case 0x36: /*** xpah p2 ***/
    t16 = ac;
    ac = (p2 >> 8) & 0xFF;
    p2 = (p2 & 0x00FF)|(t16 << 8);
    cycles = cycles + 8;
    break;
case 0x37: /*** xpah p3 ***/
    t16 = ac;
    ac = (p3 >> 8) & 0xFF;
    p3 = (p3 & 0x00FF)|(t16 << 8);
    cycles = cycles + 8;
    break;
case 0x38: /*** db 38 ***/
    ;
    break;
case 0x39: /*** db 39 ***/
    ;
    break;
case 0x3a: /*** db 3a ***/
    ;
    break;
case 0x3b: /*** db 3b ***/
    ;
    break;
case 0x3c: /*** xppc p0 ***/
    t16 = p0;
    p0 = p0;
    p0 = t16;
    cycles = cycles + 7;
    break;
case 0x3d: /*** xppc p1 ***/
    t16 = p0;
    p0 = p1;
    p1 = t16;
    cycles = cycles + 7;
    break;
case 0x3e: /*** xppc p2 ***/
    t16 = p0;
    p0 = p2;
    p2 = t16;
    cycles = cycles + 7;
    break;
case 0x3f: /*** xppc p3 ***/
    t16 = p0;
    p0 = p3;
    p3 = t16;
    cycles = cycles + 7;
    break;
case 0x40: /*** lde ***/
    ac = e;
    cycles = cycles + 6;
    break;
case 0x41: /*** db 41 ***/
    ;
    break;
case 0x42: /*** db 42 ***/
    ;
    break;
case 0x43: /*** db 43 ***/
    ;
    break;
case 0x44: /*** db 44 ***/
    ;
    break;
case 0x45: /*** db 45 ***/
    ;
    break;
case 0x46: /*** db 46 ***/
    ;
    break;
case 0x47: /*** db 47 ***/
    ;
    break;
case 0x48: /*** db 48 ***/
    ;
    break;
case 0x49: /*** db 49 ***/
    ;
    break;
case 0x4a: /*** db 4a ***/
    ;
    break;
case 0x4b: /*** db 4b ***/
    ;
    break;
case 0x4c: /*** db 4c ***/
    ;
    break;
case 0x4d: /*** db 4d ***/
    ;
    break;
case 0x4e: /*** db 4e ***/
    ;
    break;
case 0x4f: /*** db 4f ***/
    ;
    break;
case 0x50: /*** ane ***/
    ac = ac & e;
    cycles = cycles + 6;
    break;
case 0x51: /*** db 51 ***/
    ;
    break;
case 0x52: /*** db 52 ***/
    ;
    break;
case 0x53: /*** db 53 ***/
    ;
    break;
case 0x54: /*** db 54 ***/
    ;
    break;
case 0x55: /*** db 55 ***/
    ;
    break;
case 0x56: /*** db 56 ***/
    ;
    break;
case 0x57: /*** db 57 ***/
    ;
    break;
case 0x58: /*** ore ***/
    ac = ac | e;
    cycles = cycles + 6;
    break;
case 0x59: /*** db 59 ***/
    ;
    break;
case 0x5a: /*** db 5a ***/
    ;
    break;
case 0x5b: /*** db 5b ***/
    ;
    break;
case 0x5c: /*** db 5c ***/
    ;
    break;
case 0x5d: /*** db 5d ***/
    ;
    break;
case 0x5e: /*** db 5e ***/
    ;
    break;
case 0x5f: /*** db 5f ***/
    ;
    break;
case 0x60: /*** xre ***/
    ac = ac ^ e;
    cycles = cycles + 6;
    break;
case 0x61: /*** db 61 ***/
    ;
    break;
case 0x62: /*** db 62 ***/
    ;
    break;
case 0x63: /*** db 63 ***/
    ;
    break;
case 0x64: /*** db 64 ***/
    ;
    break;
case 0x65: /*** db 65 ***/
    ;
    break;
case 0x66: /*** db 66 ***/
    ;
    break;
case 0x67: /*** db 67 ***/
    ;
    break;
case 0x68: /*** dae ***/
    mbr = e;
    			t16 = (ac & 0x0F)+(mbr & 0x0F)+cyl;
    			cyl = 0;
    			if (t16 > 9) t16 = t16 + 6;
    			t16 = t16 + (ac & 0xF0) + (mbr & 0xF0);
    			if (t16 > 0x99) { t16 = t16 + 0x60;
    cyl = 1;
     }			ac = t16 & 0xFF;
    		;
    cycles = cycles + 11;
    break;
case 0x69: /*** db 69 ***/
    ;
    break;
case 0x6a: /*** db 6a ***/
    ;
    break;
case 0x6b: /*** db 6b ***/
    ;
    break;
case 0x6c: /*** db 6c ***/
    ;
    break;
case 0x6d: /*** db 6d ***/
    ;
    break;
case 0x6e: /*** db 6e ***/
    ;
    break;
case 0x6f: /*** db 6f ***/
    ;
    break;
case 0x70: /*** ade ***/
    mbr = e;
    t16 = ac + mbr + cyl;
    ac = (t16 & 0xFF);
    cyl = (t16 >> 8) & 1;
    ;
    cycles = cycles + 7;
    break;
case 0x71: /*** db 71 ***/
    ;
    break;
case 0x72: /*** db 72 ***/
    ;
    break;
case 0x73: /*** db 73 ***/
    ;
    break;
case 0x74: /*** db 74 ***/
    ;
    break;
case 0x75: /*** db 75 ***/
    ;
    break;
case 0x76: /*** db 76 ***/
    ;
    break;
case 0x77: /*** db 77 ***/
    ;
    break;
case 0x78: /*** cae ***/
    mbr = e ^ 0xFF;
    t16 = ac + mbr + cyl;
    ac = (t16 & 0xFF);
    cyl = (t16 >> 8) & 1;
    ;
    cycles = cycles + 8;
    break;
case 0x79: /*** db 79 ***/
    ;
    break;
case 0x7a: /*** db 7a ***/
    ;
    break;
case 0x7b: /*** db 7b ***/
    ;
    break;
case 0x7c: /*** db 7c ***/
    ;
    break;
case 0x7d: /*** db 7d ***/
    ;
    break;
case 0x7e: /*** db 7e ***/
    ;
    break;
case 0x7f: /*** db 7f ***/
    ;
    break;
case 0x80: /*** db 80 ***/
    ;
    break;
case 0x81: /*** db 81 ***/
    ;
    break;
case 0x82: /*** db 82 ***/
    ;
    break;
case 0x83: /*** db 83 ***/
    ;
    break;
case 0x84: /*** db 84 ***/
    ;
    break;
case 0x85: /*** db 85 ***/
    ;
    break;
case 0x86: /*** db 86 ***/
    ;
    break;
case 0x87: /*** db 87 ***/
    ;
    break;
case 0x88: /*** db 88 ***/
    ;
    break;
case 0x89: /*** db 89 ***/
    ;
    break;
case 0x8a: /*** db 8a ***/
    ;
    break;
case 0x8b: /*** db 8b ***/
    ;
    break;
case 0x8c: /*** db 8c ***/
    ;
    break;
case 0x8d: /*** db 8d ***/
    ;
    break;
case 0x8e: /*** db 8e ***/
    ;
    break;
case 0x8f: /*** dly %c ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    delay4cycles = ac/2 + 128 * mbr;
    ac = 0xFF;
    cycles = cycles + 13;
    break;
case 0x90: /*** jmp %o(p0) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p0+t16) & 0xFFFF;
    ;
    p0 = mar;
    ;
    cycles = cycles + 11;
    break;
case 0x91: /*** jmp %o(p1) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p1+t16) & 0xFFFF;
    ;
    p0 = mar;
    ;
    cycles = cycles + 11;
    break;
case 0x92: /*** jmp %o(p2) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p2+t16) & 0xFFFF;
    ;
    p0 = mar;
    ;
    cycles = cycles + 11;
    break;
case 0x93: /*** jmp %o(p3) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p3+t16) & 0xFFFF;
    ;
    p0 = mar;
    ;
    cycles = cycles + 11;
    break;
case 0x94: /*** jp %o(p0) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p0+t16) & 0xFFFF;
    ;
    if ((ac & 0x80) == 0x00) { p0 = mar;
     };
    cycles = cycles + 10;
    break;
case 0x95: /*** jp %o(p1) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p1+t16) & 0xFFFF;
    ;
    if ((ac & 0x80) == 0x00) { p0 = mar;
     };
    cycles = cycles + 10;
    break;
case 0x96: /*** jp %o(p2) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p2+t16) & 0xFFFF;
    ;
    if ((ac & 0x80) == 0x00) { p0 = mar;
     };
    cycles = cycles + 10;
    break;
case 0x97: /*** jp %o(p3) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p3+t16) & 0xFFFF;
    ;
    if ((ac & 0x80) == 0x00) { p0 = mar;
     };
    cycles = cycles + 10;
    break;
case 0x98: /*** jz %o(p0) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p0+t16) & 0xFFFF;
    ;
    if (ac == 0x00) { p0 = mar;
     };
    cycles = cycles + 10;
    break;
case 0x99: /*** jz %o(p1) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p1+t16) & 0xFFFF;
    ;
    if (ac == 0x00) { p0 = mar;
     };
    cycles = cycles + 10;
    break;
case 0x9a: /*** jz %o(p2) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p2+t16) & 0xFFFF;
    ;
    if (ac == 0x00) { p0 = mar;
     };
    cycles = cycles + 10;
    break;
case 0x9b: /*** jz %o(p3) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p3+t16) & 0xFFFF;
    ;
    if (ac == 0x00) { p0 = mar;
     };
    cycles = cycles + 10;
    break;
case 0x9c: /*** jnz %o(p0) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p0+t16) & 0xFFFF;
    ;
    if (ac != 0x00) { p0 = mar;
     };
    cycles = cycles + 10;
    break;
case 0x9d: /*** jnz %o(p1) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p1+t16) & 0xFFFF;
    ;
    if (ac != 0x00) { p0 = mar;
     };
    cycles = cycles + 10;
    break;
case 0x9e: /*** jnz %o(p2) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p2+t16) & 0xFFFF;
    ;
    if (ac != 0x00) { p0 = mar;
     };
    cycles = cycles + 10;
    break;
case 0x9f: /*** jnz %o(p3) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p3+t16) & 0xFFFF;
    ;
    if (ac != 0x00) { p0 = mar;
     };
    cycles = cycles + 10;
    break;
case 0xa0: /*** db a0 ***/
    ;
    break;
case 0xa1: /*** db a1 ***/
    ;
    break;
case 0xa2: /*** db a2 ***/
    ;
    break;
case 0xa3: /*** db a3 ***/
    ;
    break;
case 0xa4: /*** db a4 ***/
    ;
    break;
case 0xa5: /*** db a5 ***/
    ;
    break;
case 0xa6: /*** db a6 ***/
    ;
    break;
case 0xa7: /*** db a7 ***/
    ;
    break;
case 0xa8: /*** ild %o(p0) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p0+t16) & 0xFFFF;
    ;
    READ();
    ac = (mbr + 1) & 0xFF;
    mbr = ac;
    WRITE();
    cycles = cycles + 22;
    break;
case 0xa9: /*** ild %o(p1) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p1+t16) & 0xFFFF;
    ;
    READ();
    ac = (mbr + 1) & 0xFF;
    mbr = ac;
    WRITE();
    cycles = cycles + 22;
    break;
case 0xaa: /*** ild %o(p2) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p2+t16) & 0xFFFF;
    ;
    READ();
    ac = (mbr + 1) & 0xFF;
    mbr = ac;
    WRITE();
    cycles = cycles + 22;
    break;
case 0xab: /*** ild %o(p3) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p3+t16) & 0xFFFF;
    ;
    READ();
    ac = (mbr + 1) & 0xFF;
    mbr = ac;
    WRITE();
    cycles = cycles + 22;
    break;
case 0xac: /*** db ac ***/
    ;
    break;
case 0xad: /*** db ad ***/
    ;
    break;
case 0xae: /*** db ae ***/
    ;
    break;
case 0xaf: /*** db af ***/
    ;
    break;
case 0xb0: /*** db b0 ***/
    ;
    break;
case 0xb1: /*** db b1 ***/
    ;
    break;
case 0xb2: /*** db b2 ***/
    ;
    break;
case 0xb3: /*** db b3 ***/
    ;
    break;
case 0xb4: /*** db b4 ***/
    ;
    break;
case 0xb5: /*** db b5 ***/
    ;
    break;
case 0xb6: /*** db b6 ***/
    ;
    break;
case 0xb7: /*** db b7 ***/
    ;
    break;
case 0xb8: /*** dld %o(p0) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p0+t16) & 0xFFFF;
    ;
    READ();
    ac = (mbr - 1) & 0xFF;
    mbr = ac;
    WRITE();
    cycles = cycles + 22;
    break;
case 0xb9: /*** dld %o(p1) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p1+t16) & 0xFFFF;
    ;
    READ();
    ac = (mbr - 1) & 0xFF;
    mbr = ac;
    WRITE();
    cycles = cycles + 22;
    break;
case 0xba: /*** dld %o(p2) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p2+t16) & 0xFFFF;
    ;
    READ();
    ac = (mbr - 1) & 0xFF;
    mbr = ac;
    WRITE();
    cycles = cycles + 22;
    break;
case 0xbb: /*** dld %o(p3) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p3+t16) & 0xFFFF;
    ;
    READ();
    ac = (mbr - 1) & 0xFF;
    mbr = ac;
    WRITE();
    cycles = cycles + 22;
    break;
case 0xbc: /*** db bc ***/
    ;
    break;
case 0xbd: /*** db bd ***/
    ;
    break;
case 0xbe: /*** db be ***/
    ;
    break;
case 0xbf: /*** db bf ***/
    ;
    break;
case 0xc0: /*** ld %o(p0) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p0+t16) & 0xFFFF;
    ;
    READ();
    ac = mbr;
    cycles = cycles + 18;
    break;
case 0xc1: /*** ld %o(p1) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p1+t16) & 0xFFFF;
    ;
    READ();
    ac = mbr;
    cycles = cycles + 18;
    break;
case 0xc2: /*** ld %o(p2) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p2+t16) & 0xFFFF;
    ;
    READ();
    ac = mbr;
    cycles = cycles + 18;
    break;
case 0xc3: /*** ld %o(p3) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p3+t16) & 0xFFFF;
    ;
    READ();
    ac = mbr;
    cycles = cycles + 18;
    break;
case 0xc4: /*** ldi %c ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    ac = mbr;
    cycles = cycles + 10;
    break;
case 0xc5: /*** ld @%o(p1) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    if (mbr & 0x80) { p1 = (p1+(mbr|0xFF00)) & 0xFFFF;
     mar = p1;
     } else { mar = p1;
      p1 = (p1+mbr) & 0xFFFF;
     };
    READ();
    ac = mbr;
    cycles = cycles + 18;
    break;
case 0xc6: /*** ld @%o(p2) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    if (mbr & 0x80) { p2 = (p2+(mbr|0xFF00)) & 0xFFFF;
     mar = p2;
     } else { mar = p2;
      p2 = (p2+mbr) & 0xFFFF;
     };
    READ();
    ac = mbr;
    cycles = cycles + 18;
    break;
case 0xc7: /*** ld @%o(p3) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    if (mbr & 0x80) { p3 = (p3+(mbr|0xFF00)) & 0xFFFF;
     mar = p3;
     } else { mar = p3;
      p3 = (p3+mbr) & 0xFFFF;
     };
    READ();
    ac = mbr;
    cycles = cycles + 18;
    break;
case 0xc8: /*** st %o(p0) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p0+t16) & 0xFFFF;
    ;
    mbr = ac;
    WRITE();
    cycles = cycles + 22;
    break;
case 0xc9: /*** st %o(p1) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p1+t16) & 0xFFFF;
    ;
    mbr = ac;
    WRITE();
    cycles = cycles + 22;
    break;
case 0xca: /*** st %o(p2) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p2+t16) & 0xFFFF;
    ;
    mbr = ac;
    WRITE();
    cycles = cycles + 22;
    break;
case 0xcb: /*** st %o(p3) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p3+t16) & 0xFFFF;
    ;
    mbr = ac;
    WRITE();
    cycles = cycles + 22;
    break;
case 0xcc: /*** db cc ***/
    ;
    break;
case 0xcd: /*** st @%o(p1) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    if (mbr & 0x80) { p1 = (p1+(mbr|0xFF00)) & 0xFFFF;
     mar = p1;
     } else { mar = p1;
      p1 = (p1+mbr) & 0xFFFF;
     };
    mbr = ac;
    WRITE();
    cycles = cycles + 22;
    break;
case 0xce: /*** st @%o(p2) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    if (mbr & 0x80) { p2 = (p2+(mbr|0xFF00)) & 0xFFFF;
     mar = p2;
     } else { mar = p2;
      p2 = (p2+mbr) & 0xFFFF;
     };
    mbr = ac;
    WRITE();
    cycles = cycles + 22;
    break;
case 0xcf: /*** st @%o(p3) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    if (mbr & 0x80) { p3 = (p3+(mbr|0xFF00)) & 0xFFFF;
     mar = p3;
     } else { mar = p3;
      p3 = (p3+mbr) & 0xFFFF;
     };
    mbr = ac;
    WRITE();
    cycles = cycles + 22;
    break;
case 0xd0: /*** and %o(p0) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p0+t16) & 0xFFFF;
    ;
    READ();
    ac = ac & mbr;
    cycles = cycles + 18;
    break;
case 0xd1: /*** and %o(p1) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p1+t16) & 0xFFFF;
    ;
    READ();
    ac = ac & mbr;
    cycles = cycles + 18;
    break;
case 0xd2: /*** and %o(p2) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p2+t16) & 0xFFFF;
    ;
    READ();
    ac = ac & mbr;
    cycles = cycles + 18;
    break;
case 0xd3: /*** and %o(p3) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p3+t16) & 0xFFFF;
    ;
    READ();
    ac = ac & mbr;
    cycles = cycles + 18;
    break;
case 0xd4: /*** ani %c ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    ac = ac & mbr;
    cycles = cycles + 10;
    break;
case 0xd5: /*** and @%o(p1) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    if (mbr & 0x80) { p1 = (p1+(mbr|0xFF00)) & 0xFFFF;
     mar = p1;
     } else { mar = p1;
      p1 = (p1+mbr) & 0xFFFF;
     };
    READ();
    ac = ac & mbr;
    cycles = cycles + 18;
    break;
case 0xd6: /*** and @%o(p2) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    if (mbr & 0x80) { p2 = (p2+(mbr|0xFF00)) & 0xFFFF;
     mar = p2;
     } else { mar = p2;
      p2 = (p2+mbr) & 0xFFFF;
     };
    READ();
    ac = ac & mbr;
    cycles = cycles + 18;
    break;
case 0xd7: /*** and @%o(p3) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    if (mbr & 0x80) { p3 = (p3+(mbr|0xFF00)) & 0xFFFF;
     mar = p3;
     } else { mar = p3;
      p3 = (p3+mbr) & 0xFFFF;
     };
    READ();
    ac = ac & mbr;
    cycles = cycles + 18;
    break;
case 0xd8: /*** or %o(p0) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p0+t16) & 0xFFFF;
    ;
    READ();
    ac = ac | mbr;
    cycles = cycles + 18;
    break;
case 0xd9: /*** or %o(p1) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p1+t16) & 0xFFFF;
    ;
    READ();
    ac = ac | mbr;
    cycles = cycles + 18;
    break;
case 0xda: /*** or %o(p2) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p2+t16) & 0xFFFF;
    ;
    READ();
    ac = ac | mbr;
    cycles = cycles + 18;
    break;
case 0xdb: /*** or %o(p3) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p3+t16) & 0xFFFF;
    ;
    READ();
    ac = ac | mbr;
    cycles = cycles + 18;
    break;
case 0xdc: /*** ori %c ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    ac = ac | mbr;
    cycles = cycles + 10;
    break;
case 0xdd: /*** or @%o(p1) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    if (mbr & 0x80) { p1 = (p1+(mbr|0xFF00)) & 0xFFFF;
     mar = p1;
     } else { mar = p1;
      p1 = (p1+mbr) & 0xFFFF;
     };
    READ();
    ac = ac | mbr;
    cycles = cycles + 18;
    break;
case 0xde: /*** or @%o(p2) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    if (mbr & 0x80) { p2 = (p2+(mbr|0xFF00)) & 0xFFFF;
     mar = p2;
     } else { mar = p2;
      p2 = (p2+mbr) & 0xFFFF;
     };
    READ();
    ac = ac | mbr;
    cycles = cycles + 18;
    break;
case 0xdf: /*** or @%o(p3) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    if (mbr & 0x80) { p3 = (p3+(mbr|0xFF00)) & 0xFFFF;
     mar = p3;
     } else { mar = p3;
      p3 = (p3+mbr) & 0xFFFF;
     };
    READ();
    ac = ac | mbr;
    cycles = cycles + 18;
    break;
case 0xe0: /*** xor %o(p0) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p0+t16) & 0xFFFF;
    ;
    READ();
    ac = ac ^ mbr;
    cycles = cycles + 18;
    break;
case 0xe1: /*** xor %o(p1) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p1+t16) & 0xFFFF;
    ;
    READ();
    ac = ac ^ mbr;
    cycles = cycles + 18;
    break;
case 0xe2: /*** xor %o(p2) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p2+t16) & 0xFFFF;
    ;
    READ();
    ac = ac ^ mbr;
    cycles = cycles + 18;
    break;
case 0xe3: /*** xor %o(p3) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p3+t16) & 0xFFFF;
    ;
    READ();
    ac = ac ^ mbr;
    cycles = cycles + 18;
    break;
case 0xe4: /*** xri %c ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    ac = ac ^ mbr;
    cycles = cycles + 10;
    break;
case 0xe5: /*** xor @%o(p1) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    if (mbr & 0x80) { p1 = (p1+(mbr|0xFF00)) & 0xFFFF;
     mar = p1;
     } else { mar = p1;
      p1 = (p1+mbr) & 0xFFFF;
     };
    READ();
    ac = ac ^ mbr;
    cycles = cycles + 18;
    break;
case 0xe6: /*** xor @%o(p2) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    if (mbr & 0x80) { p2 = (p2+(mbr|0xFF00)) & 0xFFFF;
     mar = p2;
     } else { mar = p2;
      p2 = (p2+mbr) & 0xFFFF;
     };
    READ();
    ac = ac ^ mbr;
    cycles = cycles + 18;
    break;
case 0xe7: /*** xor @%o(p3) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    if (mbr & 0x80) { p3 = (p3+(mbr|0xFF00)) & 0xFFFF;
     mar = p3;
     } else { mar = p3;
      p3 = (p3+mbr) & 0xFFFF;
     };
    READ();
    ac = ac ^ mbr;
    cycles = cycles + 18;
    break;
case 0xe8: /*** dad %o(p0) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p0+t16) & 0xFFFF;
    ;
    READ();
    			t16 = (ac & 0x0F)+(mbr & 0x0F)+cyl;
    			cyl = 0;
    			if (t16 > 9) t16 = t16 + 6;
    			t16 = t16 + (ac & 0xF0) + (mbr & 0xF0);
    			if (t16 > 0x99) { t16 = t16 + 0x60;
    cyl = 1;
     }			ac = t16 & 0xFF;
    		;
    cycles = cycles + 23;
    break;
case 0xe9: /*** dad %o(p1) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p1+t16) & 0xFFFF;
    ;
    READ();
    			t16 = (ac & 0x0F)+(mbr & 0x0F)+cyl;
    			cyl = 0;
    			if (t16 > 9) t16 = t16 + 6;
    			t16 = t16 + (ac & 0xF0) + (mbr & 0xF0);
    			if (t16 > 0x99) { t16 = t16 + 0x60;
    cyl = 1;
     }			ac = t16 & 0xFF;
    		;
    cycles = cycles + 23;
    break;
case 0xea: /*** dad %o(p2) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p2+t16) & 0xFFFF;
    ;
    READ();
    			t16 = (ac & 0x0F)+(mbr & 0x0F)+cyl;
    			cyl = 0;
    			if (t16 > 9) t16 = t16 + 6;
    			t16 = t16 + (ac & 0xF0) + (mbr & 0xF0);
    			if (t16 > 0x99) { t16 = t16 + 0x60;
    cyl = 1;
     }			ac = t16 & 0xFF;
    		;
    cycles = cycles + 23;
    break;
case 0xeb: /*** dad %o(p3) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p3+t16) & 0xFFFF;
    ;
    READ();
    			t16 = (ac & 0x0F)+(mbr & 0x0F)+cyl;
    			cyl = 0;
    			if (t16 > 9) t16 = t16 + 6;
    			t16 = t16 + (ac & 0xF0) + (mbr & 0xF0);
    			if (t16 > 0x99) { t16 = t16 + 0x60;
    cyl = 1;
     }			ac = t16 & 0xFF;
    		;
    cycles = cycles + 23;
    break;
case 0xec: /*** dai %c ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    ;
    			t16 = (ac & 0x0F)+(mbr & 0x0F)+cyl;
    			cyl = 0;
    			if (t16 > 9) t16 = t16 + 6;
    			t16 = t16 + (ac & 0xF0) + (mbr & 0xF0);
    			if (t16 > 0x99) { t16 = t16 + 0x60;
    cyl = 1;
     }			ac = t16 & 0xFF;
    		;
    cycles = cycles + 15;
    break;
case 0xed: /*** dad @%o(p1) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    if (mbr & 0x80) { p1 = (p1+(mbr|0xFF00)) & 0xFFFF;
     mar = p1;
     } else { mar = p1;
      p1 = (p1+mbr) & 0xFFFF;
     };
    READ();
    			t16 = (ac & 0x0F)+(mbr & 0x0F)+cyl;
    			cyl = 0;
    			if (t16 > 9) t16 = t16 + 6;
    			t16 = t16 + (ac & 0xF0) + (mbr & 0xF0);
    			if (t16 > 0x99) { t16 = t16 + 0x60;
    cyl = 1;
     }			ac = t16 & 0xFF;
    		;
    cycles = cycles + 23;
    break;
case 0xee: /*** dad @%o(p2) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    if (mbr & 0x80) { p2 = (p2+(mbr|0xFF00)) & 0xFFFF;
     mar = p2;
     } else { mar = p2;
      p2 = (p2+mbr) & 0xFFFF;
     };
    READ();
    			t16 = (ac & 0x0F)+(mbr & 0x0F)+cyl;
    			cyl = 0;
    			if (t16 > 9) t16 = t16 + 6;
    			t16 = t16 + (ac & 0xF0) + (mbr & 0xF0);
    			if (t16 > 0x99) { t16 = t16 + 0x60;
    cyl = 1;
     }			ac = t16 & 0xFF;
    		;
    cycles = cycles + 23;
    break;
case 0xef: /*** dad @%o(p3) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    if (mbr & 0x80) { p3 = (p3+(mbr|0xFF00)) & 0xFFFF;
     mar = p3;
     } else { mar = p3;
      p3 = (p3+mbr) & 0xFFFF;
     };
    READ();
    			t16 = (ac & 0x0F)+(mbr & 0x0F)+cyl;
    			cyl = 0;
    			if (t16 > 9) t16 = t16 + 6;
    			t16 = t16 + (ac & 0xF0) + (mbr & 0xF0);
    			if (t16 > 0x99) { t16 = t16 + 0x60;
    cyl = 1;
     }			ac = t16 & 0xFF;
    		;
    cycles = cycles + 23;
    break;
case 0xf0: /*** add %o(p0) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p0+t16) & 0xFFFF;
    ;
    READ();
    t16 = ac + mbr + cyl;
    ac = (t16 & 0xFF);
    cyl = (t16 >> 8) & 1;
    ;
    cycles = cycles + 19;
    break;
case 0xf1: /*** add %o(p1) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p1+t16) & 0xFFFF;
    ;
    READ();
    t16 = ac + mbr + cyl;
    ac = (t16 & 0xFF);
    cyl = (t16 >> 8) & 1;
    ;
    cycles = cycles + 19;
    break;
case 0xf2: /*** add %o(p2) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p2+t16) & 0xFFFF;
    ;
    READ();
    t16 = ac + mbr + cyl;
    ac = (t16 & 0xFF);
    cyl = (t16 >> 8) & 1;
    ;
    cycles = cycles + 19;
    break;
case 0xf3: /*** add %o(p3) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p3+t16) & 0xFFFF;
    ;
    READ();
    t16 = ac + mbr + cyl;
    ac = (t16 & 0xFF);
    cyl = (t16 >> 8) & 1;
    ;
    cycles = cycles + 19;
    break;
case 0xf4: /*** adi %c ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    ;
    t16 = ac + mbr + cyl;
    ac = (t16 & 0xFF);
    cyl = (t16 >> 8) & 1;
    ;
    cycles = cycles + 11;
    break;
case 0xf5: /*** add @%o(p1) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    if (mbr & 0x80) { p1 = (p1+(mbr|0xFF00)) & 0xFFFF;
     mar = p1;
     } else { mar = p1;
      p1 = (p1+mbr) & 0xFFFF;
     };
    READ();
    t16 = ac + mbr + cyl;
    ac = (t16 & 0xFF);
    cyl = (t16 >> 8) & 1;
    ;
    cycles = cycles + 19;
    break;
case 0xf6: /*** add @%o(p2) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    if (mbr & 0x80) { p2 = (p2+(mbr|0xFF00)) & 0xFFFF;
     mar = p2;
     } else { mar = p2;
      p2 = (p2+mbr) & 0xFFFF;
     };
    READ();
    t16 = ac + mbr + cyl;
    ac = (t16 & 0xFF);
    cyl = (t16 >> 8) & 1;
    ;
    cycles = cycles + 19;
    break;
case 0xf7: /*** add @%o(p3) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    if (mbr & 0x80) { p3 = (p3+(mbr|0xFF00)) & 0xFFFF;
     mar = p3;
     } else { mar = p3;
      p3 = (p3+mbr) & 0xFFFF;
     };
    READ();
    t16 = ac + mbr + cyl;
    ac = (t16 & 0xFF);
    cyl = (t16 >> 8) & 1;
    ;
    cycles = cycles + 19;
    break;
case 0xf8: /*** cad %o(p0) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p0+t16) & 0xFFFF;
    ;
    READ();
    mbr = mbr ^ 0xFF;
    t16 = ac + mbr + cyl;
    ac = (t16 & 0xFF);
    cyl = (t16 >> 8) & 1;
    ;
    cycles = cycles + 20;
    break;
case 0xf9: /*** cad %o(p1) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p1+t16) & 0xFFFF;
    ;
    READ();
    mbr = mbr ^ 0xFF;
    t16 = ac + mbr + cyl;
    ac = (t16 & 0xFF);
    cyl = (t16 >> 8) & 1;
    ;
    cycles = cycles + 20;
    break;
case 0xfa: /*** cad %o(p2) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p2+t16) & 0xFFFF;
    ;
    READ();
    mbr = mbr ^ 0xFF;
    t16 = ac + mbr + cyl;
    ac = (t16 & 0xFF);
    cyl = (t16 >> 8) & 1;
    ;
    cycles = cycles + 20;
    break;
case 0xfb: /*** cad %o(p3) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    t16 = (mbr & 0x80) ? (mbr | 0xFF00) : mbr;
    mar = (p3+t16) & 0xFFFF;
    ;
    READ();
    mbr = mbr ^ 0xFF;
    t16 = ac + mbr + cyl;
    ac = (t16 & 0xFF);
    cyl = (t16 >> 8) & 1;
    ;
    cycles = cycles + 20;
    break;
case 0xfc: /*** cai %c ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    mbr = mbr ^ 0xFF;
    t16 = ac + mbr + cyl;
    ac = (t16 & 0xFF);
    cyl = (t16 >> 8) & 1;
    ;
    cycles = cycles + 12;
    break;
case 0xfd: /*** cad @%o(p1) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    if (mbr & 0x80) { p1 = (p1+(mbr|0xFF00)) & 0xFFFF;
     mar = p1;
     } else { mar = p1;
      p1 = (p1+mbr) & 0xFFFF;
     };
    READ();
    mbr = mbr ^ 0xFF;
    t16 = ac + mbr + cyl;
    ac = (t16 & 0xFF);
    cyl = (t16 >> 8) & 1;
    ;
    cycles = cycles + 20;
    break;
case 0xfe: /*** cad @%o(p2) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    if (mbr & 0x80) { p2 = (p2+(mbr|0xFF00)) & 0xFFFF;
     mar = p2;
     } else { mar = p2;
      p2 = (p2+mbr) & 0xFFFF;
     };
    READ();
    mbr = mbr ^ 0xFF;
    t16 = ac + mbr + cyl;
    ac = (t16 & 0xFF);
    cyl = (t16 >> 8) & 1;
    ;
    cycles = cycles + 20;
    break;
case 0xff: /*** cad @%o(p3) ***/
    p0 = (p0 + 1) & 0xFFFF;
    mar = p0;
    READ();
    if (mbr == 0x80) mbr = e;
    ;
    if (mbr & 0x80) { p3 = (p3+(mbr|0xFF00)) & 0xFFFF;
     mar = p3;
     } else { mar = p3;
      p3 = (p3+mbr) & 0xFFFF;
     };
    READ();
    mbr = mbr ^ 0xFF;
    t16 = ac + mbr + cyl;
    ac = (t16 & 0xFF);
    cyl = (t16 >> 8) & 1;
    ;
    cycles = cycles + 20;
    break;
