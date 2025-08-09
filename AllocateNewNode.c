
void AllocateNewNode(longlong param_1,undefined4 param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar1 = (undefined8 *)MemoryAllocate(40);
  puVar2 = (undefined8 *)0x0;
  if (puVar1 != (undefined8 *)0x0) {
    puVar1[2] = 0;
    puVar1[3] = 0;
    *puVar1 = &PTR_FUN_140067728;
    puVar1[1] = 0xd;
    *(undefined4 *)(puVar1 + 4) = param_2;
    puVar2 = puVar1;
  }
  InsertNodeIntoList(param_1,(longlong)puVar2);
  return;
}

