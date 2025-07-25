
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

HRESULT XmlCreate(OLECHAR *package,undefined8 *document)

{
  HRESULT HVar1;
  BSTR bstrString;
  undefined8 uVar2;
  short local_res8 [4];
  longlong *local_res18;
  
  local_res8[0] = -1;
  local_res18 = (longlong *)0x0;
  bstrString = (BSTR)0x0;
  if (package == (OLECHAR *)0x0) {
    uVar2 = 0x291;
LAB_140021138:
    HVar1 = -0x7ff8ffa9;
    bstrString = (BSTR)0x0;
  }
  else {
    if (document == (undefined8 *)0x0) {
      uVar2 = 0x292;
      goto LAB_140021138;
    }
    HVar1 = CoCreateInstance((IID *)&DAT_14006afa0,(LPUNKNOWN)0x0,0x15,(IID *)&DAT_14006af70,
                             &local_res18);
    if (HVar1 < 0) {
      uVar2 = 0x29a;
    }
    else {
      HVar1 = (**(code **)(*local_res18 + 0x1f8))(local_res18,0);
      if (HVar1 < 0) {
        uVar2 = 0x29d;
      }
      else {
        bstrString = SysAllocString(package);
        if (bstrString == (BSTR)0x0) {
          HVar1 = -0x7ff8fff2;
          uVar2 = 0x2a0;
        }
        else {
          HVar1 = (**(code **)(*local_res18 + 0x208))(local_res18,bstrString,local_res8);
          if (HVar1 < 0) {
            uVar2 = 0x2a3;
          }
          else {
            if (local_res8[0] != 0) {
              *document = local_res18;
              (**(code **)(*local_res18 + 8))();
              goto LAB_140021253;
            }
            HVar1 = -0x7fffbffb;
            uVar2 = 0x2a4;
          }
        }
      }
    }
  }
  
   PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","DwzXmlCreate",uVar2);
LAB_140021253:
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x10))();
    local_res18 = (longlong *)0x0;
  }
  if (bstrString != (BSTR)0x0) {
    SysFreeString(bstrString);
  }
  return HVar1;
}

