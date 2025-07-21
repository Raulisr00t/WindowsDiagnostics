
DWORD CreateDirectoryWR(LPCWSTR filename)

{
  DWORD error_code;
  BOOL Created;
  ulonglong uVar1;
  LPCWSTR lpPathName;
  wchar_t *pwVar2;
  LPCWSTR pWVar3;
  HANDLE hHeap;
  DWORD DVar4;
  undefined8 uVar5;
  _SECURITY_ATTRIBUTES lpSecurityAttributes;
  
  lpSecurityAttributes.nLength = 0;
  lpSecurityAttributes._4_4_ = 0;
  lpSecurityAttributes.lpSecurityDescriptor = (HLOCAL)0x0;
  lpSecurityAttributes.bInheritHandle = 0;
  lpSecurityAttributes._20_4_ = 0;
  DVar4 = 0;
  if (*filename == L'\0') goto LocalFree;
  uVar1 = 0xffffffffffffffff;
  do {
    uVar1 = uVar1 + 1;
  } while (filename[uVar1] != L'\0');
  if (uVar1 < 4) goto LocalFree;
  hHeap = GetProcessHeap();
  lpPathName = (LPCWSTR)HeapAlloc(hHeap,0,0x800);
  if (lpPathName == (LPCWSTR)0x0) {
    DVar4 = 0x8007000e;
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","CreateDirectoryW",982);
    goto LocalFree;
  }
  error_code = CreateSecurityDescriptorR(&lpSecurityAttributes.nLength);
  if ((int)error_code < 0) {
    uVar5 = 985;
LAB_140040ced:
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","CreateDirectoryW",uVar5);
    DVar4 = error_code;
  }
  else {
    error_code = ExpandVariables(lpPathName,1024,filename);
    if ((int)error_code < 0) {
      uVar5 = 0x3df;
      goto LAB_140040ced;
    }
    if ((*lpPathName == L'\\') && (lpPathName[1] == L'\\')) {
      pwVar2 = wcschr(lpPathName + 2,L'\\');
      if ((pwVar2 == (wchar_t *)0x0) ||
         (pWVar3 = wcschr(pwVar2 + 1,L'\\'), pWVar3 == (wchar_t *)0x0)) {
        error_code = 0x800700a1;
        uVar5 = 0x3f1;
        goto LAB_140040ced;
      }
    }
    else {
      pWVar3 = lpPathName + 2;
    }
    while (pWVar3 = wcschr(pWVar3 + 1,L'\\'), pWVar3 != (wchar_t *)0x0) {
      *pWVar3 = L'\0';
      Created = CreateDirectoryW(lpPathName,&lpSecurityAttributes);
      if (Created == 0) {
        error_code = GetLastError();
        if (0 < (int)error_code) {
          error_code = error_code & 0xffff | 0x80070000;
        }
        if (((int)error_code < 0) && ((short)error_code != L'·')) {
          uVar5 = 1026;
          goto LAB_140040ced;
        }
      }
      *pWVar3 = L'\\';
    }
  }
  hHeap = GetProcessHeap();
  HeapFree(hHeap,0,lpPathName);

LocalFree:
  if (lpSecurityAttributes.lpSecurityDescriptor != (HLOCAL)0x0) {
    LocalFree(lpSecurityAttributes.lpSecurityDescriptor);
  }
  return DVar4;
}

