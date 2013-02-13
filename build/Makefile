include ../config.mak

VPATH=../asm:../disasm:../common:../simulate:../table

default: $(ASM_OBJS) $(DISASM_OBJS) $(COMMON_OBJS) $(SIM_OBJS) $(TABLE_OBJS)
	$(CC) -o ../naken_asm$(CONFIG_EXT) ../common/naken_asm.c $(ASM_OBJS) \
	   $(DISASM_OBJS) $(COMMON_OBJS) $(SIM_OBJS) $(TABLE_OBJS) \
	    -DINCLUDE_PATH="\"$(INCLUDE_PATH)\"" \
	   $(CFLAGS) $(LDFLAGS)
	$(CC) -o ../naken_util$(CONFIG_EXT) ../common/naken_util.c \
	   $(DISASM_OBJS) \
	   $(TABLE_OBJS) \
	   $(SIM_OBJS) \
	   $(DFLAGS) \
	   parse_elf.o parse_hex.o memory.o \
	   -I../disasm -I../common -I../simulate \
	   $(CFLAGS) $(LDFLAGS) $(LDFLAGS_UTIL)

assembler.o: assembler.c assembler.h
	$(CC) -c $< -o $*.o $(CFLAGS) $(LDFLAGS) $(DFLAGS) \
	   -I../common -I../disasm -I../table -I../asm -I../simulate

%.o: %.c %.h
	$(CC) -c $< -o $*.o $(CFLAGS) $(LDFLAGS) \
	   -I../common -I../disasm -I../table -I../asm -I../simulate

%.o: %.c
	$(CC) -c $< -o $*.o $(CFLAGS) $(LDFLAGS) \
	   -I../common -I../disasm -I../table -I../asm -I../simulate


