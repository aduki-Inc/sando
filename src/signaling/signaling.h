#ifndef SIGNALING_H
#define SIGNALING_H

#include <uwebsockets/WebSocket.h>

void on_connection(uWS::WebSocket<false, true> *ws);
void on_message(uWS::WebSocket<false, true> *ws, std::string_view message, uWS::OpCode opCode);
void on_disconnection(uWS::WebSocket<false, true> *ws, int code, std::string_view message);

#endif // SIGNALING_H