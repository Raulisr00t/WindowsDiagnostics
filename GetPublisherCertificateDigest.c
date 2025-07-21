
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GetPublisherCertificateDigest(undefined8 param_1,longlong *param_2,longlong param_3)

{
  LPVOID lpMem;
  int iVar1;
  HANDLE pvVar2;
  LPVOID pvVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  SAFEARRAY *local_res8;
  void *local_res10;
  
  local_res8 = (SAFEARRAY *)0x0;
  local_res10 = (void *)0x0;
  iVar1 = (**(code **)(*param_2 + 0x60))(param_2,&local_res8);
  if (iVar1 < 0) {
    uVar6 = 0x1bc;
  }
  else {
    if (local_res8 == (SAFEARRAY *)0x0) goto LAB_140039e97;
    iVar1 = SafeArrayAccessData(local_res8,&local_res10);
    if (iVar1 < 0) {
      uVar6 = 0x1c0;
    }
    else {
      lVar5 = 0x14;
      if (local_res8->rgsabound[0].cElements == 0x14) {
        pvVar2 = GetProcessHeap();
        pvVar3 = HeapAlloc(pvVar2,0,0x14);
        if (pvVar3 != (LPVOID)0x0) {
          lVar4 = 0;
          do {
            *(undefined1 *)(lVar4 + (longlong)pvVar3) =
                 *(undefined1 *)(lVar4 + (longlong)local_res10);
            lVar4 = lVar4 + 1;
            lVar5 = lVar5 + -1;
          } while (lVar5 != 0);
          lpMem = *(LPVOID *)(param_3 + 0x50);
          if (lpMem != (LPVOID)0x0) {
            pvVar2 = GetProcessHeap();
            HeapFree(pvVar2,0,lpMem);
          }
          *(LPVOID *)(param_3 + 0x50) = pvVar3;
          goto LAB_140039e97;
        }
        iVar1 = -0x7ff8fff2;
        uVar6 = 0x1d1;
      }
      else {
        iVar1 = -0x7ff8ffa9;
        uVar6 = 0x1cd;
      }
    }
  }
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Provider::GetPublisherCertificateDigest",uVar6 );
LAB_140039e97:
  if (local_res10 != (void *)0x0) {
    SafeArrayUnaccessData(local_res8);
  }
  if (local_res8 != (SAFEARRAY *)0x0) {
    SafeArrayDestroy(local_res8);
  }
  return iVar1;
}

