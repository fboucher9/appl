# See LICENSE for license details

appl-toolchain-gnu-release-exe-cflags = \
    $(CFLAGS) \
    $(appl-gnu-common-flags) \
    $(appl-gnu-common-cflags) \
    $(appl-gnu-release-flags) \
    $(appl-gnu-release-cflags) \
    $(appl-gnu-exe-flags) \
    $(appl-gnu-exe-cflags) \
    -DAPPL_OS_LINUX

appl-toolchain-gnu-release-exe-cxxflags = \
    $(CXXFLAGS) \
    $(appl-gnu-common-flags) \
    $(appl-gnu-common-cxxflags) \
    $(appl-gnu-release-flags) \
    $(appl-gnu-release-cxxflags) \
    $(appl-gnu-exe-flags) \
    $(appl-gnu-exe-cxxflags) \
    -DAPPL_OS_LINUX

define appl-toolchain-gnu-release-exe-linker
	$(APPL_VERBOSE)echo -o $(1) $(appl-toolchain-gnu-release-exe-cflags) $(3) $(2) $(foreach x,$(4),$(APPL_LIBRARY-$(x)-gnu-lflags)) > $(1).cmd
	$(APPL_VERBOSE)$(appl-gnu-cc) @$(strip $(1)).cmd
endef

define appl-toolchain-gnu-release-exe-c-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-gnu-release-exe-cflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(appl-gnu-cc) @$(strip $(1)).cmd
endef

define appl-toolchain-gnu-release-exe-cxx-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-gnu-release-exe-cxxflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(appl-gnu-cxx) @$(strip $(1)).cmd
endef

