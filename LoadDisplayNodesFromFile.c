
DWORD LoadDisplayNodesFromFile(undefined8 param_1,longlong *param_2)

{
  DWORD version;
  int isadmin;
  HANDLE hHeap;
  OLECHAR *memory;
  LPCWSTR bstrString;
  undefined8 uVar1;
  LPCWSTR variable;
  LPCWSTR Link;
  
  bstrString = (BSTR)0x0;
  variable = (LPCWSTR)0x0;
  hHeap = GetProcessHeap();
  memory = (OLECHAR *)HeapAlloc(hHeap,0,520);
  if (memory == (OLECHAR *)0x0) {
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Configuration::LoadDisplayNodesFromFile",0x3 ee)
    ;
    return 0x8007000e;
  }
  isadmin = TextFromSingleNode(L"cfg:PackageConfiguration/cfg:Execution/cfg:Name",param_2,&variab le)
  ;
  Link = variable;
  if (isadmin != 0) {
    uVar1 = 0x3f7;
    goto LAB_140036fee;
  }
  version = ExpandVariables(memory,260,variable);
  if ((int)version < 0) {
    uVar1 = 0x3fd;
    bstrString = Link;
    goto LAB_140037040;
  }
  if (Link != (LPCWSTR)0x0) {
    SysFreeString(Link);
    variable = (BSTR)0x0;
  }
  version = TryLoadResourceString(memory,&variable);
  Link = variable;
  if ((int)version < 0) {
    uVar1 = 0x402;
    goto LAB_140036ff7;
  }
  SetPackageName(variable);
  if (Link != (OLECHAR *)0x0) {
    SysFreeString(Link);
    variable = (OLECHAR *)0x0;
  }
  isadmin = TextFromSingleNode(L"cfg:PackageConfiguration/cfg:Execution/cfg:Description",param_2,
                               &variable);
  Link = variable;
  if (isadmin != 0) {
    uVar1 = 0x40e;
    goto LAB_140036fee;
  }
  version = ExpandVariables(memory,260,variable);
  if ((int)version < 0) {
    uVar1 = 0x414;
    bstrString = Link;
LAB_140037040:
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Configuration::LoadDisplayNodesFromFile",uVa r1)
    ;
  }
  else {
    if (Link != (LPCWSTR)0x0) {
      SysFreeString(Link);
      variable = (BSTR)0x0;
    }
    version = TryLoadResourceString(memory,&variable);
    Link = variable;
    if ((int)version < 0) {
      uVar1 = 0x419;
      goto LAB_140036ff7;
    }
    SetPackageDescription(variable);
    if (Link != (OLECHAR *)0x0) {
      SysFreeString(Link);
      variable = (OLECHAR *)0x0;
    }
    isadmin = TextFromSingleNode(L"cfg:PackageConfiguration/cfg:Index/cfg:PrivacyUrl",param_2,
                                 &variable);
    Link = variable;
    if ((isadmin != 0) ||
       ((isadmin = _wcsnicmp(variable,L"http://",7), isadmin != 0 &&
        (isadmin = _wcsnicmp(Link,L"https://",8), isadmin != 0)))) {
      version = 0x80070057;
      uVar1 = 0x428;
      bstrString = Link;
      goto LAB_140037040;
    }
    SetPrivacyLink(Link);
    if (Link != (wchar_t *)0x0) {
      SysFreeString(Link);
      variable = (BSTR)0x0;
    }
    isadmin = TextFromSingleNode(L"cfg:PackageConfiguration/cfg:Index/cfg:PublisherName",param_2,
                                 &variable);
    Link = variable;
    if (isadmin == 0) {
      Packages_SetPublisher(variable);
      if (Link != (OLECHAR *)0x0) {
        SysFreeString(Link);
        variable = (OLECHAR *)0x0;
      }
      isadmin = TextFromSingleNode(L"cfg:PackageConfiguration/cfg:Index/cfg:RequiresAdminPrivileges "
                                   ,param_2,&variable);
      Link = variable;
      if (isadmin != 0) {
        uVar1 = 0x440;
        goto LAB_140036fee;
      }
      isadmin = _wcsicmp(variable,L"true");
      SetElevation((uint)(isadmin == 0));
      if (Link != (wchar_t *)0x0) {
        SysFreeString(Link);
        variable = (wchar_t *)0x0;
      }
      version = TextFromSingleNode(L"cfg:PackageConfiguration/cfg:Index/cfg:Version",param_2,
                                   &variable);
      Link = variable;
      if ((int)version < 0) {
        uVar1 = 0x449;
      }
      else {
        if ((version == 0) && (SetVersion(variable), Link != (OLECHAR *)0x0)) {
          SysFreeString(Link);
          variable = (OLECHAR *)0x0;
        }
        version = TextFromSingleNode(L"cfg:PackageConfiguration/cfg:Index/cfg:Id",param_2,&variab le)
        ;
        Link = variable;
        if ((int)version < 0) {
          uVar1 = 0x453;
        }
        else {
          if ((version == 0) && (Packages_SetID(variable), Link != (OLECHAR *)0x0)) {
            SysFreeString(Link);
            variable = (OLECHAR *)0x0;
          }
          version = TextFromSingleNode(L"cfg:PackageConfiguration/cfg:Execution/cfg:Icon",param_2 ,
                                       &variable);
          Link = variable;
          if ((int)version < 0) {
            uVar1 = 0x45d;
          }
          else {
            if (version == 0) {
              version = ExpandVariables(memory,260,variable);
              if ((int)version < 0) {
                uVar1 = 0x463;
                bstrString = Link;
                goto LAB_140037040;
              }
              if (Link != (LPCWSTR)0x0) {
                SysFreeString(Link);
                variable = (BSTR)0x0;
                Link = bstrString;
              }
              SetIcon(memory);
            }
            if (Link != (BSTR)0x0) {
              SysFreeString(Link);
              variable = (BSTR)0x0;
            }
            version = TextFromSingleNode(L"cfg:PackageConfiguration/cfg:Index/cfg:Category",param _2,
                                         &variable);
            Link = variable;
            if (-1 < (int)version) {
              if (version == 0) {
                version = ExpandVariables(memory,260,variable);
                if ((int)version < 0) {
                  uVar1 = 0x477;
                  bstrString = Link;
                  goto LAB_140037040;
                }
                if (Link != (LPCWSTR)0x0) {
                  SysFreeString(Link);
                  variable = (BSTR)0x0;
                }
                version = TryLoadResourceString(memory,&variable);
                Link = variable;
                if ((int)version < 0) {
                  uVar1 = 0x47c;
                  goto LAB_140036ff7;
                }
                SetCategory(variable);
              }
              if (Link == (BSTR)0x0) goto LAB_140037471;
              SysFreeString(Link);
              goto LAB_14003745d;
            }
            uVar1 = 0x470;
          }
        }
      }
    }
    else {
      uVar1 = 0x434;
LAB_140036fee:
      version = 0x80070057;
    }
LAB_140036ff7:
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Configuration::LoadDisplayNodesFromFile",uVa r1)
    ;
    bstrString = variable;
  }
LAB_14003745d:
  if (bstrString != (BSTR)0x0) {
    SysFreeString(bstrString);
  }
LAB_140037471:
  hHeap = GetProcessHeap();
  HeapFree(hHeap,0,memory);
  return version;
}

