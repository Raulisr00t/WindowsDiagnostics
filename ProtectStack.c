
void ProtectStack(longlong failure)

{
  if ((failure == DAT_14007f440) && ((short)((ulonglong)failure >> 0x30) == 0)) {
    return;
  }
  TriggerSecurityFailure(failure);
  return;
}

