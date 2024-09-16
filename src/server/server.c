#include "server.h"
#include "config/server.h"
#include "libs/uWebSockets/App.h"
#include "signaling/signaling.h"
#include "helpers/logger.h"

int start_server(const ServerConfig *config) {
    log_info("Starting server on port %d", config->port);

    uWS::App().ws<false>("/*", {
        .compression = uWS::SHARED_COMPRESSOR,
        .maxPayloadLength = 16 * 1024 * 1024,
        .idleTimeout = 16,
        .maxBackpressure = 1 * 1024 * 1024,
        .closeOnBackpressureLimit = false,
        .resetIdleTimeoutOnSend = false,
        .sendPingsAutomatically = true,
        .open = on_connection,
        .message = on_message,
        .close = on_disconnection
    }).listen(config->port, [config](auto *listen_socket) {
        if (listen_socket) {
            log_info("Listening on port %d", config->port);
        } else {
            log_error("Failed to listen on port %d", config->port);
        }
    }).run();

    return 0;
}