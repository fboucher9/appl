# See LICENSE for license details

appl-toolchain-gnudbg32-cflags = \
    $(CFLAGS) \
    $(appl-gnu-common-flags) \
    $(appl-gnu-common-cflags) \
    $(appl-gnu-debug-flags) \
    $(appl-gnu-debug-cflags) \
    -DAPPL_OS_LINUX

appl-toolchain-gnudbg32-cxxflags = \
    $(CXXFLAGS) \
    $(appl-gnu-common-flags) \
    $(appl-gnu-common-cxxflags) \
    $(appl-gnu-debug-flags) \
    $(appl-gnu-debug-cxxflags) \
    -DAPPL_OS_LINUX

define appl-toolchain-gnudbg32-linker
	$(APPL_VERBOSE)echo -o $(1) -m32 -rdynamic $(appl-toolchain-gnudbg32-cflags) $(3) $(2) $(foreach x,$(4),$(APPL_LIBRARY-$(x)-gnu-lflags)) > $(1).cmd
	$(APPL_VERBOSE)$(appl-gnu-cc) @$(strip $(1)).cmd
endef

define appl-toolchain-gnudbg32-c-compiler
	$(APPL_VERBOSE)echo -c -o $(1) -m32 $(appl-toolchain-gnudbg32-cflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(appl-gnu-cc) @$(strip $(1)).cmd
endef

define appl-toolchain-gnudbg32-cxx-compiler
	$(APPL_VERBOSE)echo -c -o $(1) -m32 $(appl-toolchain-gnudbg32-cxxflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(appl-gnu-cxx) @$(strip $(1)).cmd
endef

