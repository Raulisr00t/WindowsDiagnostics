
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int XmlGetNodes(OLECHAR *node,longlong *param_2,longlong *param_3,undefined8 *param_4)

{
  int iVar1;
  BSTR bstrString;
  longlong lVar2;
  undefined8 uVar3;
  longlong *local_res8;
  
  local_res8 = (longlong *)0x0;
  if (node == (OLECHAR *)0x0) {
    uVar3 = 0x3df;
LAB_1400217e2:
    iVar1 = -0x7ff8ffa9;
  }
  else {
    if (param_4 == (undefined8 *)0x0) {
      uVar3 = 0x3e0;
      goto LAB_1400217e2;
    }
    if ((param_2 == (longlong *)0x0) && (param_3 == (longlong *)0x0)) {
      uVar3 = 0x3e4;
      goto LAB_1400217e2;
    }
    bstrString = SysAllocString(node);
    if (bstrString != (BSTR)0x0) {
      if (param_2 == (longlong *)0x0) {
        lVar2 = *param_3;
        param_2 = param_3;
      }
      else {
        lVar2 = *param_2;
      }
      iVar1 = (**(code **)(lVar2 + 0x120))(param_2,bstrString,&local_res8);
      if (iVar1 < 0) {
        PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","DwzXmlGetNodes",0x3f0);
      }
      else {
        *param_4 = local_res8;
        (**(code **)(*local_res8 + 8))();
      }
      SysFreeString(bstrString);
      goto LAB_1400218c2;
    }
    iVar1 = -0x7ff8fff2;
    uVar3 = 1000;
  }
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","DwzXmlGetNodes",uVar3);
LAB_1400218c2:
  if (local_res8 != (longlong *)0x0) {
    (**(code **)(*local_res8 + 0x10))();
  }
  return iVar1;
}

