# See LICENSE for license details

# Setup mingw toolchain program
APPL_TOOLCHAIN_MINGW_CC ?= x86_64-w64-mingw32-gcc
APPL_TOOLCHAIN_MINGW_CXX ?= x86_64-w64-mingw32-g++

# Setup mingw compiler options
APPL_TOOLCHAIN_MINGW_CFLAGS ?= $(APPL_CFLAGS-gnu)
APPL_TOOLCHAIN_MINGW_CXXFLAGS ?= $(APPL_CXXFLAGS-gnu)

define appl-toolchain-mingwdbg-linker
	@echo linking $(1) with mingw
	$(APPL_VERBOSE)echo -o $(1) $(APPL_TOOLCHAIN_MINGW_CFLAGS) $(3) -DAPPL_OS_WINDOWS -DAPPL_DEBUG $(2) -static $(foreach x,$(4),$(APPL_LIBRARY-$(x)-mingw-lflags)) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_TOOLCHAIN_MINGW_CC) @$(strip $(1)).cmd
endef

define appl-toolchain-mingwdbg-c-compiler
	@echo compiling $(1) with mingw-gcc
	$(APPL_VERBOSE)echo -c -o $(1) $(APPL_TOOLCHAIN_MINGW_CFLAGS) $(3) -DAPPL_OS_WINDOWS -DAPPL_DEBUG -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_TOOLCHAIN_MINGW_CC) @$(strip $(1)).cmd
endef

define appl-toolchain-mingwdbg-cxx-compiler
	@echo compiling $(1) with mingw-g++
	$(APPL_VERBOSE)echo -c -o $(1) $(APPL_TOOLCHAIN_MINGW_CXXFLAGS) $(3) -DAPPL_OS_WINDOWS -DAPPL_DEBUG -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_TOOLCHAIN_MINGW_CXX) @$(strip $(1)).cmd
endef

