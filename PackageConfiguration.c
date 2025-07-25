
undefined8 PackageConfiguration(longlong param_1,undefined8 *param_2)

{
  LPVOID lpMem;
  HANDLE hHeap;
  
  lpMem = *(LPVOID *)(param_1 + 0xa8);
  if (lpMem != (LPVOID)0x0) {
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,lpMem);
    *(undefined8 *)(param_1 + 0xa8) = 0;
  }
  *(undefined8 *)(param_1 + 0xa8) = param_2[10];
  param_2[10] = 0;
  Packages_SetPath((OLECHAR *)param_2[2]);
  SetPackageName((OLECHAR *)*param_2);
  SetPackageDescription((OLECHAR *)param_2[5]);
  SetElevation(*(undefined4 *)((longlong)param_2 + 0x4c));
  Packages_SetPublisher((OLECHAR *)param_2[4]);
  SetPrivacyLink((OLECHAR *)param_2[1]);
  Setkeywords((OLECHAR *)param_2[8]);
  SetCategory((OLECHAR *)param_2[7]);
  if ((OLECHAR *)param_2[3] != (OLECHAR *)0x0) {
    SetIcon((OLECHAR *)param_2[3]);
  }
  return 0;
}

