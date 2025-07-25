
DWORD LoadResourceString(LPCWSTR library,UINT param_2,undefined8 *param_3)

{
  int iVar1;
  DWORD error;
  HMODULE hInstance;
  HANDLE hHeap;
  LPWSTR Buffer;
  BSTR pOVar2;
  undefined8 uVar3;
  
  error = 0;
  hInstance = LoadLibraryExW(library,(HANDLE)0x0,2);
  if ((undefined1 *)0xfffffffffffffffd < (undefined1 *)((longlong)&hInstance[-1].unused + 3)) {
    error = GetLastError();
    if (0 < (int)error) {
      error = error & 0xffff | 0x80070000;
    }
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","DwzLoadResourceString",0x11f);
    Buffer = (LPWSTR)0x0;
    if (hInstance == (HMODULE)0x0) {
      return error;
    }
    goto CleanUp;
  }
  hHeap = GetProcessHeap();
  Buffer = (LPWSTR)HeapAlloc(hHeap,0,2048);
  if (Buffer == (LPWSTR)0x0) {
    uVar3 = 289;
LAB_1400421f0:
    error = 0x8007000e;
  }
  else {
    iVar1 = LoadStringW(hInstance,param_2,Buffer,1024);
    if (0 < iVar1) {
      pOVar2 = SysAllocString(Buffer);
      *param_3 = pOVar2;
      if (pOVar2 != (BSTR)0x0) goto CleanUp;
      uVar3 = 0x129;
      goto LAB_1400421f0;
    }
    error = 0x803c010a;
    uVar3 = 0x125;
  }
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","DwzLoadResourceString",uVar3);
CleanUp:
  FreeLibrary(hInstance);
  if (Buffer != (LPWSTR)0x0) {
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,Buffer);
  }
  return error;
}

