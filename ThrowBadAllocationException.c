
void ThrowBadAllocationException(void)

{
  exception local_28 [40];
  
  CreateBadAllocationExceptionObject(local_28);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_28,(ThrowInfo *)&DAT_140079200);
}

