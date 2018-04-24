# See LICENSE for license details

# TODO: compile multiple toolchain in a single make
# TODO: compile debug and release in a single make
# TODO: support for src files in any subfolder
# TODO: detect folder name of a src file

# Select a toolchain
# May be gnu, clang, mingw
APPL_TOOLCHAIN ?= gnudbg gnu clang mingw mingwdbg gnudbg32

# Verbose output of executed commands
APPL_VERBOSE ?= @

# Location of source code files
APPL_SRC ?=

# Location of output files
APPL_DST ?= .obj/

# Setup clang C compiler program
appl-clang-cc = clang

# Setup clang C++ compiler program
appl-clang-cxx = clang++

# Select a C compiler program
appl-gnu-cc = $(CC)

# Select a C++ compiler program
appl-gnu-cxx = $(CXX)

# Common compiler flags for C and C++
appl-gnu-common-flags = \
    -g \
    -O2 \
    -D_BSD_SOURCE \
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

appl-gnu-common-flags-program =

appl-gnu-common-flags-dynamic = -shared -fPIC

appl-gnu-common-flags-static =

appl-gnu-debug-flags = -DAPPL_DEBUG

appl-gnu-release-flags = -DAPPL_NDEBUG

# Append common flags to C compiler flags
appl-gnu-common-cflags = \
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
appl-gnu-common-cxxflags = \
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
appl-gnu-debug-cflags =

appl-gnu-debug-cxxflags =

appl-gnu-release-cflags =

appl-gnu-release-cxxflags =

# Setup clang compiler options
appl-clang-common-flags = \
    -g \
    -O0 \
    -Weverything \
    -D_BSD_SOURCE \
    -I$(APPL_SRC).

appl-clang-common-cflags = \
    -std=c89

appl-clang-common-cxxflags = \
    -std=c++98 \
    -fno-rtti \
    -fno-exceptions

APPL_LIBRARY-pthread-gnu-lflags = -lpthread
APPL_LIBRARY-pthread-clang-lflags = -lpthread
APPL_LIBRARY-pthread-mingw-lflags = -lpthread

APPL_LIBRARY-rt-gnu-lflags = -lrt
APPL_LIBRARY-rt-clang-lflags = -lrt
APPL_LIBRARY-rt-mingw-lflags = -lwinmm

# appl-toolchain-$(x)-linker
# $1: output
# $2: inputs
# $3: flags
# $4: libs

# appl-toolchain-$(x)-c-compiler
# $1: output
# $2: input
# $3: flags

# appl-toolchain-$(x)-cxx-compiler
# $1: output
# $2: input
# $3: flags

# include the toolchain files
include $(wildcard $(foreach x,$(APPL_TOOLCHAIN), $(APPL_SRC)appl_toolchain_$(x).mak))

# automatic include of project makefiles
include $(wildcard $(APPL_PROJECT_LIST))
$(if $(target-list),$(info building $(target-list)),$(error no targets in list))

#
# Function: do_source
#
# Description:
#       Generate compiler rule for a source
#
# Parameters:
#       $1       program name
#       $2       toolchain
#       $3       target name
#
define do_source
$(1)-$(2)-$(3)-dst ?= $$($(1)-$(2)-dst)
$(1)-$(2)-$(3)-src ?= $$($(1)-$(2)-src)
$(1)-$(2)-$(3)-output ?= $$($(1)-$(2)-$(3)-dst)$(3).o
$(1)-$(2)-$(3)-input ?= $$($(1)-$(2)-$(3)-src)$(3)
ifeq "$(suffix $(3))" ".c"
$(1)-$(2)-$(3)-flags ?= $$($(1)-$(2)-c-flags)
$(1)-$(2)-$(3)-compiler ?= $$($(1)-$(2)-c-compiler)
else ifeq "$(suffix $(3))" ".cpp"
$(1)-$(2)-$(3)-flags ?= $$($(1)-$(2)-cxx-flags)
$(1)-$(2)-$(3)-compiler ?= $$($(1)-$(2)-cxx-compiler)
endif
APPL_HEADER_DEPS += $$($(1)-$(2)-$(3)-output).d
$$($(1)-$(2)-$(3)-output) : $$($(1)-$(2)-$(3)-input) $$(MAKEFILE_LIST)
	@echo compiling $(3) with $(2)
	-$$(APPL_VERBOSE)mkdir -p $$(dir $$($(1)-$(2)-$(3)-output))
	$$(call $$($(1)-$(2)-$(3)-compiler), $$($(1)-$(2)-$(3)-output),$$($(1)-$(2)-$(3)-input),$$($(1)-$(2)-$(3)-flags))
endef

#
# Function: do_target
#
# Description:
#       Generate linker and compiler rules for a target
#
# Parameters:
#       $1      target name
#       $2      toolchain
#
# Comments:
#
define do_target
$(1)-src ?= $$(APPL_SRC)
$(1)-dst ?= $$(APPL_DST)$(1)/
$(1)-$(2)-c-flags ?= $$($(2)-c-flags)
$(1)-$(2)-cxx-flags ?= $$($(2)-cxx-flags)
$(1)-$(2)-deps ?= $$($(1)-deps)
$(1)-$(2)-libs ?= $$($(1)-libs)
$(1)-$(2)-dst ?= $$($(1)-dst)$(2)/
$(1)-$(2)-src ?= $$($(1)-src)
$(1)-$(2)-output ?= $$($(1)-$(2)-dst)$(1).exe
$(1)-$(2)-input ?= $$(foreach y, $$($(1)-$(2)-deps), $$($(1)-$(2)-dst)$$(y).o)
$(1)-$(2)-c-compiler ?= appl-toolchain-$(2)-c-compiler
$(1)-$(2)-cxx-compiler ?= appl-toolchain-$(2)-cxx-compiler
$(1)-$(2)-linker ?= appl-toolchain-$(2)-linker
.PHONY : $(1)-$(2)
$(1)-$(2) : $$($(1)-$(2)-output)
.PHONY : $(1) $(2) all
all $(1) $(2) : $(1)-$(2)
$$($(1)-$(2)-output) : $$($(1)-$(2)-input) $$(MAKEFILE_LIST)
	@echo linking $(1) with $(2)
	-$$(APPL_VERBOSE)mkdir -p $$(dir $$($(1)-$(2)-output))
	$$(call $$($(1)-$(2)-linker),$$($(1)-$(2)-output),$$($(1)-$(2)-input),$$($(1)-$(2)-c-flags),$$($(1)-$(2)-libs))
$$(foreach x, $$($(1)-deps), $$(eval $$(call do_source,$(1),$(2),$$(x))))
endef

$(foreach x,$(target-list), $(foreach y, $($(x)-cfgs), $(eval $(call do_target,$(x),$(y)))))

# Generic "clean" rule, delete all object files
.PHONY: clean
clean: appl_clean

# Define a phony rule for clean of appl objects
.PHONY: appl_clean
appl_clean:
	@echo cleaning
	-$(APPL_VERBOSE)rm -rf .obj/

# Include automatic header file dependency files
include $(wildcard $(APPL_HEADER_DEPS))

# end-of-file: appl_project.mak
