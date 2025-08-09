
void ThrowVectorTooLongException(char *param_1)

{
  exception local_28 [40];
  
  ExceptionHandle(local_28,param_1);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_28,(ThrowInfo *)&DAT_140079288);
}

