#ifndef COMMON_THREAD_H
#define COMMON_THREAD_H

#include <stdbool.h>
#include <stddef.h>

// Thread related stuff available to user and kernel

#define INVALID_THREAD -1
// For the set/get property API
#define CURRENT_THREAD INVALID_THREAD

// Including null terminator
// So use this as the size of any buffer to hold a thread name
#define THREAD_NAME_SIZE 13
// Max strlen() of a thread name
#define THREAD_NAME_MAX_LEN (THREAD_NAME_SIZE - 1)

#define KCFG_DESTROY_ON_STACK_ERR 1 << 0
#define KCFG_LOG_SCHEDULER        1 << 1
#define KCFG_LOG_THREADS          1 << 2
#define KCFG_COLOUR_OUTPUT        1 << 3

#define TPROP_ID              0
#define TPROP_NAME            1
#define TPROP_CHILD           2
#define TPROP_STATE           3
#define TPROP_PERMISSIONS     4
#define TPROP_REGISTERS       5
#define TPROP_ERRNO_PTR       6
#define TPROP_PENDING_SIGNALS 7
#define TPROP_SIGNAL_HANDLER  8

#define TFLAG_KIND_MASK 0xFFFF
#define THREAD_FUNC     0
#define THREAD_FILE     1

// Amount to shift up when making "flags" for add_thread
#define TFLAG_PERM_SHIFT 16

#define TPERM_NONE          (0)
#define TPERM_ALL           (0xFFFF)
#define TPERM_CREATE        (1 << 0)
#define TPERM_FILE          (1 << 1)
#define TPERM_ALLOC         (1 << 2)
#define TPERM_KCONFIG       (1 << 3)
#define TPERM_TCONFIG       (1 << 4)
#define TPERM_TCONFIG_OTHER (1 << 5)

// Use when removing permissions via add_thread
#define TPERM_NO_ALL     ((uint32_t)TPERM_ALL << TFLAG_PERM_SHIFT)
#define TPERM_NO_CREATE  ((uint32_t)TPERM_CREATE << TFLAG_PERM_SHIFT)
#define TPERM_NO_FILE    ((uint32_t)TPERM_FILE << TFLAG_PERM_SHIFT)
#define TPERM_NO_ALLOC   ((uint32_t)TPERM_ALLOC << TFLAG_PERM_SHIFT)
#define TPERM_NO_KCONFIG ((uint32_t)TPERM_KCONFIG << TFLAG_PERM_SHIFT)
#define TPERM_NO_TCONFIG ((uint32_t)TPERM_TCONFIG << TFLAG_PERM_SHIFT)
#define TPERM_NO_TCONFIG_OTHER                                                 \
  ((uint32_t)TPERM_TCONFIG_OTHER << TFLAG_PERM_SHIFT)

#define YIELD_ANY  0
#define YIELD_TO   1
#define YIELD_NEXT 2

typedef struct {
  size_t a1;
  size_t a2;
  size_t a3;
  size_t a4;
} ThreadArgs;

// Note the () around the args so we don't mess up pointer
// arithmetic e.g. make_args(argv+1...) => (size_t)(argv+1)
#define make_args(a, b, c, d)                                                  \
  { (size_t)(a), (size_t)(b), (size_t)(c), (size_t)(d) }

#endif /* ifdef COMMON_THREAD_H */
