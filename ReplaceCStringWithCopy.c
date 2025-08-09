
undefined8 * ReplaceCStringWithCopy(undefined8 *param_1,char *param_2)

{
  char cVar1;
  void *_Dst;
  char *pcVar2;
  
  pcVar2 = (char *)*param_1;
  if (pcVar2 != param_2) {
    if (pcVar2 != (char *)0x0) {
      free(pcVar2);
    }
    *param_1 = 0;
    if (param_2 != (char *)0x0) {
      cVar1 = *param_2;
      pcVar2 = param_2;
      while (cVar1 != '\0') {
        pcVar2 = pcVar2 + 1;
        cVar1 = *pcVar2;
      }
      _Dst = malloc((size_t)(pcVar2 + (1 - (longlong)param_2)));
      *param_1 = _Dst;
      if (_Dst != (void *)0x0) {
        memcpy(_Dst,param_2,(size_t)(pcVar2 + (1 - (longlong)param_2)));
      }
    }
  }
  return param_1;
}

