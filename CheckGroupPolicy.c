
int CheckGroupPolicy(LPCWSTR KEY_PATH,LPCWSTR value)

{
  int iVar1;
  uint uVar2;
  HRESULT result;
  HANDLE heap_handle;
  LPWSTR memory;
  undefined8 UID;
  int local_res8 [4];
  DWORD local_res18 [2];
  DWORD local_res20 [2];
  int *local_28 [2];
  
  local_res20[0] = 4;
  local_res18[0] = 4;
  local_res8[0] = 1;
  local_28[0] = local_res8;
  if (KEY_PATH == (LPCWSTR)0x0) {
    UID = 0x754;
  }
  else {
    if (value != (LPCWSTR)0x0) {
      uVar2 = ReadRegistryValueWithLogging
                        ((HKEY)0xffffffff80000002,KEY_PATH,local_res20,value,local_28,local_res18) ;
      if ((int)uVar2 < 0) {
        PrintERROR(1,"Dwz IGNORED: %s:%d - hr = 0x%08X\n","CheckGroupPolicy",0x761);
      }
      if (local_res8[0] != 0) {
        return 0;
      }
      heap_handle = GetProcessHeap();
                    /* Alocate 2048 byte from Heap dynamicly... */
      memory = (LPWSTR)HeapAlloc(heap_handle,0,2048);
      if (memory == (LPWSTR)0x0) {
        iVar1 = -0x7ff8fff2;
                    /* The identifier of the string to be loaded. */
        UID = 1892;
      }
      else {
                    /* The identifier of the string to be loaded. */
        UID = 390;
                    /* Load string Max size is 1024 UID us 390 */
        result = DwzLoadLocalString(390,memory,1024);
        if (result < 0) {
          PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","CheckGroupPolicy",0x767);
          heap_handle = GetProcessHeap();
          HeapFree(heap_handle,0,memory);
          return result;
        }
        Free?(UID,memory);
        iVar1 = -0x7ff8fffb;
        UID = 1901;
      }
      goto EXIT;
    }
    UID = 0x755;
  }
  iVar1 = -0x7ff8ffa9;
EXIT:
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","CheckGroupPolicy",UID);
  return iVar1;
}

