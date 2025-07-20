
uint SafeWcsnlen(short *input_pointer,longlong MaxChars,longlong *Out_length)

{
  uint uVar1;
  longlong lVar2;
  
  lVar2 = MaxChars;
  do {
    if (*input_pointer == 0) break;
    input_pointer = input_pointer + 1;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  uVar1 = ~-(uint)(lVar2 != 0) & 0x80070057;
  if (Out_length != (longlong *)0x0) {
    if (lVar2 != 0) {
      *Out_length = MaxChars - lVar2;
      return uVar1;
    }
    *Out_length = 0;
  }
  return uVar1;
}

