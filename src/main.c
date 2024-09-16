#include <stdio.h>
#include "server/server.h"
#include "config/server.h"

int main() {
	printf("Starting VoIP Signaling Server...\n");

	ServerConfig config;
	if (load_server_config(&config) != 0) {
			fprintf(stderr, "Failed to load server configuration\n");
			return 1;
	}

	if (start_server(&config) != 0) {
		fprintf(stderr, "Failed to start server\n");
		return 1;
	}

	return 0;
}