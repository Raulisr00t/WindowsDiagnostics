
uint NormalizeHRESULTToNTStatus(uint param_1)

{
                    /* 0x80070057 E_INVALIDARG 0xC000000D STATUS_INVALID_PARAMETER
                       0x80004005 E_FAIL 0xC0000001 STATUS_UNSUCCESSFUL
                       0x8007000E E_OUTOFMEMORY 0xC0000017 STATUS_NO_MEMORY
                       0x80070002 ERROR_FILE_NOT_FOUND 0xC0000034 STATUS_OBJECT_NAME_NOT_FOUND
                       0x80070003 ERROR_PATH_NOT_FOUND 0xC000003A STATUS_OBJECT_PATH_NOT_FOUND
                       0x8007007E ERROR_MOD_NOT_FOUND 0xC0000135 STATUS_DLL_NOT_FOUND
                       0x80070272 (Win32 error, device not connected) 0xC0000273
                       STATUS_DEVICE_NOT_CONNECTED */
  if ((int)param_1 < -0x7ff8ff15) {
    if (param_1 == 0x800700ea) {
      return 0x80000005;
    }
    if ((int)param_1 < -0x7ff8ffa8) {
      if (param_1 == 0x80070057) {
        return 0xc000000d;
      }
      if (param_1 == 0x80004005) {
        return 0xc0000001;
      }
      if (param_1 == 0x80070001) {
        return 0xc0000002;
      }
      if (param_1 == 0x80070002) {
        return 0xc0000034;
      }
      if (param_1 == 0x80070003) {
        return 0xc000003a;
      }
      if (param_1 == 0x8007000e) {
        return 0xc0000017;
      }
    }
    else {
      if (param_1 == 0x80070070) {
        return 0xc000007f;
      }
      if (param_1 == 0x8007007a) {
        return 0xc0000023;
      }
      if (param_1 == 0x8007007b) {
        return 0xc0000033;
      }
      if (param_1 == 0x8007007e) {
        return 0xc0000135;
      }
    }
  }
  else if ((int)param_1 < -0x7ff8fb81) {
    if (param_1 == 0x8007047e) {
      return 0xc0000059;
    }
    if (param_1 == 0x80070216) {
      return 0xc0000095;
    }
    if (param_1 == 0x8007023e) {
      return 0xc0000025;
    }
    if (param_1 == 0x80070246) {
      return 0xc0000161;
    }
    if (param_1 == 0x80070247) {
      return 0xc0000163;
    }
    if (param_1 == 0x80070272) {
      return 0xc0000273;
    }
  }
  else {
    if (param_1 == 0x8007050c) {
      return 0xc000042b;
    }
    if (param_1 == 0x8007054f) {
      return 0xc00000e5;
    }
    if (param_1 == 0x800705b9) {
      return 0xc000a083;
    }
    if (param_1 == 0) {
      return 0;
    }
  }
  if ((param_1 >> 0x1c & 1) != 0) {
    return param_1 & 0xefffffff;
  }
  if ((param_1 & 0x1fff0000) == 0x70000) {
    if ((param_1 & 0xffff) != 0) {
      return param_1 & 0xffff | 0xc0070000;
    }
    return 0;
  }
  if ((param_1 & 0x1fff0000) != 0x90000) {
    return 0xc00000e5;
  }
  if (0 < (int)param_1) {
    return param_1 & 0xffff | 0xc0090000;
  }
  return param_1;
}

