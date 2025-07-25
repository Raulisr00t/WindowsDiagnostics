
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

HRESULT XmlLoad(OLECHAR *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  HRESULT result;
  undefined8 uVar3;
  short local_res8 [4];
  longlong *local_res18;
  _union_2707 local_58;
  undefined4 local_38;
  ULONG UStack_34;
  undefined4 uStack_30;
  ULONG UStack_2c;
  undefined8 local_28;
  
  local_58._16_8_ = 0;
  local_res8[0] = -1;
  local_res18 = (longlong *)0x0;
  local_58._0_8_ = 0;
  local_58.decVal.u2 = (_union_1719)0x0;
  VariantInit((VARIANTARG *)&local_58.n2);
  if (param_1 == (OLECHAR *)0x0) {
    uVar3 = 0x2d4;
LAB_140021af5:
    result = -0x7ff8ffa9;
  }
  else {
    if (param_2 == (undefined8 *)0x0) {
      uVar3 = 0x2d5;
      goto LAB_140021af5;
    }
    result = CoCreateInstance((IID *)&DAT_14006afa0,(LPUNKNOWN)0x0,21,(IID *)&DAT_14006af70,
                              &local_res18);
    if (result < 0) {
      uVar3 = 0x2e0;
    }
    else {
      result = (**(code **)(*local_res18 + 0x1f8))(local_res18,0);
      if (result < 0) {
        uVar3 = 0x2e3;
      }
      else {
        local_58.decVal.u2 = (_union_1719)SysAllocString(param_1);
        uVar1 = local_58._0_8_;
        if (local_58.decVal.u2.Lo64 == (_union_1719)0x0) {
          result = -0x7ff8fff2;
          uVar3 = 0x2e6;
        }
        else {
          local_28 = local_58._16_8_;
          local_58.n2.vt = 8;
          uVar2 = local_58._0_8_;
          local_58.decVal.Hi32 = SUB84(uVar1,4);
          local_38 = local_58._0_4_;
          UStack_34 = local_58.decVal.Hi32;
          uStack_30 = local_58._8_4_;
          UStack_2c = local_58._12_4_;
          local_58._0_8_ = uVar2;
          result = (**(code **)(*local_res18 + 0x1d0))(local_res18,&local_38,local_res8);
          if (result < 0) {
            uVar3 = 0x2eb;
          }
          else {
            if (local_res8[0] != 0) {
              *param_2 = local_res18;
              (**(code **)(*local_res18 + 8))();
              goto CleanUp;
            }
            result = -0x7fffbffb;
            uVar3 = 0x2ec;
          }
        }
      }
    }
  }
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","DwzXmlLoad",uVar3);
CleanUp:
  VariantClear((VARIANTARG *)&local_58.n2);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x10))();
  }
  return result;
}

