# Minitalk-42
Minitalk is a 42 Network Project for Inter-processes Communication Using UNIX Signals

Minitalk is a small program written in C that allows you to send a message from a process called 'server' to another process named 'client'.

The main purpose of this 42 project is to introduce you to the fascinating world of Inter-process Communication, and how can a simple Process Communicate
to Another Process via Signals only.

## Methodology

According to POSIX Specifications, in every UNIX system there should be a 2 customizable Signals named SIGUSR1 and SIGUSR2 which a programmer can freely
use to communicate between 2 processes.

These 2 Signals are not specified by the system by rather by the user or the programmer, it's up to you to tell your program what to do when it receives
one of these 2 Signals.

## Algorithm to send a message by Signals


In my Minitalk, to send a message or a string to another a process I have broken it up into it's binary representation first, then once it's broken down
and I have the binary representation of each character in my message then I send SIGUSR1 Signal when I face a 0. And SIGUSR2 Signal when I find a 1 in the binary
representation of the string.

However, this may seem unclear at the beginning but let's consider the image below:
