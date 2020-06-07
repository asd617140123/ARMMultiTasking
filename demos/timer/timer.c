#include "user/thread.h"
#include "user/util.h"
#include "thread.h"
#include "timer.h"
#include "util.h"
#include <string.h>

const char* msgs[] = {
    "zero",
    "one",
    "two",
    NULL,
};
const char** curr_msg = msgs;

void thread_work() {
  if (!*curr_msg) {
    log_event("three");
    exit(0);
  }

  log_event(*curr_msg);
  curr_msg++;
  add_thread(thread_work);
  enable_timer();
  while (1) { //!OCLINT
  }
}

void setup(void) {
  k_add_thread(thread_work);
}
