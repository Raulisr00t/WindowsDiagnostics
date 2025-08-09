
void CleanFiles(void)

{
  LPVOID pvVar1;
  int iVar2;
  BOOL BVar3;
  HANDLE hHeap;
  wchar_t *path;
  wchar_t *path_00;
  wchar_t *Path;
  DWORD code;
  HANDLE hFile;
  ulonglong token;
  undefined8 uVar4;
  undefined1 auStackY_4c8 [32];
  _WIN32_FIND_DATAW variable;
  short buffer [264];
  ulonglong local_28;
  
  local_28 = DAT_14007f440 ^ (ulonglong)auStackY_4c8;
  memset(&variable,0,592);
  hFile = (HANDLE)0x0;
  path_00 = (wchar_t *)0x0;
  Path = (wchar_t *)0x0;
  hHeap = GetProcessHeap();
  path = (wchar_t *)HeapAlloc(hHeap,0,520);
  if (path == (wchar_t *)0x0) {
    uVar4 = 0x464;
  }
  else {
    hHeap = GetProcessHeap();
    path_00 = (wchar_t *)HeapAlloc(hHeap,0,520);
    if (path_00 == (wchar_t *)0x0) {
      uVar4 = 0x465;
    }
    else {
      hHeap = GetProcessHeap();
      token = 0;
      Path = (wchar_t *)HeapAlloc(hHeap,0,520);
      if (Path == (wchar_t *)0x0) {
        uVar4 = 0x466;
      }
      else {
        if ((longlong)DAT_140080148 - 1U < 0xfffffffffffffffe) {
          CloseHandle(DAT_140080148);
          DAT_140080148 = (HANDLE)0x0;
        }
        code = GetMSDTTempPath(buffer,token);
        if ((int)code < 0) {
          uVar4 = 0x470;
        }
        else {
          uVar4 = SafeFormatWString(Path,260,&DAT_140071390,buffer);
          if ((int)uVar4 < 0) {
            uVar4 = 0x473;
          }
          else {
            hHeap = FindFirstFileW(Path,&variable);
            if ((longlong)hHeap - 1U < 0xfffffffffffffffe) {
              do {
                if (((((byte)variable.dwFileAttributes & 0x10) == 0) ||
                    (iVar2 = _wcsicmp(variable.cFileName,L"."), iVar2 == 0)) ||
                   (iVar2 = _wcsicmp(variable.cFileName,L".."), iVar2 == 0)) goto FindNext;
                uVar4 = SafeFormatWString(path,260,L"%s%s",buffer);
                if ((int)uVar4 < 0) {
                  uVar4 = 0x489;
LAB_14004045f:
                  PrintERROR(1,"Dwz WARNING: %s:%d - hr = 0x%08X\n","CleanupFiles",uVar4);
                }
                else {
                  code = GetFileAttributesW(path);
                  if (((code & 1) != 0) && (BVar3 = SetFileAttributesW(path,0x80), BVar3 == 0)) {
                    code = GetLastError();
                    if (0 < (int)code) {
                      code = code & 0xffff | 0x80070000;
                    }
                    if ((int)code < 0) {
                      PrintERROR(1,"Dwz IGNORED: %s:%d - hr = 0x%08X\n","CleanupFiles",0x490);
                    }
                  }
                  uVar4 = SafeFormatWString(path_00,260,L"%s\\%s",path);
                  if ((int)uVar4 < 0) {
                    uVar4 = 0x494;
                    goto LAB_14004045f;
                  }
                  code = GetFileAttributesW(path_00);
                  if (((code & 1) != 0) && (BVar3 = SetFileAttributesW(path_00,0x80), BVar3 == 0))  {
                    code = GetLastError();
                    if (0 < (int)code) {
                      code = code & 0xffff | 0x80070000;
                    }
                    if ((int)code < 0) {
                      PrintERROR(1,"Dwz IGNORED: %s:%d - hr = 0x%08X\n","CleanupFiles",0x49b);
                    }
                  }
                  DeleteFileW(path_00);
                  hFile = CreateFileW(path_00,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,
                                      (HANDLE)0x0);
                  if (hFile == (HANDLE)0xffffffffffffffff) {
                    code = GetLastError();
                    if ((code == 2) && (iVar2 = FUN_1400411e8(path), iVar2 < 0)) {
                      uVar4 = 0x4b3;
                      goto LAB_14004045f;
                    }
                  }
                  else if (hFile != (HANDLE)0x0) {
                    CloseHandle(hFile);
                    hFile = (HANDLE)0x0;
                  }
                }
FindNext:
                BVar3 = FindNextFileW(hHeap,&variable);
              } while (BVar3 != 0);
              FindClose(hHeap);
              goto CleanUP;
            }
            GetLastError();
            uVar4 = 0x476;
          }
        }
      }
    }
  }
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","CleanupFiles",uVar4);
CleanUP:
  pvVar1 = DAT_140080150;
  if (DAT_140080150 != (LPVOID)0x0) {
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,pvVar1);
    DAT_140080150 = (LPVOID)0x0;
  }
  pvVar1 = DAT_140080158;
  if (DAT_140080158 != (LPVOID)0x0) {
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,pvVar1);
    DAT_140080158 = (LPVOID)0x0;
  }
  if ((longlong)hFile - 1U < 0xfffffffffffffffe) {
    CloseHandle(hFile);
  }
  if ((longlong)DAT_140080148 - 1U < 0xfffffffffffffffe) {
    CloseHandle(DAT_140080148);
    DAT_140080148 = (HANDLE)0x0;
  }
  if (path_00 != (wchar_t *)0x0) {
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,path_00);
  }
  if (path != (wchar_t *)0x0) {
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,path);
  }
  if (Path != (wchar_t *)0x0) {
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,Path);
  }
  ProtectStack(local_28 ^ (ulonglong)auStackY_4c8);
  return;
}

