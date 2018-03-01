# See LICENSE for license details

define appl-toolchain-gnu-linker
	@echo linking $(1) with gcc
	$(APPL_VERBOSE)echo -o $(1) $(APPL_CFLAGS-gnu) $(3) $(2) $(foreach x,$(4),$(APPL_LIBRARY-$(x)-gnu-lflags)) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_CC-gnu) @$(strip $(1)).cmd
endef

define appl-toolchain-gnu-c-compiler
	@echo compiling $(1) with gcc
	$(APPL_VERBOSE)echo -c -o $(1) $(APPL_CFLAGS-gnu) $(3) -DAPPL_OS_LINUX -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_CC-gnu) @$(strip $(1)).cmd
endef

define appl-toolchain-gnu-cxx-compiler
	@echo compiling $(1) with g++
	$(APPL_VERBOSE)echo -c -o $(1) $(APPL_CXXFLAGS-gnu) $(3) -DAPPL_OS_LINUX -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_CXX-gnu) @$(strip $(1)).cmd
endef

