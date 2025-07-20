
uint CopyWideStringToHeap(undefined8 *out_ptr,short *input_ptr)

{
  uint status;
  short *memory;
  HANDLE heap_handle;
  undefined8 uVar1;
  longlong bytes;
  longlong dwbytes;
  
  bytes = 0;
  if (out_ptr == (undefined8 *)0x0) {
    uVar1 = 454;
  }
  else {
    if (input_ptr != (short *)0x0) {
      status = Calculate_buffer(input_ptr,1024,&bytes);
      if ((int)status < 0) {
        uVar1 = 0x1ca;
      }
      else {
        heap_handle = GetProcessHeap();
        dwbytes = bytes;
        memory = (short *)HeapAlloc(heap_handle,0,bytes * 2 + 2);
        if (memory != (short *)0x0) {
          status = SafeWcsCopy(memory,dwbytes + 1,input_ptr);
          if ((int)status < 0) {
            PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","DwzStrCpy",464);
            heap_handle = GetProcessHeap();
            HeapFree(heap_handle,0,memory);
            return status;
          }
          *out_ptr = memory;
          return status;
        }
                    /* E_OUTOFMEMORY */
        status = 0x8007000e;
        uVar1 = 461;
      }
      goto ERROR;
    }
    uVar1 = 455;
  }
                    /* E_INVALIDARG */
  status = 0x80070057;
ERROR:
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","DwzStrCpy",uVar1);
  return status;
}

