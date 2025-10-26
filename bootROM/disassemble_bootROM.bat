@echo off

riscv64-unknown-elf-objcopy -I binary -O elf32-littleriscv bootROM.bin bootROM.o

riscv64-unknown-elf-ld -T bootROM.ld bootROM.o -o bootROM.elf

py patch_symbols_in_elf_file.py

::riscv64-unknown-elf-readelf -WhSs bootROM.elf

riscv64-unknown-elf-objdump -D --wide bootROM.elf > bootROM.dis

::riscv64-unknown-elf-readelf -s bootROM.elf

del *.o

pause