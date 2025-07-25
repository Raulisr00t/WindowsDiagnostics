
uint LoadCommandLineAnswers(OLECHAR *param_1,longlong FILE)

{
  bool bVar1;
  OLECHAR *pOVar2;
  uint uVar3;
  longlong lVar4;
  HANDLE hHeap;
  OLECHAR *memory;
  undefined8 uVar5;
  OLECHAR *local_res8;
  undefined8 *local_res18;
  OLECHAR *local_res20;
  
  bVar1 = false;
  local_res18 = (undefined8 *)0x0;
  local_res20 = (OLECHAR *)0x0;
  local_res8 = param_1;
  uVar3 = Instance((longlong *)&local_res18);
  if ((int)uVar3 < 0) {
    uVar5 = 0x766;
  }
  else {
    if (FILE == 0) {
      return uVar3;
    }
    lVar4 = -1;
    do {
      lVar4 = lVar4 + 1;
    } while (*(short *)(FILE + lVar4 * 2) != 0);
    if (lVar4 == 0) {
      return uVar3;
    }
    hHeap = GetProcessHeap();
    memory = (OLECHAR *)HeapAlloc(hHeap,0,2048);
    if (memory != (OLECHAR *)0x0) {
      uVar3 = SafeWcsCopy(memory,1024,FILE);
      pOVar2 = memory;
      if ((int)uVar3 < 0) {
        uVar5 = 0x76f;
LAB_1400369a6:
        PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Configuration::LoadCommandLineAnswers",
                   uVar5);
      }
      else {
        do {
          local_res8 = pOVar2;
          pOVar2 = local_res8;
          uVar3 = StrTok(local_res8,L' ',(longlong *)&local_res20);
          if ((int)uVar3 < 0) {
            uVar5 = 0x775;
            goto LAB_1400369a6;
          }
          if (uVar3 == 1) {
            bVar1 = true;
          }
          lVar4 = -1;
          do {
            lVar4 = lVar4 + 1;
          } while (pOVar2[lVar4] != L'\0');
          if (lVar4 != 0) {
            uVar3 = StrTok(pOVar2,L'=',(longlong *)&local_res8);
            if ((int)uVar3 < 0) {
              uVar5 = 0x782;
            }
            else {
              if (uVar3 != 1) {
                lVar4 = -1;
                do {
                  lVar4 = lVar4 + 1;
                } while (pOVar2[lVar4] != L'\0');
                if (lVar4 != 0) {
                  uVar3 = AddCatchAllAnswers(local_res18,pOVar2,local_res8);
                  if (-1 < (int)uVar3) goto LAB_140036952;
                  uVar5 = 0x78f;
                  goto LAB_1400369a6;
                }
              }
              uVar3 = 0x80070057;
              uVar5 = 0x78b;
            }
            goto LAB_1400369a6;
          }
LAB_140036952:
          local_res8 = local_res20;
          pOVar2 = local_res8;
        } while (!bVar1);
      }
      hHeap = GetProcessHeap();
      HeapFree(hHeap,0,memory);
      return uVar3;
    }
    uVar3 = 0x8007000e;
    uVar5 = 0x76c;
  }
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Configuration::LoadCommandLineAnswers",uVar5);
  return uVar3;
}

