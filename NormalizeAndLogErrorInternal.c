
void NormalizeAndLogErrorInternal(undefined8 param_1,int param_2,undefined8 param_3)

{
  undefined8 uVar1;
  code *pcVar2;
  longlong lVar3;
  undefined8 auStackX_8 [2];
  int aiStackX_18 [2];
  undefined8 uStack_20;
  
  uStack_20 = 0x140004712;
  lVar3 = StackProbing();
  lVar3 = -lVar3;
  *(ulonglong *)(&stack0x00001508 + lVar3) =
       DAT_14007f440 ^ (ulonglong)(&stack0xffffffffffffffe8 + lVar3);
  uVar1 = *(undefined8 *)(&stack0x00001560 + lVar3);
  *(undefined8 *)((longlong)&uStack_20 + lVar3) = 0x14000474c;
  memset(&stack0x00000068 + lVar3,0,0x98);
  *(undefined1 **)(&stack0x00000058 + lVar3) = &stack0x00000068 + lVar3;
  *(undefined1 **)(&stack0x00000048 + lVar3) = &stack0x00000108 + lVar3;
  *(undefined1 **)(&stack0x00000038 + lVar3) = &stack0x00000508 + lVar3;
  *(undefined8 *)(&stack0x00000028 + lVar3) = *(undefined8 *)(&stack0x00001570 + lVar3);
  *(undefined8 *)(&stack0x00000020 + lVar3) = *(undefined8 *)(&stack0x00001568 + lVar3);
  *(undefined4 *)((longlong)aiStackX_18 + lVar3) = 1;
  *(undefined8 *)((longlong)auStackX_8 + lVar3 + 8) = uVar1;
  *(undefined8 *)((longlong)auStackX_8 + lVar3) = 0;
  *(undefined8 *)((longlong)&uStack_20 + lVar3) = 0x1400047b0;
  LogErrorEvent(param_1,param_2,param_3,0,*(undefined8 *)((longlong)auStackX_8 + lVar3),
                *(undefined8 *)((longlong)auStackX_8 + lVar3 + 8),
                *(int *)((longlong)aiStackX_18 + lVar3),*(int **)(&stack0x00000020 + lVar3),
                *(short **)(&stack0x00000028 + lVar3),*(undefined8 *)(&stack0x00000030 + lVar3),
                *(wchar_t **)(&stack0x00000038 + lVar3),*(undefined8 *)(&stack0x00000040 + lVar3),
                *(undefined1 **)(&stack0x00000048 + lVar3),*(undefined8 *)(&stack0x00000050 + lVar 3)
                ,*(int **)(&stack0x00000058 + lVar3));
  if (((&stack0x0000006c)[lVar3] & 1) != 0) {
    *(undefined8 *)((longlong)&uStack_20 + lVar3) = 0x1400047c7;
    FUN_14000730c((longlong)(&stack0x00000068 + lVar3));
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  *(undefined8 *)((longlong)&uStack_20 + lVar3) = 0x1400047d8;
  ProtectStack(*(ulonglong *)(&stack0x00001508 + lVar3) ^
               (ulonglong)(&stack0xffffffffffffffe8 + lVar3));
  return;
}

