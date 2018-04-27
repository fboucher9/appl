# See LICENSE for license details

# Setup mingw toolchain program
APPL_TOOLCHAIN_MINGW_CC ?= x86_64-w64-mingw32-gcc
APPL_TOOLCHAIN_MINGW_CXX ?= x86_64-w64-mingw32-g++
APPL_TOOLCHAIN_MINGW_AR ?= x86_64-w64-mingw32-ar

# Setup mingw prefix for target files
appl-toolchain-mingw-exe-prefix =
appl-toolchain-mingw-dll-prefix =
appl-toolchain-mingw-lib-prefix =
appl-toolchain-mingw-debug-exe-prefix = $(appl-toolchain-mingw-exe-prefix)
appl-toolchain-mingw-release-exe-prefix = $(appl-toolchain-mingw-exe-prefix)
appl-toolchain-mingw-debug-dll-prefix = $(appl-toolchain-mingw-dll-prefix)
appl-toolchain-mingw-release-dll-prefix = $(appl-toolchain-mingw-dll-prefix)
appl-toolchain-mingw-debug-lib-prefix = $(appl-toolchain-mingw-lib-prefix)
appl-toolchain-mingw-release-lib-prefix = $(appl-toolchain-mingw-lib-prefix)

# Setup mingw suffix for target files
appl-toolchain-mingw-exe-suffix = .exe
appl-toolchain-mingw-dll-suffix = .dll
appl-toolchain-mingw-lib-suffix = .lib
appl-toolchain-mingw-debug-exe-suffix = $(appl-toolchain-mingw-exe-suffix)
appl-toolchain-mingw-release-exe-suffix = $(appl-toolchain-mingw-exe-suffix)
appl-toolchain-mingw-debug-dll-suffix = $(appl-toolchain-mingw-dll-suffix)
appl-toolchain-mingw-release-dll-suffix = $(appl-toolchain-mingw-dll-suffix)
appl-toolchain-mingw-debug-lib-suffix = $(appl-toolchain-mingw-lib-suffix)
appl-toolchain-mingw-release-lib-suffix = $(appl-toolchain-mingw-lib-suffix)

# Setup mingw toolchain flags using common gnu flags
appl-toolchain-mingw-common-flags = $(appl-gnu-common-flags) -DAPPL_OS_WINDOWS
appl-toolchain-mingw-common-cflags = $(appl-gnu-common-cflags)
appl-toolchain-mingw-common-cxxflags = $(appl-gnu-common-cxxflags)
appl-toolchain-mingw-release-flags = $(appl-gnu-release-flags)
appl-toolchain-mingw-release-cflags = $(appl-gnu-release-cflags)
appl-toolchain-mingw-release-cxxflags = $(appl-gnu-release-cxxflags)
appl-toolchain-mingw-debug-flags = $(appl-gnu-debug-flags)
appl-toolchain-mingw-debug-cflags = $(appl-gnu-debug-cflags)
appl-toolchain-mingw-debug-cxxflags = $(appl-gnu-debug-cxxflags)
appl-toolchain-mingw-exe-flags = $(appl-gnu-exe-flags)
appl-toolchain-mingw-exe-cflags = $(appl-gnu-exe-cflags)
appl-toolchain-mingw-exe-cxxflags = $(appl-gnu-exe-cxxflags)
appl-toolchain-mingw-dll-flags = $(appl-gnu-dll-flags)
appl-toolchain-mingw-dll-cflags = $(appl-gnu-dll-cflags)
appl-toolchain-mingw-dll-cxxflags = $(appl-gnu-dll-cxxflags)
appl-toolchain-mingw-lib-flags = $(appl-gnu-lib-flags)
appl-toolchain-mingw-lib-cflags = $(appl-gnu-lib-cflags)
appl-toolchain-mingw-lib-cxxflags = $(appl-gnu-lib-cxxflags)

# Combine flags for release exe
appl-toolchain-mingw-release-exe-cflags = \
    $(appl-toolchain-mingw-common-flags) \
    $(appl-toolchain-mingw-common-cflags) \
    $(appl-toolchain-mingw-release-flags) \
    $(appl-toolchain-mingw-release-cflags) \
    $(appl-toolchain-mingw-exe-flags) \
    $(appl-toolchain-mingw-exe-cflags)

appl-toolchain-mingw-release-exe-cxxflags = \
    $(appl-toolchain-mingw-common-flags) \
    $(appl-toolchain-mingw-common-cxxflags) \
    $(appl-toolchain-mingw-release-flags) \
    $(appl-toolchain-mingw-release-cxxflags) \
    $(appl-toolchain-mingw-exe-flags) \
    $(appl-toolchain-mingw-exe-cxxflags)

define appl-toolchain-mingw-release-exe-linker
	$(APPL_VERBOSE)echo -o $(1) $(appl-toolchain-mingw-release-exe-cflags) $(3) $(2) -static $(foreach x,$(4),$(APPL_LIBRARY-$(x)-mingw-lflags)) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_TOOLCHAIN_MINGW_CC) @$(strip $(1)).cmd
endef

define appl-toolchain-mingw-release-exe-c-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-mingw-release-exe-cflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_TOOLCHAIN_MINGW_CC) @$(strip $(1)).cmd
endef

define appl-toolchain-mingw-release-exe-cxx-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-mingw-release-exe-cxxflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_TOOLCHAIN_MINGW_CXX) @$(strip $(1)).cmd
endef

# Combine flags for debug exe
appl-toolchain-mingw-debug-exe-cflags = \
    $(appl-toolchain-mingw-common-flags) \
    $(appl-toolchain-mingw-common-cflags) \
    $(appl-toolchain-mingw-debug-flags) \
    $(appl-toolchain-mingw-debug-cflags) \
    $(appl-toolchain-mingw-exe-flags) \
    $(appl-toolchain-mingw-exe-cflags)

appl-toolchain-mingw-debug-exe-cxxflags = \
    $(appl-toolchain-mingw-common-flags) \
    $(appl-toolchain-mingw-common-cxxflags) \
    $(appl-toolchain-mingw-debug-flags) \
    $(appl-toolchain-mingw-debug-cxxflags) \
    $(appl-toolchain-mingw-exe-flags) \
    $(appl-toolchain-mingw-exe-cxxflags)

define appl-toolchain-mingw-debug-exe-linker
	$(APPL_VERBOSE)echo -o $(1) $(appl-toolchain-mingw-debug-exe-cflags) $(3) $(2) -static $(foreach x,$(4),$(APPL_LIBRARY-$(x)-mingw-lflags)) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_TOOLCHAIN_MINGW_CC) @$(strip $(1)).cmd
endef

define appl-toolchain-mingw-debug-exe-c-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-mingw-debug-exe-cflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_TOOLCHAIN_MINGW_CC) @$(strip $(1)).cmd
endef

define appl-toolchain-mingw-debug-exe-cxx-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-mingw-debug-exe-cxxflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_TOOLCHAIN_MINGW_CXX) @$(strip $(1)).cmd
endef

# Combine flags for release dll
appl-toolchain-mingw-release-dll-cflags = \
    $(appl-toolchain-mingw-common-flags) \
    $(appl-toolchain-mingw-common-cflags) \
    $(appl-toolchain-mingw-release-flags) \
    $(appl-toolchain-mingw-release-cflags) \
    $(appl-toolchain-mingw-dll-flags) \
    $(appl-toolchain-mingw-dll-cflags)

appl-toolchain-mingw-release-dll-cxxflags = \
    $(appl-toolchain-mingw-common-flags) \
    $(appl-toolchain-mingw-common-cxxflags) \
    $(appl-toolchain-mingw-release-flags) \
    $(appl-toolchain-mingw-release-cxxflags) \
    $(appl-toolchain-mingw-dll-flags) \
    $(appl-toolchain-mingw-dll-cxxflags)

define appl-toolchain-mingw-release-dll-linker
	$(APPL_VERBOSE)echo -o $(1) $(appl-toolchain-mingw-release-dll-cflags) $(3) $(2) -static $(foreach x,$(4),$(APPL_LIBRARY-$(x)-mingw-lflags)) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_TOOLCHAIN_MINGW_CC) @$(strip $(1)).cmd
endef

define appl-toolchain-mingw-release-dll-c-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-mingw-release-dll-cflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_TOOLCHAIN_MINGW_CC) @$(strip $(1)).cmd
endef

define appl-toolchain-mingw-release-dll-cxx-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-mingw-release-dll-cxxflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_TOOLCHAIN_MINGW_CXX) @$(strip $(1)).cmd
endef

# Combine flags for debug dll
appl-toolchain-mingw-debug-dll-cflags = \
    $(appl-toolchain-mingw-common-flags) \
    $(appl-toolchain-mingw-common-cflags) \
    $(appl-toolchain-mingw-debug-flags) \
    $(appl-toolchain-mingw-debug-cflags) \
    $(appl-toolchain-mingw-dll-flags) \
    $(appl-toolchain-mingw-dll-cflags)

appl-toolchain-mingw-debug-dll-cxxflags = \
    $(appl-toolchain-mingw-common-flags) \
    $(appl-toolchain-mingw-common-cxxflags) \
    $(appl-toolchain-mingw-debug-flags) \
    $(appl-toolchain-mingw-debug-cxxflags) \
    $(appl-toolchain-mingw-dll-flags) \
    $(appl-toolchain-mingw-dll-cxxflags)

define appl-toolchain-mingw-debug-dll-linker
	$(APPL_VERBOSE)echo -o $(1) $(appl-toolchain-mingw-debug-dll-cflags) $(3) $(2) -static $(foreach x,$(4),$(APPL_LIBRARY-$(x)-mingw-lflags)) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_TOOLCHAIN_MINGW_CC) @$(strip $(1)).cmd
endef

define appl-toolchain-mingw-debug-dll-c-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-mingw-debug-dll-cflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_TOOLCHAIN_MINGW_CC) @$(strip $(1)).cmd
endef

define appl-toolchain-mingw-debug-dll-cxx-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-mingw-debug-dll-cxxflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_TOOLCHAIN_MINGW_CXX) @$(strip $(1)).cmd
endef

# Combine flags for release lib
appl-toolchain-mingw-release-lib-cflags = \
    $(appl-toolchain-mingw-common-flags) \
    $(appl-toolchain-mingw-common-cflags) \
    $(appl-toolchain-mingw-release-flags) \
    $(appl-toolchain-mingw-release-cflags) \
    $(appl-toolchain-mingw-lib-flags) \
    $(appl-toolchain-mingw-lib-cflags)

appl-toolchain-mingw-release-lib-cxxflags = \
    $(appl-toolchain-mingw-common-flags) \
    $(appl-toolchain-mingw-common-cxxflags) \
    $(appl-toolchain-mingw-release-flags) \
    $(appl-toolchain-mingw-release-cxxflags) \
    $(appl-toolchain-mingw-lib-flags) \
    $(appl-toolchain-mingw-lib-cxxflags)

define appl-toolchain-mingw-release-lib-linker
	$(APPL_VERBOSE)$(APPL_TOOLCHAIN_MINGW_AR) cr $(1) $(2)
endef

define appl-toolchain-mingw-release-lib-c-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-mingw-release-lib-cflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_TOOLCHAIN_MINGW_CC) @$(strip $(1)).cmd
endef

define appl-toolchain-mingw-release-lib-cxx-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-mingw-release-lib-cxxflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_TOOLCHAIN_MINGW_CXX) @$(strip $(1)).cmd
endef

# Combine flags for debug lib
appl-toolchain-mingw-debug-lib-cflags = \
    $(appl-toolchain-mingw-common-flags) \
    $(appl-toolchain-mingw-common-cflags) \
    $(appl-toolchain-mingw-debug-flags) \
    $(appl-toolchain-mingw-debug-cflags) \
    $(appl-toolchain-mingw-lib-flags) \
    $(appl-toolchain-mingw-lib-cflags)

appl-toolchain-mingw-debug-lib-cxxflags = \
    $(appl-toolchain-mingw-common-flags) \
    $(appl-toolchain-mingw-common-cxxflags) \
    $(appl-toolchain-mingw-debug-flags) \
    $(appl-toolchain-mingw-debug-cxxflags) \
    $(appl-toolchain-mingw-lib-flags) \
    $(appl-toolchain-mingw-lib-cxxflags)

define appl-toolchain-mingw-debug-lib-linker
	$(APPL_VERBOSE)$(APPL_TOOLCHAIN_MINGW_AR) cr $(1) $(2)
endef

define appl-toolchain-mingw-debug-lib-c-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-mingw-debug-lib-cflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_TOOLCHAIN_MINGW_CC) @$(strip $(1)).cmd
endef

define appl-toolchain-mingw-debug-lib-cxx-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-mingw-debug-lib-cxxflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_TOOLCHAIN_MINGW_CXX) @$(strip $(1)).cmd
endef

