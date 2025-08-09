
undefined1 CheckEscapeSequence(longlong *param_1)

{
  short *psVar1;
  
  psVar1 = (short *)(*param_1 + 2);
  if (psVar1 != (short *)param_1[2]) {
    if (((*(uint *)(param_1 + 0x10) & 8) == 0) && ((ushort)(*psVar1 - L'('U) < 2)) {
      return 1;
    }
    if (((*(uint *)(param_1 + 0x10) & 0x10) == 0) && ((*psVar1 - L'{'U & 0xfffd) == 0)) {
      return 1;
    }
  }
  return 0;
}

