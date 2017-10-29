#ifndef MESSAGE_H
#define MESSAGE_H

#include <stdlib.h>

#define MAX_NAME 256
#define MAX_DATA 2048

#define MAX_MESSAGE sizeof(struct message)

typedef unsigned int message_t;

struct message {
  message_t type;
  size_t size;
  char source[MAX_NAME];
  char data[MAX_DATA];
};

#define UNKNOWN 0
#define LOGIN 1
#define LO_ACK 2
#define LO_NAK 3
#define EXIT 4
#define JOIN 5
#define JN_ACK 6
#define JN_NAK 7
#define LEAVE_SESS 8
#define NEW_SESS 9
#define NS_ACK 10
#define MESSAGE 11
#define QUERY 12
#define QU_ACK 13

void parse_message(const char* buf, struct message* m);
// @server response to client
int response(int sockfd, message_t type, const char* data);
#endif
