
void PointerEncoder(PVOID param_1)

{
  PVOID pvVar1;
  
  if (DAT_14007f408 == 0) {
                    /* WARNING: Subroutine does not return */
    abort();
  }
  pvVar1 = EncodePointer(param_1);
  DAT_14007f408 = DAT_14007f408 + -1;
  *(PVOID *)(&DAT_14007f670 + DAT_14007f408 * 8) = pvVar1;
  return;
}

