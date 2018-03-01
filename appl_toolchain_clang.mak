# See LICENSE for license details

define appl-toolchain-clang-linker
	@echo linking $(1) with clang
	$(APPL_VERBOSE)echo -o $(1) $(APPL_CFLAGS-clang) $(3) $(2) $(foreach x,$(4),$(APPL_LIBRARY-$(x)-clang-lflags)) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_CC-clang) @$(strip $(1)).cmd
endef

define appl-toolchain-clang-c-compiler
	@echo compiling $(1) with clang
	$(APPL_VERBOSE)echo -c -o $(1) $(APPL_CFLAGS-clang) $(3) -DAPPL_OS_LINUX -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_CC-clang) @$(strip $(1)).cmd
endef

define appl-toolchain-clang-cxx-compiler
	@echo compiling $(1) with clang++
	$(APPL_VERBOSE)echo -c -o $(1) $(APPL_CXXFLAGS-clang) $(3) -DAPPL_OS_LINUX -MT $(1) -MMD -MP -MF $(1).d $(2) > $(1).cmd
	$(APPL_VERBOSE)$(APPL_CXX-clang) @$(strip $(1)).cmd
endef

