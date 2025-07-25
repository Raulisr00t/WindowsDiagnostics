
void NormalizeAndLogError(undefined8 param_1,int param_2,undefined8 param_3)

{
  uint hresult;
  
  NormalizeHRESULTToNTStatus(hresult);
  NormalizeAndLogErrorInternal(param_1,param_2,param_3);
  return;
}

