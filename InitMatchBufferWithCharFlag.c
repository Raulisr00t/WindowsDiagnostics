
undefined8 *
InitMatchBufferWithCharFlag(undefined8 *param_1,undefined8 param_2,char *param_3,undefined8 param _4)

{
  char cVar1;
  int local_res20;
  undefined4 uStackX_24;
  
  cVar1 = *param_3;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  _local_res20 = CONCAT44((int)((ulonglong)param_4 >> 0x20),-(uint)(cVar1 != '\0'));
  FillVectorWithValue(param_1,0,&local_res20);
  param_1[3] = 0;
  return param_1;
}

