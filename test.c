
#include "mongoose.h"
#include <string.h>

static int begin_request_handler(struct mg_connection *conn) {
  // do something
  return 1;
}

int main() {
  struct mg_context *ctx;
  struct mg_callbacks callbacks;

  // List of options. Last element must be NULL.
  const char *options[] = {"listening_ports", "8080", NULL};

  // Prepare callbacks structure. We have only one callback, the rest are NULL.
  memset(&callbacks, 0, sizeof(callbacks));
  callbacks.begin_request = begin_request_handler;

  // Start the web server.
  ctx = mg_start(&callbacks, NULL, options);

  // Stop the server.
  mg_stop(ctx);

  return 0;
}