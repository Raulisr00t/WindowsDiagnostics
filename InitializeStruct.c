
undefined8 * InitializeStruct(undefined8 *objectptr)

{
  objectptr[0x18] = 0x37;
  objectptr[0xc] = 0;
  objectptr[0xd] = 0;
  objectptr[0xe] = 0;
  objectptr[0x1b] = 0;
  objectptr[0x11] = 0;
  objectptr[0x12] = 0;
  objectptr[0x10] = 0;
  objectptr[0xf] = 0;
                    /* MyStruct* InitializeMyStruct(MyStruct* obj)
                       {
                           obj->field_C0 = 0x37;
                       
                           obj->field_60 = 0;
                           obj->field_68 = 0;
                           obj->field_70 = 0;
                           obj->field_D8 = 0;
                           obj->field_88 = 0;
                           obj->field_90 = 0;
                           obj->field_80 = 0;
                           obj->field_78 = 0;
                           obj->field_E0 = 0;
                           obj->field_E8 = 0;
                           obj->field_98 = 0;
                           obj->field_A8 = 0;
                           obj->field_F0 = 0;
                           obj->field_B0 = 0;
                           obj->field_F8 = 0;
                           obj->field_A0 = 0;
                           obj->field_100 = 0;
                           obj->field_B8 = 0;
                           obj->field_C8 = 0;
                           obj->field_110 = 0;
                       
                           obj->field_00 = 0;
                           obj->field_28 = 0;
                           obj->field_18 = 0;
                           obj->field_D0 = 0;
                       
                           obj->field_108 = 0;
                           obj->field_20 = 0;
                           obj->field_30 = 0;
                           obj->field_08 = 0;
                           obj->field_10 = 0;
                       
                           *(uint64_t *)((char *)obj + 0x4C) = 0;  // unknown pointer field
                           obj->field_38 = 0;
                           *(uint64_t *)((char *)obj + 0x44) = 0;
                           *(uint32_t *)((char *)obj + 0x54) = 0;
                       
                           *(uint32_t *)(&obj->field_40) = 1;      // flag_B
                           *(uint32_t *)((char *)obj + 0x5C) = 1;  // some internal flag
                           *(uint32_t *)(&obj->field_48) = 1;      // flag_A
                       
                           return obj;
                       }
                        */
  objectptr[0x1c] = 0;
  objectptr[0x1d] = 0;
  objectptr[0x13] = 0;
  objectptr[0x15] = 0;
  objectptr[0x1e] = 0;
  objectptr[0x16] = 0;
  objectptr[0x1f] = 0;
  objectptr[0x14] = 0;
  objectptr[0x20] = 0;
  objectptr[0x17] = 0;
  objectptr[0x19] = 0;
  objectptr[0x22] = 0;
  *objectptr = 0;
  objectptr[5] = 0;
  objectptr[3] = 0;
  objectptr[0x1a] = 0;
  *(undefined4 *)(objectptr + 0x21) = 0;
  objectptr[4] = 0;
  objectptr[6] = 0;
  objectptr[1] = 0;
  objectptr[2] = 0;
  *(undefined8 *)((longlong)objectptr + 0x4c) = 0;
  objectptr[7] = 0;
  *(undefined8 *)((longlong)objectptr + 0x44) = 0;
  *(undefined4 *)((longlong)objectptr + 0x54) = 0;
  *(undefined4 *)(objectptr + 0xb) = 1;
  *(undefined4 *)((longlong)objectptr + 0x5c) = 1;
  *(undefined4 *)(objectptr + 8) = 1;
 
  return objectptr;
}

