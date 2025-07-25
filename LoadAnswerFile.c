
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

DWORD LoadAnswerFile(longlong FILE,LPCWSTR filename)

{
  longlong *plVar1;
  DWORD DVar2;
  OLECHAR *pOVar3;
  longlong *plVar4;
  undefined8 uVar5;
  longlong *local_res8;
  longlong *local_res18 [2];
  
  local_res18[0] = (longlong *)0x0;
  plVar4 = (longlong *)0x0;
  local_res8 = (longlong *)0x0;
  DVar2 = CononicalizeFilePath(filename,(undefined8 *)(FILE + 240));
  if ((int)DVar2 < 0) {
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Configuration::LoadAnswerFile",0x6b6);
    return DVar2;
  }
  pOVar3 = *(OLECHAR **)(FILE + 240);
  DVar2 = XmlLoad(pOVar3,local_res18);
  plVar1 = local_res18[0];
  if ((int)DVar2 < 0) {
    uVar5 = 0x6b9;
  }
  else {
    DVar2 = ValidateAnswersXML((ulonglong)pOVar3,local_res18[0]);
    if ((int)DVar2 < 0) {
      uVar5 = 0x6bc;
    }
    else {
      DVar2 = XmlGetRootNode(plVar1,&local_res8);
      plVar4 = local_res8;
      if ((int)DVar2 < 0) {
        PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Configuration::LoadAnswerFile",0x6bf);
        plVar4 = local_res8;
        goto LAB_14003670c;
      }
      DVar2 = (**(code **)(*local_res8 + 0x110))(local_res8,FILE + 0xf8);
      if (-1 < (int)DVar2) goto LAB_14003670c;
      uVar5 = 0x6c2;
    }
  }
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Configuration::LoadAnswerFile",uVar5);
LAB_14003670c:
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 0x10))(plVar1);
  }
  if (plVar4 != (longlong *)0x0) {
    (**(code **)(*plVar4 + 0x10))(plVar4);
  }
  return DVar2;
}

