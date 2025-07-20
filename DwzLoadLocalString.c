
HRESULT DwzLoadLocalString(UINT UID,LPWSTR buffer,ulonglong MAX_BUFFER)

{
  int success;
  HRESULT error;
  undefined8 error_line;
  
  if (MAX_BUFFER < 0x80000000) {
    success = LoadStringW(hInstance,UID,buffer,(int)MAX_BUFFER);
                    /* return SUCCESS */
    if (0 < success) {
      return 0;
    }
    error = -0x7fc3fef6;
    error_line = 57;
  }
  else {
    error = -0x7ff8fdea;
                    /* Return 0x80070216, which is a standard Windows HRESULT: Buffer size error
                       (too large...) */
    error_line = 53;
  }
  PrintERROR(1,"Dwz ERROR: %s:%d - hr = 0x%08X\n","DwzLoadLocalString",error_line);
  return error;
}

