package Server;

import java.io.IOException;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {

    public void run() {
        ServerSocket serverSocket = null;
        Socket clientSocket = null;
        try {
            serverSocket = new ServerSocket(1234);
            InetAddress localAddress = InetAddress.getLocalHost();
            System.out.println(localAddress);
            System.out.println(serverSocket.getLocalPort());
        } catch (IOException ioException) {
            System.out.println("I/O Exception couldn't initialize socket to listen\n" + ioException.getMessage());
        }

        while (true) {
            try {
                clientSocket = serverSocket.accept();
                System.out.println(serverSocket.getInetAddress());
                System.out.println("Client: " + clientSocket.getInetAddress());
                ServerThread server = new ServerThread(clientSocket);
                server.start();
            } catch (IOException ioException) {
                System.out.println("I/O Exception couldn't begin accepting.\n" + ioException.getMessage());
            }
        }
    }
}
