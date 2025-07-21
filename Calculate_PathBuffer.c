
uint Calculate_PathBuffer(short *param_1,longlong MAX_PATH,longlong param_3)

{
  short *psVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  
  psVar1 = param_1;
  lVar4 = MAX_PATH;
  if (MAX_PATH - 1U < 0x7fffffff) {
    do {
      if (*psVar1 == 0) break;
      lVar4 = lVar4 + -1;
      psVar1 = psVar1 + 1;
    } while (lVar4 != 0);
    uVar2 = ~-(uint)(lVar4 != 0) & 0x80070057;
    uVar3 = -(ulonglong)(lVar4 != 0) & MAX_PATH - lVar4;
    if (lVar4 != 0) {
      uVar2 = SafeWcsCopyInternal(param_1 + uVar3,MAX_PATH - uVar3,uVar3,param_3);
    }
  }
  else {
    uVar2 = 0x80070057;
  }
  return uVar2;
}

