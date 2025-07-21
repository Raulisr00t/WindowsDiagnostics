
DWORD ExpandVariables(short *param_1,longlong param_2,LPCWSTR param_3)

{
  DWORD somethinglikeascode;
  LPWSTR lpDst;
  HANDLE hHeap;
  undefined8 uVar1;
  
  hHeap = GetProcessHeap();
  lpDst = (LPWSTR)HeapAlloc(hHeap,0,0x800);
  if (lpDst == (LPWSTR)0x0) {
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","ExpandVariables",1074);
    return 0x8007000e;
  }
  *param_1 = 0;
  somethinglikeascode = ExpandEnvironmentStringsW(param_3,lpDst,1024);
  if (somethinglikeascode == 0) {
    somethinglikeascode = GetLastError();
    if (0 < (int)somethinglikeascode) {
      somethinglikeascode = somethinglikeascode & 0xffff | 0x80070000;
    }
    uVar1 = 1081;
  }
  else if (somethinglikeascode < 1024) {
    somethinglikeascode = SafeWcsCopy(param_1,param_2,lpDst);
    if (-1 < (int)somethinglikeascode) goto CleanUp;
    uVar1 = 0x440;
  }
  else {
    somethinglikeascode = 0x8007007a;
    uVar1 = 0x43c;
  }
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","ExpandVariables",uVar1);
CleanUp:
  hHeap = GetProcessHeap();
  HeapFree(hHeap,0,lpDst);
  return somethinglikeascode;
}

