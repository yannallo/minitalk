# Minitalk

![status](https://img.shields.io/badge/status-finished-success)
![Language](https://img.shields.io/badge/language-C-blue)
![Static Badge](https://img.shields.io/badge/Norminette-%E2%9C%93-success)

## A small data exchange program

Minitalk is a lightweight communication system that sends text from a client to a server using only the UNIX signals `SIGUSR1` and `SIGUSR2`.
The client encodes each character bit by bit, and the server reconstructs the message by decoding the incoming signals.
The communication works by providing the PID of the server to the client.

## Features

This project includes a few improvements over the mandatory requirements:
- Acknowledgment System (ACK)

   After processing each character, the server sends a signal back to the client.
  
- Unicode Support

   The client can use UTF-8 in its message.

- Large file handling

   The server sends a signal to the client to avoid overflowing the signal queue using `pause()`.

## Installation

```Bash
# Clone repository
git clone https://github.com/yannallo/minitalk.git

# Enter directory
cd minitalk

# Build
make
```

# Usage

### Start the server
```Bash
./server
Pid = <PID>
```
Keep the server running. It waits for incoming messages.

```Bash
./client <PID> "Message"
```
The server will print the received text to its standard output.
