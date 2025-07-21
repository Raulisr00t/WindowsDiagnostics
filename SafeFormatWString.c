
undefined8
SafeFormatWString(wchar_t *path,longlong buffer_size,undefined8 format,undefined8 base_str)

{
  undefined8 uVar1;
  undefined8 local_res20;
  
  if (buffer_size - 1U < 0x7fffffff) {
    local_res20 = base_str;
    uVar1 = FormatWStringInternal(path,buffer_size,format,(wchar_t *)format,(va_list)&local_res20) ;
  }
  else {
    uVar1 = 0x80070057;
    if (buffer_size != 0) {
      *path = L'\0';
    }
  }
  return uVar1;
}

