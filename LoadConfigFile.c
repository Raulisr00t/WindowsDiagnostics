
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

DWORD LoadConfigFile(longlong Conf_Context,LPCWSTR file,undefined4 *param_3)

{
  longlong *plVar1;
  DWORD result;
  int iVar2;
  BSTR pOVar3;
  HANDLE hHeap;
  LPCWSTR FILE;
  longlong *plVar4;
  BSTR bstrString;
  undefined8 uVar5;
  BSTR _Str2;
  BSTR lpMem;
  BSTR local_res18;
  longlong *local_res20;
  BSTR local_68;
  BSTR filename;
  BSTR FILE_NAME;
  longlong *local_50;
  longlong local_48 [2];
  
  pOVar3 = (BSTR)0x0;
  filename = (BSTR)0x0;
  FILE_NAME = (BSTR)0x0;
  local_res18 = (BSTR)0x0;
  local_50 = (longlong *)0x0;
  local_res20 = (longlong *)0x0;
  bstrString = (BSTR)0x0;
  local_48[0] = 0;
  DAT_14007f498 = 0x191;
  local_68 = (BSTR)0x0;
  *param_3 = 0;
  hHeap = GetProcessHeap();
  FILE = (LPCWSTR)HeapAlloc(hHeap,0,520);
  if (FILE == (LPCWSTR)0x0) {
    result = 0x8007000e;
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Configuration::LoadConfigFile",0x357);
    local_68 = pOVar3;
    bstrString = pOVar3;
    lpMem = pOVar3;
    goto LAB_140036e96;
  }
  result = CononicalizeFilePath(file,&filename);
  lpMem = filename;
  if ((int)result < 0) {
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Configuration::LoadConfigFile",0x35a);
    local_68 = (BSTR)0x0;
    lpMem = filename;
    goto LAB_140036e96;
  }
  Packages_SetPath(filename);
  result = XmlLoad(lpMem,&local_50);
  plVar1 = local_50;
  if ((int)result < 0) {
    uVar5 = 0x35f;
    bstrString = pOVar3;
LAB_140036e66:
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Configuration::LoadConfigFile",uVar5);
  }
  else {
    result = (**(code **)(*local_50 + 0x128))(local_50,L"SupportPackageConfiguration",&local_res20 );
    if ((int)result < 0) {
      uVar5 = 0x362;
      goto LAB_140036e66;
    }
    if (result != 0) {
      if (local_res20 != (longlong *)0x0) {
        (**(code **)(*local_res20 + 0x10))();
        local_res20 = (longlong *)0x0;
      }
      result = ExpandVariables(FILE,260,L"%windir%\\diagnostics\\index\\");
      if ((int)result < 0) {
        uVar5 = 0x370;
      }
      else {
        result = CononicalizeFilePath(FILE,&FILE_NAME);
        if ((int)result < 0) {
          PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Configuration::LoadConfigFile",0x373);
          local_68 = FILE_NAME;
          goto LAB_140036e7e;
        }
        local_68 = FILE_NAME;
        _Str2 = FILE_NAME;
        result = Calculate_buffer(FILE_NAME,260,local_48);
        if ((int)result < 0) {
          uVar5 = 0x379;
        }
        else {
          iVar2 = _wcsnicmp(file,_Str2,local_48[0] - 1);
          *(uint *)(Conf_Context + 4) = (uint)(iVar2 == 0);
          if (iVar2 == 0) {
            if (lpMem != (OLECHAR *)0x0) {
              hHeap = GetProcessHeap();
              HeapFree(hHeap,0,lpMem);
              lpMem = (BSTR)0x0;
            }
            *(undefined4 *)(Conf_Context + 264) = 7;
            plVar4 = plVar1;
            result = SelectNamespacehttp(plVar1);
            if ((int)result < 0) {
              uVar5 = 0x387;
            }
            else {
              result = LoadDisplayNodesFromFile(plVar4,plVar1);
              if ((int)result < 0) {
                uVar5 = 0x38a;
              }
              else {
                result = (**(code **)(*plVar1 + 0x128))
                                   (plVar1,
                                    L"cfg:PackageConfiguration/cfg:Execution/cfg:Disconnected",
                                    &local_res20);
                if (-1 < (int)result) {
                  if (result == 0) {
                    *(undefined4 *)(Conf_Context + 0x20) = 1;
                  }
                  if (local_res20 != (longlong *)0x0) {
                    (**(code **)(*local_res20 + 0x10))();
                    local_res20 = (longlong *)0x0;
                  }
                  result = TextFromSingleNode(L"cfg:PackageConfiguration/cfg:Execution/cfg:Icon",
                                              plVar1,&local_res18);
                  bstrString = local_res18;
                  if ((int)result < 0) {
                    uVar5 = 0x39b;
                  }
                  else {
                    if (result == 0) {
                      result = ExpandVariables(FILE,260,local_res18);
                      if ((int)result < 0) {
                        uVar5 = 0x3a1;
                        goto LAB_140036e66;
                      }
                      if (bstrString != (LPCWSTR)0x0) {
                        SysFreeString(bstrString);
                        bstrString = (BSTR)0x0;
                        local_res18 = (BSTR)0x0;
                      }
                      SetIcon(FILE);
                    }
                    if (bstrString != (BSTR)0x0) {
                      SysFreeString(bstrString);
                      local_res18 = (BSTR)0x0;
                    }
                    result = TextFromSingleNode(L"cfg:PackageConfiguration/cfg:Index/cfg:Category" ,
                                                plVar1,&local_res18);
                    bstrString = local_res18;
                    if (-1 < (int)result) {
                      if (result == 0) {
                        result = ExpandVariables(FILE,260,local_res18);
                        if ((int)result < 0) {
                          uVar5 = 0x3b5;
                          goto LAB_140036e66;
                        }
                        if (bstrString != (LPCWSTR)0x0) {
                          SysFreeString(bstrString);
                          local_res18 = (BSTR)0x0;
                        }
                        result = TryLoadResourceString(FILE,&local_res18);
                        bstrString = local_res18;
                        if ((int)result < 0) {
                          uVar5 = 0x3ba;
                          goto LAB_140036d24;
                        }
                        SetCategory(local_res18);
                      }
                      if (bstrString != (BSTR)0x0) {
                        SysFreeString(bstrString);
                        bstrString = (BSTR)0x0;
                      }
                      result = LoadKeywordsFromFile
                                         (plVar1,L"cfg:PackageConfiguration/cfg:Index/cfg:Keyword" );
                      if (-1 < (int)result) goto LAB_140036e7e;
                      uVar5 = 0x3c2;
                      goto LAB_140036e66;
                    }
                    uVar5 = 0x3ae;
                  }
LAB_140036d24:
                  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Configuration::LoadConfigFile" ,
                             uVar5);
                  bstrString = local_res18;
                  goto LAB_140036e7e;
                }
                uVar5 = 0x390;
              }
            }
          }
          else {
            result = 0x80070005;
            uVar5 = 0x37f;
            bstrString = pOVar3;
          }
        }
      }
      goto LAB_140036e66;
    }
    result = LoadSupport(Conf_Context,plVar1);
    if ((int)result < 0) {
      uVar5 = 0x365;
      goto LAB_140036e66;
    }
    *param_3 = 1;
    bstrString = pOVar3;
  }
LAB_140036e7e:
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 0x10))(plVar1);
  }
LAB_140036e96:
  if (local_res20 != (longlong *)0x0) {
    (**(code **)(*local_res20 + 0x10))();
    local_res20 = (longlong *)0x0;
  }
  if (bstrString != (BSTR)0x0) {
    SysFreeString(bstrString);
  }
  if (lpMem != (BSTR)0x0) {
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,lpMem);
  }
  if (FILE != (LPCWSTR)0x0) {
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,FILE);
  }
  if (local_68 != (BSTR)0x0) {
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,local_68);
  }
  return result;
}

