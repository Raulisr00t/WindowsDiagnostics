
void HandleEscapeAndAdvanceChar(longlong *arr)

{
  char cVar1;
  short *psVar2;
  short *psVar3;
  
  psVar2 = (short *)*arr;
  if (psVar2 != (short *)arr[2]) {
    psVar3 = psVar2;
    if (*psVar2 == L'\\') {
      cVar1 = CheckEscapeSequence(arr);
      if (cVar1 != '\0') {
        psVar3 = psVar2 + 1;
      }
    }
    *arr = (longlong)(psVar3 + 1);
  }
  UpdateCurrentCharAndValidate(arr);
  return;
}

