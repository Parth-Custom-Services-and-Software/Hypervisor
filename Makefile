all: testing

testing : testing.c
	clang -Wall -Wextra -g testing.c -o testing -framework Hypervisor

