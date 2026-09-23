#ifndef PORT_SWITCH_NEWLIB_COMPAT_H
#define PORT_SWITCH_NEWLIB_COMPAT_H

/* Force-included into the decomp (ssb64_game) TUs on Switch only.
 *
 * decomp/include/stddef.h shadows the compiler's <stddef.h>. newlib's
 * <sys/_types.h> (pulled in by <stdio.h>) requests wint_t through the
 * `#define __need_wint_t` + `#include <stddef.h>` protocol, which the shim
 * doesn't implement, so provide it up front. _WINT_T is GCC's own guard, so
 * a later include of the real <stddef.h> won't redefine it. */
#ifndef _WINT_T
#define _WINT_T
typedef __WINT_TYPE__ wint_t;
#endif

#endif /* PORT_SWITCH_NEWLIB_COMPAT_H */
