
ulonglong ParseConfigArguments(longlong conf_context,ulonglong argc,longlong argv)

{
  int result;
  uint hResult;
  ulonglong LoadResult;
  ulonglong count;
  wchar_t *string1;
  bool hasIDArg;
  undefined8 return_Addr;
  
  count = 1;
  hasIDArg = false;
  do {
    if (argc <= count) {
      if (hasIDArg) {
        count = 0;
      }
      else {
        hResult = 0x80070057;
        result = 0x16a;
LAB_140038d13:
        FUN_140006834(return_Addr,result,"base\\diagnosis\\pdui\\de\\wizard\\config.cpp");
LAB_140038d27:
        count = (ulonglong)hResult;
      }
      return count;
    }
    string1 = *(wchar_t **)(argv + count * 8);
    if (string1 == (wchar_t *)0x0) {
      hResult = 0x8007000e;
      result = 0x12e;
      goto LAB_140038d13;
    }
    if ((*string1 + L'ￓ' & L'�'U) == 0) {
      string1 = string1 + 1;
    }
    result = _wcsicmp(string1,L"id");
    if (result == 0) {
      count = count + 1;
      if (argc <= count) {
        hResult = 0x80070057;
        result = 0x138;
        goto LAB_140038d13;
      }
      LoadResult = LoadFromProvider(conf_context,*(OLECHAR **)(argv + count * 8));
      if ((int)LoadResult == 1) {
        hResult = 0x80070057;
        result = 0x13e;
        goto LAB_140038d13;
      }
      if ((int)LoadResult < 0) {
        FUN_140006834(return_Addr,0x13f,"base\\diagnosis\\pdui\\de\\wizard\\config.cpp");
        return LoadResult & 0xffffffff;
      }
      hasIDArg = true;
    }
    else {
      result = _wcsicmp(string1,L"custom");
      if (result == 0) {
        *(undefined4 *)(conf_context + L'(') = 1;
      }
      else {
        result = _wcsicmp(string1,L"skip");
        if (result == 0) {
          *(undefined4 *)(conf_context + L'<') = 1;
          if ((count + 1 < argc) &&
             (result = _wcsicmp(*(wchar_t **)(argv + 8 + count * 8),L"force"), result == 0)) {
            *(undefined4 *)(conf_context + 0x38) = 1;
            count = count + 1;
          }
        }
        else {
          result = _wcsicmp(string1,L"ep");
          if (result == 0) {
            if (count + 1 < argc) {
              hResult = CopyWideStringToHeap
                                  ((undefined8 *)(conf_context + 0xa0),
                                   *(short **)(argv + 8 + count * 8));
              if (-1 < (int)hResult) goto LAB_140038d27;
              result = 0x158;
            }
            else {
              hResult = 0x80070057;
              result = 0x157;
            }
            goto LAB_140038d13;
          }
          LoadResult = 0;
          while( true ) {
            if (127 < LoadResult) {
              hResult = 0x80070057;
              result = 0x166;
              goto LAB_140038d13;
            }
            result = _wcsicmp(string1,*(wchar_t **)((longlong)&PTR_u_path_140068190 + LoadResult)) ;
            if (result == 0) break;
            LoadResult = LoadResult + 8;
          }
          for (LoadResult = 0; LoadResult < 128; LoadResult = LoadResult + 8) {
            result = _wcsicmp(string1,*(wchar_t **)((longlong)&PTR_u_path_140068190 + LoadResult)) ;
            if (result == 0) {
              count = count + 1;
              break;
            }
          }
        }
      }
    }
    count = count + 1;
  } while( true );
}

