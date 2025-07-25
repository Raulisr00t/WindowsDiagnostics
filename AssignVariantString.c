
undefined4 AssignVariantString(VARIANTARG *arg,OLECHAR *string)

{
  undefined4 uVar1;
  BSTR pOVar2;
  
  uVar1 = 0;
  VariantClear(arg);
  pOVar2 = SysAllocString(string);
  (arg->n1).decVal.u2.Lo64 = (ULONGLONG)pOVar2;
  if ((string == (OLECHAR *)0x0) || (pOVar2 != (BSTR)0x0)) {
    (arg->n1).n2.vt = 8;
  }
  else {
    uVar1 = 0x8007000e;
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","AssignVariantString",0x576);
  }
  return uVar1;
}

