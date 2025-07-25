
ulonglong Packages_SetPath(OLECHAR *filename)

{
  longlong lVar1;
  longlong *plVar2;
  BSTR pOVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong local_res10;
  
  local_res10 = 0;
  plVar2 = TroubleShootingPackages(&local_res10);
  lVar1 = local_res10;
  uVar4 = (ulonglong)plVar2 & 0xffffffff;
  if ((int)plVar2 < 0) {
    uVar5 = 0x8b0;
  }
  else {
    if (*(BSTR *)(local_res10 + 0x18) != (BSTR)0x0) {
      SysFreeString(*(BSTR *)(local_res10 + 0x18));
      *(undefined8 *)(lVar1 + 0x18) = 0;
    }
    pOVar3 = SysAllocString(filename);
    *(BSTR *)(lVar1 + 0x18) = pOVar3;
    if (pOVar3 != (BSTR)0x0) {
      return uVar4;
    }
    uVar4 = 0x8007000e;
    uVar5 = 0x8b5;
  }
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Packages_SetPath",uVar5);
  return uVar4;
}

