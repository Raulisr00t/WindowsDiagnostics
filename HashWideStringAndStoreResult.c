
undefined8 HashWideStringAndStoreResult(longlong input,uint *out_hash)

{
  wint_t wVar1;
  ushort uVar2;
  longlong lVar3;
  wint_t *pwVar4;
  uint uVar5;
  
  lVar3 = -1;
  do {
    lVar3 = lVar3 + 1;
  } while (*(short *)(input + lVar3 * 2) != 0);
  uVar2 = (short)lVar3 - 1;
  pwVar4 = (wint_t *)(input + (ulonglong)uVar2 * 2);
  wVar1 = towlower(*pwVar4);
  uVar5 = (uint)wVar1;
  for (; uVar2 != 0; uVar2 = uVar2 - 1) {
    pwVar4 = pwVar4 + -1;
    wVar1 = towlower(*pwVar4);
    uVar5 = uVar5 * 0x25 + (uint)wVar1;
  }
  *out_hash = uVar5 * 0x41c64e6d + 0x3039 >> 0x10 | uVar5 * 0x10dcd + 1 & 0xffff0000;
  return 0;
}

