
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GetSingleNode(OLECHAR *param_1,longlong *param_2,ulonglong param_3,undefined8 *param_4)

{
  longlong *plVar1;
  int iVar2;
  longlong *plVar3;
  undefined8 uVar4;
  longlong *local_res8;
  ulonglong local_res18 [2];
  longlong *local_28 [2];
  
  local_28[0] = (longlong *)0x0;
  plVar3 = (longlong *)0x0;
  local_res18[0] = param_3 & 0xffffffff00000000;
  local_res8 = (longlong *)0x0;
  if (param_1 == (OLECHAR *)0x0) {
    uVar4 = 0x5a2;
LAB_1400204bf:
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","DwzGetSingleNode",uVar4);
    return -0x7ff8ffa9;
  }
  if (param_4 == (undefined8 *)0x0) {
    uVar4 = 0x5a3;
    goto LAB_1400204bf;
  }
  iVar2 = XmlGetNodes(param_1,param_2,(longlong *)0x0,local_28);
  plVar1 = local_28[0];
  if (iVar2 < 0) {
    uVar4 = 0x5a6;
  }
  else {
    iVar2 = (**(code **)(*local_28[0] + 64))(local_28[0],local_res18);
    if (-1 < iVar2) {
      if ((int)local_res18[0] == 0) {
        iVar2 = 1;
      }
      else {
        if ((int)local_res18[0] != 1) {
          uVar4 = 0x5b8;
          iVar2 = -0x7ff8ffa9;
          goto LAB_140020512;
        }
        iVar2 = XmlNextNode(plVar1,&local_res8);
        plVar3 = local_res8;
        if (iVar2 < 0) {
          PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","DwzGetSingleNode",0x5bc);
          plVar3 = local_res8;
        }
        else {
          *param_4 = local_res8;
          (**(code **)(*local_res8 + 8))(local_res8);
        }
      }
      if (plVar3 != (longlong *)0x0) {
        (**(code **)(*plVar3 + 0x10))(plVar3);
      }
      goto LAB_1400205df;
    }
    uVar4 = 0x5a9;
  }
LAB_140020512:
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","DwzGetSingleNode",uVar4);
LAB_1400205df:
  if (plVar1 == (longlong *)0x0) {
    return iVar2;
  }
  (**(code **)(*plVar1 + 0x10))(plVar1);
  return iVar2;
}

