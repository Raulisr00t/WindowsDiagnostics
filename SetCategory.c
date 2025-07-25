
void SetCategory(OLECHAR *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  BSTR pOVar3;
  longlong local_res10 [3];
  
  local_res10[0] = 0;
  plVar2 = TroubleShootingPackages(local_res10);
  lVar1 = local_res10[0];
  if ((int)plVar2 < 0) {
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Packages_SetCategory",0xa36);
  }
  else {
    if (*(BSTR *)(local_res10[0] + 104) != (BSTR)0x0) {
      SysFreeString(*(BSTR *)(local_res10[0] + 104));
      *(undefined8 *)(lVar1 + 0x68) = 0;
    }
    if (param_1 != (OLECHAR *)0x0) {
      pOVar3 = SysAllocString(param_1);
      *(BSTR *)(lVar1 + 0x68) = pOVar3;
    }
  }
  return;
}

