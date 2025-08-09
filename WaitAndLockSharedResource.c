
void WaitAndLockSharedResource(int *state)

{
  AcquireSRWLockExclusive((PSRWLOCK)&DAT_14007fd70);
  do {
    if (*state == 0) {
      *state = -1;
LAB_140003859:
                    /* WARNING: Could not recover jumptable at 0x000140003865. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      ReleaseSRWLockExclusive((PSRWLOCK)&DAT_14007fd70);
      return;
    }
    if (*state != -1) {
      *(undefined4 *)
       (*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4) =
           DAT_14007f410;
      goto LAB_140003859;
    }
    SleepConditionVariableSRW
              ((PCONDITION_VARIABLE)&DAT_14007fd78,(PSRWLOCK)&DAT_14007fd70,0xffffffff,0);
  } while( true );
}

