
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int XmlGetChildNotes(longlong *param_1,longlong *param_2,undefined8 *param_3,int *param_4)

{
  int iVar1;
  longlong *plVar2;
  undefined8 uVar3;
  longlong *local_res18;
  longlong *local_18 [2];
  
  plVar2 = (longlong *)0x0;
  local_res18 = (longlong *)0x0;
  local_18[0] = (longlong *)0x0;
  if (param_3 == (undefined8 *)0x0) {
    uVar3 = 0x34f;
LAB_1400214f3:
    iVar1 = -0x7ff8ffa9;
  }
  else {
    if (param_4 == (int *)0x0) {
      uVar3 = 0x350;
      goto LAB_1400214f3;
    }
    if (param_1 != (longlong *)0x0) {
      iVar1 = XmlGetRootNode(param_1,local_18);
      plVar2 = local_18[0];
      if (iVar1 < 0) {
        PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","DwzXmlGetChildNodes",0x355);
        plVar2 = local_18[0];
      }
      else {
        iVar1 = (**(code **)(*local_18[0] + 0x60))(local_18[0],&local_res18);
        if (iVar1 < 0) {
          uVar3 = 0x357;
        }
        else {
LAB_1400215c5:
          *param_3 = local_res18;
          (**(code **)(*local_res18 + 8))();
          iVar1 = XmlGetNumChildNodes((longlong *)*param_3,param_4);
          if (-1 < iVar1) goto LAB_14002160c;
          uVar3 = 0x364;
        }
        PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","DwzXmlGetChildNodes",uVar3);
      }
LAB_14002160c:
      if (plVar2 != (longlong *)0x0) {
        (**(code **)(*plVar2 + 0x10))(plVar2);
      }
      goto LAB_140021620;
    }
    if (param_2 == (longlong *)0x0) {
      uVar3 = 0x35b;
      goto LAB_1400214f3;
    }
    iVar1 = (**(code **)(*param_2 + 0x60))(param_2,&local_res18);
    if (-1 < iVar1) goto LAB_1400215c5;
    uVar3 = 0x35d;
  }
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","DwzXmlGetChildNodes",uVar3);
LAB_140021620:
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x10))();
  }
  return iVar1;
}

