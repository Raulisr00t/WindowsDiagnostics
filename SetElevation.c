
void SetElevation(undefined4 param_1)

{
  longlong *plVar1;
  longlong local_res10 [3];
  
  local_res10[0] = 0;
  plVar1 = TroubleShootingPackages(local_res10);
  if ((int)plVar1 < 0) {
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Packages_SetElevation",0xad4);
  }
  else {
    *(undefined4 *)(local_res10[0] + 0x10) = param_1;
  }
  return;
}

