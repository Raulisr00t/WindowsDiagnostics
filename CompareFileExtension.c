
undefined4 CompareFileExtension(longlong filepart)

{
  int compared;
  ulonglong uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (filepart != 0) {
    uVar1 = 0xffffffffffffffff;
    do {
      uVar1 = uVar1 + 1;
    } while (*(short *)(filepart + uVar1 * 2) != 0);
                    /* in windows .diagpkg files are diagnostic analysis package files used by the
                       MSDT */
    uVar2 = 0;
    if (7 < uVar1) {
      compared = _wcsicmp((wchar_t *)(filepart + uVar1 * 2 + -16),L".diagpkg");
      uVar2 = 0;
      if (compared == 0) {
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}

