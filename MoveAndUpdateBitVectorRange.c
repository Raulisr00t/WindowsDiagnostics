
undefined8 *
MoveAndUpdateBitVectorRange(longlong *param_1,undefined8 *param_2,void *param_3,void *param_4)

{
  longlong *plVar1;
  size_t _Size;
  void *pvVar2;
  
  pvVar2 = (void *)*param_1;
  plVar1 = param_1 + 1;
  if ((param_3 != pvVar2) || (param_4 != (void *)*plVar1)) {
    if (param_3 == param_4) goto LAB_140026470;
    _Size = (*plVar1 - (longlong)param_4 >> 2) * 4;
    memmove(param_3,param_4,_Size);
    pvVar2 = (void *)(_Size + (longlong)param_3);
  }
  *plVar1 = (longlong)pvVar2;
LAB_140026470:
  *param_2 = param_3;
  return param_2;
}

