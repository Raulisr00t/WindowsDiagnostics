
void Packages_SetPublisher(OLECHAR *param_1)

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
    uVar4 = 0xa86;
  }
  else {
    if (*(BSTR *)(local_res10[0] + 0x38) != (BSTR)0x0) {
      SysFreeString(*(BSTR *)(local_res10[0] + 0x38));
      *(undefined8 *)(lVar1 + 0x38) = 0;
    }
    pOVar3 = SysAllocString(param_1);
    *(BSTR *)(lVar1 + 0x38) = pOVar3;
    if (param_1 != (OLECHAR *)0x0) {
      return;
    }
    uVar4 = 0xa8b;
  }
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Packages_SetPublisher",uVar4);
  return;
}

