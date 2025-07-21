
void Free?(undefined8 unused,undefined8 result)

{
  LPVOID lpMem;
  longlong lVar1;
  HANDLE hHeap;
  
  lVar1 = maybe_everything;
  lpMem = *(LPVOID *)(maybe_everything + 152);
  if (lpMem != (LPVOID)0x0) {
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,lpMem);
  }
  *(undefined8 *)(lVar1 + 152) = result;
  return;
}

