
uint ParseLocaleString(short *param_1,undefined8 *param_2,undefined8 *param_3)

{
  uint error;
  DWORD DVar1;
  HANDLE hHeap;
  wchar_t *string;
  wchar_t *variable;
  LPWSTR destination;
  BSTR pOVar2;
  wchar_t *psz;
  undefined8 uVar3;
  
  destination = (LPWSTR)0x0;
  if (*param_1 != 0x40) {
    return 1;
  }
  hHeap = GetProcessHeap();
  string = (wchar_t *)HeapAlloc(hHeap,0,2048);
  if (string == (wchar_t *)0x0) {
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","DwzParseLocaleString",0x160);
    return 0x8007000e;
  }
  error = SafeWcsCopy(string,1024,param_1);
  if ((int)error < 0) {
    uVar3 = 0x163;
  }
  else {
    variable = wcstok(string,L"@,");
    if (variable == (wchar_t *)0x0) {
      error = 0x80070057;
      uVar3 = 0x169;
    }
    else {
      hHeap = GetProcessHeap();
      destination = (LPWSTR)HeapAlloc(hHeap,0,2048);
      if (destination == (LPWSTR)0x0) {
        uVar3 = 0x16c;
      }
      else {
        *destination = L'\0';
        DVar1 = ExpandEnvironmentStringsW(variable,destination,1024);
        if (DVar1 == 0) {
          error = GetLastError();
          if (0 < (int)error) {
            error = error & 0xffff | 0x80070000;
          }
          uVar3 = 0x171;
          goto LAB_1400426be;
        }
        pOVar2 = SysAllocString(destination);
        *param_2 = pOVar2;
        if (pOVar2 == (BSTR)0x0) {
          uVar3 = 0x175;
        }
        else {
          variable = wcstok((wchar_t *)0x0,L", ");
          if (variable == (wchar_t *)0x0) {
            error = 0x80070057;
            uVar3 = 0x17b;
            goto LAB_1400426be;
          }
          psz = variable + 1;
          if (*variable != L'-') {
            psz = variable;
          }
          pOVar2 = SysAllocString(psz);
          *param_3 = pOVar2;
          if (pOVar2 != (BSTR)0x0) goto LAB_1400426d6;
          uVar3 = 0x183;
        }
      }
      error = 0x8007000e;
    }
  }
LAB_1400426be:
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","DwzParseLocaleString",uVar3);
LAB_1400426d6:
  hHeap = GetProcessHeap();
  HeapFree(hHeap,0,string);
  if (destination != (LPWSTR)0x0) {
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,destination);
  }
  return error;
}

