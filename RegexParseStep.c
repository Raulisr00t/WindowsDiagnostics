
undefined8 RegexParseStep(longlong *param_1)

{
  code *pcVar1;
  int iVar2;
  ulonglong in_RAX;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  char cVar6;
  
  uVar3 = in_RAX & 0xffffffffffffff00;
  do {
    iVar2 = *(int *)((longlong)param_1 + L'|');
    cVar6 = '\x01';
    if ((iVar2 == -1) || (iVar2 == L'|')) {
      return uVar3;
    }
    if (iVar2 == L')') {
      if (*(int *)((longlong)param_1 + 0x1c) != 0) {
        return uVar3;
      }
      if ((*(uint *)(param_1 + 0x10) & 0x10000000) == 0) {
LAB_140022a8f:
        ThrowRegexException(5);
        pcVar1 = (code *)swi(3);
        uVar4 = (*pcVar1)();
        return uVar4;
      }
LAB_140022942:
      if ((iVar2 == L']') && ((*(uint *)(param_1 + 0x10) & 0x10000000) == 0)) {
LAB_140022a62:
        ThrowRegexException(4);
        pcVar1 = (code *)swi(3);
        uVar4 = (*pcVar1)();
        return uVar4;
      }
LAB_140022957:
      FUN_140022248((longlong)(param_1 + 8),(short)param_1[15]);
LAB_140022964:
      uVar4 = HandleEscapeAndAdvanceChar(param_1);
      if (cVar6 != '\0') goto LAB_140022971;
    }
    else {
      if (iVar2 == 0x2e) {
        CreateAndInsertRegexNode((longlong)(param_1 + 8),5);
      }
      else {
        if (iVar2 == 0x5c) {
          HandleEscapeAndAdvanceChar(param_1);
          if ((*(byte *)(param_1 + 0x10) & 0x80) != 0) {
            if ((short)param_1[15] == L'b') {
              uVar5 = 4;
              goto LAB_1400229bc;
            }
            if ((short)param_1[15] == L'B') {
              CreateAndInsertRegexNode((longlong)(param_1 + 8),4);
              *(uint *)(param_1[9] + 0xc) = *(uint *)(param_1[9] + 0xc) ^ 1;
              goto LAB_1400229c5;
            }
          }
          FUN_140022bd8(param_1);
          goto LAB_140022971;
        }
        if (iVar2 != L'[') {
          if (iVar2 == L'(') {
            HandleEscapeAndAdvanceChar(param_1);
            uVar4 = FUN_140025a2c(param_1);
            cVar6 = (char)uVar4;
            if (*(int *)((longlong)param_1 + L'|') != L')') goto LAB_140022a8f;
            goto LAB_140022964;
          }
          if (iVar2 == L'^') {
            uVar5 = 2;
          }
          else {
            if (iVar2 != L'$') {
              if (((iVar2 == L'?') || (iVar2 - L'*'U < 2)) || (iVar2 == L'{')) {
                ThrowRegexException(10);
                pcVar1 = (code *)swi(3);
                uVar4 = (*pcVar1)();
                return uVar4;
              }
              if (iVar2 != L'}') goto LAB_140022942;
              if ((*(uint *)(param_1 + 0x10) & 0x10000000) == 0) {
                ThrowRegexException(6);
                pcVar1 = (code *)swi(3);
                uVar4 = (*pcVar1)();
                return uVar4;
              }
              goto LAB_140022957;
            }
            uVar5 = 3;
          }
LAB_1400229bc:
          CreateAndInsertRegexNode((longlong)(param_1 + 8),uVar5);
LAB_1400229c5:
          uVar4 = HandleEscapeAndAdvanceChar(param_1);
          goto LAB_140022979;
        }
        HandleEscapeAndAdvanceChar(param_1);
        FUN_140022410((longlong)(param_1 + 8));
        iVar2 = *(int *)((longlong)param_1 + L'|');
        if (iVar2 == L'^') {
          *(uint *)(param_1[9] + 0xc) = *(uint *)(param_1[9] + 0xc) ^ 1;
          HandleEscapeAndAdvanceChar(param_1);
          iVar2 = *(int *)((longlong)param_1 + L'|');
        }
        if (((*(uint *)(param_1 + 0x10) & 0x20000000) != 0) && (iVar2 == L']')) {
          FUN_140022370((longlong)(param_1 + 8),L']');
          HandleEscapeAndAdvanceChar(param_1);
        }
        FUN_1400234b4(param_1);
        if (*(int *)((longlong)param_1 + L'|') != L']') goto LAB_140022a62;
      }
      HandleEscapeAndAdvanceChar(param_1);

LAB_140022971:
      uVar4 = ParseRegexQuantifier(param_1);
    }

LAB_140022979:
    uVar3 = CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
  } while( true );
}

