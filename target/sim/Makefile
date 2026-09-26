SOC_SRAM_BASE ?= 0
SOC_SRAM_SIZE_BYTES ?= 8192
SOC_MEM_SIZE ?= 16777216
SOC_OCM_ONLY ?= 0

SOC_TOP = vernii_soc_sim
SOC_DIR ?= obj_dir_soc
SOC_BIN = $(SOC_DIR)/vernii_soc
SOC_CPP = $(wildcard cpp/*.cpp)

sources.f: ../../Bender.yml ../../Bender.lock $(wildcard rtl/*.sv)
	bender script flist-plus -t rtl -t synthesis > $@
	sed -i '\|/opentitan_peripherals-[^/]*/src/spi_host/rtl/|d' $@
	sed -i '\|/obi_peripherals-[^/]*/hw/obi_uart/|d' $@
	echo "$(CURDIR)/rtl/vernii_soc_sim.sv" >> $@

$(SOC_DIR):
	mkdir -p $@

soc: sources.f | $(SOC_DIR)
	verilator --cc --exe --build --timescale 1ns/1ps -j 0 --top-module $(SOC_TOP) -Wno-fatal \
		+define+ASSERTS_OFF \
		-GOcmBase=$(SOC_SRAM_BASE) -GOcmSize=$(SOC_SRAM_SIZE_BYTES) \
		-GExtSize=$(SOC_MEM_SIZE) -GOcmOnly=$(SOC_OCM_ONLY) $(SOC_PARAMS) \
		-CFLAGS -DVERNII_SOC_SRAM_BASE=$(SOC_SRAM_BASE) \
		-CFLAGS -DVERNII_SOC_SRAM_SIZE_BYTES=$(SOC_SRAM_SIZE_BYTES) \
		-CFLAGS -DVERNII_SOC_OCM_ONLY=$(SOC_OCM_ONLY) \
		--Mdir $(SOC_DIR) -f sources.f $(SOC_CPP) -o vernii_soc

jtag: soc
	@test -n "$(ELF)" || { echo "usage: make jtag ELF=<program.elf>" >&2; exit 1; }
	$(SOC_BIN) load "$(ELF)"

debug: soc
	@set -eu; \
	$(SOC_BIN) server & \
	sim_pid=$$!; \
	trap 'kill $$sim_pid 2>/dev/null || true; wait $$sim_pid 2>/dev/null || true' EXIT INT TERM; \
	openocd -f openocd.cfg

clean:
	rm -rf $(SOC_DIR) sources.f

all: soc

.PHONY: all soc jtag debug clean
