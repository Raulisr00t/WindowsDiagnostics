
undefined4 LoadMode(undefined8 param_1,undefined8 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  undefined **ppuVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  
  puVar5 = (undefined8 *)0x0;
  iVar1 = *(int *)(maybe_everything + 0x108);
  if (iVar1 < 8) {
    if (iVar1 != 7) {
      if (((iVar1 == 1) || (iVar1 == 2)) || (iVar1 == 3)) {
        puVar3 = (undefined8 *)MemoryAllocate(120);
        if (puVar3 != (undefined8 *)0x0) {
          puVar3[1] = 0;
          *(undefined4 *)(puVar3 + 2) = 0;
          puVar3[3] = 0;
          *puVar3 = &PTR_FUN_140067a10;
          memset(puVar3 + 4,0,0x58);
          puVar5 = puVar3 + 0xd;
          puVar3[0xe] = puVar5;
          *puVar5 = puVar5;
          puVar5 = puVar3;
        }
        goto LAB_140037e34;
      }
      if (((iVar1 != 4) && (iVar1 != 5)) && (iVar1 != 6)) {
LAB_140037d57:
        uVar2 = 0x8000ffff;
        uVar6 = 0x324;
        goto LAB_140037d62;
      }
    }
LAB_140037ca4:
    puVar3 = (undefined8 *)MemoryAllocate(32);
    if (puVar3 != (undefined8 *)0x0) {
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
      puVar3[3] = 0;
      puVar3[1] = 0;
      *(undefined4 *)(puVar3 + 2) = 0;
      puVar3[3] = 0;
      ppuVar4 = &PTR_FUN_140067de0;
LAB_140037cdb:
      *puVar3 = ppuVar4;
      puVar5 = puVar3;
    }
  }
  else {
    if ((iVar1 == 8) || (iVar1 == 9)) goto LAB_140037ca4;
    if (iVar1 == 10) {
      puVar3 = (undefined8 *)MemoryAllocate(32);
      if (puVar3 == (undefined8 *)0x0) goto LAB_140037e34;
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
      puVar3[3] = 0;
      puVar3[1] = 0;
      *(undefined4 *)(puVar3 + 2) = 0;
      puVar3[3] = 0;
      ppuVar4 = &PTR_FUN_140067dc8;
      goto LAB_140037cdb;
    }
    if (iVar1 == 0xb) {
      puVar3 = (undefined8 *)MemoryAllocate(32);
      if (puVar3 != (undefined8 *)0x0) {
        *puVar3 = 0;
        puVar3[1] = 0;
        puVar3[2] = 0;
        puVar3[3] = 0;
        puVar3[1] = 0;
        *(undefined4 *)(puVar3 + 2) = 0;
        puVar3[3] = 0;
        ppuVar4 = &PTR_FUN_140067db0;
        goto LAB_140037cdb;
      }
    }
    else {
      if (iVar1 != 0xc) goto LAB_140037d57;
      puVar3 = (undefined8 *)MemoryAllocate(32);
      if (puVar3 != (undefined8 *)0x0) {
        *puVar3 = 0;
        puVar3[1] = 0;
        puVar3[2] = 0;
        puVar3[3] = 0;
        puVar3[1] = 0;
        *(undefined4 *)(puVar3 + 2) = 0;
        puVar3[3] = 0;
        ppuVar4 = &PTR_FUN_140067d98;
        goto LAB_140037cdb;
      }
    }
  }
LAB_140037e34:
  if (puVar5 != (undefined8 *)0x0) {
    *param_2 = puVar5;
    return 0;
  }
  uVar2 = 0x8007000e;
  uVar6 = 0x327;
LAB_140037d62:
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Configuration::LoadMode",uVar6);
  return uVar2;
}

