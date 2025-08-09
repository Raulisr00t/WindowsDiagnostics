
void CreateWrappedNodeAndInsert(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined4 uVar3;
  
  if (*(int *)(param_2 + 8) == 8) {
    uVar3 = 9;
  }
  else {
    uVar3 = 0xc;
    if (*(int *)(param_2 + 8) != 10) {
      uVar3 = 0xc;
      if (*(int *)(param_2 + 8) != 0xb) {
        uVar3 = 0xe;
      }
    }
  }
  puVar1 = (undefined8 *)MemoryAllocate(40);
  puVar2 = (undefined8 *)0x0;
  if (puVar1 != (undefined8 *)0x0) {
    *(undefined4 *)((longlong)puVar1 + 0xc) = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    *puVar1 = &PTR_FUN_140067728;
    *(undefined4 *)(puVar1 + 1) = uVar3;
    puVar1[4] = param_2;
    puVar2 = puVar1;
  }
  InsertNodeIntoList(param_1,(longlong)puVar2);
  return;
}

