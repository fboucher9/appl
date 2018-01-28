# See LICENSE for license details

ifndef APPL_SRC
    APPL_SRC =
endif

ifndef APPL_DST
    APPL_DST =
endif

ifndef APPL_CC
    APPL_CC = $(CC)
endif

ifndef APPL_CXX
    APPL_CXX = $(CXX)
endif

ifndef APPL_CFLAGS
    APPL_CFLAGS = $(CFLAGS)
endif

ifndef APPL_CXXFLAGS
    APPL_CXXFLAGS = $(CXXFLAGS)
endif

APPL_TEST_OBJS = \
    $(APPL_DST)appl.o \
    $(APPL_DST)appl_object.o \
    $(APPL_DST)appl_client.o \
    $(APPL_DST)appl_heap.o \
    $(APPL_DST)appl_heap_std.o \
    $(APPL_DST)appl_options.o \
    $(APPL_DST)appl_options_std.o \
    $(APPL_DST)appl_test.o

APPL_FLAGS = -g -O0 -Wall -Wextra

APPL_CFLAGS += $(APPL_FLAGS)

APPL_CXXFLAGS += $(APPL_FLAGS)

.PHONY: all
all : appl_test

.PHONY: appl_test
appl_test: $(APPL_DST)test_appl.exe

$(APPL_DST)test_appl.exe : $(APPL_TEST_OBJS)
	$(APPL_CXX) -o $(APPL_DST)test_appl.exe $(APPL_CFLAGS) $(APPL_TEST_OBJS)

$(APPL_DST)%.o : $(APPL_SRC)%.c
	$(APPL_CC) -c -o $@ $(APPL_CFLAGS) $<

$(APPL_DST)%.o : $(APPL_SRC)%.cpp
	$(APPL_CXX) -c -o $@ $(APPL_CXXFLAGS) $<

$(APPL_DST)test_appl.exe $(APPL_TEST_OBJS) : $(APPL_SRC)appl_project.mak

.PHONY: clean
clean: appl_clean

.PHONY: appl_clean
appl_clean:
	-rm $(APPL_DST)*.o
