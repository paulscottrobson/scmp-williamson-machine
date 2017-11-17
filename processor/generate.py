#
#	SC/MP processor
#
import re
src = [x.replace("\t"," ") for x in open("scmp.def").readlines()]
src = [x if x.find("//") < 0 else x[:x.find("//")] for x in src]
src = [x.strip() for x in src if x.strip() != ""]

mnemonics = [ None ] * 256
execCode = [ None ] * 256

for l in src:
	m = re.match("^([0-9A-F\-]+)\s*(\d+)\s*\"(.*?)\"\s*(.*)$",l)
	assert m is not None,"Bad line "+l
	g1 = m.group(1)
	opcr = [ int(g1,16)] if len(g1) == 2 else range(int(g1[:2],16),int(g1[-2:],16)+1)
	for op in opcr:
		assert mnemonics[op] is None,"duplicate "+l
		mnemonics[op] = m.group(3).replace("@p",str(op & 3))
		code = m.group(4)+";$cycles = $cycles + {0};".format(m.group(2))

		eacidx = "@fetch;[E];$t16 = ($mbr & 0x80) ? ($mbr | 0xFF00) : $mbr;$mar = ($p@p+$t16) & 0xFFFF;"
		eReplace = "if ($mbr == 0x80) $mbr = $e;"
		code = code.replace("@eacidxe",eacidx.replace("[E]",eReplace))
		code = code.replace("@eacidx",eacidx.replace("[E]",""))

		eacaidx = "@fetch;[E];if ($mbr & 0x80) { $p@p = ($p@p+($mbr|0xFF00)) & 0xFFFF; $mar = $p@p; } else { $mar = $p@p;  $p@p = ($p@p+$mbr) & 0xFFFF; }"
		code = code.replace("@eacaidxe",eacaidx.replace("[E]",eReplace))

		code = code.replace("@fetch","$p0 = ($p0 + 1) & 0xFFFF;$mar = $p0;$read()")

		code = code.replace("@upstatus","$status = ($status & 0x0F)+($senseA() ? 0x10:0x00)+($senseB() ? 0x20:0x00)+($ov ? 0x40:0x00)+($cyl ? 0x80:0x00);")

		code = code.replace("@binadd","$t16 = $ac + $mbr + $cyl;$ac = ($t16 & 0xFF);$cyl = ($t16 >> 8) & 1;")

		code = code.replace("@decadd","""
			$t16 = ($ac & 0x0F)+($mbr & 0x0F)+$cyl;
			$cyl = 0;
			if ($t16 > 9) $t16 = $t16 + 6;
			$t16 = $t16 + ($ac & 0xF0) + ($mbr & 0xF0);
			if ($t16 > 0x99) { $t16 = $t16 + 0x60;$cyl = 1; }
			$ac = $t16 & 0xFF;
		""".replace("\n",""))		
		execCode[op] = code.replace("@p",str(op & 3))

for i in range(0,256):
	if mnemonics[i] is None:
		mnemonics[i] = "db {0:02x}".format(i)
		execCode[i] = ";"

h = open("__scmp_mnemonics.h","w").write("{ "+",".join(['"'+x+'"' for x in mnemonics])+ "};")

h = open("__scmp_case.h","w")
for i in range(0,256):
	h.write("case 0x{0:02x}: /*** {1} ***/\n".format(i,mnemonics[i]))
	h.write("    "+execCode[i].replace("$","").replace("read()","READ()").replace("write()","WRITE()").replace(";",";\n    ")+"break;\n")
h.close()

h = open("__scmp_gen_class.ts","w")
h.write("class SCMPOpcodes {\n")
for i in range(0,256):
	h.write("function opcode{0:02x}():void {{ \n".format(i))
	h.write("    "+execCode[i].replace("$","this.")+"\n")
	h.write("}\n")
h.write("function getOpcodeFunctions(): Function[] {\n")
h.write('return ['+",".join(["this.opcode{0:02x}".format(x) for x in range(0,256)])+']\n')
h.write("}\n}\n")
h.close()