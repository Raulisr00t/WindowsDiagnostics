
void SetPackageDescription(OLECHAR *package_description)

{
  longlong lVar1;
  longlong *plVar2;
  BSTR pOVar3;
  undefined8 uVar4;
  longlong local_res10 [3];
  
  local_res10[0] = 0;
  plVar2 = TroubleShootingPackages(local_res10);
  lVar1 = local_res10[0];
  if ((int)plVar2 < 0) {
    uVar4 = 0x996;
  }
  else {
    if (*(BSTR *)(local_res10[0] + 48) != (BSTR)0x0) {
      SysFreeString(*(BSTR *)(local_res10[0] + 48));
      *(undefined8 *)(lVar1 + 0x30) = 0;
    }
    pOVar3 = SysAllocString(package_description);
    *(BSTR *)(lVar1 + 0x30) = pOVar3;
    if (package_description != (OLECHAR *)0x0) {
      return;
    }
    uVar4 = 0x99b;
  }
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Packages_SetDescription",uVar4);
  return;
}

