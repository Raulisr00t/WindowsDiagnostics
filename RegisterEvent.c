void RegisterEvent(void)

{
                    /* Registers an ETW event provider, creating a handle that can be used to write
                       ETW events. */
  if (RegistryHandle == 0) {
    EventRegister((LPCGUID)&ProviderID,EnableCallBack,&RegistryHandle,(PREGHANDLE)&RegistryHandle );
  }

  return;
}
