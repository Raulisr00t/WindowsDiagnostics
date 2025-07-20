
void ReplaceHeapBuffer(undefined8 unused,undefined8 new_buffer)

{
  longlong lVar1;
  HANDLE hHeap;
  LPVOID Memory;
  
  lVar1 = maybe_everything;
  Memory = *(LPVOID *)(maybe_everything + 96);
  if (Memory != (LPVOID)0x0) {
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,Memory);
  }
  *(undefined8 *)(lVar1 + 96) = new_buffer;
  return;
}

