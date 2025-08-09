
exception * ExceptionHandle(exception *param_1,char *param_2)

{
  char *local_res8 [4];
  
  local_res8[0] = param_2;
  exception::exception(param_1,local_res8);
  *(undefined ***)param_1 = &PTR_FUN_140064010;
  return param_1;
}

