
void CreateAndInsertRegexNode(longlong param_1,undefined4 param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar1 = (undefined8 *)MemoryAllocate(32);
  puVar2 = (undefined8 *)0x0;
  if (puVar1 != (undefined8 *)0x0) {
    *(undefined4 *)(puVar1 + 1) = param_2;
    *puVar1 = &PTR_FUN_140067728;
    *(undefined4 *)((longlong)puVar1 + 0xc) = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar2 = puVar1;
  }
  InsertNodeIntoList(param_1,(longlong)puVar2);
  return;
}

