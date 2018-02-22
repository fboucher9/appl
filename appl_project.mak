# See LICENSE for license details

# TODO: compile multiple toolchain in a single make
# TODO: compile debug and release in a single make
# TODO: support for src files in any subfolder
# TODO: detect folder name of a src file

# Select a toolchain
# May be gnu, clang, mingw
APPL_TOOLCHAIN ?= gnu

# Verbose output of executed commands
APPL_VERBOSE ?= @

# Location of source code files
APPL_SRC ?=

# Setup clang toolchain program
APPL_CC-clang = clang
APPL_CXX-clang = clang++

# Setup mingw toolchain program
APPL_CC-mingw = x86_64-w64-mingw32-gcc
APPL_CXX-mingw = x86_64-w64-mingw32-g++

# Select a C compiler program
APPL_CC-gnu = $(CC)

# Select a C++ compiler program
APPL_CXX-gnu = $(CXX)

# Common compiler flags for C and C++
APPL_FLAGS-gnu = \
    -g \
    -O0 \
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

# Setup mingw compiler options
APPL_CFLAGS-mingw = $(APPL_CFLAGS-gnu)

APPL_CXXFLAGS-mingw = $(APPL_CXXFLAGS-gnu)

# Report for toolchain
$(info curdir is $(CURDIR))
$(info toolchain is $(APPL_TOOLCHAIN))
$(info src folder is $(APPL_SRC))
$(info cc is $(APPL_CC-$(APPL_TOOLCHAIN)))
$(info cxx is $(APPL_CXX-$(APPL_TOOLCHAIN)))
$(info --- cflags are ---)
$(info $(APPL_CFLAGS-$(APPL_TOOLCHAIN)))
$(info --- cxxflags are ---)
$(info $(APPL_CXXFLAGS-$(APPL_TOOLCHAIN)))

APPL_TARGETS += test_appl

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
    appl_heap_handle.cpp \
    appl_options.cpp \
    appl_options_std.cpp \
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
test_appl-libs = -lpthread

# $1: output
# $2: inputs
# $3: flags
# $4: libs
define appl-script-LINKER-gnu
	@echo linking $(1) with gcc
	$(APPL_VERBOSE)echo -o $(1) $(3) $(2) $(4) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_CC-gnu) @$(1).cmd
endef

define appl-script-LINKER-clang
	@echo linking $(1) with clang
	$(APPL_VERBOSE)echo -o $(1) $(3) $(2) $(4) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_CC-clang) -o $(1) $(3) $(2) $(4)
endef

define appl-script-LINKER-mingw
	@echo linking $(1) with mingw
	$(APPL_VERBOSE)echo -o $(1) $(3) $(2) -static $(4) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_CC-mingw) @$(1).cmd
endef

#
# $1: output
# $2: input
# $3: flags
define appl-script-CC-gnu
	@echo compiling $(2) with gcc
	$(APPL_VERBOSE)echo -c -o $(1) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_CC-gnu) @$(1).cmd
endef

define appl-script-CC-clang
	@echo compiling $(2) with clang
	$(APPL_VERBOSE)echo -c -o $(1) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_CC-clang) -c -o $(1) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2)
endef

define appl-script-CC-mingw
	@echo compiling $(2) with mingw-gcc
	$(APPL_VERBOSE)echo -c -o $(1) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_CC-mingw) @$(1).cmd
endef

define appl-script-CXX-gnu
	@echo compiling $(2) with g++
	$(APPL_VERBOSE)echo -c -o $(1) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_CXX-gnu) @$(1).cmd
endef

define appl-script-CXX-clang
	@echo compiling $(2) with clang++
	$(APPL_VERBOSE)echo -c -o $(1) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_CXX-clang) -c -o $(1) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2)
endef

define appl-script-CXX-mingw
	@echo compiling $(2) with mingw-g++
	$(APPL_VERBOSE)echo -c -o $(1) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_CXX-mingw) @$(1).cmd
endef

#
# Function: do_source
#
# Description:
#       Generate compiler rule for a source
#
# Parameters:
#       $1       target name
#       $2       toolchain
#
define do_source
$(1)-$(2)-output ?= .obj$(2)/$(1).o
$(1)-$(2)-input ?= $$(APPL_SRC)$(1)
$(1)-$(2)-dst ?= $$(dir $$($(1)-$(2)-output))
$(1)-$(2)-src ?= $$(dir $$($(1)-$(2)-input))
ifeq "$(suffix $(1))" ".c"
$(1)-$(2)-flags ?= $$(APPL_CFLAGS-$(2))
$(1)-$(2)-compiler ?= appl-script-CC-$(2)
else ifeq "$(suffix $(1))" ".cpp"
$(1)-$(2)-flags ?= $$(APPL_CXXFLAGS-$(2))
$(1)-$(2)-compiler ?= appl-script-CXX-$(2)
endif
$$($(1)-$(2)-output) : $$($(1)-$(2)-input) $(APPL_SRC)appl_project.mak
	-$$(APPL_VERBOSE)mkdir -p $$($(1)-$(2)-dst)
	$$(call $$($(1)-$(2)-compiler),$$($(1)-$(2)-output),$$($(1)-$(2)-input),$$($(1)-$(2)-flags))
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
$(1)-$(2)-objs = $$(foreach y, $$($(1)-deps), .obj$(2)/$$(y).o)
.PHONY : all
all : .obj$(2)/$(1).exe
.obj$(2)/$(1).exe : $$($(1)-$(2)-objs) $(APPL_SRC)appl_project.mak
	-$$(APPL_VERBOSE)mkdir -p .obj$(2)
	$$(call appl-script-LINKER-$(2),.obj$(2)/$(1).exe,$$($(1)-$(2)-objs),$$(APPL_CFLAGS-$(2)),$$($(1)-libs))
$$(foreach x, $$($(1)-deps), $$(eval $$(call do_source,$$(x),$(2))))
endef

$(foreach x,$(APPL_TARGETS), $(eval $(foreach y,$(APPL_TOOLCHAIN), $(call do_target,$(x),$(y)))))

# Generic "clean" rule, delete all object files
.PHONY: clean
clean: appl_clean

# Define a phony rule for clean of appl objects
.PHONY: appl_clean
appl_clean:
	@echo cleaning
	-$(APPL_VERBOSE)rm -f .obj*/*.o
	-$(APPL_VERBOSE)rm -f .obj*/*.cmd
	-$(APPL_VERBOSE)rm -f .obj*/*.d
	-$(APPL_VERBOSE)rm -f .obj*/*.exe

# Include automatic header file dependency files
-include .obj*/*.d

# end-of-file: appl_project.mak
