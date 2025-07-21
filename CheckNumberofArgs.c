
HRESULT CheckNumberofArgs(longlong conf_context,uint argc,longlong argv)

{
  int compare_result;
  int questionmark_result;
  HRESULT hResult;
  wchar_t *argument_str;
  uint uVar1;
  undefined8 ErrorLine;
  wchar_t *command;
  
                    /* Set Default Mode */
  if (argc == 1) {
    *(undefined4 *)(conf_context + 264) = 2;
    return 0;
  }
  if (argc == 2) {
    command = *(wchar_t **)(argv + 8);
    compare_result = _wcsnicmp(command,L"ms-msdt:",8);
    argument_str = command + 8;
    if (compare_result != 0) {
      argument_str = command;
    }
    if ((*argument_str == L'-') || (*argument_str == L'/')) {
      argument_str = argument_str + 1;
    }
                    /* Help Mode */
    questionmark_result = _wcsicmp(argument_str,L"?");
    if (questionmark_result == 0) {
      hResult = ShowHelp(L"mshelp://windows/?id=a2f80104-cb3a-4b9c-901f-733f4a882248");
      if (-1 < hResult) {
        return 1;
      }
      ErrorLine = 0x2ca;
      goto Error;
    }
    if (compare_result == 0) {
      *(undefined4 *)(conf_context + 264) = 2;
      return 0;
    }
Return:
    if ((*(wchar_t **)(argv + 8) != (wchar_t *)0x0) &&
       (compare_result = _wcsnicmp(*(wchar_t **)(argv + 8),L"ms-msdt:",8), compare_result == 0)) {
      return 0;
    }
  }
  else if (1 < (int)argc) goto Return;
  uVar1 = argc & 0x80000001;
  if ((int)uVar1 < 0) {
    uVar1 = (uVar1 - 1 | 0xfffffffe) + 1;
  }
  if (uVar1 == 1) {
    return 0;
  }
                    /* E_INVALIDARG custom HRESULT */
  hResult = -0x7ff8ffa9;
  ErrorLine = 0x2e4;
Error:
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Configuration::CheckNumberArgs",ErrorLine);
  return hResult;
}

