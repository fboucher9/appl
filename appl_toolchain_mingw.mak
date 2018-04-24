# See LICENSE for license details

# Setup mingw toolchain program
APPL_TOOLCHAIN_MINGW_CC ?= x86_64-w64-mingw32-gcc
APPL_TOOLCHAIN_MINGW_CXX ?= x86_64-w64-mingw32-g++

# Setup mingw compiler options
APPL_TOOLCHAIN_MINGW_CFLAGS = \
    $(appl-gnu-common-flags) \
    $(appl-gnu-common-cflags) \
    $(appl-gnu-release-flags) \
    $(appl-gnu-release-cflags) \
    $(appl-gnu-exe-flags) \
    $(appl-gnu-exe-cflags) \

APPL_TOOLCHAIN_MINGW_CXXFLAGS = \
    $(appl-gnu-common-flags) \
    $(appl-gnu-common-cxxflags) \
    $(appl-gnu-release-flags) \
    $(appl-gnu-release-cxxflags) \
    $(appl-gnu-exe-flags) \
    $(appl-gnu-exe-cxxflags)

define appl-toolchain-mingw-linker
	$(APPL_VERBOSE)echo -o $(1) $(APPL_TOOLCHAIN_MINGW_CFLAGS) $(3) $(2) -static $(foreach x,$(4),$(APPL_LIBRARY-$(x)-mingw-lflags)) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_TOOLCHAIN_MINGW_CC) @$(strip $(1)).cmd
endef

define appl-toolchain-mingw-c-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(APPL_TOOLCHAIN_MINGW_CFLAGS) $(3) -DAPPL_OS_WINDOWS -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_TOOLCHAIN_MINGW_CC) @$(strip $(1)).cmd
endef

define appl-toolchain-mingw-cxx-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(APPL_TOOLCHAIN_MINGW_CXXFLAGS) $(3) -DAPPL_OS_WINDOWS -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_TOOLCHAIN_MINGW_CXX) @$(strip $(1)).cmd
endef

