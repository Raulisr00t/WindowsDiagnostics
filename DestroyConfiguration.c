
HRESULT DestroyConfiguration(void)

{
  void *_Memory;
  HRESULT result;
  longlong *local_res8;
  
  local_res8 = (longlong *)0x0;
  result = Instance((longlong *)&local_res8);
  if (result < 0) {
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Configuration::Destroy",0xe7);
  }
  _Memory = maybe_everything;
  if (maybe_everything != (void *)0x0) {
    Free((longlong)maybe_everything);
    free(_Memory);
    maybe_everything = (void *)0x0;
  }
  if (local_res8 != (longlong *)0x0) {
    FUN_140033640(local_res8); // that about destroy configurations maybe you can check for sure ...
  }
  return result;
}

