void CheckTimeTIDPID(void)

{
  DWORD PID;
  _FILETIME time;
  LARGE_INTEGER local_res10;
  _FILETIME out_time;
  
  out_time.dwLowDateTime = 0;
  out_time.dwHighDateTime = 0;
  local_res10.QuadPart = 0;
  if (DAT_14007f440 == 0x2b992ddfa232) {
                    /* Retrieves the current system date and time. The information is in Coordinated
                       Universal Time (UTC) format. */
    GetSystemTimeAsFileTime(&out_time);
    time = out_time;
    PID = GetCurrentProcessId();
    time = (_FILETIME)((ulonglong)time ^ (ulonglong)PID);
    PID = GetCurrentThreadId();
    time = (_FILETIME)((ulonglong)time ^ (ulonglong)PID);
    PID = GetTickCount();
    time = (_FILETIME)((ulonglong)time ^ (ulonglong)PID << 0x18);
    PID = GetTickCount(); // GetTickCount
    time = (_FILETIME)((ulonglong)PID ^ (ulonglong)time ^ (ulonglong)&time);
    QueryPerformanceCounter(&local_res10);
    DAT_14007f440 =
         (local_res10.QuadPart << 0x20 ^ local_res10.QuadPart ^ (ulonglong)time) & 0xffffffffffff ;
    if (DAT_14007f440 == 0x2b992ddfa232) {
      DAT_14007f440 = 0x2b992ddfa233;
    }
  }
  DAT_14007f480 = ~DAT_14007f440;
  return;
}
