
uint CreateTemporarySessionFile(void)

{
  uint uVar1;
  LPCWSTR FileName;
  short *dst;
  HANDLE hHeap;
  short *psVar2;
  undefined8 uVar3;
  longlong MAX_PATH;
  _SECURITY_ATTRIBUTES attr;
  
  attr._4_4_ = 0;
  attr.nLength = 0;
  attr.lpSecurityDescriptor = (HLOCAL)0x0;
  attr.bInheritHandle = 0;
  attr._20_4_ = 0;
  hHeap = GetProcessHeap();
  FileName = (LPCWSTR)HeapAlloc(hHeap,0,520);
  if (FileName == (LPCWSTR)0x0) {
    uVar3 = 0x189;
    uVar1 = 0x8007000e;
    psVar2 = (short *)0x0;
  }
  else {
    hHeap = GetProcessHeap();
    dst = (short *)HeapAlloc(hHeap,0,520);
    psVar2 = dst;
    if (dst == (short *)0x0) {
      uVar3 = 0x18a;
      uVar1 = 0x8007000e;
    }
    else {
      uVar1 = NewSessionTemporaryPath(FileName);
      if ((int)uVar1 < 0) {
        uVar3 = 400;
      }
      else {
        MAX_PATH = 260;
        uVar1 = SafeWcsCopy(dst,260,FileName);
        if ((int)uVar1 < 0) {
          uVar3 = 0x193;
        }
        else {
          uVar1 = Calculate_PathBuffer(FileName,MAX_PATH,0x1400711b8);
          if ((int)uVar1 < 0) {
            uVar3 = 0x196;
          }
          else {
            uVar1 = CreateSecurityDescriptorR(&attr.nLength);
            if ((int)uVar1 < 0) {
              uVar3 = 409;
            }
            else {
              hHeap = CreateFileW(FileName,0xc0000000,0,&attr,1,1,(HANDLE)0x0);
              if ((longlong)hHeap - 1U < 0xfffffffffffffffe) {
                psVar2 = (short *)0x0;
                DAT_140080148 = hHeap;
                DAT_140080150 = dst;
                goto CleanUp;
              }
              uVar1 = GetLastError();
              if (0 < (int)uVar1) {
                uVar1 = uVar1 & 0xffff | 0x80070000;
              }
              uVar3 = 422;
            }
          }
        }
      }
    }
  }
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","CreateTemporarySessionFile",uVar3);

CleanUp:
  if (attr.lpSecurityDescriptor != (HLOCAL)0x0) {
    LocalFree(attr.lpSecurityDescriptor);
    attr.lpSecurityDescriptor = (HLOCAL)0x0;
  }
  if (FileName != (LPCWSTR)0x0) {
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,FileName);
  }
  if (psVar2 != (short *)0x0) {
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,psVar2);
  }
  return uVar1;
}

