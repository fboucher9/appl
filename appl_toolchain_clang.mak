# See LICENSE for license details

#
#
#

ifndef appl_toolchain_clang.mak-included
appl_toolchain_clang.mak-included := 1

# Setup clang C compiler program
appl-clang-cc = clang

# Setup clang C++ compiler program
appl-clang-cxx = clang++

# Setup clang librarian
appl-clang-ar = $(AR)

# Setup clang compiler options
appl-clang-common-flags = \
    -g \
    -O0 \
    -Weverything \
    -D_BSD_SOURCE \
    -DAPPL_OS_LINUX \
    -DAPPL_BUILD_EXE \
    -I$(APPL_SRC).

appl-clang-common-cflags = \
    -std=c89

appl-clang-common-cxxflags = \
    -std=c++98 \
    -fno-rtti \
    -fno-exceptions

appl-clang-debug-flags = -O0 -DAPPL_DEBUG
appl-clang-debug-cflags =
appl-clang-debug-cxxflags =

appl-clang-release-flags = -O2 -DAPPL_RELEASE
appl-clang-release-cflags =
appl-clang-release-cxxflags =

appl-clang-exe-flags = -DAPPL_BUILD_EXE
appl-clang-exe-cflags =
appl-clang-exe-cxxflags =

appl-clang-dll-flags = -DAPPL_BUILD_DLL
appl-clang-dll-cflags =
appl-clang-dll-cxxflags =

appl-clang-lib-flags = -DAPPL_BUILD_LIB
appl-clang-lib-cflags =
appl-clang-lib-cxxflags =

appl-toolchain-clang-debug-exe-cflags = \
    $(CFLAGS) \
    $(appl-clang-common-flags) \
    $(appl-clang-common-cflags) \
    $(appl-clang-debug-flags) \
    $(appl-clang-debug-cflags) \
    $(appl-clang-exe-flags) \
    $(appl-clang-exe-cflags)

appl-toolchain-clang-debug-exe-cxxflags = \
    $(CXXFLAGS) \
    $(appl-clang-common-flags) \
    $(appl-clang-common-cxxflags) \
    $(appl-clang-debug-flags) \
    $(appl-clang-debug-cxxflags) \
    $(appl-clang-exe-flags) \
    $(appl-clang-exe-cxxflags)

define appl-toolchain-clang-debug-exe-linker
	$(APPL_VERBOSE)echo -o $(1) $(appl-toolchain-clang-debug-exe-cflags) $(3) $(2) $(foreach x,$(4),$(APPL_LIBRARY-$(x)-clang-lflags)) > $(1).cmd
	$(APPL_VERBOSE)$(appl-clang-cc) @$(strip $(1)).cmd
endef

define appl-toolchain-clang-debug-exe-c-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-clang-debug-exe-cflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(appl-clang-cc) @$(strip $(1)).cmd
endef

define appl-toolchain-clang-debug-exe-cxx-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-clang-debug-exe-cxxflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(appl-clang-cxx) @$(strip $(1)).cmd
endef

appl-toolchain-clang-release-exe-cflags = \
    $(CFLAGS) \
    $(appl-clang-common-flags) \
    $(appl-clang-common-cflags) \
    $(appl-clang-release-flags) \
    $(appl-clang-release-cflags) \
    $(appl-clang-exe-flags) \
    $(appl-clang-exe-cflags)

appl-toolchain-clang-release-exe-cxxflags = \
    $(CXXFLAGS) \
    $(appl-clang-common-flags) \
    $(appl-clang-common-cxxflags) \
    $(appl-clang-release-flags) \
    $(appl-clang-release-cxxflags) \
    $(appl-clang-exe-flags) \
    $(appl-clang-exe-cxxflags)

define appl-toolchain-clang-release-exe-linker
	$(APPL_VERBOSE)echo -o $(1) $(appl-toolchain-clang-release-exe-cflags) $(3) $(2) $(foreach x,$(4),$(APPL_LIBRARY-$(x)-clang-lflags)) > $(1).cmd
	$(APPL_VERBOSE)$(appl-clang-cc) @$(strip $(1)).cmd
endef

define appl-toolchain-clang-release-exe-c-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-clang-release-exe-cflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(appl-clang-cc) @$(strip $(1)).cmd
endef

define appl-toolchain-clang-release-exe-cxx-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-clang-release-exe-cxxflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(appl-clang-cxx) @$(strip $(1)).cmd
endef

appl-toolchain-clang-debug-lib-cflags = \
    $(CFLAGS) \
    $(appl-clang-common-flags) \
    $(appl-clang-common-cflags) \
    $(appl-clang-debug-flags) \
    $(appl-clang-debug-cflags) \
    $(appl-clang-lib-flags) \
    $(appl-clang-lib-cflags)

appl-toolchain-clang-debug-lib-cxxflags = \
    $(CXXFLAGS) \
    $(appl-clang-common-flags) \
    $(appl-clang-common-cxxflags) \
    $(appl-clang-debug-flags) \
    $(appl-clang-debug-cxxflags) \
    $(appl-clang-lib-flags) \
    $(appl-clang-lib-cxxflags)

define appl-toolchain-clang-debug-lib-linker
	$(APPL_VERBOSE)$(appl-clang-ar) cr $(1) $(2)
endef

define appl-toolchain-clang-debug-lib-c-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-clang-debug-lib-cflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(appl-clang-cc) @$(strip $(1)).cmd
endef

define appl-toolchain-clang-debug-lib-cxx-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-clang-debug-lib-cxxflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(appl-clang-cxx) @$(strip $(1)).cmd
endef

appl-toolchain-clang-release-lib-cflags = \
    $(CFLAGS) \
    $(appl-clang-common-flags) \
    $(appl-clang-common-cflags) \
    $(appl-clang-release-flags) \
    $(appl-clang-release-cflags) \
    $(appl-clang-lib-flags) \
    $(appl-clang-lib-cflags)

appl-toolchain-clang-release-lib-cxxflags = \
    $(CXXFLAGS) \
    $(appl-clang-common-flags) \
    $(appl-clang-common-cxxflags) \
    $(appl-clang-release-flags) \
    $(appl-clang-release-cxxflags) \
    $(appl-clang-lib-flags) \
    $(appl-clang-lib-cxxflags)

define appl-toolchain-clang-release-lib-linker
	$(APPL_VERBOSE)$(appl-clang-ar) cr $(1) $(2)
endef

define appl-toolchain-clang-release-lib-c-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-clang-release-lib-cflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(appl-clang-cc) @$(strip $(1)).cmd
endef

define appl-toolchain-clang-release-lib-cxx-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-clang-release-lib-cxxflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(appl-clang-cxx) @$(strip $(1)).cmd
endef

endif # ifndef appl_toolchain_clang.mak-included

# end-of-file: appl_toolchain_clang.mak
