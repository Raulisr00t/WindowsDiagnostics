
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int XmlNextNode(longlong *param_1,undefined8 *param_2)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  longlong *local_res8;
  
  local_res8 = (longlong *)0x0;
  if (param_1 == (longlong *)0x0) {
    uVar3 = 0x41c;
    iVar2 = -0x7ff8ffa9;
  }
  else if (param_2 == (undefined8 *)0x0) {
    uVar3 = 0x41d;
    iVar2 = -0x7ff8ffa9;
  }
  else {
    iVar2 = (**(code **)(*param_1 + 0x48))(param_1,&local_res8);
    if (iVar2 < 0) {
      uVar3 = 0x420;
    }
    else {
      if ((iVar2 != 1) && (local_res8 != (longlong *)0x0)) {
        lVar1 = *local_res8;
        *param_2 = local_res8;
        (**(code **)(lVar1 + 8))();
        goto LAB_140021d19;
      }
      iVar2 = -0x7fffbffb;
      uVar3 = 0x424;
    }
  }
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","DwzXmlNextNode",uVar3);
LAB_140021d19:
  if (local_res8 != (longlong *)0x0) {
    (**(code **)(*local_res8 + 0x10))();
  }
  return iVar2;
}

