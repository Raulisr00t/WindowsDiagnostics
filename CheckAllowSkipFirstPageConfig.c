
uint64_t CheckAllowSkipFirstPageConfig(undefined8 param)

{
  uint status;
  int iStackX_8;
  undefined4 stack;
  DWORD data_size [2];
  DWORD type [2];
  int *value;
  longlong configobj;
  
  configobj = maybe_everything;
  _iStackX_8 = CONCAT44((int)((ulonglong)param >> 0x20),1);
  type[0] = 4;
  data_size[0] = 4;
  value = &iStackX_8;
  status = ReadRegistryValueWithLogging
                     ((HKEY)0xffffffff80000001,
                      L"Software\\Microsoft\\Windows NT\\CurrentVersion\\MSDT",type,
                      L"AllowSkipFirstPage",&value,data_size);
  if ((int)status < 0) {
    PrintERROR(1,"Dwz IGNORED: %s:%d - hr = 0x%08X\n","Configuration::CheckRegistrySkipWelcome",1 986
              );
  }
  *(uint *)(configobj + 0x38) = (uint)(iStackX_8 != 0);

  return 0;
}

