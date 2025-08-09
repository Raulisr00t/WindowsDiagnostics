
ulonglong AllocateVectorMemory(undefined8 *param_1,ulonglong param_2)

{
  code *pcVar1;
  ulonglong in_RAX;
  ulonglong uVar2;
  void *pvVar3;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  if (param_2 == 0) {
    uVar2 = in_RAX & 0xffffffffffffff00;
  }
  else {
    if (0x3fffffffffffffff < param_2) {
      ThrowVectorTooLongException("vector<T> too long");
      pcVar1 = (code *)swi(3);
      uVar2 = (*pcVar1)();
      return uVar2;
    }
    pvVar3 = MemoryAllocate(param_2 * 4);
    if (pvVar3 == (void *)0x0) {
      ThrowBadAllocationException();
      pcVar1 = (code *)swi(3);
      uVar2 = (*pcVar1)();
      return uVar2;
    }
    *param_1 = pvVar3;
    param_1[1] = pvVar3;
    pvVar3 = (void *)((longlong)pvVar3 + param_2 * 4);
    param_1[2] = pvVar3;
    uVar2 = CONCAT71((int7)((ulonglong)pvVar3 >> 8),1);
  }
  return uVar2;
}

