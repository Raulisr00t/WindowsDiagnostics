
void FillVectorWithValue(undefined8 *param_1,ulonglong param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  ulonglong uVar2;
  undefined4 *puVar3;
  
  uVar2 = AllocateVectorMemory(param_1,param_2);
  if ((char)uVar2 != '\0') {
    puVar1 = (undefined4 *)*param_1;
    uVar2 = param_2;
    puVar3 = puVar1;
    if (param_2 != 0) {
      do {
        *puVar3 = *param_3;
        puVar3 = puVar3 + 1;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    param_1[1] = puVar1 + param_2;
  }
  return;
}

