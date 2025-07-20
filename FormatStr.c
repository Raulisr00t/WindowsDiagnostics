
HRESULT FormatStr(char *buffer,undefined8 unused_param,char *format,va_list args)

{
  uint writtenchars;
  HRESULT result;
  
  writtenchars = _vsnprintf(buffer,1023,format,args);
  if (((int)writtenchars < 0) || (1023 < writtenchars)) {
                    /* Force null-termination */
    buffer[1023] = '\0';
                    /* HRESULT for ERROR_INSUFFICIENT_BUFFER */
    result = -0x7ff8ff86;
  }
  else {
    result = 0;
    if (writtenchars == 1023) {
      buffer[1023] = '\0';
      result = 0;
    }
  }
  return result;
}

