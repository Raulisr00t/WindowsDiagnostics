
void * MemoryAllocate(size_t buff_size)

{
  int result;
  void *ptr;
  
  do {
    ptr = malloc(buff_size);
    if (ptr != (void *)0x0) {
      return ptr;
    }
    result = _callnewh(buff_size);
  } while (result != 0);
  return (void *)0x0;
}

