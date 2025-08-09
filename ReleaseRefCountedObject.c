
void ReleaseRefCountedObject(longlong *param_1)

{
  int *piVar1;
  
  if (*param_1 != 0) {
    piVar1 = (int *)(*param_1 + 0x2c);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      FreeRefCountedObject((undefined8 *)*param_1,(undefined8 *)0x0);
    }
  }
  *param_1 = 0;
  return;
}

