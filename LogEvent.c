void LogEvent(REGHANDLE *reghandle,PCEVENT_DESCRIPTOR EventDescriptor,undefined8 activityid,
             ULONG UserDataCount,PEVENT_DATA_DESCRIPTOR evnt)

{
  ushort *puVar1;
  uint uVar2;
  uint uVar3;
  
  puVar1 = (ushort *)reghandle[1];
  uVar3 = 0;
  if (puVar1 == (ushort *)0x0) {
    evnt->Ptr = 0;
    uVar2 = uVar3;
  }
  else {
    evnt->Ptr = (ULONGLONG)puVar1;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  evnt->Size = uVar3;
  evnt->Reserved = uVar2;
  
  EventWriteTransfer(*reghandle,EventDescriptor,(LPCGUID)0x0,(LPCGUID)0x0,UserDataCount,evnt); // Writes an ETW event with an activity ID and an optional related activity ID.
 
  return;
}
