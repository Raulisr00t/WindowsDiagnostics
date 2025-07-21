
undefined8 Query(int *param_1,uint *param_2)

{
  uint uVar1;
  bool bVar2;
  int local_res8 [4];
  DWORD local_res18 [2];
  DWORD local_res20 [2];
  int *local_38 [2];
  
  *param_1 = 0;
  local_res20[0] = 4;
  local_res18[0] = 4;
  local_38[0] = local_res8;
  local_res8[0] = 1;
  uVar1 = ReadRegistryValueWithLogging
                    ((HKEY)0xffffffff80000002,
                     L"Software\\Policies\\Microsoft\\Windows\\ScriptedDiagnosticsProvider\\Policy" ,
                     local_res20,L"EnableQueryRemoteServer",local_38,local_res18);
  if ((int)uVar1 < 0) {
    PrintERROR(1,"Dwz IGNORED: %s:%d - hr = 0x%08X\n","Provider::BWCOn",0x307);
  }
  if (local_res8[0] == 0) {
    if (param_2 != (uint *)0x0) {
      *param_2 = 1;
    }
  }
  else {
    uVar1 = ReadRegistryValueWithLogging
                      ((HKEY)0xffffffff80000002,
                       L"Software\\Microsoft\\Windows\\ScriptedDiagnosticsProvider\\Policy",
                       local_res20,L"EnableQueryRemoteServer",local_38,local_res18);
    if ((int)uVar1 < 0) {
      PrintERROR(1,"Dwz IGNORED: %s:%d - hr = 0x%08X\n","Provider::BWCOn",799);
    }
    if (local_res8[0] == 0) {
      if (param_2 != (uint *)0x0) {
        *param_2 = 2;
      }
    }
    else {
      local_res8[0] = 0;
      uVar1 = ReadRegistryValueWithLogging
                        ((HKEY)0xffffffff80000002,L"Software\\Microsoft\\MSDE\\Policy",local_res20 ,
                         L"DefaultQueryRemoteServer",local_38,local_res18);
      if ((int)uVar1 < 0) {
        PrintERROR(1,"Dwz IGNORED: %s:%d - hr = 0x%08X\n","Provider::BWCOn",0x339);
      }
      bVar2 = local_res8[0] == 1;
      local_res8[0] = 2;
      uVar1 = ReadRegistryValueWithLogging
                        ((HKEY)0xffffffff80000001,
                         L"Software\\Microsoft\\Windows\\ScriptedDiagnosticsProvider\\Policy",
                         local_res20,L"EnableQueryRemoteServer",local_38,local_res18);
      if ((int)uVar1 < 0) {
        PrintERROR(1,"Dwz IGNORED: %s:%d - hr = 0x%08X\n","Provider::BWCOn",0x349);
      }
      if ((local_res8[0] == 1) || ((local_res8[0] != 0 && (bVar2)))) {
        *param_1 = 1;
      }
      if (param_2 != (uint *)0x0) {
        *param_2 = ~-(uint)(*param_1 != 0) & 3;
      }
    }
  }
  return 0;
}

