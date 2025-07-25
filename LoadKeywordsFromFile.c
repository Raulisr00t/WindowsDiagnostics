
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

DWORD LoadKeywordsFromFile(longlong *param_1,OLECHAR *node)

{
  uint uVar1;
  DWORD DVar2;
  HANDLE hHeap;
  OLECHAR *path;
  BSTR bstrString;
  BSTR bstrString_00;
  BSTR pOVar3;
  undefined8 uVar4;
  uint uVar5;
  uint local_res18 [2];
  BSTR local_res20;
  longlong *local_48;
  longlong *local_40;
  
  bstrString_00 = (BSTR)0x0;
  local_res20 = (BSTR)0x0;
  pOVar3 = (BSTR)0x0;
  local_48 = (longlong *)0x0;
  local_40 = (longlong *)0x0;
  local_res18[0] = 0;
  hHeap = GetProcessHeap();
  path = (OLECHAR *)HeapAlloc(hHeap,0,2048);
  if (path == (OLECHAR *)0x0) {
    uVar4 = 0x5e8;
    bstrString = bstrString_00;
LAB_14003784b:
    DVar2 = 0x8007000e;
  }
  else {
    bstrString = SysAllocString(node);
    if (bstrString == (BSTR)0x0) {
      uVar4 = 0x5eb;
      goto LAB_14003784b;
    }
    DVar2 = (**(code **)(*param_1 + 288))(param_1,bstrString,&local_40);
    if ((int)DVar2 < 0) {
      uVar4 = 0x5f1;
      bstrString_00 = pOVar3;
    }
    else {
      DVar2 = (**(code **)(*local_40 + 0x40))(local_40,local_res18);
      uVar1 = local_res18[0];
      if ((int)DVar2 < 0) {
        uVar4 = 0x5f4;
        bstrString_00 = pOVar3;
      }
      else {
        if (local_res18[0] == 0) {
LAB_140037b67:
          if (local_40 != (longlong *)0x0) {
            (**(code **)(*local_40 + 0x10))();
            local_40 = (longlong *)0x0;
          }
          goto CleanUp;
        }
        if ((int)local_res18[0] < 0) {
          DVar2 = 0x80070216;
          uVar4 = 0x5f8;
        }
        else {
          if (local_48 != (longlong *)0x0) {
            (**(code **)(*local_48 + 0x10))();
            local_48 = (longlong *)0x0;
          }
          if (local_res20 != (BSTR)0x0) {
            SysFreeString(local_res20);
            local_res20 = (BSTR)0x0;
          }
          DVar2 = (**(code **)(*local_40 + 0x48))(local_40,&local_48);
          if ((int)DVar2 < 0) {
            uVar4 = 0x601;
            bstrString_00 = pOVar3;
          }
          else {
            DVar2 = (**(code **)(*local_48 + 0xd0))(local_48,&local_res20);
            if ((int)DVar2 < 0) {
              uVar4 = 0x604;
              bstrString_00 = pOVar3;
            }
            else {
              DVar2 = ExpandVariables(path,260,local_res20);
              if ((int)DVar2 < 0) {
                uVar4 = 0x60a;
                bstrString_00 = pOVar3;
              }
              else {
                if (local_res20 != (BSTR)0x0) {
                  SysFreeString(local_res20);
                  local_res20 = (BSTR)0x0;
                }
                DVar2 = TryLoadResourceString(path,&local_res20);
                if (-1 < (int)DVar2) {
                  bstrString_00 = SysAllocString(local_res20);
                  for (uVar5 = 1; uVar5 < uVar1; uVar5 = uVar5 + 1) {
                    if (local_48 != (longlong *)0x0) {
                      (**(code **)(*local_48 + 0x10))();
                      local_48 = (longlong *)0x0;
                    }
                    if (local_res20 != (BSTR)0x0) {
                      SysFreeString(local_res20);
                      local_res20 = (BSTR)0x0;
                    }
                    DVar2 = (**(code **)(*local_40 + 0x48))(local_40,&local_48);
                    if ((int)DVar2 < 0) {
                      uVar4 = 0x618;
                      goto LAB_140037856;
                    }
                    DVar2 = (**(code **)(*local_48 + 0xd0))(local_48,&local_res20);
                    if ((int)DVar2 < 0) {
                      uVar4 = 0x61b;
                      goto LAB_140037856;
                    }
                    DVar2 = ExpandVariables(path,260,local_res20);
                    if ((int)DVar2 < 0) {
                      uVar4 = 0x621;
                      goto LAB_140037856;
                    }
                    if (local_res20 != (BSTR)0x0) {
                      SysFreeString(local_res20);
                      local_res20 = (BSTR)0x0;
                    }
                    DVar2 = TryLoadResourceString(path,&local_res20);
                    if ((int)DVar2 < 0) {
                      uVar4 = 0x626;
                      goto LAB_140037856;
                    }
                    uVar4 = SafeFormatWString(path,1024,L"%s%c%s",bstrString_00);
                    DVar2 = (DWORD)uVar4;
                    if ((int)DVar2 < 0) {
                      uVar4 = 0x62f;
                      goto LAB_140037856;
                    }
                    if (bstrString_00 != (OLECHAR *)0x0) {
                      SysFreeString(bstrString_00);
                    }
                    bstrString_00 = SysAllocString(path);
                  }
                  if (local_48 != (longlong *)0x0) {
                    (**(code **)(*local_48 + 0x10))();
                    local_48 = (longlong *)0x0;
                  }
                  if (local_res20 != (BSTR)0x0) {
                    SysFreeString(local_res20);
                    local_res20 = (BSTR)0x0;
                  }
                  Setkeywords(bstrString_00);
                  goto LAB_140037b67;
                }
                uVar4 = 0x60f;
                bstrString_00 = pOVar3;
              }
            }
          }
        }
      }
    }
  }
LAB_140037856:
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Configuration::LoadKeywordsFromFile",uVar4);
CleanUp:
  if (local_48 != (longlong *)0x0) {
    (**(code **)(*local_48 + 0x10))();
    local_48 = (longlong *)0x0;
  }
  if (local_40 != (longlong *)0x0) {
    (**(code **)(*local_40 + 0x10))();
    local_40 = (longlong *)0x0;
  }
  if (local_res20 != (BSTR)0x0) {
    SysFreeString(local_res20);
    local_res20 = (BSTR)0x0;
  }
  if (bstrString != (BSTR)0x0) {
    SysFreeString(bstrString);
  }
  if (bstrString_00 != (BSTR)0x0) {
    SysFreeString(bstrString_00);
  }
  if (path != (OLECHAR *)0x0) {
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,path);
  }
  return DVar2;
}

