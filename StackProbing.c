
void StackProbing(void)

{
  undefined1 *in_RAX;
  undefined1 *puVar1;
  void *pvVar2;
  undefined1 local_res8 [32];
  
  puVar1 = local_res8 + -(longlong)in_RAX;
  if (local_res8 < in_RAX) {
    puVar1 = (undefined1 *)0x0;
  }
  if (puVar1 < StackLimit) {
    pvVar2 = StackLimit;
    do {
      pvVar2 = (void *)((longlong)pvVar2 - 0x1000);
    } while ((void *)((ulonglong)puVar1 & 0xfffffffffffff000) < pvVar2);
  }
  return;
}

