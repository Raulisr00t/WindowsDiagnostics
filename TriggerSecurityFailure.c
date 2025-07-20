
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TriggerSecurityFailure(undefined8 failure_code)

{
  DWORD64 ControlPc;
  PRUNTIME_FUNCTION FunctionEntry;
  ulonglong local_38 [2];
  PVOID local_28;
  undefined8 uStack_20;
  undefined8 uStack_18;
  
  local_38[1] = 0;
  local_28 = (PVOID)0x0;
  local_38[0] = 0;
  RtlCaptureContext(&DAT_14007f8a0);
  ControlPc = DAT_14007f998;
  FunctionEntry = RtlLookupFunctionEntry(DAT_14007f998,local_38,(PUNWIND_HISTORY_TABLE)0x0);
  
  if (FunctionEntry == (PRUNTIME_FUNCTION)0x0) {
    DAT_14007f998 = *DAT_14007f938;
    DAT_14007f938 = DAT_14007f938 + 1;
  }
  else {
    RtlVirtualUnwind(0,local_38[0],ControlPc,FunctionEntry,(PCONTEXT)&DAT_14007f8a0,&local_28,
                     local_38 + 1,(PKNONVOLATILE_CONTEXT_POINTERS)0x0);
  }
  _DAT_14007f810 = DAT_14007f998;
                    /* STATUS_STACK_BUFFER_OVERRUN */
  _DAT_14007f800 = 0xc0000409;
  _DAT_14007f804 = 1;
  _DAT_14007f818 = 3;
  DAT_14007f820 = 2;
  DAT_14007f828 = DAT_14007f440;
  DAT_14007f830 = DAT_14007f480;
  uStack_20 = DAT_14007f440;
  uStack_18 = DAT_14007f480;
  _DAT_14007f920 = failure_code;
                    /* Raise fast-fail security exception */
  __raise_securityfailure((_EXCEPTION_POINTERS *)&PTR_DAT_1400649e0);

 return;
}

