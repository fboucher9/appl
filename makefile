# See LICENSE for license details

# Define list of projects to include
APPL_PROJECT_LIST += $(APPL_SRC)appl_target_test1.mak
APPL_PROJECT_LIST += $(APPL_SRC)appl_target_library.mak

include $(APPL_SRC)appl_project.mak

# end-of-file: makefile
