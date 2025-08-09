
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

_Locimp * InitializeLocaleSupport(char param_1)

{
  _Locimp *p_Var1;
  _Lockit local_res8 [8];
  
  Syn((int *)local_res8,0);
  p_Var1 = DAT_14007f578;
  if (DAT_14007f578 == (_Locimp *)0x0) {
    p_Var1 = std::locale::_Locimp::_New_Locimp(false);
    Point(p_Var1);
    *(undefined4 *)(p_Var1 + 0x20) = 0x3f;
    ReplaceCStringWithCopy((undefined8 *)(p_Var1 + 0x28),"C");
    DAT_14007f570 = p_Var1;
    (**(code **)(*(longlong *)p_Var1 + 8))(p_Var1);
    DAT_14007f5b0 = DAT_14007f570;
  }
  if (param_1 != '\0') {
    (**(code **)(*(longlong *)p_Var1 + 8))(p_Var1);
  }
  std::_Lockit::~_Lockit(local_res8);
  return p_Var1;
}

