
ulonglong InitializeGlobalConfig(void)

{
  uint status;
  undefined8 *unused_buff_ptr;
  uint64_t result;
  ulonglong typecasted;
  undefined8 error_code;
  undefined8 new_buff;
  undefined8 *memory_pointer_ref;
  
  new_buff = 0;
                    /* Allocate 288 byte memory dynamicly ... */
  unused_buff_ptr = (undefined8 *)MemoryAllocate(288);
  memory_pointer_ref = unused_buff_ptr;

  if (unused_buff_ptr == (undefined8 *)0x0) {
    maybe_everything = (undefined8 *)0x0;
  }
  
  else {
    maybe_everything = InitializeStruct(unused_buff_ptr);
    if (maybe_everything != (undefined8 *)0x0) {
      result = CheckAllowSkipFirstPageConfig(unused_buff_ptr);
                    /* ERROR */
      typecasted = result & 0xffffffff;
      if ((int)result < 0) {
        error_code = 61;
      }
      else {
        unused_buff_ptr = &new_buff;
        status = CopyWideStringToHeap(unused_buff_ptr,L"Microsoft");
        typecasted = (ulonglong)status;
        if (-1 < (int)status) {
          ReplaceHeapBuffer(unused_buff_ptr,new_buff);
          return typecasted;
        }
        error_code = 64;
      }
      goto Error;
    }
  }
  typecasted = 0x8007000e;
  error_code = 55;

Error:
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Configuration::Initialize",error_code);
  return typecasted;
}

