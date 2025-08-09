
DWORD LoadInstance(void)

{
  DWORD error;
  BOOL BVar1;
  DWORD DVar2;
  HANDLE hHeap;
  LPCWSTR lpName;
  wchar_t *path;
  HANDLE hEvent;
  HANDLE pvVar3;
  uint uVar4;
  undefined8 uVar5;
  BOOL local_res10 [2];
  _SECURITY_ATTRIBUTES lpEventAttributes;
  
  hEvent = (HANDLE)0x0;
  local_res10[0] = 0;
  lpEventAttributes.nLength = 0;
  lpEventAttributes._4_4_ = 0;
  lpEventAttributes.lpSecurityDescriptor = (HLOCAL)0x0;
  lpEventAttributes.bInheritHandle = 0;
  lpEventAttributes._20_4_ = 0;
  pvVar3 = (HANDLE)0x0;
  error = CreateIUSecurityDescriptor(&lpEventAttributes.nLength);
  if ((int)error < 0) {
    uVar4 = 0x3b;
  }
  else {
    hHeap = GetProcessHeap();
    lpName = (LPCWSTR)HeapAlloc(hHeap,0,2048);
    if (lpName != (LPCWSTR)0x0) {
      hHeap = GetProcessHeap();
      path = (wchar_t *)HeapAlloc(hHeap,0,2048);
      DAT_140080168 = path;
      if (path == (wchar_t *)0x0) {
        uVar5 = 0x3e;
        error = 0x8007000e;
LAB_140047c49:
        PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Instance::Load",uVar5);
      }
      else {
        *path = L'\0';
        uVar5 = SafeFormatWString(path,1024,L"%s%u",L"Local\\msdt");
        error = (DWORD)uVar5;
        if ((int)error < 0) {
          uVar5 = 0x45;
          hEvent = pvVar3;
          goto LAB_140047c49;
        }
        error = IsAdminToken(local_res10);
        if ((int)error < 0) {
          uVar5 = 0x48;
          hEvent = pvVar3;
          goto LAB_140047c49;
        }
        if ((local_res10[0] == 0) && (*maybe_everything == 0)) {
          error = SafeWcsCopy(lpName,1024,DAT_140080168);
          if ((int)error < 0) {
            uVar5 = 0x52;
            hEvent = pvVar3;
          }
          else {
            error = Calculate_PathBuffer(lpName,1024,0x140071a54);
            if (-1 < (int)error) {
              hEvent = OpenEventW(2,0,lpName);
              if (hEvent == (HANDLE)0x0) goto LAB_140047ae2;
              AllowSetForegroundWindow(0xffffffff);
              BVar1 = SetEvent(hEvent);
              if (BVar1 == 0) {
                error = GetLastError();
                if (0 < (int)error) {
                  error = error & 0xffff | 0x80070000;
                }
                if ((int)error < 0) {
                  uVar5 = 0x5f;
                  goto LAB_140047c49;
                }
              }
              goto LAB_140047aad;
            }
            uVar5 = 0x55;
            hEvent = pvVar3;
          }
          goto LAB_140047c49;
        }
        error = Calculate_PathBuffer(DAT_140080168,1024,0x140071a54);
        if ((int)error < 0) {
          uVar5 = 0x4c;
          hEvent = pvVar3;
          goto LAB_140047c49;
        }
LAB_140047ae2:
        DAT_140080180 = CreateEventW(&lpEventAttributes,0,0,DAT_140080168);
        if (0xfffffffffffffffd < (longlong)DAT_140080180 - 1U) {
          error = GetLastError();
          if (0 < (int)error) {
            error = error & 0xffff | 0x80070000;
          }
          uVar5 = 0x6b;
          goto LAB_140047c49;
        }
        DVar2 = GetLastError();
        if (DVar2 != 0xb7) {
          DAT_140080178 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
                    /* Create background coordination thread (if first instance) */
          if ((longlong)DAT_140080178 - 1U < 0xfffffffffffffffe) {
            DAT_140080170 =
                 CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,ActivateThread,(LPVOID)0x0,0,(LPDWORD)0 x0
                             );
            if (((longlong)DAT_140080170 + 1U & 0xfffffffffffffffe) != 0) goto BeforeCleanUp;
            error = GetLastError();
            if (0 < (int)error) {
              error = error & 0xffff | 0x80070000;
            }
            uVar5 = 0x81;
          }
          else {
                    /* ERROR_ALREADY_EXISTS */
            error = GetLastError();
            if (0 < (int)error) {
              error = error & 0xffff | 0x80070000;
            }
            uVar5 = 0x7b;
          }
          goto LAB_140047c49;
        }
        AllowSetForegroundWindow(0xffffffff);
        BVar1 = SetEvent(DAT_140080180);
        if (BVar1 == 0) {
          error = GetLastError();
          if (0 < (int)error) {
            error = error & 0xffff | 0x80070000;
          }
          if ((int)error < 0) {
            uVar5 = 0x74;
            goto LAB_140047c49;
          }
        }

LAB_140047aad:
        error = 1;
      }

BeforeCleanUp:
      pvVar3 = GetProcessHeap();
      HeapFree(pvVar3,0,lpName);
      goto CleanUp;
    }
    error = 0x8007000e;
    uVar4 = 0x3d;
  }
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Instance::Load",(ulonglong)uVar4);

CleanUp:
  if (lpEventAttributes.lpSecurityDescriptor != (HLOCAL)0x0) {
    LocalFree(lpEventAttributes.lpSecurityDescriptor);
    lpEventAttributes.lpSecurityDescriptor = (HLOCAL)0x0;
  }
  if ((longlong)hEvent - 1U < 0xfffffffffffffffe) {
    CloseHandle(hEvent);
  }
  return error;
}

