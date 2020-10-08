#include "user/fibre.h"
#include "port/port.h"
#include <string.h>

extern void set_context_from_stack_address(void);

static void init_context(UserContext* ctx) {
  memset(ctx, 0, sizeof(UserContext));
}

void make_context(UserContext* ctx, void (*function)(UserContext*), uint8_t* stack_ptr) {
  init_context(ctx);

  // Align to 16 bytes for AArch64
  ctx->sp = ALIGN_STACK_PTR((size_t)stack_ptr);
  ctx->pc = (size_t)function;

  // In case the function returns normally, we'll catch it
  ctx->lr = (size_t)set_context_from_stack_address;
  // Putting the address of the return context on the new fibre's stack
  ctx->sp -= sizeof(UserContext*);
  // Note that we align, then write to it
  ctx->sp = ALIGN_STACK_PTR(ctx->sp);

  UserContext** ctx_addr_on_stack = (UserContext**)ctx->sp;
  *ctx_addr_on_stack = ctx;
}
