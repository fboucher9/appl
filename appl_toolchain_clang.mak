# See LICENSE for license details

appl-toolchain-clang-cflags = \
    $(CFLAGS) \
    $(appl-clang-common-flags) \
    $(appl-clang-common-cflags) \
    $(appl-clang-release-flags) \
    $(appl-clang-release-cflags)

appl-toolchain-clang-cxxflags = \
    $(CXXFLAGS) \
    $(appl-clang-common-flags) \
    $(appl-clang-common-cxxflags) \
    $(appl-clang-release-flags) \
    $(appl-clang-release-cxxflags)

define appl-toolchain-clang-linker
	$(APPL_VERBOSE)echo -o $(1) $(appl-toolchain-clang-cflags) $(3) $(2) $(foreach x,$(4),$(APPL_LIBRARY-$(x)-clang-lflags)) > $(1).cmd
	$(APPL_VERBOSE)$(appl-clang-cc) @$(strip $(1)).cmd
endef

define appl-toolchain-clang-c-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-clang-cflags) $(3) -DAPPL_OS_LINUX -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(appl-clang-cc) @$(strip $(1)).cmd
endef

define appl-toolchain-clang-cxx-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-clang-cxxflags) $(3) -DAPPL_OS_LINUX -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(appl-clang-cxx) @$(strip $(1)).cmd
endef

