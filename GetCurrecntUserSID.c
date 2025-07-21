
DWORD GetCurrecntUserSID(undefined8 param_1)

{
  BOOL BVar1;
  DWORD error_code;
  int iVar2;
  HANDLE HANDLE;
  undefined8 *memory;
  undefined8 uVar3;
  DWORD local_res10 [2];
  HANDLE handle [2];
  
  local_res10[0] = 0;
  handle[0] = (HANDLE)0x0;
  memory = (undefined8 *)0x0;
  HANDLE = GetCurrentThread();
  BVar1 = OpenThreadToken(HANDLE,8,0,handle);
  if (BVar1 == 0) {
    error_code = GetLastError();
    if (0 < (int)error_code) {
      error_code = error_code & 0xffff | 0x80070000;
    }
    if ((int)error_code < 0) {
      if ((short)error_code != 0x3f0) {
        uVar3 = 730;
LAB_140041813:
        PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","GetCurrentUserSid",uVar3);
        goto LAB_14004182f;
      }
      HANDLE = GetCurrentProcess();
      BVar1 = OpenProcessToken(HANDLE,8,handle);
      if (BVar1 == 0) {
        error_code = GetLastError();
        if (0 < (int)error_code) {
          error_code = error_code & 0xffff | 0x80070000;
        }
        if ((int)error_code < 0) {
          uVar3 = 734;
          goto LAB_140041813;
        }
      }
    }
  }
  local_res10[0] = 0x32;
  do {
    if (memory != (undefined8 *)0x0) {
      HANDLE = GetProcessHeap();
      HeapFree(HANDLE,0,memory);
    }
    error_code = local_res10[0];
    HANDLE = GetProcessHeap();
    memory = (undefined8 *)HeapAlloc(HANDLE,0,(ulonglong)error_code);
    if (memory == (undefined8 *)0x0) {
      error_code = 0x8007000e;
      uVar3 = 745;
      goto LAB_140041813;
    }
    BVar1 = GetTokenInformation(handle[0],TokenUser,memory,local_res10[0],local_res10);
    if (BVar1 != 0) goto LAB_14004178e;
    error_code = GetLastError();
    if (0 < (int)error_code) {
      error_code = error_code & 0xffff | 0x80070000;
    }
  } while ((short)error_code == 0x7a);
  if ((int)error_code < 0) {
    uVar3 = 0x2ed;
LAB_1400417ca:
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","GetCurrentUserSid",uVar3);
  }
  else {
LAB_14004178e:
    iVar2 = ConvertSidToStringSidW(*memory,param_1);
    if (iVar2 == 0) {
      error_code = GetLastError();
      if (0 < (int)error_code) {
        error_code = error_code & 0xffff | 0x80070000;
      }
      if ((int)error_code < 0) {
        uVar3 = 0x2f3;
        goto LAB_1400417ca;
      }
    }
    else {
      error_code = 0;
    }
  }
  HANDLE = GetProcessHeap();
  HeapFree(HANDLE,0,memory);
LAB_14004182f:
  if ((longlong)handle[0] - 1U < 0xfffffffffffffffe) {
    CloseHandle(handle[0]);
  }
  return error_code;
}

