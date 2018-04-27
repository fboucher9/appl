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

appl-toolchain-gnu-debug-dll-cflags = \
    $(CFLAGS) \
    $(appl-gnu-common-flags) \
    $(appl-gnu-common-cflags) \
    $(appl-gnu-debug-flags) \
    $(appl-gnu-debug-cflags) \
    $(appl-gnu-dll-flags) \
    $(appl-gnu-dll-cflags) \
    -DAPPL_OS_LINUX

appl-toolchain-gnu-debug-dll-cxxflags = \
    $(CXXFLAGS) \
    $(appl-gnu-common-flags) \
    $(appl-gnu-common-cxxflags) \
    $(appl-gnu-debug-flags) \
    $(appl-gnu-debug-cxxflags) \
    $(appl-gnu-dll-flags) \
    $(appl-gnu-dll-cflags) \
    -DAPPL_OS_LINUX

define appl-toolchain-gnu-debug-dll-linker
	$(APPL_VERBOSE)echo -o $(1) -shared -rdynamic -Wl,--version-script=$(strip $(5)) $(appl-toolchain-gnu-debug-dll-cflags) $(3) $(2) $(foreach x,$(4),$(APPL_LIBRARY-$(x)-gnu-lflags)) > $(1).cmd
	$(APPL_VERBOSE)$(appl-gnu-cc) @$(strip $(1)).cmd
endef

define appl-toolchain-gnu-debug-dll-c-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-gnu-debug-dll-cflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(appl-gnu-cc) @$(strip $(1)).cmd
endef

define appl-toolchain-gnu-debug-dll-cxx-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-gnu-debug-dll-cxxflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(appl-gnu-cxx) @$(strip $(1)).cmd
endef

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

