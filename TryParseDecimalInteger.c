
bool TryParseDecimalInteger(longlong *param_1)

{
  int iVar1;
  
  iVar1 = ParseIntegerWithBase(param_1,10,0x7fffffff);
  return iVar1 != 0x7fffffff;
}

