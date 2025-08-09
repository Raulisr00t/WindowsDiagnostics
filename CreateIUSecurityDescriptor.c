
DWORD CreateIUSecurityDescriptor(undefined4 *param_1)

{
  int iVar1;
  DWORD error;
  BSTR bstrString;
  
                    /* Create SDDL String */
  bstrString = SysAllocString(L"D:(A;OICI;GA;;;IU)");
  if (bstrString == (BSTR)0x0) {
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","CreateIUSecurityDescriptor",0x144);
    return 0x8007000e;
  }
                    /* Convert the SDDL string to a real security descriptor */
  iVar1 = ConvertStringSecurityDescriptorToSecurityDescriptorW(bstrString,1,param_1 + 2);
  if (iVar1 == 0) {
    error = GetLastError();
    if (0 < (int)error) {
      error = error & 0xffff | 0x80070000;
    }
    if ((int)error < 0) {
      PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","CreateIUSecurityDescriptor",0x14e);
      goto CleanUp;
    }
  }
  else {
    error = 0;
  }
  param_1[4] = 0;
                    /* Success case setup */
  *param_1 = 0x18;
CleanUp:
  SysFreeString(bstrString);
  return error;
}

