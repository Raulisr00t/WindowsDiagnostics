
uint ReadRegistryValueWithLogging
               (HKEY key,LPCWSTR subkey,LPDWORD type,LPCWSTR valuename,undefined8 *data,
               DWORD *param_6)

{
  uint status;
  undefined8 uVar1;
  DWORD cbData [2];
  HKEY hKey;
  
  hKey = (HKEY)0x0;
  cbData[0] = 0;
                    /* Open The Key  */
  status = RegOpenKeyExW(key,subkey,0,131097,&hKey);
  if ((int)status < 0) {
    uVar1 = 0xe9;
  }
  else {
    if (hKey == (HKEY)0x0) {
      return 1;
    }
                    /* If for some reason hKey is still null (rare), return 1 as a failure. */
    cbData[0] = *param_6;
                    /* Query Value for KEY */
    status = RegQueryValueExW(hKey,valuename,(LPDWORD)0x0,type,(LPBYTE)*data,cbData);
    if (0 < (int)status) {
      status = status & 0xffff | 0x80070000;
    }
    if (-1 < (int)status) {
      if (*type != 4) {
        *param_6 = cbData[0];
      }
      goto CleanUP;
    }
    uVar1 = 0xfd;
  }
                    /* If RegQueryValueExW Fails: */
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","DwzRegReadValue",uVar1);
CleanUP:
                    /* Clean the Key free ! */
  if (hKey != (HKEY)0x0) {
    RegCloseKey(hKey);
  }

 return status;
}
