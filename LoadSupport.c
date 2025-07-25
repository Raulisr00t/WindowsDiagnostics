
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint LoadSupport(longlong conf_context,longlong *param_2)

{
  undefined8 *out_ptr;
  LPVOID lpMem;
  BSTR pOVar1;
  uint ID;
  HANDLE hHeap;
  undefined8 uVar2;
  BSTR local_res8;
  longlong *local_res18 [2];
  
  local_res8 = (BSTR)0x0;
  local_res18[0] = (longlong *)0x0;
  *(undefined4 *)(conf_context + 0x108) = 1;
  ID = TextFromSingleNode(L"/SupportPackageConfiguration/SupportProvider",param_2,&local_res8);
  if ((int)ID < 0) {
    uVar2 = 0x51f;
  }
  else {
    if (ID == 0) {
      out_ptr = (undefined8 *)(conf_context + 0x60);
      lpMem = (LPVOID)*out_ptr;
      if (lpMem != (LPVOID)0x0) {
        hHeap = GetProcessHeap();
        HeapFree(hHeap,0,lpMem);
        *out_ptr = 0;
      }
      ID = CopyWideStringToHeap(out_ptr,local_res8);
      if ((int)ID < 0) {
        uVar2 = 0x524;
        goto LAB_140037f80;
      }
      if (local_res8 != (BSTR)0x0) {
        SysFreeString(local_res8);
        local_res8 = (BSTR)0x0;
      }
    }
    ID = TextFromSingleNode(L"/SupportPackageConfiguration/CustomerID",param_2,&local_res8);
    if ((int)ID < 0) {
      uVar2 = 0x52d;
    }
    else {
      if (ID == 0) {
        ID = CopyWideStringToHeap((undefined8 *)(conf_context + 0x70),local_res8);
        if ((int)ID < 0) {
          uVar2 = 0x530;
          goto LAB_140037f80;
        }
        if (local_res8 != (BSTR)0x0) {
          SysFreeString(local_res8);
          local_res8 = (BSTR)0x0;
        }
      }
      ID = (**(code **)(*param_2 + 0x128))
                     (param_2,L"/SupportPackageConfiguration/Disconnected",local_res18);
      if ((int)ID < 0) {
        uVar2 = 0x539;
      }
      else {
        if (ID == 0) {
          *(undefined4 *)(conf_context + 0x30) = 1;
        }
        if (local_res18[0] != (longlong *)0x0) {
          (**(code **)(*local_res18[0] + 0x10))();
          local_res18[0] = (longlong *)0x0;
        }
        ID = (**(code **)(*param_2 + 0x128))
                       (param_2,L"/SupportPackageConfiguration/OAS",local_res18);
        if ((int)ID < 0) {
          uVar2 = 0x544;
        }
        else {
          if (ID == 0) {
            *(undefined4 *)(conf_context + 0x54) = 1;
          }
          if (local_res18[0] != (longlong *)0x0) {
            (**(code **)(*local_res18[0] + 0x10))();
            local_res18[0] = (longlong *)0x0;
          }
          ID = (**(code **)(*param_2 + 0x128))
                         (param_2,L"/SupportPackageConfiguration/Answers",local_res18);
          if (-1 < (int)ID) {
            if (ID == 0) {
              ID = (**(code **)(*local_res18[0] + 0x110))(local_res18[0],&local_res8);
              pOVar1 = local_res8;
              if ((int)ID < 0) {
                uVar2 = 0x552;
                goto LAB_140037f80;
              }
              local_res8 = (BSTR)0x0;
              *(BSTR *)(conf_context + 0xb0) = pOVar1;
            }
            ID = 0;
            goto Free;
          }
          uVar2 = 0x54f;
        }
      }
    }
  }
LAB_140037f80:
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Configuration::LoadSupport",uVar2);
Free:
  if (local_res18[0] != (longlong *)0x0) {
    (**(code **)(*local_res18[0] + 0x10))();
    local_res18[0] = (longlong *)0x0;
  }
  if (local_res8 != (BSTR)0x0) {
    SysFreeString(local_res8);
  }
  return ID;
}

