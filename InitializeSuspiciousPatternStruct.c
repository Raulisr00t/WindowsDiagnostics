
longlong *
InitializeSuspiciousPatternStruct
          (longlong *param_1,longlong param_2,undefined8 param_3,longlong param_4)

{
  undefined8 *puVar1;
  char cStack0000000000000028;
  
  *param_1 = (longlong)
             L"(.*(invoke-expression|invoke-command|\\$\\([\\b\\s]*iex|\\$\\([\\b\\s]*icm|\\[char\\] ).*)|(^[\\b\\s]*&.*)|(.*;[\\b\\s]*&.*)|(.*(\\[system\\.|\"|\').*)"
  ;
  param_1[1] = (longlong)
               L"(.*(invoke-expression|invoke-command|\\$\\([\\b\\s]*iex|\\$\\([\\b\\s]*icm|\\[char\ \]).*)|(^[\\b\\s]*&.*)|(.*;[\\b\\s]*&.*)|(.*(\\[system\\.|\"|\').*)"
  ;
  param_1[2] = param_4;
  *(undefined4 *)(param_1 + 3) = 0;
  *(undefined4 *)((longlong)param_1 + 0x1c) = 0;
  cStack0000000000000028 = '\0';
  InitMatchBufferWithCharFlag(param_1 + 4,param_2,&stack0x00000028,param_4);
  UpdateBitVector(param_1 + 4,0);
  puVar1 = (undefined8 *)MemoryAllocate(48);
  if (puVar1 != (undefined8 *)0x0) {
    *(undefined4 *)(puVar1 + 1) = 0x14;
    *(undefined4 *)((longlong)puVar1 + 0xc) = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    *puVar1 = &PTR_FUN_140067728;
    *(undefined4 *)((longlong)puVar1 + L'$') = 0;
    *(undefined4 *)(puVar1 + 5) = 0;
    *(undefined4 *)((longlong)puVar1 + L',') = 0;
  }
  param_1[8] = (longlong)puVar1;
  param_1[9] = (longlong)puVar1;
  *(undefined4 *)(param_1 + 10) = 0x100;
  param_1[11] = param_2;
  *(undefined4 *)(param_1 + 0xc) = 0x100;
  *(undefined4 *)((longlong)param_1 + 100) = 4;
  param_1[0xd] = param_2;
  *(undefined4 *)(param_1 + 0xe) = 0x100;
  *(undefined4 *)(param_1 + 0x10) = 0x8775dfb;
  UpdateCurrentCharAndValidate(param_1);
  return param_1;
}

