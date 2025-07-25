
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int ValidateAnswersXML(ulonglong param_1,longlong *param_2)

{
  longlong *plVar1;
  int iVar2;
  longlong *plVar3;
  uint uVar4;
  longlong *plVar5;
  undefined8 uVar6;
  ulonglong local_res8;
  longlong *local_res10;
  longlong *local_res18;
  
  local_res18 = (longlong *)0x0;
  plVar5 = (longlong *)0x0;
  local_res8 = param_1 & 0xffffffff00000000;
  local_res10 = (longlong *)0x0;
  if (param_2 == (longlong *)0x0) {
    iVar2 = -0x7ff8ffa9;
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Configuration::ValidateAnswersXML",0x6f6);
  }
  else {
    iVar2 = XmlGetChildNotes(param_2,(longlong *)0x0,&local_res18,(int *)&local_res8);
    plVar1 = local_res18;
    if (iVar2 < 0) {
      PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Configuration::ValidateAnswersXML",0x6f9);
    }
    else {
      for (uVar4 = 0; uVar4 < (uint)local_res8; uVar4 = uVar4 + 1) {
        if (plVar5 != (longlong *)0x0) {
          (**(code **)(*plVar5 + 0x10))(plVar5);
          local_res10 = (longlong *)0x0;
        }
        iVar2 = XmlNextNode(plVar1,&local_res10);
        plVar5 = local_res10;
        if (iVar2 < 0) {
          PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Configuration::ValidateAnswersXML",0x7 00)
          ;
          plVar5 = local_res10;
          break;
        }
        plVar3 = local_res10;
        iVar2 = XmlCheckNode(local_res10,L"Interaction");
        if (iVar2 < 0) {
          uVar6 = 0x703;
LAB_14003912d:
          PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Configuration::ValidateAnswersXML",uVa r6)
          ;
          break;
        }
        iVar2 = ValidateAnswer((ulonglong)plVar3,plVar5);
        if (iVar2 < 0) {
          uVar6 = 0x706;
          goto LAB_14003912d;
        }
      }
      if (plVar5 != (longlong *)0x0) {
        (**(code **)(*plVar5 + 0x10))(plVar5);
      }
    }
    if (plVar1 != (longlong *)0x0) {
      (**(code **)(*plVar1 + 0x10))(plVar1);
    }
  }
  return iVar2;
}

