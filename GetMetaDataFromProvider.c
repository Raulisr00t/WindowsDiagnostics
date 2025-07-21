
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong GetMetaDataFromProvider(undefined8 *param_1,OLECHAR *param_2,longlong param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  BOOL BVar3;
  ulonglong uVar4;
  uint error;
  HANDLE hHeap;
  longlong *plVar5;
  PULONG pulNumLanguages;
  BSTR pOVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  BSTR bstrString;
  BSTR pwszLanguagesBuffer;
  BSTR bstrString_00;
  ULONG local_res8 [2];
  int local_res20 [2];
  longlong *local_a8;
  ULONG local_a0;
  int local_9c;
  longlong *local_98;
  longlong *local_90;
  longlong *local_88;
  longlong *local_80;
  longlong local_78;
  _union_2707 local_70;
  undefined4 local_58;
  ULONG UStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 local_48;
  
  pOVar6 = (BSTR)0x0;
  local_98 = (longlong *)0x0;
  local_a8 = (longlong *)0x0;
  local_90 = (longlong *)0x0;
  local_88 = (longlong *)0x0;
  bstrString = (BSTR)0x0;
  local_80 = (longlong *)0x0;
  bstrString_00 = (BSTR)0x0;
  pwszLanguagesBuffer = (BSTR)0x0;
  local_70._16_8_ = 0;
  local_70._0_8_ = 0;
  local_70.decVal.u2 = (_union_1719)0x0;
  local_9c = 0;
  local_res20[0] = 0;
  local_a0 = 0;
  local_res8[0] = 0;
  local_78 = 0;
  VariantInit((VARIANTARG *)&local_70.n2);
  if (*(int *)(param_1 + 1) == 0) {
    error = ProviderInit(param_1);
    uVar7 = (ulonglong)error;
    if (-1 < (int)error) goto LAB_140039703;
    uVar8 = 0x120;
    bstrString = pOVar6;
    pwszLanguagesBuffer = pOVar6;
    bstrString_00 = pOVar6;
  }
  else {
LAB_140039703:
    error = GetProvider(param_1,&local_98);
    uVar7 = (ulonglong)error;
    if ((int)error < 0) {
      uVar8 = 0x124;
    }
    else {
      uVar4 = QueryToRemoteServer(local_res20,(uint *)0x0);
      uVar7 = uVar4 & 0xffffffff;
      if ((int)uVar4 < 0) {
        uVar8 = 0x127;
      }
      else {
        if (local_res20[0] != 0) {
          error = (**(code **)(*local_98 + 0x20))(local_98,0xffffffff);
          uVar7 = (ulonglong)error;
          if ((int)error < 0) {
            uVar8 = 299;
            goto LAB_140039a37;
          }
        }
        error = GetMetaDataFromProvider((longlong)param_1,&local_a8);
        uVar7 = (ulonglong)error;
        if ((int)error < 0) {
          uVar8 = 0x12f;
        }
        else {
          bstrString = SysAllocString(param_2);
          if (bstrString == (BSTR)0x0) {
            uVar8 = 0x132;
            uVar7 = 0x8007000e;
            pwszLanguagesBuffer = pOVar6;
            bstrString_00 = pOVar6;
          }
          else {
            error = (**(code **)(*local_a8 + 0x28))(local_a8,0);
            uVar7 = (ulonglong)error;
            if ((int)error < 0) {
              uVar8 = 0x138;
            }
            else {
              error = (**(code **)(*local_a8 + 0x30))(local_a8,bstrString);
              uVar7 = (ulonglong)error;
              if ((int)error < 0) {
                uVar8 = 0x13b;
              }
              else {
                error = GetMetaDataCollection((longlong)param_1,&local_90);
                uVar7 = (ulonglong)error;
                if ((int)error < 0) {
                  uVar8 = 0x141;
                }
                else {
                  error = (**(code **)(*local_90 + 0x30))(local_90,local_a8);
                  uVar7 = (ulonglong)error;
                  if ((int)error < 0) {
                    uVar8 = 0x147;
                  }
                  else {
                    pulNumLanguages = &local_a0;
                    BVar3 = GetUserPreferredUILanguages(8,pulNumLanguages,(PZZWSTR)0x0,local_res8) ;
                    if (BVar3 == 0) {
                      error = GetLastError();
                      if (0 < (int)error) {
                        error = error & 0xffff | 0x80070000;
                      }
                      uVar7 = (ulonglong)error;
                      if ((int)error < 0) {
                        uVar8 = 0x151;
                        goto LAB_140039a37;
                      }
                    }
                    error = FUN_14003a214((ulonglong)local_res8[0],pulNumLanguages,&local_78);
                    uVar7 = (ulonglong)error;
                    if ((int)error < 0) {
                      uVar8 = 0x154;
                    }
                    else {
                      hHeap = GetProcessHeap();
                      pwszLanguagesBuffer = (BSTR)HeapAlloc(hHeap,0,local_78 * 2);
                      if (pwszLanguagesBuffer == (PZZWSTR)0x0) {
                        uVar8 = 0x156;
                        uVar7 = 0x8007000e;
                      }
                      else {
                        BVar3 = GetUserPreferredUILanguages
                                          (8,&local_a0,pwszLanguagesBuffer,local_res8);
                        if (BVar3 == 0) {
                          error = GetLastError();
                          if (0 < (int)error) {
                            error = error & 0xffff | 0x80070000;
                          }
                          uVar7 = (ulonglong)error;
                          if ((int)error < 0) {
                            uVar8 = 0x15d;
                            goto LAB_140039a37;
                          }
                        }
                        bstrString_00 = SysAllocStringLen(pwszLanguagesBuffer,local_res8[0]);
                        if (bstrString_00 == (BSTR)0x0) {
                          uVar8 = 0x163;
                          uVar7 = 0x8007000e;
                        }
                        else {
                          error = (**(code **)(*local_98 + 0x28))
                                            (local_98,local_90,bstrString_00,&local_88);
                          uVar7 = (ulonglong)error;
                          if ((int)error < 0) {
                            uVar8 = 0x16c;
                          }
                          else {
                            error = (**(code **)(*local_88 + 0x18))(local_88,&local_9c);
                            uVar1 = local_70._0_8_;
                            uVar7 = (ulonglong)error;
                            if ((int)error < 0) {
                              uVar8 = 0x16f;
                            }
                            else {
                              if (local_9c == 0) {
                                uVar7 = 1;
                                goto LAB_140039a4f;
                              }
                              if (local_9c == 1) {
                                local_70.decVal.u2.Lo64 = (_union_1719)0x0;
                                local_70.n2.vt = 0x13;
                                uVar2 = local_70._0_8_;
                                local_70.decVal.Hi32 = SUB84(uVar1,4);
                                local_48 = local_70._16_8_;
                                local_58 = local_70._0_4_;
                                UStack_54 = local_70.decVal.Hi32;
                                uStack_50 = 0;
                                uStack_4c = 0;
                                plVar5 = local_88;
                                local_70._0_8_ = uVar2;
                                error = (**(code **)(*local_88 + 0x20))
                                                  (local_88,&local_58,&local_80);
                                uVar7 = (ulonglong)error;
                                if ((int)error < 0) {
                                  uVar8 = 0x184;
                                }
                                else {
                                  error = FUN_14003a004((ulonglong)plVar5,local_80,param_3);
                                  uVar7 = (ulonglong)error;
                                  if (-1 < (int)error) goto LAB_140039a4f;
                                  uVar8 = 0x187;
                                }
                              }
                              else {
                                uVar7 = 0x80070057;
                                uVar8 = 0x17c;
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
        }
      }
    }
  }
LAB_140039a37:
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Provider::GetMetadata",uVar8);
LAB_140039a4f:
  if (local_98 != (longlong *)0x0) {
    (**(code **)(*local_98 + 0x10))();
    local_98 = (longlong *)0x0;
  }
  if (local_a8 != (longlong *)0x0) {
    (**(code **)(*local_a8 + 0x10))();
    local_a8 = (longlong *)0x0;
  }
  if (local_90 != (longlong *)0x0) {
    (**(code **)(*local_90 + 0x10))();
    local_90 = (longlong *)0x0;
  }
  if (local_88 != (longlong *)0x0) {
    (**(code **)(*local_88 + 0x10))();
    local_88 = (longlong *)0x0;
  }
  if (local_80 != (longlong *)0x0) {
    (**(code **)(*local_80 + 0x10))();
    local_80 = (longlong *)0x0;
  }
  if (bstrString != (BSTR)0x0) {
    SysFreeString(bstrString);
  }
  if (bstrString_00 != (BSTR)0x0) {
    SysFreeString(bstrString_00);
  }
  if (pwszLanguagesBuffer != (BSTR)0x0) {
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,pwszLanguagesBuffer);
  }
  VariantClear((VARIANTARG *)&local_70.n2);
  return uVar7;
}

