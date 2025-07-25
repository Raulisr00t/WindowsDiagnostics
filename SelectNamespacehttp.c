
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SelectNamespacehttp(longlong *param_1)

{
  int iVar1;
  BSTR bstrString;
  undefined8 uVar2;
  _union_2707 local_48;
  undefined4 local_28;
  ULONG UStack_24;
  undefined4 uStack_20;
  ULONG UStack_1c;
  undefined8 local_18;
  
  local_48._0_8_ = 0;
  local_48.decVal.u2 = (_union_1719)0x0;
  local_48._16_8_ = 0;
  VariantInit((VARIANTARG *)&local_48.n2);
  bstrString = SysAllocString(L"SelectionNamespaces");
  if (bstrString == (BSTR)0x0) {
    iVar1 = -0x7ff8fff2;
    uVar2 = 0x63f;
  }
  else {
    local_48.n2.vt = 8;
    local_48.decVal.u2 =
         (_union_1719)
         SysAllocString(L"xmlns:cfg=\'http://www.microsoft.com/schemas/dcm/configuration/2008\'") ;
    if (local_48.decVal.u2.Lo64 == (_union_1719)0x0) {
      iVar1 = -0x7ff8fff2;
      uVar2 = 0x643;
    }
    else {
      local_28 = local_48._0_4_;
      UStack_24 = local_48.decVal.Hi32;
      uStack_20 = local_48._8_4_;
      UStack_1c = local_48._12_4_;
      local_18 = local_48._16_8_;
      iVar1 = (**(code **)(*param_1 + 0x280))(param_1,bstrString,&local_28);
      if (-1 < iVar1) goto CleanUp;
      uVar2 = 0x646;
    }
  }
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","DwzXmlSetSelectionNamespace",uVar2);
CleanUp:
  VariantClear((VARIANTARG *)&local_48.n2);
  if (bstrString != (BSTR)0x0) {
    SysFreeString(bstrString);
  }
  return iVar1;
}

