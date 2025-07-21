
TaskPage * InitTaskPage(TaskPage *page,undefined4 task_id,undefined8 buffer,undefined8 memory)

{
  InitializeTaskPageInternals(page);
  *(undefined4 *)(page + 0x80) = task_id;
  *(undefined ***)page = &PTR_OnListenerAttach_140067630;
  *(undefined ***)(page + 8) = &PTR_CreateDUICP_1400655e0;
  *(undefined8 *)(page + 0x70) = memory;
  *(undefined8 *)(page + 0x78) = buffer;
  return page;
}

