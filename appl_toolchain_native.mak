# See LICENSE for license details

APPL_TOOLCHAIN_NATIVE_CC ?= $(CC)
APPL_TOOLCHAIN_NATIVE_CXX ?= $(CXX)
APPL_TOOLCHAIN_NATIVE_CFLAGS ?= $(CFLAGS)
APPL_TOOLCHAIN_NATIVE_CXXFLAGS ?= $(CXXFLAGS)
APPL_TOOLCHAIN_NATIVE_LDFLAGS ?= $(LDFLAGS)

define appl-toolchain-native-linker
	$(APPL_VERBOSE)echo -o $(1) $(APPL_TOOLCHAIN_NATIVE_CFLAGS) $(3) $(2) $(foreach x,$(4), $(APPL_TOOLCHAIN_NATIVE_LIB_$(x))) $(APPL_TOOLCHAIN_NATIVE_LDFLAGS) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_TOOLCHAIN_NATIVE_CC) @$(strip $(1)).cmd
endef

define appl-toolchain-native-c-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(APPL_TOOLCHAIN_NATIVE_CFLAGS) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_TOOLCHAIN_NATIVE_CC) @$(strip $(1)).cmd
endef

define appl-toolchain-native-cxx-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(APPL_TOOLCHAIN_NATIVE_CXXFLAGS) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_TOOLCHAIN_NATIVE_CXX) @$(strip $(1)).cmd
endef

