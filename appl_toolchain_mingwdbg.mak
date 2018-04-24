# See LICENSE for license details

# Setup mingw toolchain program
APPL_TOOLCHAIN_MINGW_CC ?= x86_64-w64-mingw32-gcc
APPL_TOOLCHAIN_MINGW_CXX ?= x86_64-w64-mingw32-g++

# Setup mingw compiler options
APPL_TOOLCHAIN_MINGW_CFLAGS = \
    $(appl-gnu-common-flags) \
    $(appl-gnu-common-cflags) \
    $(appl-gnu-debug-flags) \
    $(appl-gnu-debug-cflags) \
    -DAPPL_OS_WINDOWS

APPL_TOOLCHAIN_MINGW_CXXFLAGS = \
    $(appl-gnu-common-flags) \
    $(appl-gnu-common-cxxflags) \
    $(appl-gnu-debug-flags) \
    $(appl-gnu-debug-cxxflags) \
    -DAPPL_OS_WINDOWS

define appl-toolchain-mingwdbg-linker
	$(APPL_VERBOSE)echo -o $(1) $(APPL_TOOLCHAIN_MINGW_CFLAGS) $(3) $(2) -static $(foreach x,$(4),$(APPL_LIBRARY-$(x)-mingw-lflags)) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_TOOLCHAIN_MINGW_CC) @$(strip $(1)).cmd
endef

define appl-toolchain-mingwdbg-c-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(APPL_TOOLCHAIN_MINGW_CFLAGS) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_TOOLCHAIN_MINGW_CC) @$(strip $(1)).cmd
endef

define appl-toolchain-mingwdbg-cxx-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(APPL_TOOLCHAIN_MINGW_CXXFLAGS) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_TOOLCHAIN_MINGW_CXX) @$(strip $(1)).cmd
endef

