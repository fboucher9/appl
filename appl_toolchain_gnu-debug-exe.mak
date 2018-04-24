# See LICENSE for license details

appl-toolchain-gnu-debug-exe-cflags = \
    $(CFLAGS) \
    $(appl-gnu-common-flags) \
    $(appl-gnu-common-cflags) \
    $(appl-gnu-debug-flags) \
    $(appl-gnu-debug-cflags) \
    $(appl-gnu-exe-flags) \
    $(appl-gnu-exe-cflags) \
    -DAPPL_OS_LINUX

appl-toolchain-gnu-debug-exe-cxxflags = \
    $(CXXFLAGS) \
    $(appl-gnu-common-flags) \
    $(appl-gnu-common-cxxflags) \
    $(appl-gnu-debug-flags) \
    $(appl-gnu-debug-cxxflags) \
    $(appl-gnu-exe-flags) \
    $(appl-gnu-exe-cxxflags) \
    -DAPPL_OS_LINUX

define appl-toolchain-gnu-debug-exe-linker
	$(APPL_VERBOSE)echo -o $(1) -rdynamic $(appl-toolchain-gnu-debug-exe-cflags) $(3) $(2) $(foreach x,$(4),$(APPL_LIBRARY-$(x)-gnu-lflags)) > $(1).cmd
	$(APPL_VERBOSE)$(appl-gnu-cc) @$(strip $(1)).cmd
endef

define appl-toolchain-gnu-debug-exe-c-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-gnu-debug-exe-cflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(appl-gnu-cc) @$(strip $(1)).cmd
endef

define appl-toolchain-gnu-debug-exe-cxx-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-gnu-debug-exe-cxxflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(appl-gnu-cxx) @$(strip $(1)).cmd
endef

