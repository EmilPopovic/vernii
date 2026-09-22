<!-- markdownlint-disable MD041 -->
[Back to Repository](https://github.com/EmilPopovic/vernii#vernii)
<!-- markdownlint-enable MD041 -->

# Vernii

Vernii is a minimal Linux-capable 32-bit RISC-V SoC built around the [FRISC-V](https://github.com/friscv/friscv-system-hw) core, using [PULP](https://github.com/pulp-platform) and [OpenTitan](https://github.com/lowRISC/opentitan) peripherals. The system (and this documentation) is heavily based on [Cheshire](https://github.com/pulp-platform/cheshire).

Vernii is designed to be an extensible platform for future systems featuring coprocessors and other non-CPU modules, and features coherent manager and subordinate AXI interfaces (similar to the PS on Zynq FPGAs or PULP's Croc). It integrates all supporting modules such system would need, including simple I/O and an integrator-configurable boot process.

Vernii is developed as part of the FERICA project, an initiative by the [Faculty of Electrical Engineering and Computing](https://www.fer.unizg.hr/en), [University of Zagreb](https://www.unizg.hr/homepage/).

## Table of Contents

<!-- markdownlint-disable MD036 -->

**[Getting Started](GETTING_STARTED.md)**

**[Targets](TARGETS.md)**

- [Simulation](SIMULATION.md)
- [Xilinx FPGAs](XILINX_FPGAS.md)
- [SoC Integration](SOC_INTEGRATION,md)

**[User Manual](USER_MANUAL.md)**

- [Architecture](ARCHITECTURE.md)
- [Software Stack](SOFTWARE_STACK.md)

<!-- markdownlint-enable MD036 -->
