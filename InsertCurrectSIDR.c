
DWORD InsertCurrectSIDR(undefined8 param_1,undefined8 *param_2)

{
  DWORD DVar1;
  HANDLE hHeap;
  wchar_t *string;
  BSTR pOVar2;
  undefined8 uVar3;
  HLOCAL local_res18;
  
  local_res18 = (HLOCAL)0x0;
  string = (wchar_t *)0x0;
  DVar1 = GetCurrecntUserSID(&local_res18);
  if ((int)DVar1 < 0) {
    uVar3 = 800;
  }
  else {
    hHeap = GetProcessHeap();
    string = (wchar_t *)HeapAlloc(hHeap,0,2048);
    if (string == (wchar_t *)0x0) {
      uVar3 = 805;
    }
    else {
      uVar3 = SafeFormatWString(string,1024,param_1,local_res18);
      DVar1 = (DWORD)uVar3;
      if ((int)DVar1 < 0) {
        uVar3 = 808;
        goto ERROR;
      }
      pOVar2 = SysAllocString(string);
      *param_2 = pOVar2;
      if (pOVar2 != (BSTR)0x0) goto Free;
      uVar3 = 0x32e;
    }
    DVar1 = 0x8007000e;
  }
ERROR:
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","InsertCurrentUserSid",uVar3);

Free:
  if (local_res18 != (HLOCAL)0x0) {
    LocalFree(local_res18);
  }
  if (string != (wchar_t *)0x0) {
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,string);
  }
  return DVar1;
}

