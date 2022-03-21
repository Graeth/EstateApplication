

#include "mongoose.h"
#include <string>
#include <iostream>

// Struct settings server http mongoose
static void fn(struct mg_connection *c, int ev, void *ev_data, void *fn_data) {
  struct mg_http_serve_opts opts = {.root_dir = "./WebServer"};   // Serve local dir
  if (ev == MG_EV_HTTP_MSG) mg_http_serve_dir(c, (mg_http_message *) ev_data, &opts);
}

int initServer(int port) {
	struct mg_mgr mgr;
  mg_mgr_init(&mgr);                                        // Init manager
  mg_http_listen(&mgr, "http://0.0.0.0:8000", fn, &mgr);  // Setup listener
  for (;;) mg_mgr_poll(&mgr, port);                         // Event loop
  mg_mgr_free(&mgr);  
	
	return 0;
}
int main(int argc, char **argv)
{
	initServer(1000);
	return 0;
}

