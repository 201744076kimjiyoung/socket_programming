import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

svrIP = input(("Sever IP(Sever IP(default: 127.0.0.1): "))
if svrIP=='':
    svrIP= '127.0.0.1'

port = input('port(default: 2500):')
if port == '':
    port = 2500
else:
    port = int(port)

sock.connect((svrIP,port))
print('Connetcted to' + svrIP)

while True:
    msg = input("Sending message: ")

    if not msg:
        continue

    try:
        sock.send(msg.encode())

    except:
        print("연결종료")
        break
    try:
        msg = sock.recv(1024)
        if not msg:
            print("연결종료")
            break
        print(f'Received message: {msg.decode()}')

    except:
        print("연결이 종료되었습니다")
sock.close()
