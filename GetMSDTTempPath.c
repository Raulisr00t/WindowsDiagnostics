
DWORD GetMSDTTempPath(short *buffer,ulonglong token)

{
  DWORD error;
  int success;
  wchar_t *pwVar1;
  undefined8 uVar2;
  ulonglong local_res10 [3];
  
  local_res10[0] = token & 0xffffffff00000000;
  error = IsAdminToken((PBOOL)local_res10);
  if ((int)error < 0) {
    uVar2 = 0x1d8;
  }
  else {
    pwVar1 = L"msdtadmin";
    if ((int)local_res10[0] == 0) {
      pwVar1 = L"msdt";
    }
                    /* Create a Temp file max path value is equal to 260 */
    success = GetTempPath2W(260,buffer);
    if (success - 1U < 0x104) {
      error = Calculate_PathBuffer(buffer,0x104,(longlong)pwVar1);
      if ((int)error < 0) {
        uVar2 = 486;
      }
      else {
        error = Calculate_PathBuffer(buffer,0x104,0x14006b240);
        if (-1 < (int)error) {
          return error;
        }
        uVar2 = 492;
      }
    }
    else {
      error = GetLastError();
      if (0 < (int)error) {
        error = error & 0xffff | 0x80070000;
      }
      uVar2 = 479;
    }
  }
  
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","GetMsdtTempPath",uVar2);
  return error;
}

