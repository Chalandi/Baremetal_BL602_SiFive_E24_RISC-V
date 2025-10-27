#######################################################################################################################################
# This script calculates the size of the binary image (extracted from the ELF file and merged with "boot_header.bin" on top of it) 
#   and patches the boot header with the image size at offset 0x78.
#######################################################################################################################################
import sys
import struct

if len(sys.argv) != 2:
    sys.exit(1)

filename = sys.argv[1]

with open(filename, "r+b") as f:
    f.seek(0, 2)
    filesize = f.tell()
    boot_header_size = 0x2000
    value = filesize - boot_header_size
    if value < 0:
        value = 0
    # Write 32-bit little-endian at offset 0x78
    f.seek(0x78)
    f.write(struct.pack("<I", value))
