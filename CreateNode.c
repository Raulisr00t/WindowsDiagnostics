
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int CreateNode(undefined8 *param_1,OLECHAR *param_2,ulonglong param_3,OLECHAR *param_4,
              undefined8 *param_5)

{
  longlong *plVar1;
  int iVar2;
  BSTR bstrString;
  BSTR bstrString_00;
  undefined8 uVar3;
  longlong *local_res8;
  longlong *local_res18 [2];
  longlong *local_78;
  _union_2707 local_70;
  undefined4 local_58;
  ULONG UStack_54;
  undefined4 uStack_50;
  ULONG UStack_4c;
  undefined8 local_48;
  
  bstrString_00 = (BSTR)0x0;
  local_78 = (longlong *)0x0;
  local_res8 = (longlong *)0x0;
  local_res18[0] = (longlong *)0x0;
  local_70._16_8_ = 0;
  local_70._0_8_ = 0;
  local_70.decVal.u2 = (_union_1719)0x0;
  VariantInit((VARIANTARG *)&local_70.n2);
  iVar2 = GetSingleNode(param_2,(longlong *)*param_1,param_3,&local_78);
  plVar1 = local_78;
  if (iVar2 < 0) {
    uVar3 = 0x2f2;
  }
  else if (iVar2 == 1) {
    iVar2 = -0x7ff8ffa9;
    uVar3 = 0x2f5;
  }
  else {
    bstrString = SysAllocString(L"Interaction");
    if (bstrString != (BSTR)0x0) {
      iVar2 = (**(code **)(*(longlong *)*param_1 + 0x178))
                        ((longlong *)*param_1,bstrString,local_res18);
      if (iVar2 < 0) {
        uVar3 = 0x2ff;
LAB_140033af5:
        PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Answers::CreateNode",uVar3);
      }
      else {
        if (param_4 != (OLECHAR *)0x0) {
          bstrString_00 = SysAllocString(L"ID");
          if (bstrString_00 == (BSTR)0x0) {
            uVar3 = 0x306;
            iVar2 = -0x7ff8fff2;
          }
          else {
            iVar2 = AssignVariantString((VARIANTARG *)&local_70.n2,param_4);
            if (iVar2 < 0) {
              uVar3 = 0x309;
            }
            else {
              local_58 = local_70._0_4_;
              UStack_54 = local_70.decVal.Hi32;
              uStack_50 = local_70._8_4_;
              UStack_4c = local_70._12_4_;
              local_48 = local_70._16_8_;
              iVar2 = (**(code **)(*local_res18[0] + 0x168))(local_res18[0],bstrString_00,&local_5 8)
              ;
              if (iVar2 < 0) {
                uVar3 = 0x30c;
              }
              else {
                iVar2 = (**(code **)(*plVar1 + 0xa8))(plVar1,local_res18[0],0);
                if (-1 < iVar2) goto LAB_140033bc7;
                uVar3 = 0x30f;
              }
            }
          }
          goto LAB_140033af5;
        }
LAB_140033bc7:
        iVar2 = (**(code **)*local_res18[0])(local_res18[0],&DAT_14006af50,&local_res8);
        if (iVar2 < 0) {
          uVar3 = 0x318;
          goto LAB_140033af5;
        }
        (**(code **)(*local_res8 + 8))();
        *param_5 = local_res8;
      }
      SysFreeString(bstrString);
      if (bstrString_00 != (BSTR)0x0) {
        SysFreeString(bstrString_00);
      }
      goto LAB_140033c30;
    }
    uVar3 = 0x2fc;
    iVar2 = -0x7ff8fff2;
  }
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Answers::CreateNode",uVar3);
LAB_140033c30:
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 0x10))(plVar1);
  }
  if (local_res18[0] != (longlong *)0x0) {
    (**(code **)(*local_res18[0] + 0x10))();
    local_res18[0] = (longlong *)0x0;
  }
  if (local_res8 != (longlong *)0x0) {
    (**(code **)(*local_res8 + 0x10))();
    local_res8 = (longlong *)0x0;
  }
  VariantClear((VARIANTARG *)&local_70.n2);
  return iVar2;
}

