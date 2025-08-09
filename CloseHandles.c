
void CloseHandles(void)

{
  LPVOID lpMem;
  BOOL BVar1;
  DWORD error;
  HANDLE hHeap;
  undefined8 uVar2;
  
  if ((longlong)DAT_140080178 - 1U < 0xfffffffffffffffe) {
    BVar1 = SetEvent(DAT_140080178);
    if (BVar1 == 0) {
      error = GetLastError();
      if (0 < (int)error) {
        error = error & 0xffff | 0x80070000;
      }
      if ((int)error < 0) {
        uVar2 = 0xa8;
        goto CloseHandles;
      }
    }
    WaitForSingleObject(DAT_140080170,2000);
  }
  else {
    GetLastError();
    uVar2 = 0xa5;
CloseHandles:
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Instance::Destroy",uVar2);
  }
  if ((longlong)DAT_140080180 - 1U < 0xfffffffffffffffe) {
    CloseHandle(DAT_140080180);
    DAT_140080180 = (HANDLE)0x0;
  }
  if ((longlong)DAT_140080178 - 1U < 0xfffffffffffffffe) {
    CloseHandle(DAT_140080178);
    DAT_140080178 = (HANDLE)0x0;
  }
  if ((longlong)DAT_140080170 - 1U < 0xfffffffffffffffe) {
    CloseHandle(DAT_140080170);
    DAT_140080170 = (HANDLE)0x0;
  }
  lpMem = DAT_140080168;
  if (DAT_140080168 != (LPVOID)0x0) {
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,lpMem);
    DAT_140080168 = (LPVOID)0x0;
  }
  return;
}

