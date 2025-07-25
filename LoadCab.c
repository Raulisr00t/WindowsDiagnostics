
DWORD LoadCab(longlong param_1,LPCWSTR param_2)

{
  DWORD DVar1;
  OLECHAR *local_res18 [2];
  
  local_res18[0] = (OLECHAR *)0x0;
  DVar1 = CononicalizeFilePath(param_2,local_res18);
  if ((int)DVar1 < 0) {
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Configuration::LoadCab",0x68f);
  }
  else {
    Packages_SetPath(local_res18[0]);
    *(undefined4 *)(param_1 + 0x108) = 5;
  }
  return DVar1;
}

