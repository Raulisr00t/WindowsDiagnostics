
DWORD IsAdminToken(PBOOL IsMember)

{
  BOOL Created;
  DWORD error;
  LPVOID pSid;
  HANDLE hHeap;
  DWORD cbSID [2];
  
  cbSID[0] = 68;
  hHeap = GetProcessHeap();
  pSid = HeapAlloc(hHeap,0,68);
  if (pSid == (LPVOID)0x0) {
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","IsAdminToken",670);
    return 0x8007000e;
  }
  Created = CreateWellKnownSid(WinBuiltinAdministratorsSid,(PSID)0x0,pSid,cbSID);
  if (Created == 0) {
    error = GetLastError();
    if (0 < (int)error) {
      error = error & 0xffff | 0x80070000;
    }
    if ((int)error < 0) {
      PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","IsAdminToken",676);
      goto CleanUP;
    }
  }
  Created = CheckTokenMembership((HANDLE)0x0,pSid,IsMember);
  if (Created == 0) {
    error = GetLastError();
    if (0 < (int)error) {
      error = error & 0xffff | 0x80070000;
    }
    if ((int)error < 0) {
      error = 0;
      *IsMember = 0;
    }
  }
  else {
    error = 0;
  }

CleanUP:
  hHeap = GetProcessHeap();
  HeapFree(hHeap,0,pSid);
  return error;
}

