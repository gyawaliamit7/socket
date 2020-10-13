all: server client

socServer: 	server.c soc.h
		$(cc)  -o server server.c

socClient: 	client.c soc.h
		$(cc)  -o client client.c
clean: rm -f client
	   rm -f server 
