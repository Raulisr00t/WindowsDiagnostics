
exception * CreateBadAllocationExceptionObject(exception *param_1)

{
  char *local_res8 [4];
  
  local_res8[0] = "bad allocation";
  exception::exception(param_1,local_res8,1);
  *(undefined ***)param_1 = &PTR_`scalar_deleting_destructor'_140064000;
  return param_1;
}

