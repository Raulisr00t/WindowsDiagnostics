
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
FlagSuspiciousPowerShellPatterns(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  longlong length;
  longlong pattern_struct [4];
  undefined8 local_78 [3];
  undefined8 local_60;
  
  DAT_1400801f0 = 0;
  _DAT_1400801f8 = 0;
  _DAT_140080200 = 0;
  _DAT_140080208 = InitializeLocaleSupport(1);
  length = GetWcharStringLength
                     (
                     L"(.*(invoke-expression|invoke-command|\\$\\([\\b\\s]*iex|\\$\\([\\b\\s]*icm|\\ [char\\]).*)|(^[\\b\\s]*&.*)|(.*;[\\b\\s]*&.*)|(.*(\\[system\\.|\"|\').*)"
                     );
  InitializeSuspiciousPatternStruct
            (pattern_struct,0x1400801f8,param_3,
             (longlong)
             (
             L"(.*(invoke-expression|invoke-command|\\$\\([\\b\\s]*iex|\\$\\([\\b\\s]*icm|\\[char\\] ).*)|(^[\\b\\s]*&.*)|(.*;[\\b\\s]*&.*)|(.*(\\[system\\.|\"|\').*)"
             + length));
  length = FinalizeSuspiciousPatternStruct(pattern_struct);
  if (length != 0) {
    *(int *)(length + 44) = *(int *)(length + 44) + 1;
  }
  ReleaseRefCountedObject(&DAT_1400801f0);
  local_60 = 0;
  DAT_1400801f0 = length;
  Free(local_78);
  return &DAT_1400801f0;
}

