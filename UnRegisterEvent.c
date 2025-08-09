
ULONG UnRegisterEvent(void)

{
  ULONG UVar1;
  
  if (RegistryHandle == 0) {
    UVar1 = 0;
  }
  else {
    UVar1 = EventUnregister(RegistryHandle);
    RegistryHandle = 0;
  }
  return UVar1;
}

