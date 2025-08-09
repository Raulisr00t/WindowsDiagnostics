
undefined8 * CreateAndLinkNodePair(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  
  puVar2 = (undefined8 *)MemoryAllocate(32);
  if (puVar2 == (undefined8 *)0x0) {
    puVar2 = (undefined8 *)0x0;
  }
  else {
    *(undefined4 *)((longlong)puVar2 + 0xc) = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    *(undefined4 *)(puVar2 + 1) = 0x11;
    *puVar2 = &PTR_FUN_140067728;
  }
  InsertNodeIntoList(param_1,(longlong)puVar2);
  puVar3 = (undefined8 *)MemoryAllocate(48);
  if (puVar3 != (undefined8 *)0x0) {
    *(undefined4 *)((longlong)puVar3 + 0xc) = 0;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[5] = 0;
    *puVar3 = &PTR_FUN_1400677f0;
    *(undefined4 *)(puVar3 + 1) = 0x10;
    puVar3[4] = puVar2;
  }
  lVar1 = *(longlong *)(param_2 + 0x10);
  puVar3[3] = *(undefined8 *)(lVar1 + 0x18);
  *(undefined8 **)(*(longlong *)(lVar1 + 0x18) + 0x10) = puVar3;
  puVar3[2] = lVar1;
  *(undefined8 **)(lVar1 + 0x18) = puVar3;
  return puVar2;
}

