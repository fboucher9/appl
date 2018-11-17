# See LICENSE for license details

#
#  Module: appl_target_library.mak
#
#  Description:
#      Build a static library for appl project.
#

ifndef appl_target_library.mak-included
appl_target_library.mak-included := 1

include $(APPL_SRC)appl_target_base.mak

target-list += appl_library

appl_library-name = appl

appl_library-type = dll

appl_library-exports = appl.exports

appl_library-deps = \
    $(appl_base-deps)

endif # ifndef appl_target_library.mak-included

# end-of-file: appl_target_library.mak
