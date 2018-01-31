# See LICENSE for license details

# Location of source code files
ifndef APPL_SRC
    APPL_SRC =
endif

# Location of object files
ifndef APPL_DST
    APPL_DST =
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
    $(APPL_DST)appl_object.o \
    $(APPL_DST)appl_object_handle.o \
    $(APPL_DST)appl_client.o \
    $(APPL_DST)appl_context_handle.o \
    $(APPL_DST)appl_heap.o \
    $(APPL_DST)appl_heap_std.o \
    $(APPL_DST)appl_options.o \
    $(APPL_DST)appl_options_std.o \
    $(APPL_DST)appl_thread_handle.o \
    $(APPL_DST)appl_thread_node.o \
    $(APPL_DST)appl_thread_std_node.o \
    $(APPL_DST)appl_thread_mgr.o \
    $(APPL_DST)appl_thread_std_mgr.o \
    $(APPL_DST)appl_test.o

# Common compiler flags for C and C++
APPL_FLAGS = -g -O0 -Wall -Wextra

# Append common flags to C compiler flags
APPL_CFLAGS += $(APPL_FLAGS)

# Append common flags to C++ compiler flags
APPL_CXXFLAGS += $(APPL_FLAGS)

# List of libraries required to link test application
APPL_TEST_LIBS = -lpthread

# Generic "all" rule, compile all targets
.PHONY: all
all : appl_test

# Define a phony rule for test application
.PHONY: appl_test
appl_test: $(APPL_DST)test_appl.exe

# Link of test application
$(APPL_DST)test_appl.exe : $(APPL_TEST_OBJS)
	$(APPL_CXX) -o $(APPL_DST)test_appl.exe $(APPL_CXXFLAGS) $(APPL_TEST_OBJS) $(APPL_TEST_LIBS)

# Compile of C source files
$(APPL_DST)%.o : $(APPL_SRC)%.c
	$(APPL_CC) -c -o $@ $(APPL_CFLAGS) $<

# Compile of C++ source files
$(APPL_DST)%.o : $(APPL_SRC)%.cpp
	$(APPL_CXX) -c -o $@ $(APPL_CXXFLAGS) $<

# Dependency on makefile and appl_project.mak
$(APPL_DST)test_appl.exe $(APPL_TEST_OBJS) : $(APPL_SRC)makefile $(APPL_SRC)appl_project.mak

# Generic "clean" rule, delete all object files
.PHONY: clean
clean: appl_clean

# Define a phony rule for clean of appl objects
.PHONY: appl_clean
appl_clean:
	-rm $(APPL_DST)*.o

# end-of-file: appl_project.mak
