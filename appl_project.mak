# See LICENSE for license details

# Select a toolchain
# May be gnu, clang, mingw
ifndef APPL_TOOLCHAIN
    APPL_TOOLCHAIN = gnu
endif

# Location of source code files
ifndef APPL_SRC
    APPL_SRC =
endif

# Location of object files
ifndef APPL_DST
    APPL_DST = .obj$(APPL_TOOLCHAIN)/
endif

# Setup clang toolchain program
ifeq ($(APPL_TOOLCHAIN),clang)
    APPL_CC = clang
    APPL_CXX = clang++
endif

# Setup mingw toolchain program
ifeq ($(APPL_TOOLCHAIN),mingw)
    APPL_CC = x86_64-w64-mingw32-gcc
    APPL_CXX = x86_64-w64-mingw32-g++
endif

# Select a C compiler program
ifndef APPL_CC
    APPL_CC = $(CC)
endif

# Select a C++ compiler program
ifndef APPL_CXX
    APPL_CXX = $(CXX)
endif

# Select base C compiler flags
ifndef APPL_CFLAGS
    APPL_CFLAGS = $(CFLAGS)
endif

# Select base C++ compiler flags
ifndef APPL_CXXFLAGS
    APPL_CXXFLAGS = $(CXXFLAGS)
endif

# List of object files required to link test application
APPL_TEST_OBJS = \
    $(APPL_DST)appl.o \
    $(APPL_DST)appl_buf.o \
    $(APPL_DST)appl_list.o \
    $(APPL_DST)appl_object.o \
    $(APPL_DST)appl_object_handle.o \
    $(APPL_DST)appl_clock_handle.o \
    $(APPL_DST)appl_clock_service.o \
    $(APPL_DST)appl_clock.o \
    $(APPL_DST)appl_clock_std.o \
    $(APPL_DST)appl_context.o \
    $(APPL_DST)appl_context_std.o \
    $(APPL_DST)appl_context_handle.o \
    $(APPL_DST)appl_debug.o \
    $(APPL_DST)appl_debug_std.o \
    $(APPL_DST)appl_debug_handle.o \
    $(APPL_DST)appl_event_handle.o \
    $(APPL_DST)appl_event_service.o \
    $(APPL_DST)appl_event_node.o \
    $(APPL_DST)appl_event_mgr.o \
    $(APPL_DST)appl_event_std_mgr.o \
    $(APPL_DST)appl_file_handle.o \
    $(APPL_DST)appl_file_service.o \
    $(APPL_DST)appl_file_node.o \
    $(APPL_DST)appl_file_mgr.o \
    $(APPL_DST)appl_file_std_mgr.o \
    $(APPL_DST)appl_file_std_node.o \
    $(APPL_DST)appl_heap.o \
    $(APPL_DST)appl_heap_std.o \
    $(APPL_DST)appl_heap_handle.o \
    $(APPL_DST)appl_options.o \
    $(APPL_DST)appl_options_std.o \
    $(APPL_DST)appl_thread_handle.o \
    $(APPL_DST)appl_thread_node.o \
    $(APPL_DST)appl_thread_std_node.o \
    $(APPL_DST)appl_thread_mgr.o \
    $(APPL_DST)appl_thread_std_mgr.o \
    $(APPL_DST)appl_mutex_handle.o \
    $(APPL_DST)appl_mutex_service.o \
    $(APPL_DST)appl_mutex_node.o \
    $(APPL_DST)appl_mutex_mgr.o \
    $(APPL_DST)appl_mutex_std_mgr.o \
    $(APPL_DST)appl_mutex_std_node.o \
    $(APPL_DST)appl_node.o \
    $(APPL_DST)appl_node_iterator.o \
    $(APPL_DST)appl_poll_handle.o \
    $(APPL_DST)appl_poll_service.o \
    $(APPL_DST)appl_poll_mgr.o \
    $(APPL_DST)appl_poll_node.o \
    $(APPL_DST)appl_test.o

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
	-@mkdir -p $(APPL_DST)

# Link of test application
$(APPL_DST)test_appl.exe : $(APPL_TEST_OBJS) | $(APPL_DST)
	@echo linking $(APPL_DST)test_appl.exe
	@echo -o $(APPL_DST)test_appl.exe $(APPL_CFLAGS) $(APPL_TEST_OBJS) $(APPL_TEST_LIBS) > $(APPL_DST)test_appl.exe.cmd
	@$(APPL_CC) @$(APPL_DST)test_appl.exe.cmd

# Compile of C source files
$(APPL_DST)%.o : $(APPL_SRC)%.c | $(APPL_DST)
	@echo compiling $@
	@echo -c -o $@ $(APPL_CFLAGS) -MT $@ -MMD -MP -MF $@.d $< > $@.cmd
	@$(APPL_CC) @$@.cmd

# Compile of C++ source files
$(APPL_DST)%.o : $(APPL_SRC)%.cpp | $(APPL_DST)
	@echo compiling $@
	@echo -c -o $@ $(APPL_CXXFLAGS) -MT $@ -MMD -MP -MF $@.d $< > $@.cmd
	@$(APPL_CXX) @$@.cmd

# Dependency on makefile and appl_project.mak
$(APPL_DST)test_appl.exe $(APPL_TEST_OBJS) : $(APPL_SRC)makefile $(APPL_SRC)appl_project.mak

# Generic "clean" rule, delete all object files
.PHONY: clean
clean: appl_clean

# Define a phony rule for clean of appl objects
.PHONY: appl_clean
appl_clean:
	-rm -f $(APPL_DST)*.o
	-rm -f $(APPL_DST)*.cmd
	-rm -f $(APPL_DST)*.d
	-rm -f $(APPL_DST)*.exe

# Include automatic header file dependency files
-include $(APPL_DST)*.d

# end-of-file: appl_project.mak
