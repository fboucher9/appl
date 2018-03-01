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

# Setup clang toolchain program
APPL_CC-clang = clang
APPL_CXX-clang = clang++

# Select a C compiler program
APPL_CC-gnu = $(CC)

# Select a C++ compiler program
APPL_CXX-gnu = $(CXX)

# Common compiler flags for C and C++
APPL_FLAGS-gnu = \
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

# Append common flags to C compiler flags
APPL_CFLAGS-gnu = \
    $(CFLAGS) \
    $(APPL_FLAGS-gnu) \
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
APPL_CXXFLAGS-gnu = \
    $(CXXFLAGS) \
    $(APPL_FLAGS-gnu) \
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

# Setup clang compiler options
APPL_FLAGS-clang = \
    -g \
    -O0 \
    -Weverything \
    -D_BSD_SOURCE \
    -I$(APPL_SRC).

APPL_CFLAGS-clang = \
    $(APPL_FLAGS-clang) \
    -std=c89

APPL_CXXFLAGS-clang = \
    $(APPL_FLAGS-clang) \
    -std=c++98 \
    -fno-rtti \
    -fno-exceptions

APPL_TARGETS += test_appl

test_appl-cfgs = $(APPL_TOOLCHAIN)

test_appl-deps = \
    appl_test.c \
    appl.cpp \
    appl_buf.cpp \
    appl_list.cpp \
    appl_object.cpp \
    appl_object_handle.cpp \
    appl_clock_handle.cpp \
    appl_clock_service.cpp \
    appl_clock.cpp \
    appl_clock_std.cpp \
    appl_clock_w32.cpp \
    appl_context.cpp \
    appl_context_std.cpp \
    appl_context_handle.cpp \
    appl_debug.cpp \
    appl_debug_std.cpp \
    appl_debug_handle.cpp \
    appl_event_handle.cpp \
    appl_event_service.cpp \
    appl_event_node.cpp \
    appl_event_mgr.cpp \
    appl_event_std_mgr.cpp \
    appl_file_handle.cpp \
    appl_file_service.cpp \
    appl_file_node.cpp \
    appl_file_mgr.cpp \
    appl_file_std_mgr.cpp \
    appl_file_std_node.cpp \
    appl_heap.cpp \
    appl_heap_std.cpp \
    appl_heap_dbg.cpp \
    appl_heap_service.cpp \
    appl_heap_handle.cpp \
    appl_options.cpp \
    appl_options_std.cpp \
    appl_socket_handle.cpp \
    appl_thread_handle.cpp \
    appl_thread_node.cpp \
    appl_thread_std_node.cpp \
    appl_thread_mgr.cpp \
    appl_thread_std_mgr.cpp \
    appl_mutex_handle.cpp \
    appl_mutex_service.cpp \
    appl_mutex_node.cpp \
    appl_mutex_mgr.cpp \
    appl_mutex_std_mgr.cpp \
    appl_mutex_std_node.cpp \
    appl_node.cpp \
    appl_node_iterator.cpp \
    appl_poll_handle.cpp \
    appl_poll_service.cpp \
    appl_poll_mgr.cpp \
    appl_poll_node.cpp

# List of libraries required to link test application
test_appl-libs = pthread rt

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

#
# Function: do_source
#
# Description:
#       Generate compiler rule for a source
#
# Parameters:
#       $1       target name
#       $2       toolchain
#       $3       program name
#
define do_source
$(3)-$(2)-$(1)-dst ?= $$($(3)-$(2)-dst)
$(3)-$(2)-$(1)-src ?= $$($(3)-$(2)-src)
$(3)-$(2)-$(1)-output ?= $$($(3)-$(2)-$(1)-dst)$(1).o
$(3)-$(2)-$(1)-input ?= $$($(3)-$(2)-$(1)-src)$(1)
ifeq "$(suffix $(1))" ".c"
$(3)-$(2)-$(1)-flags ?= $$($(3)-$(2)-c-flags)
$(3)-$(2)-$(1)-compiler ?= $$($(3)-$(2)-c-compiler)
else ifeq "$(suffix $(1))" ".cpp"
$(3)-$(2)-$(1)-flags ?= $$($(3)-$(2)-cxx-flags)
$(3)-$(2)-$(1)-compiler ?= $$($(3)-$(2)-cxx-compiler)
endif
APPL_HEADER_DEPS += $$($(3)-$(2)-$(1)-output).d
$$($(3)-$(2)-$(1)-output) : $$($(3)-$(2)-$(1)-input) $(APPL_SRC)appl_project.mak
	-$$(APPL_VERBOSE)mkdir -p $$($(3)-$(2)-$(1)-dst)
	$$(call $$($(3)-$(2)-$(1)-compiler), $$($(3)-$(2)-$(1)-output),$$($(3)-$(2)-$(1)-input),$$($(3)-$(2)-$(1)-flags))
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
$(1)-$(2)-c-flags ?= $$($(2)-c-flags)
$(1)-$(2)-cxx-flags ?= $$($(2)-cxx-flags)
$(1)-$(2)-deps ?= $$($(1)-deps)
$(1)-$(2)-libs ?= $$($(1)-libs)
$(1)-$(2)-dst ?= .obj/$(1)/$(2)/
$(1)-$(2)-src ?= $(APPL_SRC)
$(1)-$(2)-output ?= $$($(1)-$(2)-dst)$(1).exe
$(1)-$(2)-input ?= $$(foreach y, $$($(1)-$(2)-deps), $$($(1)-$(2)-dst)$$(y).o)
$(1)-$(2)-c-compiler ?= appl-toolchain-$(2)-c-compiler
$(1)-$(2)-cxx-compiler ?= appl-toolchain-$(2)-cxx-compiler
$(1)-$(2)-linker ?= appl-toolchain-$(2)-linker
.PHONY : $(1)-$(2)
$(1)-$(2) : $$($(1)-$(2)-output)
.PHONY : all
all : $(1)-$(2)
$$($(1)-$(2)-output) : $$($(1)-$(2)-input) $(APPL_SRC)appl_project.mak
	-$$(APPL_VERBOSE)mkdir -p $$($(1)-$(2)-dst)
	$$(call $$($(1)-$(2)-linker),$$($(1)-$(2)-output),$$($(1)-$(2)-input),$$($(1)-$(2)-c-flags),$$($(1)-$(2)-libs))
$$(foreach x, $$($(1)-deps), $$(eval $$(call do_source,$$(x),$(2),$(1))))
endef

$(foreach x,$(APPL_TARGETS), $(foreach y, $($(x)-cfgs), $(eval $(call do_target,$(x),$(y)))))

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
