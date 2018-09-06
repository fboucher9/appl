# See LICENSE for license details

#
#
#

ifndef appl_toolchain_gnu.mak-included
appl_toolchain_gnu.mak-included := 1

# Select a C compiler program
appl-toolchain-gnu-cc = $(CC)

# Select a C++ compiler program
appl-toolchain-gnu-cxx = $(CXX)

# Select archive program
appl-toolchain-gnu-ar = $(AR)

# Common compiler flags for C and C++
appl-toolchain-gnu-common-flags = \
    -g \
    -DAPPL_OS_LINUX \
    -D_DEFAULT_SOURCE \
    -I$(APPL_SRC). \
    -pedantic \
    -Wall \
    -Wextra \
    -Wabi \
    -Waggregate-return \
    -Warray-bounds \
    -Wattributes \
    -Wbuiltin-macro-redefined \
    -Wcast-align \
    -Wcast-qual \
    -Wconversion \
    -Wdeprecated \
    -Wdiv-by-zero \
    -Wendif-labels \
    -Wfloat-equal \
    -Wformat-contains-nul \
    -Wformat-extra-args \
    -Wformat-nonliteral \
    -Wformat-security \
    -Wformat-y2k \
    -Wlarger-than=4096 \
    -Wlong-long \
    -Wmissing-declarations \
    -Wmissing-format-attribute \
    -Wmissing-include-dirs \
    -Wmultichar \
    -Woverflow \
    -Woverlength-strings \
    -Wpacked \
    -Wpacked-bitfield-compat \
    -Wpadded \
    -Wpointer-arith \
    -Wpragmas \
    -Wredundant-decls \
    -Wsequence-point \
    -Wshadow \
    -Wstrict-overflow=5 \
    -Wsync-nand \
    -Wundef \
    -Wunused \
    -Wunused-macros \
    -Wunused-result \
    -Wvariadic-macros \
    -Wvla \
    -Wwrite-strings

appl-toolchain-gnu-debug-flags = -O0 -DAPPL_DEBUG

appl-toolchain-gnu-release-flags = -O2 -DAPPL_RELEASE

appl-toolchain-gnu-exe-flags = -DAPPL_BUILD_EXE

appl-toolchain-gnu-dll-flags = -DAPPL_BUILD_DLL -shared $(APPL_TOOLCHAIN_PIC)

appl-toolchain-gnu-lib-flags = -DAPPL_BUILD_LIB

# Append common flags to C compiler flags
appl-toolchain-gnu-common-cflags = \
    -Wbad-function-cast \
    -Wc++-compat \
    -Wdeclaration-after-statement \
    -Wformat-zero-length \
    -Wint-to-pointer-cast \
    -Wmissing-prototypes \
    -Wnested-externs \
    -Wold-style-definition \
    -Wpointer-to-int-cast \
    -Wstrict-prototypes \
    -std=c89

# Append common flags to C++ compiler flags
appl-toolchain-gnu-common-cxxflags = \
    -Wc++0x-compat \
    -Wctor-dtor-privacy \
    -Weffc++ \
    -Wenum-compare \
    -Wnon-virtual-dtor \
    -Woverloaded-virtual \
    -Wstrict-null-sentinel \
    -Wsign-promo \
    -std=c++98 \
    -fno-rtti \
    -fno-exceptions

# Configuration specific gnu flags
appl-toolchain-gnu-debug-cflags =

appl-toolchain-gnu-debug-cxxflags =

appl-toolchain-gnu-release-cflags =

appl-toolchain-gnu-release-cxxflags =

appl-toolchain-gnu-exe-cflags =

appl-toolchain-gnu-exe-cxxflags =

appl-toolchain-gnu-dll-cflags =

appl-toolchain-gnu-dll-cxxflags =

appl-toolchain-gnu-lib-cflags =

appl-toolchain-gnu-lib-cxxflags =

appl-toolchain-gnu-prefix = $(appl-prefix)
appl-toolchain-gnu-exe-prefix = $(appl-toolchain-gnu-prefix)
appl-toolchain-gnu-dll-prefix = lib$(appl-toolchain-gnu-prefix)
appl-toolchain-gnu-lib-prefix = lib$(appl-toolchain-gnu-prefix)
appl-toolchain-gnu-debug-exe-prefix = $(appl-toolchain-gnu-exe-prefix)
appl-toolchain-gnu-debug-dll-prefix = $(appl-toolchain-gnu-dll-prefix)
appl-toolchain-gnu-debug-lib-prefix = $(appl-toolchain-gnu-lib-prefix)
appl-toolchain-gnu-release-exe-prefix = $(appl-toolchain-gnu-exe-prefix)
appl-toolchain-gnu-release-dll-prefix = $(appl-toolchain-gnu-dll-prefix)
appl-toolchain-gnu-release-lib-prefix = $(appl-toolchain-gnu-lib-prefix)

appl-toolchain-gnu-suffix = $(appl-suffix)
appl-toolchain-gnu-exe-suffix = $(appl-suffix)
appl-toolchain-gnu-dll-suffix = $(appl-suffix).so
appl-toolchain-gnu-lib-suffix = $(appl-suffix).a
appl-toolchain-gnu-debug-exe-suffix = $(appl-toolchain-gnu-exe-suffix)
appl-toolchain-gnu-debug-dll-suffix = $(appl-toolchain-gnu-dll-suffix)
appl-toolchain-gnu-debug-lib-suffix = $(appl-toolchain-gnu-lib-suffix)
appl-toolchain-gnu-release-exe-suffix = $(appl-toolchain-gnu-exe-suffix)
appl-toolchain-gnu-release-dll-suffix = $(appl-toolchain-gnu-dll-suffix)
appl-toolchain-gnu-release-lib-suffix = $(appl-toolchain-gnu-lib-suffix)

appl-toolchain-gnu-debug-exe-cflags = \
    $(CFLAGS) \
    $(appl-toolchain-gnu-common-flags) \
    $(appl-toolchain-gnu-common-cflags) \
    $(appl-toolchain-gnu-debug-flags) \
    $(appl-toolchain-gnu-debug-cflags) \
    $(appl-toolchain-gnu-exe-flags) \
    $(appl-toolchain-gnu-exe-cflags)

appl-toolchain-gnu-debug-exe-cxxflags = \
    $(CXXFLAGS) \
    $(appl-toolchain-gnu-common-flags) \
    $(appl-toolchain-gnu-common-cxxflags) \
    $(appl-toolchain-gnu-debug-flags) \
    $(appl-toolchain-gnu-debug-cxxflags) \
    $(appl-toolchain-gnu-exe-flags) \
    $(appl-toolchain-gnu-exe-cxxflags)

define appl-toolchain-gnu-debug-exe-linker
	$(APPL_VERBOSE)echo -o $(1) -rdynamic $(appl-toolchain-gnu-debug-exe-cflags) $(3) $(2) $(foreach x,$(4),$(APPL_LIBRARY-$(x)-gnu-lflags)) > $(1).cmd
	$(APPL_VERBOSE)$(appl-toolchain-gnu-cc) @$(strip $(1)).cmd
endef

define appl-toolchain-gnu-debug-exe-c-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-gnu-debug-exe-cflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(appl-toolchain-gnu-cc) @$(strip $(1)).cmd
endef

define appl-toolchain-gnu-debug-exe-cxx-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-gnu-debug-exe-cxxflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(appl-toolchain-gnu-cxx) @$(strip $(1)).cmd
endef

appl-toolchain-gnu-debug-dll-cflags = \
    $(CFLAGS) \
    $(appl-toolchain-gnu-common-flags) \
    $(appl-toolchain-gnu-common-cflags) \
    $(appl-toolchain-gnu-debug-flags) \
    $(appl-toolchain-gnu-debug-cflags) \
    $(appl-toolchain-gnu-dll-flags) \
    $(appl-toolchain-gnu-dll-cflags)

appl-toolchain-gnu-debug-dll-cxxflags = \
    $(CXXFLAGS) \
    $(appl-toolchain-gnu-common-flags) \
    $(appl-toolchain-gnu-common-cxxflags) \
    $(appl-toolchain-gnu-debug-flags) \
    $(appl-toolchain-gnu-debug-cxxflags) \
    $(appl-toolchain-gnu-dll-flags) \
    $(appl-toolchain-gnu-dll-cflags)

define appl-toolchain-gnu-debug-dll-linker
	$(APPL_VERBOSE)echo -o $(1) -shared -rdynamic -Wl,--version-script=$(strip $(5)) $(appl-toolchain-gnu-debug-dll-cflags) $(3) $(2) $(foreach x,$(4),$(APPL_LIBRARY-$(x)-gnu-lflags)) > $(1).cmd
	$(APPL_VERBOSE)$(appl-toolchain-gnu-cc) @$(strip $(1)).cmd
endef

define appl-toolchain-gnu-debug-dll-c-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-gnu-debug-dll-cflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(appl-toolchain-gnu-cc) @$(strip $(1)).cmd
endef

define appl-toolchain-gnu-debug-dll-cxx-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-gnu-debug-dll-cxxflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(appl-toolchain-gnu-cxx) @$(strip $(1)).cmd
endef

appl-toolchain-gnu-debug-lib-c-flags = \
    $(CFLAGS) \
    $(appl-toolchain-gnu-common-flags) \
    $(appl-toolchain-gnu-common-cflags) \
    $(appl-toolchain-gnu-debug-flags) \
    $(appl-toolchain-gnu-debug-cflags) \
    $(appl-toolchain-gnu-lib-flags) \
    $(appl-toolchain-gnu-lib-cflags)

appl-toolchain-gnu-debug-lib-cxx-flags = \
    $(CXXFLAGS) \
    $(appl-toolchain-gnu-common-flags) \
    $(appl-toolchain-gnu-common-cxxflags) \
    $(appl-toolchain-gnu-debug-flags) \
    $(appl-toolchain-gnu-debug-cxxflags) \
    $(appl-toolchain-gnu-lib-flags) \
    $(appl-toolchain-gnu-lib-cxxflags)

define appl-toolchain-gnu-debug-lib-linker
	$(APPL_VERBOSE)$(appl-toolchain-gnu-ar) cr $(1) $(2)
endef

define appl-toolchain-gnu-debug-lib-c-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-gnu-debug-lib-c-flags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(appl-toolchain-gnu-cc) @$(strip $(1)).cmd
endef

define appl-toolchain-gnu-debug-lib-cxx-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-gnu-debug-lib-cxx-flags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(appl-toolchain-gnu-cxx) @$(strip $(1)).cmd
endef

appl-toolchain-gnu-release-exe-cflags = \
    $(CFLAGS) \
    $(appl-toolchain-gnu-common-flags) \
    $(appl-toolchain-gnu-common-cflags) \
    $(appl-toolchain-gnu-release-flags) \
    $(appl-toolchain-gnu-release-cflags) \
    $(appl-toolchain-gnu-exe-flags) \
    $(appl-toolchain-gnu-exe-cflags)

appl-toolchain-gnu-release-exe-cxxflags = \
    $(CXXFLAGS) \
    $(appl-toolchain-gnu-common-flags) \
    $(appl-toolchain-gnu-common-cxxflags) \
    $(appl-toolchain-gnu-release-flags) \
    $(appl-toolchain-gnu-release-cxxflags) \
    $(appl-toolchain-gnu-exe-flags) \
    $(appl-toolchain-gnu-exe-cxxflags)

define appl-toolchain-gnu-release-exe-linker
	$(APPL_VERBOSE)echo -o $(1) $(appl-toolchain-gnu-release-exe-cflags) $(3) $(2) $(foreach x,$(4),$(APPL_LIBRARY-$(x)-gnu-lflags)) > $(1).cmd
	$(APPL_VERBOSE)$(appl-toolchain-gnu-cc) @$(strip $(1)).cmd
endef

define appl-toolchain-gnu-release-exe-c-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-gnu-release-exe-cflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(appl-toolchain-gnu-cc) @$(strip $(1)).cmd
endef

define appl-toolchain-gnu-release-exe-cxx-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-gnu-release-exe-cxxflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(appl-toolchain-gnu-cxx) @$(strip $(1)).cmd
endef

appl-toolchain-gnu-release-dll-cflags = \
    $(CFLAGS) \
    $(appl-toolchain-gnu-common-flags) \
    $(appl-toolchain-gnu-common-cflags) \
    $(appl-toolchain-gnu-release-flags) \
    $(appl-toolchain-gnu-release-cflags) \
    $(appl-toolchain-gnu-dll-flags) \
    $(appl-toolchain-gnu-dll-cflags)

appl-toolchain-gnu-release-dll-cxxflags = \
    $(CXXFLAGS) \
    $(appl-toolchain-gnu-common-flags) \
    $(appl-toolchain-gnu-common-cxxflags) \
    $(appl-toolchain-gnu-release-flags) \
    $(appl-toolchain-gnu-release-cxxflags) \
    $(appl-toolchain-gnu-dll-flags) \
    $(appl-toolchain-gnu-dll-cflags)

define appl-toolchain-gnu-release-dll-linker
	$(APPL_VERBOSE)echo -o $(1) -shared -rdynamic $(appl-toolchain-gnu-release-dll-cflags) $(3) $(2) $(foreach x,$(4),$(APPL_LIBRARY-$(x)-gnu-lflags)) > $(1).cmd
	$(APPL_VERBOSE)$(appl-toolchain-gnu-cc) @$(strip $(1)).cmd
endef

define appl-toolchain-gnu-release-dll-c-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-gnu-release-dll-cflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(appl-toolchain-gnu-cc) @$(strip $(1)).cmd
endef

define appl-toolchain-gnu-release-dll-cxx-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-gnu-release-dll-cxxflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(appl-toolchain-gnu-cxx) @$(strip $(1)).cmd
endef

appl-toolchain-gnu-release-lib-cflags = \
    $(CFLAGS) \
    $(appl-toolchain-gnu-common-flags) \
    $(appl-toolchain-gnu-common-cflags) \
    $(appl-toolchain-gnu-release-flags) \
    $(appl-toolchain-gnu-release-cflags) \
    $(appl-toolchain-gnu-lib-flags) \
    $(appl-toolchain-gnu-lib-cflags)

appl-toolchain-gnu-release-lib-cxxflags = \
    $(CXXFLAGS) \
    $(appl-toolchain-gnu-common-flags) \
    $(appl-toolchain-gnu-common-cxxflags) \
    $(appl-toolchain-gnu-release-flags) \
    $(appl-toolchain-gnu-release-cxxflags) \
    $(appl-toolchain-gnu-lib-flags) \
    $(appl-toolchain-gnu-lib-cxxflags)

define appl-toolchain-gnu-release-lib-linker
	$(APPL_VERBOSE)$(appl-toolchain-gnu-ar) cr $(1) $(2)
endef

define appl-toolchain-gnu-release-lib-c-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-gnu-release-lib-cflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(appl-toolchain-gnu-cc) @$(strip $(1)).cmd
endef

define appl-toolchain-gnu-release-lib-cxx-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(appl-toolchain-gnu-release-lib-cxxflags) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(appl-toolchain-gnu-cxx) @$(strip $(1)).cmd
endef

endif # ifndef appl_toolchain_gnu.mak-included

# end-of-file: appl_toolchain_gnu.mak
