/**
 *  naken_asm assembler.
 *  Author: Michael Kohn
 *   Email: mike@mikekohn.net
 *     Web: http://www.mikekohn.net/
 * License: GPL
 *
 * Copyright 2010-2016 by Michael Kohn
 *
 */

#include <stdlib.h>

#include "table/6800.h"

// Based on: http://mdfs.net/Docs/Comp/6800/OpList

struct _table_6800 table_6800[] = {
  { NULL, M6800_OP_UNDEF },  // 0x00
  { "nop", M6800_OP_NONE },  // 0x01
  { NULL, M6800_OP_UNDEF },  // 0x02
  { NULL, M6800_OP_UNDEF },  // 0x03
  { NULL, M6800_OP_UNDEF },  // 0x04
  { NULL, M6800_OP_UNDEF },  // 0x05
  { "tap", M6800_OP_NONE },  // 0x06
  { "tpa", M6800_OP_NONE },  // 0x07
  { "inx", M6800_OP_NONE },  // 0x08
  { "dex", M6800_OP_NONE },  // 0x09
  { "clv", M6800_OP_NONE },  // 0x0a
  { "sev", M6800_OP_NONE },  // 0x0b
  { "clc", M6800_OP_NONE },  // 0x0c
  { "sec", M6800_OP_NONE },  // 0x0d
  { "cli", M6800_OP_NONE },  // 0x0e
  { "sei", M6800_OP_NONE },  // 0x0f
  { "sba", M6800_OP_NONE },  // 0x10
  { "cba", M6800_OP_NONE },  // 0x11
  { NULL, M6800_OP_UNDEF },  // 0x12
  { NULL, M6800_OP_UNDEF },  // 0x13
  { NULL, M6800_OP_UNDEF },  // 0x14
  { NULL, M6800_OP_UNDEF },  // 0x15
  { "tab", M6800_OP_NONE },  // 0x16
  { "tba", M6800_OP_NONE },  // 0x17
  { NULL, M6800_OP_UNDEF },  // 0x18
  { "daa", M6800_OP_NONE },  // 0x19
  { NULL, M6800_OP_UNDEF },  // 0x1a
  { "aba", M6800_OP_NONE },  // 0x1b
  { NULL, M6800_OP_UNDEF },  // 0x1c
  { NULL, M6800_OP_UNDEF },  // 0x1d
  { NULL, M6800_OP_UNDEF },  // 0x1e
  { NULL, M6800_OP_UNDEF },  // 0x1f
  { "bra", M6800_OP_REL_OFFSET },  // 0x20
  { NULL, M6800_OP_UNDEF },  // 0x21
  { "bhi", M6800_OP_REL_OFFSET },  // 0x22
  { "bls", M6800_OP_REL_OFFSET },  // 0x23
  { "bcc", M6800_OP_REL_OFFSET },  // 0x24
  { "bcs", M6800_OP_REL_OFFSET },  // 0x25
  { "bne", M6800_OP_REL_OFFSET },  // 0x26
  { "beq", M6800_OP_REL_OFFSET },  // 0x27
  { "bvc", M6800_OP_REL_OFFSET },  // 0x28
  { "bvs", M6800_OP_REL_OFFSET },  // 0x29
  { "bpl", M6800_OP_REL_OFFSET },  // 0x2a
  { "bmi", M6800_OP_REL_OFFSET },  // 0x2b
  { "bge", M6800_OP_REL_OFFSET },  // 0x2c
  { "blt", M6800_OP_REL_OFFSET },  // 0x2d
  { "bgt", M6800_OP_REL_OFFSET },  // 0x2e
  { "ble", M6800_OP_REL_OFFSET },  // 0x2f
  { "tsx", M6800_OP_NONE },  // 0x30
  { "ins", M6800_OP_NONE },  // 0x31
  { "pula", M6800_OP_NONE },  // 0x32
  { "pulb", M6800_OP_NONE },  // 0x33
  { "des", M6800_OP_NONE },  // 0x34
  { "txs", M6800_OP_NONE },  // 0x35
  { "psha", M6800_OP_NONE },  // 0x36
  { "pshb", M6800_OP_NONE },  // 0x37
  { NULL, M6800_OP_UNDEF },  // 0x38
  { "rts", M6800_OP_NONE },  // 0x39
  { NULL, M6800_OP_UNDEF },  // 0x3a
  { "rti", M6800_OP_NONE },  // 0x3b
  { NULL, M6800_OP_UNDEF },  // 0x3c
  { "wai", M6800_OP_NONE },  // 0x3d
  { NULL, M6800_OP_UNDEF },  // 0x3e
  { "swi", M6800_OP_NONE },  // 0x3f
  { "nega", M6800_OP_NONE },  // 0x40
  { NULL, M6800_OP_UNDEF },  // 0x41
  { NULL, M6800_OP_UNDEF },  // 0x42
  { "coma", M6800_OP_NONE },  // 0x43
  { "lsra", M6800_OP_NONE },  // 0x44
  { NULL, M6800_OP_UNDEF },  // 0x45
  { "rora", M6800_OP_NONE },  // 0x46
  { "asra", M6800_OP_NONE },  // 0x47
  { "asla", M6800_OP_NONE },  // 0x48
  { "rola", M6800_OP_NONE },  // 0x49
  { "deca", M6800_OP_NONE },  // 0x4a
  { NULL, M6800_OP_UNDEF },  // 0x4b
  { "inca", M6800_OP_NONE },  // 0x4c
  { "tsta", M6800_OP_NONE },  // 0x4d
  { NULL, M6800_OP_UNDEF },  // 0x4e
  { "clra", M6800_OP_NONE },  // 0x4f
  { "negb", M6800_OP_NONE },  // 0x50
  { NULL, M6800_OP_UNDEF },  // 0x51
  { NULL, M6800_OP_UNDEF },  // 0x52
  { "comb", M6800_OP_NONE },  // 0x53
  { "lsrb", M6800_OP_NONE },  // 0x54
  { NULL, M6800_OP_UNDEF },  // 0x55
  { "rorb", M6800_OP_NONE },  // 0x56
  { "asrb", M6800_OP_NONE },  // 0x57
  { "aslb", M6800_OP_NONE },  // 0x58
  { "rolb", M6800_OP_NONE },  // 0x59
  { "decb", M6800_OP_NONE },  // 0x5a
  { NULL, M6800_OP_UNDEF },  // 0x5b
  { "incb", M6800_OP_NONE },  // 0x5c
  { "tstb", M6800_OP_NONE },  // 0x5d
  { NULL, M6800_OP_UNDEF },  // 0x5e
  { "clrb", M6800_OP_NONE },  // 0x5f
  { "neg", M6800_OP_NN_X },  // 0x60
  { NULL, M6800_OP_UNDEF },  // 0x61
  { NULL, M6800_OP_UNDEF },  // 0x62
  { "com", M6800_OP_NN_X },  // 0x63
  { "lsr", M6800_OP_NN_X },  // 0x64
  { NULL, M6800_OP_UNDEF },  // 0x65
  { "ror", M6800_OP_NN_X },  // 0x66
  { "asr", M6800_OP_NN_X },  // 0x67
  { "asl", M6800_OP_NN_X },  // 0x68
  { "rol", M6800_OP_NN_X },  // 0x69
  { "dec", M6800_OP_NN_X },  // 0x6a
  { NULL, M6800_OP_UNDEF },  // 0x6b
  { "inc", M6800_OP_NN_X },  // 0x6c
  { "tst", M6800_OP_NN_X },  // 0x6d
  { "jmp", M6800_OP_NN_X },  // 0x6e
  { "clr", M6800_OP_NN_X },  // 0x6f
  { "neg", M6800_OP_ABSOLUTE_16 },  // 0x70
  { NULL, M6800_OP_UNDEF },  // 0x71
  { NULL, M6800_OP_UNDEF },  // 0x72
  { "com", M6800_OP_ABSOLUTE_16 },  // 0x73
  { "lsr", M6800_OP_ABSOLUTE_16 },  // 0x74
  { NULL, M6800_OP_UNDEF },  // 0x75
  { "ror", M6800_OP_ABSOLUTE_16 },  // 0x76
  { "asr", M6800_OP_ABSOLUTE_16 },  // 0x77
  { "asl", M6800_OP_ABSOLUTE_16 },  // 0x78
  { "rol", M6800_OP_ABSOLUTE_16 },  // 0x79
  { "dec", M6800_OP_ABSOLUTE_16 },  // 0x7a
  { NULL, M6800_OP_UNDEF },  // 0x7b
  { "inc", M6800_OP_ABSOLUTE_16 },  // 0x7c
  { "tst", M6800_OP_ABSOLUTE_16 },  // 0x7d
  { "jmp", M6800_OP_ABSOLUTE_16 },  // 0x7e
  { "clr", M6800_OP_ABSOLUTE_16 },  // 0x7f
  { "suba", M6800_OP_IMM8 },  // 0x80
  { "cmpa", M6800_OP_IMM8 },  // 0x81
  { "sbca", M6800_OP_IMM8 },  // 0x82
  { NULL, M6800_OP_UNDEF },  // 0x83
  { "anda", M6800_OP_IMM8 },  // 0x84
  { "bita", M6800_OP_IMM8 },  // 0x85
  { "ldaa", M6800_OP_IMM8 },  // 0x86
  { NULL, M6800_OP_UNDEF },  // 0x87
  { "eora", M6800_OP_IMM8 },  // 0x88
  { "adca", M6800_OP_IMM8 },  // 0x89
  { "oraa", M6800_OP_IMM8 },  // 0x8a
  { "adda", M6800_OP_IMM8 },  // 0x8b
  { "cpx", M6800_OP_IMM16 },  // 0x8c
  { "bsr", M6800_OP_REL_OFFSET },  // 0x8d
  { "lds", M6800_OP_IMM16 },  // 0x8e
  { NULL, M6800_OP_UNDEF },  // 0x8f
  { "suba", M6800_OP_DIR_PAGE_8 },  // 0x90
  { "cmpa", M6800_OP_DIR_PAGE_8 },  // 0x91
  { "sbca", M6800_OP_DIR_PAGE_8 },  // 0x92
  { NULL, M6800_OP_UNDEF },  // 0x93
  { "anda", M6800_OP_DIR_PAGE_8 },  // 0x94
  { "bita", M6800_OP_DIR_PAGE_8 },  // 0x95
  { "ldaa", M6800_OP_DIR_PAGE_8 },  // 0x96
  { "staa", M6800_OP_DIR_PAGE_8 },  // 0x97
  { "eora", M6800_OP_DIR_PAGE_8 },  // 0x98
  { "adca", M6800_OP_DIR_PAGE_8 },  // 0x99
  { "oraa", M6800_OP_DIR_PAGE_8 },  // 0x9a
  { "adda", M6800_OP_DIR_PAGE_8 },  // 0x9b
  { "cpx", M6800_OP_DIR_PAGE_8 },  // 0x9c
  { NULL, M6800_OP_UNDEF },  // 0x9d
  { "lds", M6800_OP_DIR_PAGE_8 },  // 0x9e
  { "sts", M6800_OP_DIR_PAGE_8 },  // 0x9f
  { "suba", M6800_OP_NN_X },  // 0xa0
  { "cmpa", M6800_OP_NN_X },  // 0xa1
  { "sbca", M6800_OP_NN_X },  // 0xa2
  { NULL, M6800_OP_UNDEF },  // 0xa3
  { "anda", M6800_OP_NN_X },  // 0xa4
  { "bita", M6800_OP_NN_X },  // 0xa5
  { "ldaa", M6800_OP_NN_X },  // 0xa6
  { "staa", M6800_OP_NN_X },  // 0xa7
  { "eora", M6800_OP_NN_X },  // 0xa8
  { "adca", M6800_OP_NN_X },  // 0xa9
  { "oraa", M6800_OP_NN_X },  // 0xaa
  { "adda", M6800_OP_NN_X },  // 0xab
  { "cpx", M6800_OP_NN_X },  // 0xac
  { "jsr", M6800_OP_NN_X },  // 0xad
  { "lds", M6800_OP_NN_X },  // 0xae
  { "sts", M6800_OP_NN_X },  // 0xaf
  { "suba", M6800_OP_ABSOLUTE_16 },  // 0xb0
  { "cmpa", M6800_OP_ABSOLUTE_16 },  // 0xb1
  { "sbca", M6800_OP_ABSOLUTE_16 },  // 0xb2
  { NULL, M6800_OP_UNDEF },  // 0xb3
  { "anda", M6800_OP_ABSOLUTE_16 },  // 0xb4
  { "bita", M6800_OP_ABSOLUTE_16 },  // 0xb5
  { "ldaa", M6800_OP_ABSOLUTE_16 },  // 0xb6
  { "staa", M6800_OP_ABSOLUTE_16 },  // 0xb7
  { "eora", M6800_OP_ABSOLUTE_16 },  // 0xb8
  { "adca", M6800_OP_ABSOLUTE_16 },  // 0xb9
  { "oraa", M6800_OP_ABSOLUTE_16 },  // 0xba
  { "adda", M6800_OP_ABSOLUTE_16 },  // 0xbb
  { "cpx", M6800_OP_ABSOLUTE_16 },  // 0xbc
  { "jsr", M6800_OP_ABSOLUTE_16 },  // 0xbd
  { "lds", M6800_OP_ABSOLUTE_16 },  // 0xbe
  { "sts", M6800_OP_ABSOLUTE_16 },  // 0xbf
  { "subb", M6800_OP_IMM8 },  // 0xc0
  { "cmpb", M6800_OP_IMM8 },  // 0xc1
  { "sbcb", M6800_OP_IMM8 },  // 0xc2
  { NULL, M6800_OP_UNDEF },  // 0xc3
  { "andb", M6800_OP_IMM8 },  // 0xc4
  { "bitb", M6800_OP_IMM8 },  // 0xc5
  { "ldab", M6800_OP_IMM8 },  // 0xc6
  { NULL, M6800_OP_UNDEF },  // 0xc7
  { "eorb", M6800_OP_IMM8 },  // 0xc8
  { "adcb", M6800_OP_IMM8 },  // 0xc9
  { "orab", M6800_OP_IMM8 },  // 0xca
  { "addb", M6800_OP_IMM8 },  // 0xcb
  { NULL, M6800_OP_UNDEF },  // 0xcc
  { NULL, M6800_OP_UNDEF },  // 0xcd
  { "ldx", M6800_OP_IMM16 },  // 0xce
  { NULL, M6800_OP_UNDEF },  // 0xcf
  { "subb", M6800_OP_DIR_PAGE_8 },  // 0xd0
  { "cmpb", M6800_OP_DIR_PAGE_8 },  // 0xd1
  { "sbcb", M6800_OP_DIR_PAGE_8 },  // 0xd2
  { NULL, M6800_OP_UNDEF },  // 0xd3
  { "andb", M6800_OP_DIR_PAGE_8 },  // 0xd4
  { "bitb", M6800_OP_DIR_PAGE_8 },  // 0xd5
  { "ldab", M6800_OP_DIR_PAGE_8 },  // 0xd6
  { "stab", M6800_OP_DIR_PAGE_8 },  // 0xd7
  { "eorb", M6800_OP_DIR_PAGE_8 },  // 0xd8
  { "adcb", M6800_OP_DIR_PAGE_8 },  // 0xd9
  { "orab", M6800_OP_DIR_PAGE_8 },  // 0xda
  { "addb", M6800_OP_DIR_PAGE_8 },  // 0xdb
  { NULL, M6800_OP_UNDEF },  // 0xdc
  { NULL, M6800_OP_UNDEF },  // 0xdd
  { "ldx", M6800_OP_DIR_PAGE_8 },  // 0xde
  { "stx", M6800_OP_DIR_PAGE_8 },  // 0xdf
  { "subb", M6800_OP_NN_X },  // 0xe0
  { "cmpb", M6800_OP_NN_X },  // 0xe1
  { "sbcb", M6800_OP_NN_X },  // 0xe2
  { NULL, M6800_OP_UNDEF },  // 0xe3
  { "andb", M6800_OP_NN_X },  // 0xe4
  { "bitb", M6800_OP_NN_X },  // 0xe5
  { "ldab", M6800_OP_NN_X },  // 0xe6
  { "stab", M6800_OP_NN_X },  // 0xe7
  { "eorb", M6800_OP_NN_X },  // 0xe8
  { "adcb", M6800_OP_NN_X },  // 0xe9
  { "orab", M6800_OP_NN_X },  // 0xea
  { "addb", M6800_OP_NN_X },  // 0xeb
  { NULL, M6800_OP_UNDEF },  // 0xec
  { NULL, M6800_OP_UNDEF },  // 0xed
  { "ldx", M6800_OP_NN_X },  // 0xee
  { "stx", M6800_OP_NN_X },  // 0xef
  { "subb", M6800_OP_ABSOLUTE_16 },  // 0xf0
  { "cmpb", M6800_OP_ABSOLUTE_16 },  // 0xf1
  { "sbcb", M6800_OP_ABSOLUTE_16 },  // 0xf2
  { NULL, M6800_OP_UNDEF },  // 0xf3
  { "andb", M6800_OP_ABSOLUTE_16 },  // 0xf4
  { "bitb", M6800_OP_ABSOLUTE_16 },  // 0xf5
  { "ldab", M6800_OP_ABSOLUTE_16 },  // 0xf6
  { "stab", M6800_OP_ABSOLUTE_16 },  // 0xf7
  { "eorb", M6800_OP_ABSOLUTE_16 },  // 0xf8
  { "adcb", M6800_OP_ABSOLUTE_16 },  // 0xf9
  { "orab", M6800_OP_ABSOLUTE_16 },  // 0xfa
  { "addb", M6800_OP_ABSOLUTE_16 },  // 0xfb
  { NULL, M6800_OP_UNDEF },  // 0xfc
  { NULL, M6800_OP_UNDEF },  // 0xfd
  { "ldx", M6800_OP_ABSOLUTE_16 },  // 0xfe
  { "stx", M6800_OP_ABSOLUTE_16 },  // 0xff
};

