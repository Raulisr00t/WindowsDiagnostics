
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Allocation(longlong *param_1,undefined4 task_id)

{
  HRESULT result;
  LPWSTR mem;
  LPWSTR buff;
  TaskPage *pTVar1;
  HANDLE handle_heap;
  undefined8 uVar2;
  undefined1 auStack_878 [32];
  HRESULT error;
  TaskPage *page;
  WCHAR buffer [1024];
  ulonglong local_38;
  
  local_38 = DAT_14007f440 ^ (ulonglong)auStack_878;
  pTVar1 = (TaskPage *)0x0;
                    /* NULL termination '\0' */
  buffer[0] = L'\0';
  handle_heap = GetProcessHeap();
  mem = (LPWSTR)HeapAlloc(handle_heap,0,2048);
  if (mem == (LPWSTR)0x0) {
    error = -0x7ff8fff2;
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Mode::Error",103);
    goto CleanUP;
  }
  *mem = L'\0';
  handle_heap = GetProcessHeap();
  buff = (LPWSTR)HeapAlloc(handle_heap,0,2048);
  if (buff == (LPWSTR)0x0) {
    error = -0x7ff8fff2;
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Mode::Error",106);
  }
  else {
    *mem = L'\0';
    result = DwzLoadLocalString(440,buffer,1024);
    if (result < 0) {
      uVar2 = 110;
LAB_140028b1e:
      error = result;
      PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Mode::Error",uVar2);
    }
    else {
      result = DwzLoadLocalString(DAT_14007f498,mem,1024);
      if (result < 0) {
        uVar2 = 0x71;
        goto LAB_140028b1e;
      }
      result = DwzLoadLocalString(0x132,buff,1024);
      if (result < 0) {
        uVar2 = 0x74;
        goto LAB_140028b1e;
      }
      page = (TaskPage *)MemoryAllocate(136);
      if (page != (TaskPage *)0x0) {
        pTVar1 = InitTaskPage(page,task_id,buffer,mem);
      }
      if (pTVar1 == (TaskPage *)0x0) {
        result = -0x7ff8fff2;
        uVar2 = 0x7b;
        goto LAB_140028b1e;
      }
      result = (**(code **)(*param_1 + 0x10))(param_1,pTVar1,buff);
      if (result < 0) {
        uVar2 = 0x7e;
        goto LAB_140028b1e;
      }
    }
    handle_heap = GetProcessHeap();
    HeapFree(handle_heap,0,buff);
  }
  handle_heap = GetProcessHeap();
  HeapFree(handle_heap,0,mem);
CleanUP:

  ProtectStack(local_38 ^ (ulonglong)auStack_878);
  return;
}

