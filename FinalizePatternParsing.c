
void FinalizePatternParsing(longlong *param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  
  lVar1 = param_1[9];
  uVar2 = RegexParseStep(param_1);
  if ((char)uVar2 == '\0') {
    if (*(int *)((longlong)param_1 + L'|') != L'|') {
      return;
    }
    lVar3 = CreateAndInsertRegexNode((longlong)(param_1 + 8),8);
    CreateWrappedNodeAndInsert((longlong)(param_1 + 8),lVar3);
  }
  plVar5 = param_1 + 8;
  puVar4 = CreateAndLinkNodePair((longlong)plVar5,lVar1);
  while (*(int *)((longlong)param_1 + 0x7c) == 0x7c) {
    HandleEscapeAndAdvanceChar(param_1);
    uVar2 = RegexParseStep(param_1);
    if ((char)uVar2 == '\0') {
      lVar3 = CreateAndInsertRegexNode((longlong)plVar5,8);
      CreateWrappedNodeAndInsert((longlong)plVar5,lVar3);
    }
    FUN_14002429c((longlong)plVar5,lVar1,(longlong)puVar4);
  }
  return;
}

