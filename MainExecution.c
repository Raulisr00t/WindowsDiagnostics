
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void MainExecution(undefined8 param)

{
  uint typecasted_status;
  BOOL exited;
  ulonglong status;
  longlong *plVar1;
  undefined8 ActivityID;
  undefined1 stack [32];
  uint local_38;
  DWORD exit_code;
  longlong *local_30;
  _EVENT_DATA_DESCRIPTOR evnt;
  ulonglong local_18;
  longlong *plVar2;
  
  local_18 = DAT_14007f440 ^ (ulonglong)stack;
  plVar2 = (longlong *)0x0;
  plVar1 = (longlong *)0x0;
  local_38 = 0;
  ActivityID = 0;
                    /* Register Event for Diagnos */
  local_30 = (longlong *)0x0;
  HeapSetInformation((HANDLE)0x0,HeapEnableTerminationOnCorruption,(PVOID)0x0,0);
  RegisterEvent();
  if ((DAT_14007ff40 & 1) != 0) {
                    /* Logging Event  */
    LogEvent(&RegistryHandle,(PCEVENT_DESCRIPTOR)&DAT_14006b610,ActivityID,1,&evnt);
  }
  hInstance = param;
  status = InitializeGlobalConfig();
  typecasted_status = (uint)status;
  if ((int)typecasted_status < 0) {
    ActivityID = 79;
    plVar1 = plVar2;
CleanUP:
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","wWinMain",ActivityID);
    if (plVar1 == (longlong *)0x0) {
      plVar1 = (longlong *)MemoryAllocate(32);
      if (plVar1 == (longlong *)0x0) goto EXIT;
      *(undefined4 *)(plVar1 + 1) = 0;
      *(undefined4 *)((longlong)plVar1 + 0xc) = 0;
      *(undefined4 *)(plVar1 + 2) = 0;
      plVar1[3] = 0;
      *plVar1 = (longlong)&PTR_FUN_140064ac0;
    }
    Allocation(plVar1,typecasted_status);
  }

  else {
    typecasted_status =
         WriteToRegistry(L"Software\\Policies\\Microsoft\\Windows\\ScriptedDiagnostics",
                         L"EnableDiagnostics");
    if ((int)typecasted_status < 0) {
      ActivityID = 87;
      plVar1 = plVar2;
      goto CleanUP;
    }
    DAT_14007f498 = 0x197;
    typecasted_status = CreateTemporarySessionFile();
    if ((int)typecasted_status < 0) {
      ActivityID = 91;
      plVar1 = plVar2;
      goto CleanUP;
    }
    DAT_14007f498 = 0x192;
    typecasted_status = CoInitializeEx((LPVOID)0x0,2);
    if ((int)typecasted_status < 0) {
      ActivityID = 98;
      goto CleanUP;
    }
    status = maybe_everything;
    typecasted_status = ArgumentParser(maybe_everything);
    if ((int)typecasted_status < 0) {
      ActivityID = 101;
      goto CleanUP;
    }
    if (typecasted_status == 1) goto EXIT;
    typecasted_status = GetInstanceHash(status,&local_38);
    if ((int)typecasted_status < 0) {
      ActivityID = 134;
      goto CleanUP;
    }
    status = (ulonglong)local_38;
    typecasted_status = LoadInstance();
    if ((int)typecasted_status < 0) {
      ActivityID = 137;
      goto CleanUP;
    }
    if (typecasted_status == 1) goto EXIT;
    typecasted_status = LoadMode(status,&local_30);
    plVar1 = local_30;
    if ((int)typecasted_status < 0) {
      ActivityID = 147;
      goto CleanUP;
    }
    DAT_14007f498 = 400;
    typecasted_status = (**(code **)*local_30)(local_30);
    if ((int)typecasted_status < 0) {
      ActivityID = 0x9a;
      goto CleanUP;
    }
  }
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 8))(plVar1,1);
  }

EXIT:
  DestroyConfiguration();
  CloseHandles();
  CleanFiles();
  UnRegisterEvent();
  
  if ((((hProcess != (HANDLE)0x0) &&
       (exit_code = WaitForSingleObject(hProcess,0xffffffff), exit_code == 0)) &&
      (exited = GetExitCodeProcess(hProcess,&exit_code), exited != 0)) && (exit_code != 0xffffffff ))
  {
    new = exit_code;
  }

  ProtectStack(local_18 ^ (ulonglong)stack);
  return;
}
