
void UpdateBitVector(longlong *bitVectorStruct,ulonglong newBitCount)

{
  longlong lVar1;
  uint *puVar2;
  ulonglong uVar3;
  undefined8 local_res10;
  
  uVar3 = newBitCount + 0x1f >> 5;
  lVar1 = uVar3 * 4;
  if (uVar3 < (ulonglong)(bitVectorStruct[1] - *bitVectorStruct >> 2)) {
    MoveAndUpdateBitVectorRange
              (bitVectorStruct,&local_res10,(void *)(*bitVectorStruct + lVar1),
               (void *)bitVectorStruct[1]);
  }
  bitVectorStruct[3] = newBitCount;
  if ((newBitCount & 0x1f) != 0) {
    puVar2 = (uint *)(lVar1 + -4 + *bitVectorStruct);
    *puVar2 = *puVar2 & (1 << ((byte)newBitCount & 0x1f)) - 1U;
  }
  return;
}

