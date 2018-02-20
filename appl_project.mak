# See LICENSE for license details

# Select a toolchain
# May be gnu, clang, mingw
APPL_TOOLCHAIN ?= gnu

# Verbose output of executed commands
APPL_VERBOSE ?= @

# Location of source code files
APPL_SRC ?=

# Location of object files
APPL_DST ?= .obj$(APPL_TOOLCHAIN)/

# Setup clang toolchain program
ifeq ($(APPL_TOOLCHAIN),clang)
    APPL_CC ?= clang
    APPL_CXX ?= clang++
endif

# Setup mingw toolchain program
ifeq ($(APPL_TOOLCHAIN),mingw)
    APPL_CC ?= x86_64-w64-mingw32-gcc
    APPL_CXX ?= x86_64-w64-mingw32-g++
endif

# Select a C compiler program
APPL_CC ?= $(CC)

# Select a C++ compiler program
APPL_CXX ?= $(CXX)

# Select base C compiler flags
APPL_CFLAGS ?= $(CFLAGS)

# Select base C++ compiler flags
APPL_CXXFLAGS ?= $(CXXFLAGS)

APPL_TEST_C_DEPS = \
    appl_test

APPL_TEST_CXX_DEPS = \
    appl \
    appl_buf \
    appl_list \
    appl_object \
    appl_object_handle \
    appl_clock_handle \
    appl_clock_service \
    appl_clock \
    appl_clock_std \
    appl_context \
    appl_context_std \
    appl_context_handle \
    appl_debug \
    appl_debug_std \
    appl_debug_handle \
    appl_event_handle \
    appl_event_service \
    appl_event_node \
    appl_event_mgr \
    appl_event_std_mgr \
    appl_file_handle \
    appl_file_service \
    appl_file_node \
    appl_file_mgr \
    appl_file_std_mgr \
    appl_file_std_node \
    appl_heap \
    appl_heap_std \
    appl_heap_handle \
    appl_options \
    appl_options_std \
    appl_thread_handle \
    appl_thread_node \
    appl_thread_std_node \
    appl_thread_mgr \
    appl_thread_std_mgr \
    appl_mutex_handle \
    appl_mutex_service \
    appl_mutex_node \
    appl_mutex_mgr \
    appl_mutex_std_mgr \
    appl_mutex_std_node \
    appl_node \
    appl_node_iterator \
    appl_poll_handle \
    appl_poll_service \
    appl_poll_mgr \
    appl_poll_node

# List of object files required to link test application
APPL_TEST_OBJS = \
    $(foreach x,$(APPL_TEST_C_DEPS), $(APPL_DST)$(x).o ) \
    $(foreach x,$(APPL_TEST_CXX_DEPS), $(APPL_DST)$(x).o )

# Common compiler flags for C and C++
APPL_FLAGS = \
    -g \
    -O0 \
    -D_BSD_SOURCE \
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
APPL_CFLAGS += $(APPL_FLAGS) \
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
APPL_CXXFLAGS += \
    $(APPL_FLAGS) \
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
ifeq ($(APPL_TOOLCHAIN),clang)

APPL_FLAGS = \
    -g \
    -O0 \
    -Weverything \
    -D_BSD_SOURCE

APPL_CFLAGS = \
    $(APPL_FLAGS) \
    -std=c89

APPL_CXXFLAGS = \
    $(APPL_FLAGS) \
    -std=c++98 \
    -fno-rtti \
    -fno-exceptions

endif

# List of libraries required to link test application
APPL_TEST_LIBS = -lpthread

# Generic "all" rule, compile all targets
.PHONY: all
all : appl_test

# Define a phony rule for test application
.PHONY: appl_test
appl_test: $(APPL_DST)test_appl.exe

$(APPL_DST) :
	@echo create $(APPL_DST) folder
	-$(APPL_VERBOSE)mkdir -p $(APPL_DST)

# $1: output
# $2: inputs
# $3: flags
# $4: libs
define APPL_TOOLCHAIN_LINKER-gnu
	@echo linking $(1) with gcc
	$(APPL_VERBOSE)echo -o $(1) $(3) $(2) $(4) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_CC) @$(1).cmd
endef

define APPL_TOOLCHAIN_LINKER-clang
	@echo linking $(1) with clang
	$(APPL_VERBOSE)echo -o $(1) $(3) $(2) $(4) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_CC) @$(1).cmd
endef

define APPL_TOOLCHAIN_LINKER-mingw
	@echo linking $(1) with mingw
	$(APPL_VERBOSE)echo -o $(1) $(3) $(2) -static $(4) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_CC) @$(1).cmd
endef

# Link of test application
$(APPL_DST)test_appl.exe : $(APPL_TEST_OBJS) | $(APPL_DST)
	$(call APPL_TOOLCHAIN_LINKER-$(APPL_TOOLCHAIN),$(APPL_DST)test_appl.exe,$(APPL_TEST_OBJS),$(APPL_CFLAGS),$(APPL_TEST_LIBS))

#
# $1: output
# $2: input
# $3: flags
define APPL_TOOLCHAIN_CC-gnu
	@echo compiling $(2) with gcc
	$(APPL_VERBOSE)$(APPL_CC) -c -o $(1) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2)
endef

define APPL_TOOLCHAIN_CC-clang
	@echo compiling $(2) with clang
	$(APPL_VERBOSE)$(APPL_CC) -c -o $(1) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2)
endef

define APPL_TOOLCHAIN_CC-mingw
	@echo compiling $(2) with mingw-gcc
	$(APPL_VERBOSE)$(APPL_CC) -c -o $(1) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2)
endef

# $1: target name
define APPL_TEST_BASE_RULES
.PHONY : $$($(1)-label)
$$($(1)-label) : $$($(1)-output)
$$($(1)-output) : $$($(1)-input)
	$$(call $$($(1)-compiler),$$($(1)-output),$$($(1)-input),$$($(1)-flags))
endef

#
# $1: target name
define APPL_TEST_C_RULES
$(1)-label ?= $(1)_c
$(1)-output ?= $$(APPL_DST)$(1).o
$(1)-input ?= $$(APPL_SRC)$(1).c
$(1)-flags ?= $$(APPL_CFLAGS)
$(1)-compiler ?= APPL_TOOLCHAIN_CC-$$(APPL_TOOLCHAIN)
$(call APPL_TEST_BASE_RULES,$(1))
endef

$(foreach x,$(APPL_TEST_C_DEPS),$(eval $(call APPL_TEST_C_RULES,$(x))))

#
# $1: output
# $2: input
# $3: flags
define APPL_TOOLCHAIN_CXX-gnu
	@echo compiling $(2) with g++
	$(APPL_VERBOSE)$(APPL_CXX) -c -o $(1) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2)
endef

define APPL_TOOLCHAIN_CXX-clang
	@echo compiling $(2) with clang++
	$(APPL_VERBOSE)$(APPL_CXX) -c -o $(1) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2)
endef

define APPL_TOOLCHAIN_CXX-mingw
	@echo compiling $(2) with mingw-g++
	$(APPL_VERBOSE)$(APPL_CXX) -c -o $(1) $(3) -MT $(1) -MMD -MP -MF $(1).d $(2)
endef

#
# $1: target name
define APPL_TEST_CXX_RULES
$(1)-label ?= $(1)_cpp
$(1)-output ?= $$(APPL_DST)$(1).o
$(1)-input ?= $$(APPL_SRC)$(1).cpp
$(1)-flags ?= $$(APPL_CXXFLAGS)
$(1)-compiler ?= APPL_TOOLCHAIN_CXX-$$(APPL_TOOLCHAIN)
$(call APPL_TEST_BASE_RULES,$(1))
endef

$(foreach x,$(APPL_TEST_CXX_DEPS),$(eval $(call APPL_TEST_CXX_RULES,$(x))))

# Dependency on makefile and appl_project.mak
$(APPL_DST)test_appl.exe $(APPL_TEST_OBJS) : $(APPL_SRC)makefile $(APPL_SRC)appl_project.mak

# Generic "clean" rule, delete all object files
.PHONY: clean
clean: appl_clean

# Define a phony rule for clean of appl objects
.PHONY: appl_clean
appl_clean:
	@echo cleaning
	-$(APPL_VERBOSE)rm -f $(APPL_DST)*.o
	-$(APPL_VERBOSE)rm -f $(APPL_DST)*.cmd
	-$(APPL_VERBOSE)rm -f $(APPL_DST)*.d
	-$(APPL_VERBOSE)rm -f $(APPL_DST)*.exe

# Include automatic header file dependency files
-include $(APPL_DST)*.d

# end-of-file: appl_project.mak
