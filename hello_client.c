 #include <stdio.h>
  2 #include <stdlib.h>
  3 #include <string.h>
  4 #include <unistd.h>
  5 #include <arpa/inet.h>
  6 #include <sys/soket.h>
  7
  8 void error_handling(char *message);

int main(int argc, char *argv[])
{
	int sock;

	struct sockaddr_in serv_addr;
	char message[30];
	int str_len;
	
	if(argc!=3)
	{
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}

	sock = socket(PF_INET, SOCK_STREAM, 0);
	if(sock == -1)
		error_handling("socket() error");
	memset(&serv_addr, 0, sizeof(serv
-addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));

	if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr))==-1)
		error_handling("socket() error");
	str_len=read(sock,message,sizeof(message)-1);
	if(str_len == -1)
		error_handling("read() error!");
	printf("Message from server : %s \n", message);
	clode(sock);
	return 0 ;
		
}

void error_handling(char *mssage)
{
	fputs(message, stderr);
	fputs('\n', stderr);
	exit(1);
}
