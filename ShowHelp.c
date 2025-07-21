
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

HRESULT ShowHelp(OLECHAR *protocol_url)

{
  int hresult;
  BSTR bstrUrl;
  undefined8 ErrorLine;
  longlong *help_com_interface;
  
  help_com_interface = (longlong *)0x0;
                    /* Create COM instance (probably IWebBrowser or custom HelpViewer) */
  bstrUrl = (BSTR)0x0;
  hresult = CoCreateInstance((IID *)&DAT_140071118,(LPUNKNOWN)0x0,1,(IID *)&DAT_140071128,
                             &help_com_interface);
  if (hresult < 0) {
    ErrorLine = 0x16d;
  }
  else {
    bstrUrl = SysAllocString(protocol_url);
    if (bstrUrl == (BSTR)0x0) {
                    /* E_OUTOFMEMORY */
      hresult = -0x7ff8fff2;
      ErrorLine = 0x170;
    }
    else {
      hresult = (**(code **)(*help_com_interface + 0x18))(help_com_interface,bstrUrl);
      if (-1 < hresult) goto Free;
      ErrorLine = 0x173;
    }
  }
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","ShowHelp",ErrorLine);

Free:
  if (help_com_interface != (longlong *)0x0) {
    (**(code **)(*help_com_interface + 0x10))();
    help_com_interface = (longlong *)0x0;
  }
  if (bstrUrl != (BSTR)0x0) {
    SysFreeString(bstrUrl);
  }
  return hresult;
}

