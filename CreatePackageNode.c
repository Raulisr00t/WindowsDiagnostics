
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int CreatePackageNode(undefined8 param_1,longlong *param_2,longlong *param_3)

{
  int iVar1;
  BSTR bstrString;
  BSTR bstrString_00;
  undefined8 uVar2;
  longlong *local_res20;
  _union_2707 local_58;
  undefined4 local_38;
  ULONG UStack_34;
  undefined4 uStack_30;
  ULONG UStack_2c;
  undefined8 local_28;
  
  bstrString_00 = (BSTR)0x0;
  local_res20 = (longlong *)0x0;
  local_58._0_8_ = 0;
  local_58.decVal.u2 = (_union_1719)0x0;
  local_58._16_8_ = 0;
  VariantInit((VARIANTARG *)&local_58.n2);
  bstrString = SysAllocString(L"ID");
  if (bstrString == (BSTR)0x0) {
    iVar1 = -0x7ff8fff2;
    uVar2 = 0x34f;
  }
  else {
    bstrString_00 = SysAllocString(L"Package");
    if (bstrString_00 == (BSTR)0x0) {
      iVar1 = -0x7ff8fff2;
      uVar2 = 0x355;
    }
    else {
      iVar1 = (**(code **)(*param_3 + 0x178))(param_3,bstrString_00,&local_res20);
      if (iVar1 < 0) {
        uVar2 = 0x358;
      }
      else {
        iVar1 = AssignVariantString((VARIANTARG *)&local_58.n2,L"Default");
        if (iVar1 < 0) {
          uVar2 = 0x35b;
        }
        else {
          local_38 = local_58._0_4_;
          UStack_34 = local_58.decVal.Hi32;
          uStack_30 = local_58._8_4_;
          UStack_2c = local_58._12_4_;
          local_28 = local_58._16_8_;
          iVar1 = (**(code **)(*local_res20 + 0x168))(local_res20,bstrString,&local_38);
          if (iVar1 < 0) {
            uVar2 = 0x35e;
          }
          else {
            iVar1 = (**(code **)(*param_2 + 0xa8))(param_2,local_res20,0);
            if (-1 < iVar1) goto Free;
            uVar2 = 0x361;
          }
        }
      }
    }
  }
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Answers::CreatePackageNode",uVar2);
Free:
  if (local_res20 != (longlong *)0x0) {
    (**(code **)(*local_res20 + 0x10))();
    local_res20 = (longlong *)0x0;
  }
  if (bstrString != (BSTR)0x0) {
    SysFreeString(bstrString);
  }
  if (bstrString_00 != (BSTR)0x0) {
    SysFreeString(bstrString_00);
  }
  VariantClear((VARIANTARG *)&local_58.n2);
  return iVar1;
}

