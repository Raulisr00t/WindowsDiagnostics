
int RegisterFunction(_onexit_t function)

{
  _onexit_t p_Var1;
  
  p_Var1 = RegisterOnExitFunction(function);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}

