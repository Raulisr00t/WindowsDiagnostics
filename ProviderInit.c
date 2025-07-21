
void ProviderInit(undefined8 *module)

{
  DWORD error;
  HMODULE hModule;
  FARPROC address;
  undefined8 uVar1;
  undefined1 auStack_258 [32];
  DWORD local_238;
  WCHAR dest [264];
  ulonglong local_18;
  
  local_18 = DAT_14007f440 ^ (ulonglong)auStack_258;
  dest[0] = L'\0';
  error = ExpandEnvironmentStringsW(L"%windir%\\system32\\sdiagprv.dll",dest,260);
  if (error == 0) {
Addres:
                    /* hmodule = sdiagprv.dll  It's part of the Windows Scripted Diagnostic Provider
                       API */
    hModule = LoadLibraryW(dest);
    *module = hModule;
    if (hModule == (HMODULE)0x0) {
      uVar1 = 0x62;
      local_238 = 0x8000ffff;
    }
    else {
      address = GetProcAddress(hModule,"DllGetClassObject");
      if (address != (FARPROC)0x0) {
        module[2] = address;
        *(undefined4 *)(module + 1) = 1;
        goto Return;
      }
      uVar1 = 0x67;
      local_238 = 0x8000ffff;
    }
  }
  else {
    error = GetLastError();
    if (0 < (int)error) {
      error = error & 0xffff | 0x80070000;
    }
    if (-1 < (int)error) goto Addres;
    uVar1 = 0x5f;
    local_238 = error;
  }
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Provider::Init",uVar1);
Return:
  ProtectStack(local_18 ^ (ulonglong)auStack_258);
  return;
}

