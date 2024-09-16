# VoIP Signaling Server

This project implements a high-performance VoIP (Voice over IP) signaling server using C and uWebSockets. It's designed to handle WebRTC signaling, manage user sessions, and facilitate various types of voice communications including one-to-one, group chats, and community interactions.

## Features

- High-performance WebSocket server using uWebSockets
- WebRTC signaling support
- One-to-one, group, and community chat capabilities
- Integration with Valkey for caching (alternative to Redis)
- Flexible authentication system
- Scalable and modular architecture

## Project Structure

```
sando/
├── src/
│   ├── main.c
│   ├── server/
│   ├── signaling/
│   ├── auth/
│   ├── database/
│   ├── cache/
│   ├── chat/
│   ├── community/
│   └── helpers/
├── include/
├── config/
├── tests/
├── docs/
├── scripts/
├── libs/
│   └── uWebsockets/
├── Makefile
└── README.md
```

## Prerequisites

- C compiler (GCC or Clang)
- CMake (version 3.10 or higher)
- OpenSSL development files
- zlib development files

## Installation

1. Clone the repository:
  ```
   git clone https://github.com/yourusername/voip_signaling_server.git
   cd voip_signaling_server
  ```

2. Install uWebSockets:
  ```
   mkdir -p third_party
   cd third_party
   git clone https://github.com/uNetworking/uWebSockets.git
   cd uWebSockets
   git submodule update --init --recursive
   make
   cd ../..
  ```

3. Build the project:
  ```
   mkdir build
   cd build
   cmake ..
   make
  ```

## Configuration

Edit the configuration files in the `config/` directory to set up your server:

- `server.h`: Configure server port, database connection, and Valkey settings

## Building uWebSockets library
Follow the instructions below to build the uWebSockets library:

```
cd sando
mkdir -p libs
cd libs
git clone https://github.com/uNetworking/uWebSockets.git
cd uWebSockets
git submodule update --init --recursive
make
```

## Running the Server

After building the project, you can run the server using:

```
./build/voip_server
```

## Testing

To run the tests:

```
cd build
make test
```

## Documentation

API documentation and additional details can be found in the `docs/` directory.

## Contributing

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments

- uWebSockets library
- Valkey caching system

## Contact

Fredrick Femar Ochieng - isfescii@gamail.com

Project Link: https://github.com/aduki-Inc/sando