APPL_THREAD_TEST_FLAGS = -g -O0 -Wall -Wextra -fno-exceptions -fno-rtti

APPL_THREAD_TEST_SRCS = \
    appl_thread_test.cpp \
    appl_thread_mgr.cpp \
    appl_object.cpp \
    appl_thread_std_mgr.cpp \
    appl_thread_node.cpp \
    appl_thread_std_node.cpp

APPL_THREAD_TEST_LIBS = \
    -lpthread

test : $(APPL_THREAD_TEST_SRCS)
	$(CXX) -o test $(APPL_THREAD_TEST_FLAGS) $(APPL_THREAD_TEST_SRCS) $(APPL_THREAD_TEST_LIBS)
