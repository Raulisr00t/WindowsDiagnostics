
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 CreatePackageCollection(longlong *param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  if (param_1 == (longlong *)0x0) {
    uVar1 = 0x80070057;
    uVar3 = 0x34;
  }
  else if (param_2 == (undefined8 *)0x0) {
    uVar1 = 0x80070057;
    uVar3 = 0x35;
  }
  else {
    puVar2 = (undefined8 *)MemoryAllocate(80);
    if (puVar2 != (undefined8 *)0x0) {
      puVar2[1] = 0;
      *puVar2 = &PTR_FUN_140067e20;
      puVar2[2] = 0;
      puVar2[3] = 0;
      puVar2[4] = 1;
      puVar2[5] = 0;
      puVar2[6] = 0;
      puVar2[8] = 0;
      *(undefined4 *)(puVar2 + 9) = 0;
      puVar2[7] = param_1;
      (**(code **)(*param_1 + 8))(param_1);
      *param_2 = puVar2;
      return 0;
    }
    uVar1 = 0x8007000e;
    uVar3 = 0x38;
  }
  PrintERROR(1,"Met ERROR: %s:%d - hr = 0x%08X\n","CreatePackageCollection",uVar3);
  return uVar1;
}

