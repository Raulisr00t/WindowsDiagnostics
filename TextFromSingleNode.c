
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int TextFromSingleNode(OLECHAR *package_name,longlong *param_2,undefined8 *param_3)

{
  longlong *plVar1;
  int iVar2;
  undefined8 uVar3;
  BSTR local_res20;
  longlong *local_18 [2];
  
  local_18[0] = (longlong *)0x0;
  local_res20 = (BSTR)0x0;
  iVar2 = GetSingleNode(package_name,param_2,(ulonglong)param_3,local_18);
  plVar1 = local_18[0];
  if (iVar2 < 0) {
    uVar3 = 0x5b6;
RETURN:
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Configuration::TextFromSingleNode",uVar3);
  }
  else {
    if (iVar2 == 0) {
      iVar2 = (**(code **)(*local_18[0] + 0xd0))(local_18[0],&local_res20);
      if (iVar2 < 0) {
        uVar3 = 0x5b9;
        goto RETURN;
      }
    }
    *param_3 = local_res20;
    local_res20 = (BSTR)0x0;
  }
  if (local_res20 != (BSTR)0x0) {
    SysFreeString(local_res20);
    local_res20 = (BSTR)0x0;
  }
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 0x10))(plVar1);
  }
  return iVar2;
}

