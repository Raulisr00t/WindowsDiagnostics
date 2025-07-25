
DWORD ArgumentParser(ulonglong userparam)

{
  undefined8 *out_ptr;
  LPVOID lpMem;
  undefined4 *conf_context;
  DWORD result;
  int result1;
  long lVar1;
  HANDLE hHeap;
  LPWSTR CommandLine;
  LPWSTR *argv;
  ulonglong uVar2;
  LPCWSTR file_name;
  OLECHAR *out_ptr_00;
  LPCWSTR pWVar3;
  undefined8 uVar4;
  int iVar5;
  LPCWSTR bytes;
  LPWSTR *file;
  ulonglong argc;
  uint local_res10;
  int local_res18;
  undefined4 local_res20 [2];
  LPCWSTR filename;
  LPWSTR FilePart;
  longlong OutInstance;
  LPCWSTR local_60;
  LPWSTR *arg;
  LPWSTR memory;
  
  conf_context = maybe_everything;
  pWVar3 = (LPCWSTR)0x0;
  filename = (LPCWSTR)0x0;
  FilePart = (LPWSTR)0x0;
  argc = userparam & 0xffffffff00000000;
  bytes = (LPCWSTR)0x0;
  local_res10 = 0;
  local_res20[0] = 0;
  OutInstance = 0;
  hHeap = GetProcessHeap();
  memory = (LPWSTR)HeapAlloc(hHeap,0,520);
  if (memory == (LPWSTR)0x0) {
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Configuration::ParseArgs",0x199);
    return 0x8007000e;
  }
  CommandLine = GetCommandLineW();
  argv = CommandLineToArgvW(CommandLine,(int *)&argc);
  arg = argv;
  result = CheckNumberofArgs((longlong)conf_context,(uint)argc,(longlong)argv);
  if ((int)result < 0) {
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Configuration::ParseArgs",0x19e);
    bytes = pWVar3;
    goto LAB_14003834b;
  }
  if ((result == 1) || (conf_context[L'B'] == 2)) goto LAB_14003834b;
  local_60 = (LPCWSTR)0x0;
  if (1 < (int)(uint)argc) {
    local_60 = (LPCWSTR)0x0;
    result1 = _wcsnicmp(argv[1],L"ms-msdt:",8);
    if (result1 == 0) {
      argv[1] = argv[1] + 8;
      uVar2 = ParseConfigArguments((longlong)conf_context,(longlong)(int)(uint)argc,(longlong)arg v);
      if ((int)uVar2 < 0) {
        uVar2 = ParseConfigArguments
                          ((longlong)conf_context,(longlong)(int)(uint)argc,(longlong)argv);
        result = (DWORD)uVar2;
        uVar4 = 0x1ae;
LAB_14003832d:
        PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Configuration::ParseArgs",uVar4);
      }
      else {
        result = Instance(&OutInstance);
        if ((int)result < 0) {
          result = Instance(&OutInstance);
          uVar4 = 0x1af;
          goto LAB_14003832d;
        }
      }
      bytes = (LPCWSTR)0x0;
      goto LAB_14003834b;
    }
  }
  local_res18 = 1;
  bytes = pWVar3;
  file_name = pWVar3;
  if ((int)((uint)argc + -1) < 2) {
LAB_140038a7e:
    result = Instance(&OutInstance);
    if ((int)result < 0) {
      uVar4 = 0x281;
      goto PrintError_Label;
    }
  }
  else {
    do {
      file = argv + 2;
      CommandLine = argv[1];
      DAT_14007f498 = 0x192;
      if ((*CommandLine + L'ￓ' & 0xfffdU) == 0) {
        CommandLine = CommandLine + 1;
      }
      if (bytes != (LPCWSTR)0x0) {
        hHeap = GetProcessHeap();
        HeapFree(hHeap,0,bytes);
        bytes = (LPCWSTR)0x0;
        filename = (LPCWSTR)0x0;
      }
      result1 = _wcsicmp(CommandLine,L"id");
      iVar5 = (int)pWVar3;
      if (result1 == 0) {
        pWVar3 = (LPCWSTR)(ulonglong)(iVar5 + 1);
        uVar2 = LoadFromProvider((longlong)conf_context,*file);
        result = (DWORD)uVar2;
        if ((int)result < 0) {
          uVar4 = 0x1c7;
          goto PrintError_Label;
        }
LAB_140038545:
        if (result == 1) {
          local_res10 = 1;
        }
      }
      else {
        result1 = _wcsicmp(CommandLine,L"path");
        if ((result1 == 0) && (file_name == (LPCWSTR)0x0)) {
          pWVar3 = (LPCWSTR)(ulonglong)(iVar5 + 1);
          result = CononicalizeFilePath(*file,&filename);
          bytes = filename;
          if ((int)result < 0) {
            PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Configuration::ParseArgs",0x1d7);
            bytes = filename;
            goto LAB_140038aac;
          }
          result = GetFileAttributesW(filename);
          CommandLine = memory;
          if (result == 0xffffffff) {
            result = GetLastError();
            if (0 < (int)result) {
              result = result & 0xffff | 0x80070000;
            }
            uVar4 = 0x1dc;
            goto PrintError_Label;
          }
          file_name = bytes;
          if ((result & 0x10) == 0) {
            result = GetFullPathNameW(bytes,260,memory,&FilePart);
            if ((0x103 < result - 1) || (FilePart <= CommandLine)) {
              result = 0x80028016;
              uVar4 = 0x1f1;
              goto PrintError_Label;
            }
            FilePart[-1] = L'\0';
            result1 = CompareFileExtension((longlong)FilePart);
            file_name = CommandLine;
            if (result1 == 0) {
              result = LoadConfigFile((longlong)conf_context,bytes,local_res20);
              if (-1 < (int)result) goto LAB_140038545;
              uVar4 = 0x201;
              goto PrintError_Label;
            }
          }
          Packages_SetPath(file_name);
          conf_context[L'B'] = 4;
        }
        else {
          result1 = _wcsicmp(CommandLine,L"cab");
          if ((result1 == 0) && (file_name == (LPCWSTR)0x0)) {
            pWVar3 = (LPCWSTR)(ulonglong)(iVar5 + 1U);
            if (1 < (int)(iVar5 + 1U)) goto LAB_140038a60;
            result = LoadCab((longlong)conf_context,*file);
            if ((int)result < 0) {
              uVar4 = 0x215;
              goto PrintError_Label;
            }
          }
          else {
            result1 = _wcsicmp(CommandLine,L"dci");
            if (result1 == 0) {
              conf_context[0x42] = 3;
              result = CopyWideStringToHeap((undefined8 *)(conf_context + 0x1c),*file);
              if ((int)result < 0) {
                uVar4 = 0x21e;
                goto PrintError_Label;
              }
            }
            else {
              result1 = _wcsicmp(CommandLine,L"sp");
              if (result1 == 0) {
                out_ptr = (undefined8 *)(conf_context + 0x18);
                pWVar3 = (LPCWSTR)(ulonglong)(iVar5 + 1);
                lpMem = (LPVOID)*out_ptr;
                if (lpMem != (LPVOID)0x0) {
                  hHeap = GetProcessHeap();
                  HeapFree(hHeap,0,lpMem);
                  *out_ptr = 0;
                }
                result = CopyWideStringToHeap(out_ptr,*file);
                if ((int)result < 0) {
                  uVar4 = 0x227;
                  goto PrintError_Label;
                }
                conf_context[66] = 3 - (uint)(conf_context[66] != 3);
              }
              else {
                result1 = _wcsicmp(CommandLine,L"context");
                if (result1 == 0) {
                  result = CopyWideStringToHeap((undefined8 *)(conf_context + 0x36),*file);
                  if ((int)result < 0) {
                    uVar4 = 0x233;
                    goto PrintError_Label;
                  }
                }
                else {
                  result1 = _wcsicmp(CommandLine,L"param");
                  if (result1 == 0) {
                    out_ptr_00 = (OLECHAR *)(conf_context + 0x3a);
                    result = CopyWideStringToHeap((undefined8 *)out_ptr_00,*file);
                    if ((int)result < 0) {
                      uVar4 = 0x236;
                      goto PrintError_Label;
                    }
                    result = LoadCommandLineAnswers(out_ptr_00,(longlong)*file);
                    if ((int)result < 0) {
                      uVar4 = 0x239;
                      goto PrintError_Label;
                    }
                  }
                  else {
                    result1 = _wcsicmp(CommandLine,L"af");
                    if (result1 == 0) {
                      result = LoadAnswerFile((longlong)conf_context,*file);
                      if ((int)result < 0) {
                        uVar4 = 0x23c;
                        goto PrintError_Label;
                      }
                    }
                    else {
                      result1 = _wcsicmp(CommandLine,L"elevated");
                      if (result1 == 0) {
                        *conf_context = 1;
                      }
                      else {
                        result1 = _wcsicmp(CommandLine,L"advanced");
                        if (result1 == 0) {
                          conf_context[6] = 1;
                        }
                        else {
                          result1 = _wcsicmp(CommandLine,L"disconnected");
                          if (result1 == 0) {
                            conf_context[8] = 1;
                          }
                          else {
                            result1 = _wcsicmp(CommandLine,L"custom");
                            if (result1 == 0) {
                              conf_context[10] = 1;
                            }
                            else {
                              result1 = _wcsicmp(CommandLine,L"skip");
                              if (result1 == 0) {
                                conf_context[15] = 1;
                                result1 = _wcsicmp(*file,L"force");
                                if (result1 == 0) {
                                  conf_context[14] = 1;
                                }
                              }
                              else {
                                result1 = _wcsicmp(CommandLine,L"dt");
                                if (result1 == 0) {
                                  conf_context[0x42] = 10;
                                  pWVar3 = (LPCWSTR)(ulonglong)(iVar5 + 1);
                                  result = CononicalizeFilePath(*file,&DAT_140080158);
                                  if ((int)result < 0) {
                                    uVar4 = 0x25a;
                                    goto PrintError_Label;
                                  }
                                }
                                else {
                                  result1 = _wcsicmp(CommandLine,L"up");
                                  if (result1 == 0) {
                                    conf_context[0x42] = 0xb;
                                    pWVar3 = (LPCWSTR)(ulonglong)(iVar5 + 1);
                                    result = CononicalizeFilePath(*file,&DAT_140080158);
                                    if ((int)result < 0) {
                                      uVar4 = 0x261;
                                      goto PrintError_Label;
                                    }
                                  }
                                  else {
                                    result1 = _wcsicmp(CommandLine,L"elev");
                                    if (result1 == 0) {
                                      conf_context[4] = 1;
                                      result = CopyWideStringToHeap
                                                         ((undefined8 *)(conf_context + 0x1e),*file )
                                      ;
                                      if ((int)result < 0) {
                                        uVar4 = 0x269;
                                        goto PrintError_Label;
                                      }
                                    }
                                    else {
                                      result1 = _wcsicmp(CommandLine,L"modal");
                                      if (result1 == 0) {
                                        lVar1 = _wtol(*file);
                                        *(longlong *)(conf_context + 0x44) = (longlong)lVar1;
                                      }
                                      else {
                                        result1 = _wcsicmp(CommandLine,L"ep");
                                        if (result1 == 0) {
                                          result = CopyWideStringToHeap
                                                             ((undefined8 *)(conf_context + 0x28),
                                                              *file);
                                          if ((int)result < 0) {
                                            uVar4 = 0x26e;
                                            goto PrintError_Label;
                                          }
                                        }
                                        else {
                                          result1 = _wcsicmp(CommandLine,L"moreoptions");
                                          if ((result1 == 0) &&
                                             (result1 = _wcsicmp(*file,L"false"), result1 == 0)) {
                                            conf_context[0x16] = 0;
                                          }
                                          else {
                                            result1 = _wcsicmp(CommandLine,L"givefeedback");
                                            if ((result1 != 0) ||
                                               (result1 = _wcsicmp(*file,L"false"), result1 != 0)) {
                                              result = 0x80070057;
                                              uVar4 = 0x277;
                                              goto PrintError_Label;
                                            }
                                            conf_context[23] = 0;
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      local_res18 = local_res18 + 2;
      file_name = local_60;
      argv = file;
    } while (local_res18 < (int)((uint)argc + -1));
    if ((int)pWVar3 < 2) goto LAB_140038a7e;
LAB_140038a60:
    result = 0x80070057;
    uVar4 = 0x27d;
PrintError_Label:
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Configuration::ParseArgs",uVar4);
  }
LAB_140038aac:
  if (bytes != (LPCWSTR)0x0) {
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,bytes);
  }
  bytes = (LPCWSTR)(ulonglong)local_res10;
  argv = arg;
LAB_14003834b:
  hHeap = GetProcessHeap();
  HeapFree(hHeap,0,memory);
  if (argv != (LPWSTR *)0x0) {
    LocalFree(argv);
  }
  if ((-1 < (int)result) && ((int)bytes != 0)) {
    conf_context[66] = 0xc;
  }
  
  return result;
}

