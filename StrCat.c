
uint StrCat(short *param_1,short *param_2,undefined8 param_3,undefined8 *param_4)

{
  uint uVar1;
  HANDLE pvVar2;
  wchar_t *path;
  undefined8 uVar3;
  ulonglong size;
  ulonglong buffer_size;
  longlong local_res8;
  longlong local_28 [2];
  
  local_28[0] = 0;
  local_res8 = 0;
  if (param_1 == (short *)0x0) {
    uVar3 = 0x206;
  }
  else if (param_2 == (short *)0x0) {
    uVar3 = 0x207;
  }
  else {
    if (param_4 != (undefined8 *)0x0) {
      size = 0x800;
      uVar1 = Calculate_buffer(param_1,0x800,local_28);
      if ((int)uVar1 < 0) {
        uVar3 = 0x20b;
      }
      else {
        uVar1 = Calculate_buffer(param_2,size,&local_res8);
        if ((int)uVar1 < 0) {
          uVar3 = 0x20e;
        }
        else {
          buffer_size = local_28[0] + 2 + local_res8;
          if (size < buffer_size) {
            uVar1 = 0x8007006f;
            uVar3 = 0x214;
          }
          else {
            pvVar2 = GetProcessHeap();
            path = (wchar_t *)HeapAlloc(pvVar2,0,buffer_size * 2);
            if (path != (wchar_t *)0x0) {
              uVar3 = SafeFormatWString(path,buffer_size,L"%s%c%s",param_1);
              uVar1 = (uint)uVar3;
              if ((int)uVar1 < 0) {
                PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","DwzStrCat",0x220);
                pvVar2 = GetProcessHeap();
                HeapFree(pvVar2,0,path);
                return uVar1;
              }
              *param_4 = path;
              return uVar1;
            }
            uVar1 = 0x8007000e;
            uVar3 = 0x218;
          }
        }
      }
      goto LAB_140020969;
    }
    uVar3 = 0x208;
  }
  uVar1 = 0x80070057;
LAB_140020969:
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","DwzStrCat",uVar3);
  return uVar1;
}

