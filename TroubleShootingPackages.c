
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

longlong * TroubleShootingPackages(undefined8 *param_1)

{
  uint uVar1;
  longlong *_Memory;
  longlong *plVar2;
  longlong *plVar3;
  undefined8 uVar4;
  longlong *local_res10;
  undefined8 *local_res18;
  
  plVar2 = (longlong *)0x0;
  local_res10 = (longlong *)0x0;
  plVar3 = plVar2;
  if (DAT_140080190 == (undefined8 *)0x0) {
    local_res18 = (undefined8 *)MemoryAllocate(0x10);
    if (local_res18 != (undefined8 *)0x0) {
      _Memory = FUN_140026a30(local_res18);
      if (_Memory != (longlong *)0x0) {
        uVar1 = FUN_1400536f4(_Memory,&local_res10);
        plVar3 = (longlong *)(ulonglong)uVar1;
        if ((int)uVar1 < 0) {
          uVar4 = 0x41;
        }
        else {
          local_res18 = (undefined8 *)MemoryAllocate(0x70);
          if (local_res18 != (undefined8 *)0x0) {
            *local_res18 = 0;
            local_res18[1] = 0;
            *(undefined4 *)(local_res18 + 2) = 0;
            *(undefined4 *)((longlong)local_res18 + 0x14) = 1;
            local_res18[3] = 0;
            local_res18[4] = 0;
            local_res18[5] = 0;
            local_res18[6] = 0;
            local_res18[7] = 0;
            local_res18[8] = 0;
            local_res18[9] = 0;
            local_res18[10] = 0;
            local_res18[0xb] = 0;
            local_res18[0xc] = 0;
            local_res18[0xd] = 0;
            if (local_res18 != (undefined8 *)0x0) {
              *local_res18 = local_res10;
              local_res18[1] = _Memory;
              DAT_140080190 = local_res18;
              goto LAB_140048bcb;
            }
          }
          uVar4 = 0x44;
          plVar3 = (longlong *)0x8007000e;
        }
        PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","TroubleshootingPackages::GetInstance",uV ar4
                  );
        free(_Memory);
        plVar2 = local_res10;
        goto LAB_140048bce;
      }
    }
    plVar3 = (longlong *)0x8007000e;
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","TroubleshootingPackages::GetInstance",0x3e);
  }

  else {
LAB_140048bcb:
    *param_1 = DAT_140080190;
LAB_140048bce:
    if (plVar2 != (longlong *)0x0) {
      (**(code **)(*plVar2 + 0x10))();
    }
  }
  return plVar3;
}

