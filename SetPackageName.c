
void SetPackageName(OLECHAR *name)

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
    uVar4 = 0x96f;
  }
  else {
    if (*(BSTR *)(local_res10[0] + 0x28) != (BSTR)0x0) {
      SysFreeString(*(BSTR *)(local_res10[0] + 0x28));
      *(undefined8 *)(lVar1 + 0x28) = 0;
    }
    pOVar3 = SysAllocString(name);
    *(BSTR *)(lVar1 + 0x28) = pOVar3;
    if (name != (OLECHAR *)0x0) {
      return;
    }
    uVar4 = 0x974;
  }
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Packages_SetName",uVar4);
  return;
}

