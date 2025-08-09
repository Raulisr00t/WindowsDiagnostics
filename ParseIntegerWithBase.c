
int ParseIntegerWithBase(longlong *parserCtx,int base,int max_digits)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  
  *(undefined4 *)((longlong)parserCtx + 0x74) = 0;
  if (max_digits != 0) {
    do {
      uVar1 = *(ushort *)(parserCtx + 0xf);
      uVar2 = (uint)uVar1;
      if (base == 8) {
        if (7 < (ushort)(uVar1 - 0x30)) {
          return max_digits;
        }
LAB_140023b8e:
        iVar3 = uVar2 - 0x30;
      }
      else {
        if ((ushort)(uVar1 - 0x30) < 10) goto LAB_140023b8e;
        if (base != 0x10) {
          return max_digits;
        }
        if ((ushort)(uVar1 - 0x61) < 6) {
          iVar3 = uVar2 - 0x57;
        }
        else {
          if (5 < (ushort)(uVar1 - 0x41)) {
            return max_digits;
          }
          iVar3 = uVar2 - 0x37;
        }
      }
      if (iVar3 == -1) {
        return max_digits;
      }
      *(int *)((longlong)parserCtx + 0x74) = base * *(int *)((longlong)parserCtx + 0x74) + iVar3;
      HandleEscapeAndAdvanceChar(parserCtx);
      max_digits = max_digits + -1;
    } while (max_digits != 0);
  }
  return max_digits;
}

