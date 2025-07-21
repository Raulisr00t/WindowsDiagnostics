
DWORD CreateSDDL(undefined8 *param_1)

{
  DWORD DVar1;
  wchar_t *pwVar2;
  undefined8 uVar3;
  BOOL SUCCESS [6];
  
  SUCCESS[0] = 0;
  DVar1 = IsAdminToken(SUCCESS);
  if ((int)DVar1 < 0) {
    uVar3 = 860;
  }
  else {
    pwVar2 = L"D:(A;OICI;GA;;;SY)(A;OICI;GA;;;BA)";
    if (SUCCESS[0] == 0) {
      pwVar2 = L"D:(A;OICI;GA;;;SY)(A;OICI;GA;;;BA)(A;OICI;GA;;;%s)";
    }
    DVar1 = InsertCurrectSIDR(pwVar2,param_1);
    if (-1 < (int)DVar1) {
      return DVar1;
    }
    uVar3 = 876;
  }
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","CreateSddl",uVar3);
  return DVar1;
}

