
undefined8 InterestingFunction(wchar_t *any_string,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  wchar_t *pwVar2;
  undefined4 *puVar3;
  undefined *puVar4;
  
  if (any_string != (wchar_t *)0x0) {
    puVar4 = &DAT_14006d95c;
    pwVar2 = wcsstr(any_string,L"$(");
    if (pwVar2 == (wchar_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
      if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_1400801e8) {
        puVar3 = &DAT_1400801e8;
        FUN_1400037f4(&DAT_1400801e8);
        if (DAT_1400801e8 == -1) {
          ISawPowershellCommandExpression(puVar3,puVar4,param_3);
          FUN_1400034c0(FUN_140062c10);
          _Init_thread_footer(&DAT_1400801e8);
        }
      }
      cVar1 = FUN_14001ede0(any_string);
      if (cVar1 != '\0') {
        return 0x80070057;
      }
      return 0;
    }
  }
  return 0x80070057;
}

