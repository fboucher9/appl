# See LICENSE for license details

# TODO: compile multiple toolchain in a single make
# TODO: compile debug and release in a single make
# TODO: support for src files in any subfolder
# TODO: detect folder name of a src file

# Select a toolchain
# May be gnu, clang, mingw
APPL_TOOLCHAIN ?= \
    gnu \
    clang \
    mingw \
    gnudbg32

# Setup -fPIC option for gnu compiler
APPL_TOOLCHAIN_PIC ?= -fPIC

# Verbose output of executed commands
APPL_VERBOSE ?= @

# Location of source code files
APPL_SRC ?=

# Location of output files
APPL_DST ?= .obj/

# Setup prefix of output file
appl-prefix =

# Setup suffix of output file
appl-suffix =

APPL_LIBRARY-pthread-gnu-lflags = -lpthread
APPL_LIBRARY-pthread-clang-lflags = -lpthread
APPL_LIBRARY-pthread-mingw-lflags = -lpthread

APPL_LIBRARY-rt-gnu-lflags = -lrt
APPL_LIBRARY-rt-clang-lflags = -lrt
APPL_LIBRARY-rt-mingw-lflags = -lwinmm

# Macro to expand list of includes
appl-expand-incs = $(foreach x,$(1), -I$(x))

# Macro to expand list of defines
appl-expand-defs = $(foreach x,$(1), -D$(x))

# appl-toolchain-$(x)-linker
# $1: output
# $2: inputs
# $3: flags
# $4: libs
# $5: exports

# appl-toolchain-$(x)-c-compiler
# $1: output
# $2: input
# $3: flags
# $4: incs
# $5: defs

# appl-toolchain-$(x)-cxx-compiler
# $1: output
# $2: input
# $3: flags
# $4: incs
# $5: defs

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
$(1)-$(2)-$(3)-incs ?= $$($(1)-$(2)-incs)
$(1)-$(2)-$(3)-defs ?= $$($(1)-$(2)-defs)
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
	$$(call $$($(1)-$(2)-$(3)-compiler), $$($(1)-$(2)-$(3)-output),$$($(1)-$(2)-$(3)-input),$$($(1)-$(2)-$(3)-flags),$$($(1)-$(2)-$(3)-incs),$$($(1)-$(2)-$(3)-defs))
endef

#
# Function: do_target_2
#
# Description:
#       Generate linker and compiler rules for a target
#
# Parameters:
#       $1      target name
#       $2      toolchain-build-type
#       $3      toolchain
#       $4      build
#       $5      type
#
# Comments:
#
define do_target_2
$(1)-$(2)-name ?= $$($(1)-name)
$(1)-$(2)-c-flags ?=
$(1)-$(2)-cxx-flags ?=
$(1)-$(2)-deps ?= $$($(1)-deps)
$(1)-$(2)-libs ?= $$($(1)-libs)
$(1)-$(2)-dst ?= $$($(1)-dst)$(2)/
$(1)-$(2)-src ?= $$($(1)-src)
$(1)-$(2)-incs ?= $$($(1)-incs)
$(1)-$(2)-defs ?= $$($(1)-defs)
$(1)-$(2)-output ?= $$($(1)-$(2)-dst)$$(appl-toolchain-$(2)-prefix)$$($(1)-name)$$(appl-toolchain-$(2)-suffix)
$(1)-$(2)-input ?= $$(foreach y, $$($(1)-$(2)-deps), $$($(1)-$(2)-dst)$$(y).o)
$(1)-$(2)-c-compiler ?= appl-toolchain-$(2)-c-compiler
$(1)-$(2)-cxx-compiler ?= appl-toolchain-$(2)-cxx-compiler
$(1)-$(2)-linker ?= appl-toolchain-$(2)-linker
.PHONY : $(1)-$(2)
$(1)-$(2) : $$($(1)-$(2)-output)
.PHONY : all $(1) $(2) $(3) $(4) $(3)-$(4) $(4)-$(5) $(5)
all $(1) $(2) $(3) $(4) $(3)-$(4) $(4)-$(5) $(5) : $(1)-$(2)
$$($(1)-$(2)-output) : $$($(1)-$(2)-input) $$(MAKEFILE_LIST)
	@echo linking $(1) with $(2)
	-$$(APPL_VERBOSE)mkdir -p $$(dir $$($(1)-$(2)-output))
	$$(call $$($(1)-$(2)-linker),$$($(1)-$(2)-output),$$($(1)-$(2)-input),$$($(1)-$(2)-c-flags),$$($(1)-$(2)-libs),$$($(1)-exports-path))
$$(foreach x, $$($(1)-deps), $$(eval $$(call do_source,$(1),$(2),$$(x))))
endef

#
# Function: do_target_1
#
# Description:
#       Setup default variables of a target and generate all configurations
#       supported by the target.
#
# Parameters:
#       $1      target name
#
define do_target_1
$(1)-src ?= $$(APPL_SRC)
$(1)-dst ?= $$(APPL_DST)$(1)/
$(1)-type ?= exe
$(1)-name ?= $(1)
$(1)-exports-path ?= $$($(1)-src)$$($(1)-exports)
$(1)-cfgs ?= $$(APPL_TOOLCHAIN)
$$(foreach x, $$($(1)-cfgs), $$(eval $$(call do_target_2,$(1),$$(x)-debug-$$($(1)-type),$$(x),debug,$$($(1)-type))))
$$(foreach x, $$($(1)-cfgs), $$(eval $$(call do_target_2,$(1),$$(x)-release-$$($(1)-type),$$(x),release,$$($(1)-type))))
endef

$(foreach x,$(target-list), $(eval $(call do_target_1,$(x),$(y))))

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
