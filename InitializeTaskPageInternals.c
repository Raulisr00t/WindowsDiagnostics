
TaskPage * InitializeTaskPageInternals(TaskPage *page)

{
  DirectUI::TaskPage::TaskPage(page);
  *(undefined ***)page = &PTR_OnListenerAttach_1400655f8;
  *(undefined ***)(page + 8) = &PTR_CreateDUICP_1400655e0;
  *(undefined8 *)(page + 0x68) = 0;
  FUN_14000d2dc((undefined8 *)(page + 0x68));
  *(undefined8 *)(page + 0x58) = 0;
  *(undefined8 *)(page + 0x60) = 0;
  *(undefined4 *)(page + 0x50) = 0x37;
  return page;
}

