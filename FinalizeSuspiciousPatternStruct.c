
void FinalizeSuspiciousPatternStruct(longlong *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  
  plVar1 = param_1 + 8;
  lVar2 = AllocateNewNode((longlong)plVar1,0);
  FinalizePatternParsing(param_1);
  if (*param_1 != param_1[2]) {
    ThrowRegexException(0xe);
  }
  CreateWrappedNodeAndInsert((longlong)plVar1,lVar2);
  CreateAndInsertRegexNode((longlong)plVar1,0x15);
  lVar2 = *plVar1;
  *(int *)(lVar2 + 0x20) = (int)param_1[0xe];
  *(int *)(lVar2 + 0x28) = (int)param_1[3] + 1;
  return;
}

