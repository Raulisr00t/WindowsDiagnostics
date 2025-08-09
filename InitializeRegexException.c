
exception * InitializeRegexException(exception *param_1,error_type param_2)

{
  exception *local_res8;
  
  local_res8 = param_1;
  local_res8 = (exception *)std::regex_error::_Stringify(param_2);
  exception::exception(param_1,(char **)&local_res8);
  *(error_type *)(param_1 + 0x18) = param_2;
  *(undefined ***)param_1 = &PTR_FUN_140064010;
  return param_1;
}

