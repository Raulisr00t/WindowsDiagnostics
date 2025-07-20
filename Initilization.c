
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong Initilization(void)

{
  void *pvVar1;
  bool bVar2;
  bool bVar3;
  void *pvVar4;
  ushort uVar5;
  int iVar6;
  BOOL BVar7;
  void *pvVar8;
  ulonglong uVar9;
  ushort *puVar10;
  longlong *plVar11;
  bool bVar12;
  _STARTUPINFOW si;
  
  si._4_4_ = 0;
  memset(&si,0,100);
  iVar6 = 0;
  bVar2 = false;
  bVar3 = false;
                    /* StartUPInfo Initilization */
                    /* msdt.exe starts by locking, ensuring only one diagnostic runs at a time. */
  GetStartupInfoW(&si);
  pvVar1 = StackBase;
  while( true ) {
    pvVar8 = (void *)0x0;
    LOCK();
    bVar12 = DAT_140080218 == (void *)0x0;
    pvVar4 = pvVar1;
    if (!bVar12) {
      pvVar8 = DAT_140080218;
      pvVar4 = DAT_140080218;
    }
    DAT_140080218 = pvVar4;
    UNLOCK();
    if (bVar12) goto CleanUP;
    if (pvVar8 == pvVar1) break;
                    /* Sleep 1 second */
    Sleep(1000);
  }
  bVar2 = true;
CleanUP:
                    /* CleanUP */
  if (DAT_140080220 == 1) {
    _amsg_exit(0x1f);
  }
  else if (DAT_140080220 == 0) {
    DAT_140080220 = 1;
    for (plVar11 = &DAT_140069550; plVar11 < &DAT_140069568; plVar11 = plVar11 + 1) {
      if (iVar6 != 0) {
        return 0xff;
      }
      if (*plVar11 != 0) {
        iVar6 = (*(code *)*plVar11)();
      }
    }
    if (iVar6 != 0) {
      return 0xff;
    }
  }
  else {
    DAT_14007f7d0 = 1;
  }
  if (DAT_140080220 == 1) {
    _initterm(&DAT_1400694b0,&DAT_140069548);
    DAT_140080220 = 2;
  }
  if (!bVar2) {
    LOCK();
    DAT_140080218 = (void *)0x0;
    UNLOCK();
  }
  if ((DAT_140080238 != (code *)0x0) &&
     (BVar7 = _IsNonwritableInCurrentImage((PBYTE)&DAT_140080238), BVar7 != 0)) {
    (*DAT_140080238)(0,2);
  }
                    /* Command-Line Argument Parsing */
  puVar10 = *(ushort **)_wcmdln_exref;
  if (puVar10 == (ushort *)0x0) {
    uVar9 = 0xff;
  }
  else {
    while ((uVar5 = *puVar10, 0x20 < uVar5 || ((uVar5 != 0 && (bVar3))))) {
      if (uVar5 == 0x22) {
        bVar3 = !bVar3;
      }
      puVar10 = puVar10 + 1;
    }

    while ((ushort)(uVar5 - 1) < 0x20) {
      puVar10 = puVar10 + 1;
      uVar5 = *puVar10;
    }
                    /* Final Execution */
    uVar9 = MainExecution(&IMAGE_DOS_HEADER_140000000);
    DAT_14007f7cc = (uint)uVar9;
    if (DAT_14007f7f0 == 0) {
                    /* WARNING: Subroutine does not return */
      exit(DAT_14007f7cc);
    }
    if (DAT_14007f7d0 == 0) {
      _cexit();
      uVar9 = (ulonglong)DAT_14007f7cc;
    }
  }
  return uVar9;
}

