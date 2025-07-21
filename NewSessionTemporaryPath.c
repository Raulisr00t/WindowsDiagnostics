
void NewSessionTemporaryPath(LPCWSTR param_1)

{
  RPC_STATUS status;
  int value;
  uint uVar1;
  HANDLE hHeap;
  LPOLESTR memory;
  ulonglong token;
  undefined8 uVar2;
  undefined1 auStack_58 [32];
  uint local_38;
  ulonglong local_28;
  UUID UUID;
  ulonglong protection;
  
  protection = DAT_14007f440 ^ (ulonglong)auStack_58;
  local_28 = 0;
  UUID.Data1 = 0;
  UUID.Data2 = 0;
  UUID.Data3 = 0;
  UUID.Data4[0] = '\0';
  UUID.Data4[1] = '\0';
  UUID.Data4[2] = '\0';
  UUID.Data4[3] = '\0';
  UUID.Data4[4] = '\0';
  UUID.Data4[5] = '\0';
  UUID.Data4[6] = '\0';
  UUID.Data4[7] = '\0';
  hHeap = GetProcessHeap();
  memory = (LPOLESTR)HeapAlloc(hHeap,0,512);
  if (memory == (LPOLESTR)0x0) {
    local_38 = 0x8007000e;
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","NewSessionTemporaryPath",530);
    goto CleanUP;
  }
  status = UuidCreate(&UUID);
  if ((status == 0) || (status == 0x720)) {
    value = StringFromGUID2(&UUID,memory,256);
    if (value == 0) {
      uVar1 = 0x80004005;
      uVar2 = 540;
      goto Free;
    }
    token = 256;
    uVar1 = Calculate_buffer(memory,256,(longlong *)&local_28);
    if ((int)uVar1 < 0) {
      uVar2 = 0x220;
      goto Free;
    }
    if (2 < local_28) {
      *memory = L'_';
      memory[local_28 - 1] = L'_';
    }
    uVar1 = GetMSDTTempPath(param_1,token);
    if ((int)uVar1 < 0) {
      uVar2 = 0x22e;
      goto Free;
    }
    uVar1 = Calculate_PathBuffer(param_1,260,(longlong)memory);
    if ((int)uVar1 < 0) {
      uVar2 = 0x234;
      goto Free;
    }
    uVar1 = Calculate_PathBuffer(param_1,260,0x14006b240);
    if ((int)uVar1 < 0) {
      uVar2 = 0x23a;
      goto Free;
    }
    uVar1 = CreateDirectoryWR(param_1);
    if ((int)uVar1 < 0) {
      uVar2 = 0x240;
      goto Free;
    }
  }
  else {
    uVar1 = 0x80004005;
    uVar2 = 535;
Free:
    local_38 = uVar1;
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","NewSessionTemporaryPath",uVar2);
  }
  hHeap = GetProcessHeap();
  HeapFree(hHeap,0,memory);
CleanUP:
  ProtectStack(protection ^ (ulonglong)auStack_58);
  return;
}

