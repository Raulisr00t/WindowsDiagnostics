
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint LoadMetaData(ulonglong param_1,longlong *param_2,longlong param_3)

{
  uint uVar1;
  longlong *plVar2;
  undefined8 uVar3;
  ulonglong local_res8;
  
  local_res8 = param_1 & 0xffffffffffff0000;
  uVar1 = (**(code **)(*param_2 + 0x28))(param_2,param_3 + 0x10);
  if ((int)uVar1 < 0) {
    uVar3 = 0xc0;
  }
  else {
    uVar1 = (**(code **)(*param_2 + 0x18))(param_2,param_3);
    if ((int)uVar1 < 0) {
      uVar3 = 0xc3;
    }
    else {
      uVar1 = (**(code **)(*param_2 + 0x58))(param_2,param_3 + 0x20);
      if ((int)uVar1 < 0) {
        uVar3 = 0xc6;
      }
      else {
        uVar1 = (**(code **)(*param_2 + 0x30))(param_2,param_3 + 8);
        if ((int)uVar1 < 0) {
          uVar3 = 0xc9;
        }
        else {
          uVar1 = (**(code **)(*param_2 + 0x68))(param_2,param_3 + 0x18);
          if ((int)uVar1 < 0) {
            uVar3 = 0xcf;
          }
          else {
            uVar1 = (**(code **)(*param_2 + 0x20))(param_2,param_3 + 0x28);
            if ((int)uVar1 < 0) {
              uVar3 = 0xd2;
            }
            else {
              uVar1 = (**(code **)(*param_2 + 0x50))(param_2,&local_res8);
              if ((int)uVar1 < 0) {
                uVar3 = 0xd5;
              }
              else {
                *(uint *)(param_3 + 0x48) = (uint)((short)local_res8 == -1);
                uVar1 = (**(code **)(*param_2 + 0x38))(param_2,&local_res8);
                if ((int)uVar1 < 0) {
                  uVar3 = 0xda;
                }
                else {
                  *(uint *)(param_3 + 0x4c) = (uint)((short)local_res8 == -1);
                  uVar1 = (**(code **)(*param_2 + 0x40))(param_2,param_3 + 0x30);
                  if ((int)uVar1 < 0) {
                    uVar3 = 0xdf;
                  }
                  else {
                    plVar2 = param_2;
                    uVar1 = (**(code **)(*param_2 + 0x70))(param_2,param_3 + 0x38);
                    if ((int)uVar1 < 0) {
                      uVar3 = 0xe2;
                    }
                    else {
                      uVar1 = GetPublisherCertificateDigest(plVar2,param_2,param_3);
                      if ((int)uVar1 < 0) {
                        uVar3 = 0xe5;
                      }
                      else {
                        uVar1 = GetKeywords((ulonglong)plVar2,param_2,param_3);
                        if (-1 < (int)uVar1) {
                          return uVar1;
                        }
                        uVar3 = 0xeb;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Provider::LoadMetadata",uVar3);
  return uVar1;
}

