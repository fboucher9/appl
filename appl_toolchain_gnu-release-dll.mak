# See LICENSE for license details

appl-toolchain-gnu-release-dll-cflags = \
    $(CFLAGS) \
    $(appl-gnu-common-flags) \
    $(appl-gnu-common-cflags) \
    $(appl-gnu-release-flags) \
    $(appl-gnu-release-cflags) \
    $(appl-gnu-dll-flags) \
    $(appl-gnu-dll-cflags) \
    -DAPPL_OS_LINUX

appl-toolchain-gnu-release-dll-cxxflags = \
    $(CXXFLAGS) \
    $(appl-gnu-common-flags) \
    $(appl-gnu-common-cxxflags) \
    $(appl-gnu-release-flags) \
    $(appl-gnu-release-cxxflags) \
    $(appl-gnu-dll-flags) \
    $(appl-gnu-dll-cflags) \
    -DAPPL_OS_LINUX

define appl-toolchain-gnu-release-dll-linker
	$(APPL_VERBOSE)echo -o $(1) -shared -rdynamic $(appl-toolchain-gnu-release-dll-cflags) $(3) $(2) $(foreach x,$(4),$(APPL_LIBRARY-$(x)-gnu-lflags)) > $(1).cmd
	$(APPL_VERBOSE)$(appl-gnu-cc) @$(strip $(1)).cmd
endef

define appl-toolchain-gnu-release-dll-c-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-gnu-release-dll-cflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(appl-gnu-cc) @$(strip $(1)).cmd
endef

define appl-toolchain-gnu-release-dll-cxx-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-gnu-release-dll-cxxflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(appl-gnu-cxx) @$(strip $(1)).cmd
endef

