syscalls = (
    # Name and whether the call has a return value
    ("add_thread",          True),
    ("get_thread_property", True),
    ("set_thread_property", True),
    ("get_kernel_config",   True),
    ("set_kernel_config",   False),
    ("yield",               False),
    ("get_msg",             True),
    ("send_msg",            True),
    ("thread_wait",         False),
    ("thread_wake",         True),
    ("thread_cancel",       True),
    ("mutex",               True),
    # One of the ops does return void but we return
    # true from kernel for that anyway
    ("condition_variable",  True),
    ("open",                True),
    ("read",                True),
    ("write",               True),
    ("lseek",               True),
    ("remove",              True),
    ("close",               True),
    ("exit",                False),
    ("malloc",              True),
    ("realloc",             True),
    ("free",                False),
    ("list_dir",            True),
)
