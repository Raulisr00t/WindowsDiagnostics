
undefined8 GetPackagesPath(void)

{
  longlong *plVar1;
  undefined8 uVar2;
  longlong local_res8 [4];
  
  uVar2 = 0;
  local_res8[0] = 0;
  plVar1 = TroubleShootingPackages(local_res8);
  if ((int)plVar1 < 0) {
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Packages_GetPath",0x8d6);
  }
  else {
    uVar2 = *(undefined8 *)(local_res8[0] + 0x18);
  }
  return uVar2;
}

