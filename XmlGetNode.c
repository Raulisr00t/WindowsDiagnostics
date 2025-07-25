
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int XmlGetNode(OLECHAR *Package,longlong *param_2,longlong *param_3,undefined8 *param_4)

{
  int iVar1;
  BSTR bstrString;
  longlong lVar2;
  undefined8 uVar3;
  longlong *local_res8;
  
  local_res8 = (longlong *)0x0;
  if (Package == (OLECHAR *)0x0) {
    uVar3 = 0x393;
LAB_140021686:
    iVar1 = -0x7ff8ffa9;
  }
  else {
    if (param_4 == (undefined8 *)0x0) {
      uVar3 = 0x394;
      goto LAB_140021686;
    }
    if ((param_2 == (longlong *)0x0) && (param_3 == (longlong *)0x0)) {
      uVar3 = 0x398;
      goto LAB_140021686;
    }
    bstrString = SysAllocString(Package);
    if (bstrString != (BSTR)0x0) {
      if (param_2 == (longlong *)0x0) {
        lVar2 = *param_3;
        param_2 = param_3;
      }
      else {
        lVar2 = *param_2;
      }
      iVar1 = (**(code **)(lVar2 + 0x128))(param_2,bstrString,&local_res8);
      if (iVar1 < 0) {
        uVar3 = 0x3a8;
LAB_140021752:
        PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","DwzXmlGetNode",uVar3);
      }
      else {
        if ((iVar1 == 1) || (local_res8 == (longlong *)0x0)) {
          iVar1 = -0x7fffbffb;
          uVar3 = 0x3ac;
          goto LAB_140021752;
        }
        *param_4 = local_res8;
        (**(code **)(*local_res8 + 8))();
      }
      SysFreeString(bstrString);
      goto LAB_14002177d;
    }
    iVar1 = -0x7ff8fff2;
    uVar3 = 0x39c;
  }
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","DwzXmlGetNode",uVar3);
LAB_14002177d:
  if (local_res8 != (longlong *)0x0) {
    (**(code **)(*local_res8 + 0x10))();
  }
  return iVar1;
}

