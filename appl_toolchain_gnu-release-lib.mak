# See LICENSE for license details

appl-toolchain-gnu-release-lib-cflags = \
    $(CFLAGS) \
    $(appl-gnu-common-flags) \
    $(appl-gnu-common-cflags) \
    $(appl-gnu-release-flags) \
    $(appl-gnu-release-cflags) \
    $(appl-gnu-lib-flags) \
    $(appl-gnu-lib-cflags) \
    -DAPPL_OS_LINUX

appl-toolchain-gnu-release-lib-cxxflags = \
    $(CXXFLAGS) \
    $(appl-gnu-common-flags) \
    $(appl-gnu-common-cxxflags) \
    $(appl-gnu-release-flags) \
    $(appl-gnu-release-cxxflags) \
    $(appl-gnu-lib-flags) \
    $(appl-gnu-lib-cxxflags) \
    -DAPPL_OS_LINUX

define appl-toolchain-gnu-release-lib-linker
	$(APPL_VERBOSE)$(appl-gnu-ar) cr $(1) $(2)
endef

define appl-toolchain-gnu-release-lib-c-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-gnu-release-lib-cflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(appl-gnu-cc) @$(strip $(1)).cmd
endef

define appl-toolchain-gnu-release-lib-cxx-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-gnu-release-lib-cxxflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(appl-gnu-cxx) @$(strip $(1)).cmd
endef

