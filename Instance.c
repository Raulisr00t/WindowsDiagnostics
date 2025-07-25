
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

HRESULT Instance(longlong *OutInstance)

{
  HRESULT hResult;
  longlong *plVar1;
  longlong *plVar2;
  undefined8 uVar3;
  longlong *XmlDoc;
  longlong *local_res18;
  
  plVar2 = (longlong *)0x0;
  hResult = 0;
  XmlDoc = (longlong *)0x0;
                    /* Create initial XML: <Packages /> */
  plVar1 = DAT_140080138;
  if (DAT_140080138 == (longlong *)0x0) {
    hResult = XmlCreate(L"<Packages />",&XmlDoc);
    if (hResult < 0) {
      uVar3 = 0x6f;
    }
    else {
                    /* Allocate 16 bytes for AnswersManager struct (or wrapper) */
      plVar1 = (longlong *)MemoryAllocate(16);
      plVar2 = XmlDoc;
      local_res18 = plVar1;
      if (plVar1 != (longlong *)0x0) {
        *plVar1 = 0;
        plVar1[1] = 0;
        if (plVar1 != (longlong *)0x0) {
          *plVar1 = (longlong)XmlDoc;
          (**(code **)(*XmlDoc + 8))(XmlDoc);
          hResult = AddPackageID(plVar1);
          if (hResult < 0) {
            PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Answers::Instance",0x78);
            FUN_140033640(plVar1);
            goto Error;
          }
          goto CleanUp;
        }
      }
      hResult = -0x7ff8fff2;
      uVar3 = 0x72;
    }
    PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","Answers::Instance",uVar3);
    plVar2 = XmlDoc;
  }
  else {
CleanUp:
    DAT_140080138 = plVar1;
    *OutInstance = (longlong)DAT_140080138;
  }
Error:
  if (plVar2 != (longlong *)0x0) {
    (**(code **)(*plVar2 + 0x10))(plVar2);
  }

  return hResult;
}

