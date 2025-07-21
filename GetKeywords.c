
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint GetKeywords(ulonglong param_1,longlong *param_2,longlong param_3)

{
  undefined8 *out_ptr;
  uint uVar1;
  uint uVar2;
  BSTR *pv;
  undefined8 uVar3;
  ulonglong local_res8;
  BSTR local_res10;
  SAFEARRAY *local_res20;
  
  local_res8 = param_1 & 0xffffffff00000000;
  local_res10 = (BSTR)0x0;
  local_res20 = (SAFEARRAY *)0x0;
  uVar1 = (**(code **)(*param_2 + 0x78))(param_2,&local_res20);
  if ((int)uVar1 < 0) {
    uVar3 = 0x20c;
  }
  else {
    if (local_res20 == (SAFEARRAY *)0x0) {
      *(undefined8 *)(param_3 + 0x40) = 0;
      goto LAB_14003954e;
    }
    if (local_res20->cDims < 2) {
      uVar2 = 0;
      while (uVar2 < local_res20->rgsabound[0].cElements) {
        pv = &local_res10;
        uVar1 = SafeArrayGetElement(local_res20,(LONG *)&local_res8,pv);
        if ((int)uVar1 < 0) {
          uVar3 = 0x21a;
          goto LAB_14003953b;
        }
        if (local_res10 == (BSTR)0x0) {
          uVar1 = 0x8000ffff;
          uVar3 = 0x21b;
          goto LAB_14003953b;
        }
        out_ptr = (undefined8 *)(param_3 + 0x40);
        if ((int)local_res8 == 0) {
          uVar1 = CopyWideStringToHeap(out_ptr,local_res10);
          if ((int)uVar1 < 0) {
            uVar3 = 0x22d;
            goto LAB_14003953b;
          }
        }
        else {
          uVar1 = StrCat((short *)*out_ptr,local_res10,pv,out_ptr);
          if ((int)uVar1 < 0) {
            uVar3 = 0x227;
            goto LAB_14003953b;
          }
        }
        if (local_res10 != (BSTR)0x0) {
          SysFreeString(local_res10);
          local_res10 = (BSTR)0x0;
        }
        uVar2 = (int)local_res8 + 1;
        local_res8 = CONCAT44(local_res8._4_4_,uVar2);
      }
      goto LAB_14003954e;
    }
    uVar1 = 0x80070057;
    uVar3 = 0x215;
  }
LAB_14003953b:
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Provider::GetKeywords",uVar3);
LAB_14003954e:
  if (local_res10 != (BSTR)0x0) {
    SysFreeString(local_res10);
  }
  return uVar1;
}

