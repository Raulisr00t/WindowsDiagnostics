
uint TryLoadResourceString(OLECHAR *param_1,undefined8 *param_2)

{
  uint uVar1;
  UINT UVar2;
  BSTR pOVar3;
  undefined8 uVar4;
  LPCWSTR library;
  wchar_t *local_res20;
  BSTR local_28 [2];
  
  library = (LPCWSTR)0x0;
  local_res20 = (wchar_t *)0x0;
  local_28[0] = (BSTR)0x0;
  uVar1 = ParseLocaleString(param_1,&library,&local_res20);
  if ((int)uVar1 < 0) {
    uVar4 = 0xea;
LAB_140042c3f:
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","DwzTryLoadResourceString",uVar4);
    pOVar3 = (BSTR)0x0;
  }
  else {
    if (uVar1 == 1) {
      pOVar3 = SysAllocString(param_1);
      if (pOVar3 == (BSTR)0x0) {
        uVar1 = 0x8007000e;
        uVar4 = 0xee;
        goto LAB_140042c3f;
      }
    }
    else {
      UVar2 = _wtol(local_res20);
      uVar1 = LoadResourceString(library,UVar2,local_28);
      pOVar3 = local_28[0];
      if ((int)uVar1 < 0) {
        PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","DwzTryLoadResourceString",0xf1);
        pOVar3 = local_28[0];
        goto Free;
      }
    }
    *param_2 = pOVar3;
    pOVar3 = (BSTR)0x0;
  }
Free:
  if (library != (BSTR)0x0) {
    SysFreeString(library);
  }
  if (local_res20 != (BSTR)0x0) {
    SysFreeString(local_res20);
  }
  if (pOVar3 != (BSTR)0x0) {
    SysFreeString(pOVar3);
  }
  return uVar1;
}

