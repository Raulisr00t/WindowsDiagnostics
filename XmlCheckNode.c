
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int XmlCheckNode(longlong *param_1,wchar_t *param_2)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  wchar_t *local_res8;
  
  local_res8 = (wchar_t *)0x0;
  iVar1 = (**(code **)(*param_1 + 0x38))(param_1,&local_res8);
  if (iVar1 < 0) {
    uVar3 = 0x4c6;
  }
  else {
    iVar2 = _wcsicmp(local_res8,param_2);
    if (iVar2 == 0) goto LAB_1400210d9;
    iVar1 = -0x7fffbffb;
    uVar3 = 0x4ca;
  }
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","DwzXmlCheckNode",uVar3);
LAB_1400210d9:
  if (local_res8 != (BSTR)0x0) {
    SysFreeString(local_res8);
  }
  return iVar1;
}

