#ifndef SERVER_CONFIG_H
#define SERVER_CONFIG_H

typedef struct {
  int port;
  char db_host[256];
  char db_name[64];
  char db_user[64];
  char db_password[64];
  char valkey_host[256];
  int valkey_port;
} ServerConfig;

int load_server_config(ServerConfig *config);

#endif // SERVER_CONFIG_H