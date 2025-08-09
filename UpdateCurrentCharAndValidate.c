
void UpdateCurrentCharAndValidate(longlong *param_1)

{
  char escapeResult;
  char *foundCharPtr;
  ulonglong checkresult;
  ushort current_chr;
  bool invalid_charflag;
  
  if ((ushort *)*param_1 == (ushort *)param_1[2]) {
    current_chr = 0xffff;
    *(undefined2 *)(param_1 + 0xf) = 0xffff;
    foundCharPtr = (char *)0xffffffff;
  }
  else {
    current_chr = *(ushort *)*param_1;
    *(ushort *)(param_1 + 0xf) = current_chr;
    foundCharPtr = strchr("()$^.*+?[]|\\-{},:=!\n\r\b",(uint)current_chr);
    current_chr = *(ushort *)(param_1 + 0xf);
    if (foundCharPtr != (char *)0x0) {
      foundCharPtr = (char *)(ulonglong)current_chr;
    }
  }
  *(int *)((longlong)param_1 + 0x7c) = (int)foundCharPtr;
  if (current_chr < L'@') {
    if (current_chr != L'?') {
      if (current_chr == L'\n') {
        if ((*(byte *)(param_1 + 0x10) & 4) == 0) {
          return;
        }
        if (*(int *)((longlong)param_1 + 0x1c) != 0) {
          return;
        }
        *(undefined4 *)((longlong)param_1 + 0x7c) = L'|';
        return;
      }
      if (current_chr == L'$') {
        if ((*(uint *)(param_1 + 0x10) & 0x2000000) == 0) {
          return;
        }
        if ((short *)(*param_1 + 2) == (short *)param_1[2]) {
          return;
        }
        invalid_charflag = *(short *)(*param_1 + 2) == L'\n';
      }
      else {
        if ((current_chr == L'(') || (current_chr == L')')) {
          invalid_charflag = (*(byte *)(param_1 + 0x10) & 8) == 0;
          goto LAB_140025961;
        }
        if (current_chr != L'*') {
          if (current_chr != L'+') {
            return;
          }
          goto LAB_1400258c2;
        }
        if ((*(uint *)(param_1 + 0x10) & 0x4000000) == 0) {
          return;
        }
        checkresult = IsNodeTypeAllowed((longlong)(param_1 + 8));
        invalid_charflag = (char)checkresult == '\0';
      }
      if (invalid_charflag) {
        return;
      }
      goto LAB_140025963;
    }
LAB_1400258c2:
    invalid_charflag = (*(byte *)(param_1 + 0x10) & 1) == 0;
  }
  else {
    if (current_chr == L'\\') {
      escapeResult = CheckEscapeSequence(param_1);
      if (escapeResult == '\0') {
        return;
      }
      current_chr = *(ushort *)(*param_1 + 2);
      *(ushort *)(param_1 + 0xf) = current_chr;
      *(uint *)((longlong)param_1 + 0x7c) = (uint)current_chr;
      return;
    }
    if (current_chr == L'^') {
      if ((*(uint *)(param_1 + 0x10) & 0x2000000) == 0) {
        return;
      }
      checkresult = IsNodeTypeAllowed((longlong)(param_1 + 8));
      invalid_charflag = (char)checkresult == '\0';
    }
    else {
      if (current_chr != L'{') {
        if (current_chr == L'|') {
          invalid_charflag = (*(byte *)(param_1 + 0x10) & 2) == 0;
          goto LAB_140025961;
        }
        if (current_chr != L'}') {
          return;
        }
      }
      invalid_charflag = (*(byte *)(param_1 + 0x10) & 0x10) == 0;
    }
  }

LAB_140025961:
  if (!invalid_charflag) {
    return;
  }

LAB_140025963:
  *(undefined4 *)((longlong)param_1 + 0x7c) = 0;

  return;
}

