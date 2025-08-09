
ulonglong IsNodeTypeAllowed(longlong parserNodePtr)

{
  uint uVar1;
  ulonglong uVar2;
  
  uVar1 = *(uint *)(*(longlong *)(parserNodePtr + 8) + 8);
  uVar2 = (ulonglong)uVar1;
  if ((uVar1 < 0x15) && ((0x102100U >> (uVar1 & 0x1f) & 1) != 0)) {
LAB_140022d23:
    return CONCAT71((int7)(uVar2 >> 8),1);
  }
  if (uVar1 == 2) {
    uVar2 = *(ulonglong *)(*(longlong *)(parserNodePtr + 8) + 0x18);
    if ((*(uint *)(uVar2 + 8) < 0x15) && ((0x102100U >> (*(uint *)(uVar2 + 8) & 0x1f) & 1) != 0))
    goto LAB_140022d23;
  }
  return uVar2 & 0xffffffffffffff00;
}

