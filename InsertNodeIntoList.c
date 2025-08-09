
longlong InsertNodeIntoList(longlong param_1,longlong param_2)

{
  longlong lVar1;
  
  *(undefined8 *)(param_2 + 0x18) = *(undefined8 *)(param_1 + 8);
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 8) + 0x10);
  if (lVar1 != 0) {
    *(longlong *)(param_2 + 0x10) = lVar1;
    *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x10) + 0x18) = param_2;
  }
  *(longlong *)(*(longlong *)(param_1 + 8) + 0x10) = param_2;
  *(longlong *)(param_1 + 8) = param_2;
  return param_2;
}

