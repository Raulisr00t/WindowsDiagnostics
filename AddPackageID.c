
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int AddPackageID(undefined8 *param_1)

{
  longlong *plVar1;
  int iVar2;
  wchar_t *pwVar3;
  undefined8 uVar4;
  longlong *local_res10;
  
  local_res10 = (longlong *)0x0;
  pwVar3 = L"Packages";
  iVar2 = XmlGetNode(L"Packages",(longlong *)*param_1,(longlong *)0x0,&local_res10);
  plVar1 = local_res10;
  if (iVar2 < 0) {
    uVar4 = 0xa5;
  }
  else {
    iVar2 = CreatePackageNode(pwVar3,local_res10,(longlong *)*param_1);
    if (-1 < iVar2) goto LAB_1400339c4;
    uVar4 = 0xa8;
  }
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Answers::AddPackageID",uVar4);
LAB_1400339c4:
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 0x10))(plVar1);
  }
  return iVar2;
}

