
uint Calculate_buffer(short *input_pointer,longlong size,longlong *param_3)

{
  uint uVar1;
  
  if (input_pointer == (short *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = SafeWcsnlen(input_pointer,size,param_3);
    if (-1 < (int)uVar1) {
      return uVar1;
    }
  }
  if (param_3 != (longlong *)0x0) {
    *param_3 = 0;
  }
  return uVar1;
}

