# See LICENSE for license details

appl-toolchain-gnu-debug-lib-c-flags = \
    $(CFLAGS) \
    $(appl-gnu-common-flags) \
    $(appl-gnu-common-cflags) \
    $(appl-gnu-debug-flags) \
    $(appl-gnu-debug-cflags) \
    $(appl-gnu-lib-flags) \
    $(appl-gnu-lib-cflags) \
    -DAPPL_OS_LINUX

appl-toolchain-gnu-debug-lib-cxx-flags = \
    $(CXXFLAGS) \
    $(appl-gnu-common-flags) \
    $(appl-gnu-common-cxxflags) \
    $(appl-gnu-debug-flags) \
    $(appl-gnu-debug-cxxflags) \
    $(appl-gnu-lib-flags) \
    $(appl-gnu-lib-cxxflags) \
    -DAPPL_OS_LINUX

define appl-toolchain-gnu-debug-lib-linker
	$(APPL_VERBOSE)$(appl-gnu-ar) cr $(1) $(2)
endef

define appl-toolchain-gnu-debug-lib-c-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-gnu-debug-lib-c-flags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(appl-gnu-cc) @$(strip $(1)).cmd
endef

define appl-toolchain-gnu-debug-lib-cxx-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-gnu-debug-lib-cxx-flags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(appl-gnu-cxx) @$(strip $(1)).cmd
endef

