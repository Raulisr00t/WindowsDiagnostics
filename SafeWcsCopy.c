
uint SafeWcsCopy(short *dst,longlong buffer_size,undefined8 FILE)

{
  uint uVar1;
  
  if (buffer_size - 1U < 0x7fffffff) {
    uVar1 = SafeWcsCopyInternal(dst,buffer_size,FILE,FILE);
  }
  else {
    uVar1 = 0x80070057;
    if (buffer_size != 0) {
      *dst = 0;
    }
  }
  return uVar1;
}

