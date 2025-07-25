
ulonglong LoadFromProvider(longlong param_1,OLECHAR *param_2)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  HANDLE pvVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  BSTR local_68;
  BSTR local_60;
  BSTR string;
  BSTR local_50;
  BSTR local_48;
  BSTR local_40;
  BSTR local_38;
  BSTR local_30;
  LPVOID local_28;
  LPVOID local_18;
  
  memset(&local_68,0,88);
  DAT_14007f498 = 0x199;
  Packages_SetID(param_2);
  puVar3 = (undefined8 *)0x0;
  puVar2 = *(undefined8 **)(param_1 + 0xb8);
  if (*(undefined8 **)(param_1 + 0xb8) == (undefined8 *)0x0) {
    puVar2 = (undefined8 *)MemoryAllocate(24);
    if (puVar2 != (undefined8 *)0x0) {
      puVar2[2] = 0;
      *(undefined4 *)(puVar2 + 1) = 0;
      *puVar2 = 0;
      puVar3 = puVar2;
    }
    *(undefined8 **)(param_1 + 0xb8) = puVar3;
    puVar2 = puVar3;
    if (puVar3 != (undefined8 *)0x0) goto LAB_140037600;
    uVar6 = 0x8007000e;
    uVar7 = 0x4ac;
  }
  else {
LAB_140037600:
    uVar4 = GetMetaDataFromProvider(puVar2,param_2,(longlong)&local_68);
    uVar6 = uVar4 & 0xffffffff;
    if ((int)uVar4 < 0) {
      uVar7 = 0x4b3;
    }
    else {
      if ((int)uVar4 == 1) goto CleanUp;
      uVar4 = PackageConfiguration(param_1,&local_68);
      uVar6 = uVar4 & 0xffffffff;
      if (-1 < (int)uVar4) {
        *(undefined4 *)(param_1 + 4) = 1;
        iVar1 = _wcsnicmp(string,L"http://",7);
        if ((iVar1 == 0) || (iVar1 = _wcsnicmp(string,L"https://",8), iVar1 == 0)) {
          *(undefined4 *)(param_1 + 0x108) = 9;
        }
        else {
          *(undefined4 *)(param_1 + 0x108) = 8;
        }
        goto CleanUp;
      }
      uVar7 = 0x4bc;
    }
  }
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Configuration::LoadFromProvider",uVar7);
CleanUp:
  if (local_40 != (BSTR)0x0) {
    SysFreeString(local_40);
    local_40 = (BSTR)0x0;
  }
  if (local_68 != (BSTR)0x0) {
    SysFreeString(local_68);
    local_68 = (BSTR)0x0;
  }
  if (local_50 != (BSTR)0x0) {
    SysFreeString(local_50);
    local_50 = (BSTR)0x0;
  }
  if (local_60 != (BSTR)0x0) {
    SysFreeString(local_60);
    local_60 = (BSTR)0x0;
  }
  if (local_48 != (BSTR)0x0) {
    SysFreeString(local_48);
    local_48 = (BSTR)0x0;
  }
  if (string != (BSTR)0x0) {
    SysFreeString(string);
    string = (BSTR)0x0;
  }
  if (local_38 != (BSTR)0x0) {
    SysFreeString(local_38);
    local_38 = (BSTR)0x0;
  }
  if (local_30 != (BSTR)0x0) {
    SysFreeString(local_30);
    local_30 = (BSTR)0x0;
  }
  if (local_18 != (LPVOID)0x0) {
    pvVar5 = GetProcessHeap();
    HeapFree(pvVar5,0,local_18);
    local_18 = (LPVOID)0x0;
  }
  if (local_28 != (LPVOID)0x0) {
    pvVar5 = GetProcessHeap();
    HeapFree(pvVar5,0,local_28);
  }
  return uVar6;
}

