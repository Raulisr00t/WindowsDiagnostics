
longlong GetWcharStringLength(short *expr)

{
  longlong lVar1;
  
  lVar1 = 0;
  if (*expr != 0) {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (expr[lVar1] != 0);
  }
  return lVar1;
}

