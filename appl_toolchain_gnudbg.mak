# See LICENSE for license details

define appl-toolchain-gnudbg-linker
	$(APPL_VERBOSE)echo -o $(1) -rdynamic $(APPL_CFLAGS-gnu) -DAPPL_OS_LINUX -DAPPL_DEBUG $(3) $(2) $(foreach x,$(4),$(APPL_LIBRARY-$(x)-gnu-lflags)) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_CC-gnu) @$(strip $(1)).cmd
endef

define appl-toolchain-gnudbg-c-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(APPL_CFLAGS-gnu) -DAPPL_OS_LINUX -DAPPL_DEBUG $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_CC-gnu) @$(strip $(1)).cmd
endef

define appl-toolchain-gnudbg-cxx-compiler
	$(APPL_VERBOSE)echo -c -o $(1) $(APPL_CXXFLAGS-gnu) -DAPPL_OS_LINUX -DAPPL_DEBUG $(3) -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_CXX-gnu) @$(strip $(1)).cmd
endef

