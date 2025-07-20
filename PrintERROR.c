
void PrintERROR(undefined4 Level,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  HRESULT result;
  undefined8 local_res18;
  undefined8 local_res20;
  undefined1 auStack_448 [48];
  char format [1024];
  ulonglong local_18;
  
                    /* Stack Guard SetUp */
  local_18 = DAT_14007f440 ^ (ulonglong)auStack_448;
  local_res18 = param_3;
  local_res20 = param_4;
  result = FormatStr(format,param_2,(char *)param_2,(va_list)&local_res18);
  if (-1 < result) {
                    /* Logging ... */
    DbgPrintEx(0x81,Level,&DAT_14006d758,format);
  }
  ProtectStack(local_18 ^ (ulonglong)auStack_448);
  return;
}

