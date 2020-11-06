/* Entry Point */
ENTRY(reset_handler)

MEMORY {
  FLASH (rx)      : ORIGIN = 0x08000000, LENGTH = 512K
  RAM (xrw)       : ORIGIN = 0x20000000, LENGTH = 96K
}

/* end of RAM */
_estack = 0x20017FFF;

/*
SECTIONS {
  . = 0x08000000;
  .text : {
    * (.text);
  }
  flash_sdata = .;

  . = 0x20000000;
  ram_sdata = .;
  .data : AT (flash_sdata) {
    * (.data);
  }
  ram_edata = .;
  data_size = ram_edata - ram_sdata;
}
*/

SECTIONS
{
    . = 0x08000000;

    .text : 
    { 
        *(.text)     
    }
    .rodata : 
    {
        *(.rodata) 
    }
    _DATA_ROM_START = .;

    . = 0x20000000;   

    _DATA_RAM_START = .;
    .data : AT(_DATA_ROM_START) 
    {
        *(.data) 
    }
    _DATA_RAM_END = _estack;

    _BSS_START = .;
    .bss :
    {
        *(.bss)
    }
    _BSS_END = .;  
}