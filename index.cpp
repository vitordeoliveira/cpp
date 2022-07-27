#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <cassert>

const char html[] = "HTTP/1.1 200 OK\r\n"
"Connection: close\r\n"
"Content-type: text/html\r\n"
"\r\n"
"<html>\r\n"
"<head>\r\n"
"<title>Hello, world!</title>\r\n"
"</head>\r\n"
"<body>\r\n"
"<h1>Hello, world!</h1>\r\n"
"</body>\r\n"
"</html>\r\n\r\n";

int main() {
    WSADATA wsa;

    assert( WSAStartup( MAKEWORD( 2, 2 ), &wsa ) == 0 );

    addrinfo *res = NULL;
    addrinfo hints;

    ZeroMemory( &hints, sizeof( hints ) );

    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    assert( getaddrinfo( NULL, "80", &hints, &res ) == 0 );

    SOCKET s = socket( res->ai_family, res->ai_socktype, res->ai_protocol );

    assert( s != INVALID_SOCKET );
    assert( bind( s, res->ai_addr, (int)res->ai_addrlen ) != SOCKET_ERROR );
    assert( listen( s, SOMAXCONN ) != SOCKET_ERROR );

    SOCKET client = accept( s, NULL, NULL );

    assert( client != INVALID_SOCKET );

    char buffer[512];
    int bytes;

    bytes = recv( client, buffer, 512, 0 );

    for ( int i = 0; i < bytes; ++i ) {
        std::cout << buffer[i];
    }

    assert( send( client, html, strlen( html ) - 1, 0 ) > 0 );
    assert( shutdown( client, SD_BOTH ) != SOCKET_ERROR );

    closesocket( client );
    WSACleanup();

    return 0;
}