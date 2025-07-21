
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GetProvider(undefined8 *hModule,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  longlong *local_res8;
  longlong *local_res18;
  
  local_res8 = (longlong *)0x0;
  local_res18 = (longlong *)0x0;
  if (*(int *)(hModule + 1) == 0) {
    iVar1 = ProviderInit(hModule);
    if (-1 < iVar1) goto LAB_140039c85;
    uVar2 = 600;
  }
  else {
LAB_140039c85:
    iVar1 = (*(code *)hModule[2])(&DAT_14006b100,&DAT_14006afc0,&local_res8);
    if (iVar1 < 0) {
      uVar2 = 0x25f;
    }
    else {
      iVar1 = (**(code **)(*local_res8 + 0x18))(local_res8,0,&DAT_14006afb0,&local_res18);
      if (iVar1 < 0) {
        uVar2 = 0x265;
      }
      else {
        iVar1 = (**(code **)*local_res18)(local_res18,&DAT_14006b0d0,param_2);
        if (-1 < iVar1) goto LAB_140039d1e;
        uVar2 = 0x26a;
      }
    }
  }
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Provider::GetProvider",uVar2);
LAB_140039d1e:
  if (local_res8 != (longlong *)0x0) {
    (**(code **)(*local_res8 + 0x10))();
    local_res8 = (longlong *)0x0;
  }
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x10))();
  }
  return iVar1;
}

