
DWORD CreateSecurityDescriptorR(undefined4 *param_1)

{
  DWORD error;
  int iVar1;
  undefined8 uVar2;
  BSTR local_res10 [3];
  
  local_res10[0] = (BSTR)0x0;
  error = CreateSDDL(local_res10);
  if ((int)error < 0) {
    uVar2 = 0x395;
LAB_140040f0d:
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","CreateSecurityDescriptor",uVar2);
  }
  else {
    iVar1 = ConvertStringSecurityDescriptorToSecurityDescriptorW(local_res10[0],1,param_1 + 2);
    if (iVar1 == 0) {
      error = GetLastError();
      if (0 < (int)error) {
        error = error & 0xffff | 0x80070000;
      }
      if ((int)error < 0) {
        uVar2 = 0x39f;
        goto LAB_140040f0d;
      }
    }
    else {
      error = 0;
    }
    param_1[4] = 0;
    *param_1 = 0x18;
  }
  if (local_res10[0] != (BSTR)0x0) {
    SysFreeString(local_res10[0]);
  }
  return error;
}

