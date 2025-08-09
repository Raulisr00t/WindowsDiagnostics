
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FreeRefCountedObject(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  
  if (param_1 != param_2) {
    do {
      if (param_1 == (undefined8 *)0x0) {
        return;
      }
      puVar1 = (undefined8 *)param_1[2];
      param_1[2] = 0;
      (**(code **)*param_1)(param_1,1);
      param_1 = puVar1;
    } while (puVar1 != param_2);
  }
  return;
}

