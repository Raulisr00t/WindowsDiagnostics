
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GetMetaDataCollection(longlong param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  longlong *local_res8;
  longlong *local_res18 [2];
  
  local_res8 = (longlong *)0x0;
  local_res18[0] = (longlong *)0x0;
  iVar1 = (**(code **)(param_1 + 0x10))(&DAT_14006b0f0,&DAT_14006afc0,&local_res8);
  if (iVar1 < 0) {
    uVar2 = 0x2c7;
  }
  else {
    iVar1 = (**(code **)(*local_res8 + 0x18))(local_res8,0,&DAT_14006afb0,local_res18);
    if (iVar1 < 0) {
      uVar2 = 0x2cd;
    }
    else {
      iVar1 = (**(code **)*local_res18[0])(local_res18[0],&DAT_14006b0c0,param_2);
      if (-1 < iVar1) goto LAB_140039c05;
      uVar2 = 0x2d2;
    }
  }
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Provider::GetMetadataCollection",uVar2);
LAB_140039c05:
  if (local_res8 != (longlong *)0x0) {
    (**(code **)(*local_res8 + 0x10))();
    local_res8 = (longlong *)0x0;
  }
  if (local_res18[0] != (longlong *)0x0) {
    (**(code **)(*local_res18[0] + 0x10))();
  }
  return iVar1;
}

