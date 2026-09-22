<!-- markdownlint-disable MD041 -->
[Home](DOCS_HOME.md)
<!-- markdownlint-enable MD041 -->

# Getting Started

We first discuss Vernii's project structure, its dependencies, and how to build it

## Repository Structure

Directory | Description | Documentation
--------- | ----------- | -------------
`docs/` | Documentation |
`rtl/` | SystemVerilog RTL sources |
`sw` | Software stack, SDK, build setup |
`target` | Verilator simulation, Xilinx FPGA target setups |
`verif` | Setup for verification with directed and compliance tests |

## Dependencies

This project uses Nix for dependency management and provides an automatic setup script which installs Nix (if not already installed), together with all other required tools. Only Linux is supported, use WSL if on Windows.

**Tools you should have installed:**

- `curl` for bootstrapping Nix
- `direnv` for automatic environment activation (optional, recommended)
- `python3` for various scripts
- Vivado 2025.2 for Xilinx targets (optional)

**First-time setup:**

After cloning the repo, run `./setup.sh` and restart your terminal after Nix finishes setting up the tools. No other installations should be necessary.

If using `direnv`, run `direnv allow` in the project root to automatically activate the Nix environment.

## Building Vernii

TODO

## Targets

A target is an end use of Vernii. Each target requires different steps from here. Read the page for your desired target in the [Targets](TARGETS.md) chapter.
