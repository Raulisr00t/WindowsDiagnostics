
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x00014002199a) */

undefined4 XmlGetNumChildNodes(longlong *param_1,int *param_2)

{
  int iVar1;
  undefined8 uVar2;
  longlong *local_res8;
  
  iVar1 = 0;
  local_res8 = (longlong *)0x0;
  if (param_1 == (longlong *)0x0) {
    uVar2 = 0x450;
  }
  else {
    if (param_2 != (int *)0x0) {
      while( true ) {
        local_res8 = (longlong *)0x0;
        XmlNextNode(param_1,&local_res8);
        if (local_res8 == (longlong *)0x0) break;
        (**(code **)(*local_res8 + 0x10))(local_res8);
        iVar1 = iVar1 + 1;
      }
      (**(code **)(*param_1 + 0x50))(param_1);
      *param_2 = iVar1;
      return 0;
    }
    uVar2 = 0x451;
  }
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","DwzXmlGetNumChildNodes",uVar2);
  return 0x80070057;
}

