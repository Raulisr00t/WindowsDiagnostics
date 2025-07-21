
undefined8
FormatWStringInternal
          (wchar_t *buffer,longlong param_2,undefined8 param_3,wchar_t *param_4,va_list param_5)

{
  ulonglong _Count;
  int iVar1;
  undefined8 uVar2;
  
  _Count = param_2 - 1;
  uVar2 = 0;
  iVar1 = _vsnwprintf(buffer,_Count,param_4,param_5);
  if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
                    /* NULL Termination */
    buffer[_Count] = L'\0';
    uVar2 = 0x8007007a;
  }
  else if ((longlong)iVar1 == _Count) {
    buffer[_Count] = L'\0';
  }
  return uVar2;
}

