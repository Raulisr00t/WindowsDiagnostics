
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

_onexit_t RegisterOnExitFunction(_onexit_t func)

{
  _onexit_t p_Var1;
  longlong local_res10;
  undefined8 local_res18 [2];
  
  local_res18[0] = 0;
  local_res10 = DAT_140080230;
  if (DAT_140080230 == -1) {
    p_Var1 = _onexit(func);
  }
  else {
    _lock(8);
    local_res10 = DAT_140080230;
    local_res18[0] = DAT_140080228;
    p_Var1 = (_onexit_t)__dllonexit(func,&local_res10,local_res18);
    DAT_140080230 = local_res10;
    DAT_140080228 = local_res18[0];
    _unlock(8);
  }
  return p_Var1;
}

