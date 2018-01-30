ifndef APPL_CXX
    APPL_CXX = $(CXX)
endif

APPL_THREAD_TEST_FLAGS = -g -O0 -Wall -Wextra -fno-exceptions -fno-rtti

APPL_THREAD_TEST_SRCS = \
    $(APPL_SRC)appl.cpp \
    $(APPL_SRC)appl_object.cpp \
    $(APPL_SRC)appl_heap.cpp \
    $(APPL_SRC)appl_heap_std.cpp \
    $(APPL_SRC)appl_client.cpp \
    $(APPL_SRC)appl_options.cpp \
    $(APPL_SRC)appl_options_std.cpp \
    $(APPL_SRC)appl_thread_test.cpp \
    $(APPL_SRC)appl_thread_mgr.cpp \
    $(APPL_SRC)appl_thread_std_mgr.cpp \
    $(APPL_SRC)appl_thread_node.cpp \
    $(APPL_SRC)appl_thread_std_node.cpp

APPL_THREAD_TEST_LIBS = \
    -lpthread

$(APPL_DST)test_appl_thread.exe : $(APPL_THREAD_TEST_SRCS)
	$(APPL_CXX) -o $(APPL_DST)test_appl_thread.exe $(APPL_THREAD_TEST_FLAGS) $(APPL_THREAD_TEST_SRCS) $(APPL_THREAD_TEST_LIBS)
