# Bare Metal BL602 Project

This repository contains a fully manually-written bare-metal project for the BL602 single-core RISC-V (SiFive E24), without using Bouffalo Lab's SDK.

It features a clear and easy-to-understand implementation in C11 and assembly, with a build system based on GNU Make, making this project both fun and educational.

This repository provides valuable insight into starting a bare-metal BL602 project.

## Features

- Manually-written startup code
- Interrupt vector table implementation using CLIC vectored mode
- 2 Hz LED blinking via timer interrupt

## Application Details

The BL602's boot ROM jumps to the application's entry point with the PLL configured to 160 MHz and the RTC clock set to 10 MHz (feeding the RISC-V's mtime timer).

The low-level boot process begins on Hart0 and performs the following steps:

- Sets up both exception and interrupt vector tables using CLIC vectored mode
- Enables interrupts
- Sets up the runtime environment for C/C++
- Jumps to the main() function and configures a timer interrupt at 2 Hz

An LED connected to the IO4 pin toggles every 500 ms.

## Building the Application

To build the project, you need to have the RISC-V GCC compiler (`riscv64-unknown-elf`) installed, with support for the SiFive E24 core.

Run the following commands:

```sh
cd ./Build
./Rebuild.sh
```

The build process generates the following artifacts in the `Output` directory:

- ELF file
- HEX file
- Binary image
- Assembly listing
- Symbols listing

## Flashing the Application

To flash the application's binary image, boot the BL602 with IO8 set to high.

Then run the following commands:

```sh
cd ./Build
./Flash.sh
```

After flashing, set IO8 to low and reset the target to start the application's execution.