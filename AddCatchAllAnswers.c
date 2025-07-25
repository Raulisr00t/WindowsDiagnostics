
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint AddCatchAllAnswers(undefined8 *param_1,OLECHAR *id,short *param_3)

{
  uint uVar1;
  HANDLE hHeap;
  wchar_t *path;
  undefined8 uVar2;
  BSTR bstrString;
  longlong lVar3;
  BSTR pOVar4;
  wchar_t *format_node;
  OLECHAR *pOVar5;
  BSTR pOVar6;
  longlong *local_res20;
  BSTR local_48;
  OLECHAR *local_40;
  
  pOVar4 = (BSTR)0x0;
  local_40 = (OLECHAR *)0x0;
  local_res20 = (longlong *)0x0;
  pOVar6 = (BSTR)0x0;
  local_48 = (BSTR)0x0;
  hHeap = GetProcessHeap();
  path = (wchar_t *)HeapAlloc(hHeap,0,2048);
  if (path == (wchar_t *)0x0) {
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Answers::AddCatchAllAnswer",0x125);
    return 0x8007000e;
  }
  format_node = L"/Packages/Interaction[@ID=\'%s\']";
  uVar2 = SafeFormatWString(path,1024,L"/Packages/Interaction[@ID=\'%s\']",id);
  uVar1 = (uint)uVar2;
  if ((int)uVar1 < 0) {
    uVar2 = 0x128;
  }
  else {
    uVar1 = GetSingleNode(path,(longlong *)*param_1,(ulonglong)format_node,&local_res20);
    if ((int)uVar1 < 0) {
      uVar2 = 299;
    }
    else {
      bstrString = pOVar4;
      if (uVar1 == 0) goto Free;
      uVar1 = CreateNode(param_1,L"Packages",(ulonglong)format_node,id,&local_res20);
      if ((int)uVar1 < 0) {
        uVar2 = 0x135;
      }
      else {
        bstrString = pOVar6;
        if ((param_3 == (short *)0x0) || (*param_3 == 0)) goto Free;
        uVar2 = 1024;
        uVar1 = SafeWcsCopy(path,1024,param_3);
        if ((int)uVar1 < 0) {
          uVar2 = 0x13f;
          pOVar4 = pOVar6;
        }
        else {
          uVar2 = InterestingFunction(path,uVar2,param_3);
          uVar1 = (uint)uVar2;
          if ((int)uVar1 < 0) {
            uVar2 = 0x142;
            pOVar4 = pOVar6;
          }
          else {
            bstrString = SysAllocString(L"Value");
            pOVar6 = pOVar4;
            pOVar5 = path;
            if (bstrString != (BSTR)0x0) {
              do {
                uVar1 = StrTok(pOVar5,L',',(longlong *)&local_40);
                if ((int)uVar1 < 0) {
                  uVar2 = 0x14b;
                  pOVar4 = bstrString;
                  goto LAB_1400338cc;
                }
                if (uVar1 == 1) {
                  pOVar6 = (BSTR)0x1;
                }
                lVar3 = -1;
                do {
                  lVar3 = lVar3 + 1;
                } while (pOVar5[lVar3] != L'\0');
                if (lVar3 != 0) {
                  if (pOVar4 != (BSTR)0x0) {
                    (**(code **)(*(longlong *)pOVar4 + 0x10))();
                    local_48 = (BSTR)0x0;
                  }
                  uVar1 = XmlCreateElement((longlong *)*param_1,bstrString,pOVar5,(OLECHAR *)0x0,
                                           (OLECHAR *)0x0,&local_48);
                  pOVar4 = local_48;
                  if ((int)uVar1 < 0) {
                    uVar2 = 0x15b;
                    pOVar4 = bstrString;
                    goto LAB_1400338cc;
                  }
                  uVar1 = (**(code **)(*local_res20 + 0xa8))(local_res20,local_48,0);
                  if ((int)uVar1 < 0) {
                    uVar2 = 0x15e;
                    pOVar4 = bstrString;
                    goto LAB_1400338cc;
                  }
                }
                pOVar5 = local_40;
              } while ((int)pOVar6 == 0);
              goto Free;
            }
            uVar1 = 0x8007000e;
            uVar2 = 0x147;
            pOVar4 = bstrString;
          }
        }
      }
    }
  }
LAB_1400338cc:
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Answers::AddCatchAllAnswer",uVar2);
  bstrString = pOVar4;
Free:
  hHeap = GetProcessHeap();
  HeapFree(hHeap,0,path);
  if (bstrString != (BSTR)0x0) {
    SysFreeString(bstrString);
  }
  if (local_res20 != (longlong *)0x0) {
    (**(code **)(*local_res20 + 0x10))();
  }
  return uVar1;
}

