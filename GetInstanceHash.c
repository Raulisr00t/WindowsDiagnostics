
uint GetInstanceHash(undefined8 status,uint *param2)

{
  int iVar1;
  longlong lVar2;
  uint uVar3;
  HANDLE hHeap;
  short *memory;
  longlong lVar4;
  BSTR bstrString;
  undefined8 uVar5;
  
  lVar2 = maybe_everything;
  bstrString = (BSTR)0x0;
  hHeap = GetProcessHeap();
  memory = (short *)HeapAlloc(hHeap,0,2048);
  if (memory == (short *)0x0) {
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Configuration::GetInstanceHash",0x7e9);
    return 0x8007000e;
  }
  *memory = 0;
  iVar1 = *(int *)(lVar2 + 264);
  if (iVar1 < 8) {
    if ((iVar1 != 7) && (iVar1 != 1)) {
      if ((iVar1 != 2) && (iVar1 != 3)) {
        if (iVar1 != 4) {
          if ((iVar1 == 5) || (iVar1 == 6)) {
            uVar3 = Calculate_PathBuffer(memory,1024,0x1400701c0);
            if ((int)uVar3 < 0) {
              uVar5 = 0x7fa;
            }
            else {
              lVar4 = GetPackagesPath();
              uVar3 = Calculate_PathBuffer(memory,1024,lVar4);
              if ((int)uVar3 < 0) {
                uVar5 = 0x7fd;
              }
              else {
                uVar3 = Calculate_PathBuffer(memory,1024,0x1400701d0);
                bstrString = (BSTR)0x0;
                if (-1 < (int)uVar3) goto LAB_1400363d6;
                uVar5 = 0x800;
              }
            }
          }
          else {
LAB_14003627b:
            uVar3 = 0x8000ffff;
            uVar5 = 0x841;
          }
          goto LAB_140036135;
        }
        goto LAB_1400361e8;
      }
      if (*(longlong *)(lVar2 + 0x60) != 0) {
        uVar3 = Calculate_PathBuffer(memory,0x400,0x1400701f0);
        if ((int)uVar3 < 0) {
          uVar5 = 0x81a;
        }
        else {
          uVar3 = Calculate_PathBuffer(memory,0x400,*(longlong *)(lVar2 + 0x60));
          if (-1 < (int)uVar3) goto LAB_1400363d6;
          uVar5 = 0x81d;
        }
        goto LAB_140036135;
      }
LAB_1400363d6:
      if (*(longlong *)(lVar2 + 0xe8) == 0) {
LAB_140036448:
        if (*(longlong *)(lVar2 + 0xf0) != 0) {
          uVar3 = Calculate_PathBuffer(memory,0x400,0x140070248);
          if ((int)uVar3 < 0) {
            uVar5 = 0x857;
          }
          else {
            uVar3 = Calculate_PathBuffer(memory,0x400,*(longlong *)(lVar2 + 0xf0));
            if ((int)uVar3 < 0) {
              uVar5 = 0x85a;
            }
            else {
              uVar3 = Calculate_PathBuffer(memory,0x400,0x1400701d0);
              if (-1 < (int)uVar3) goto LAB_1400364b1;
              uVar5 = 0x85d;
            }
          }
          goto LAB_1400364c8;
        }
LAB_1400364b1:
        uVar5 = HashWideStringAndStoreResult((longlong)memory,param2);
        uVar3 = (uint)uVar5;
        if ((int)uVar3 < 0) {
          uVar5 = 0x864;
          goto LAB_1400364c8;
        }
      }
      else {
        uVar3 = Calculate_PathBuffer(memory,0x400,0x140070230);
        if ((int)uVar3 < 0) {
          uVar5 = 0x849;
        }
        else {
          uVar3 = Calculate_PathBuffer(memory,0x400,*(longlong *)(lVar2 + 0xe8));
          if ((int)uVar3 < 0) {
            uVar5 = 0x84c;
          }
          else {
            uVar3 = Calculate_PathBuffer(memory,0x400,0x1400701d0);
            if (-1 < (int)uVar3) goto LAB_140036448;
            uVar5 = 0x84f;
          }
        }
LAB_1400364c8:
        PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Configuration::GetInstanceHash",uVar5);
      }
      if (bstrString != (BSTR)0x0) {
        SysFreeString(bstrString);
      }
      goto CleanUp;
    }
LAB_1400361e8:
    uVar3 = Calculate_PathBuffer(memory,0x400,0x1400701d8);
    if ((int)uVar3 < 0) {
      uVar5 = 0x807;
    }
    else {
      lVar4 = GetPackagesPath();
      uVar3 = Calculate_PathBuffer(memory,0x400,lVar4);
      if ((int)uVar3 < 0) {
        uVar5 = 0x80a;
      }
      else {
        uVar3 = Calculate_PathBuffer(memory,0x400,0x1400701d0);
        if (-1 < (int)uVar3) goto LAB_1400363d6;
        uVar5 = 0x80d;
      }
    }
  }
  else if ((iVar1 == 8) || (iVar1 == 9)) {
    uVar3 = Calculate_PathBuffer(memory,0x400,0x1400701b0);
    if (-1 < (int)uVar3) {
      bstrString = PackagesID();
      uVar3 = Calculate_PathBuffer(memory,0x400,(longlong)bstrString);
      if (-1 < (int)uVar3) goto LAB_1400363d6;
      uVar5 = 0x7f4;
      goto LAB_1400364c8;
    }
    uVar5 = 0x7f0;
  }
  else if (iVar1 == 10) {
    uVar3 = Calculate_PathBuffer(memory,0x400,0x140070210);
    if ((int)uVar3 < 0) {
      uVar5 = 0x831;
    }
    else {
      uVar3 = Calculate_PathBuffer(memory,0x400,DAT_140080158);
      if ((int)uVar3 < 0) {
        uVar5 = 0x834;
      }
      else {
        uVar3 = Calculate_PathBuffer(memory,0x400,0x1400701d0);
        if (-1 < (int)uVar3) goto LAB_1400363d6;
        uVar5 = 0x837;
      }
    }
  }
  else if (iVar1 == 0xb) {
    uVar3 = Calculate_PathBuffer(memory,0x400,0x140070200);
    if ((int)uVar3 < 0) {
      uVar5 = 0x826;
    }
    
     else {
      uVar3 = Calculate_PathBuffer(memory,0x400,DAT_140080158);
      if ((int)uVar3 < 0) {
        uVar5 = 0x829;
      }
      else {
        uVar3 = Calculate_PathBuffer(memory,0x400,0x1400701d0);
        if (-1 < (int)uVar3) goto LAB_1400363d6;
        uVar5 = 0x82c;
      }
    }
  }
  
  else {
    if (iVar1 != 0xc) goto LAB_14003627b;
    uVar3 = Calculate_PathBuffer(memory,0x400,0x140070220);
    if (-1 < (int)uVar3) goto LAB_1400363d6;
    uVar5 = 0x83c;
  }

LAB_140036135:
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Configuration::GetInstanceHash",uVar5);

CleanUp:
  hHeap = GetProcessHeap();
  HeapFree(hHeap,0,memory);
  return uVar3;
}

