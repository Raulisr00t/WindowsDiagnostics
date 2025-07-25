
DWORD CononicalizeFilePath(LPCWSTR file,undefined8 *filename)

{
  DWORD Path;
  DWORD error;
  HANDLE hHeap;
  LPWSTR lpBuffer;
  undefined8 uVar1;
  
  error = 0;
  hHeap = GetProcessHeap();
  lpBuffer = (LPWSTR)HeapAlloc(hHeap,0,520);
  if (lpBuffer == (LPWSTR)0x0) {
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Configuration::CanonicalizeFilePath",0x580);
    return 0x8007000e;
  }
  Path = GetFullPathNameW(file,259,lpBuffer,(LPWSTR *)0x0);
  if (Path == 0) {
    error = GetLastError();
    if (0 < (int)error) {
      error = error & 0xffff | 0x80070000;
    }
    if (-1 < (int)error) {
CleanUp:
      *filename = lpBuffer;
      return error;
    }
    uVar1 = 0x585;
  }
  else {
    if (Path < 260) goto CleanUp;
    error = 0x80028016;
    uVar1 = 0x588;
  }
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Configuration::CanonicalizeFilePath",uVar1);
  hHeap = GetProcessHeap();
  HeapFree(hHeap,0,lpBuffer);
  return error;
}

