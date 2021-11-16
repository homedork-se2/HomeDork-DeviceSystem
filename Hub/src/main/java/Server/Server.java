package Server;

import Controllers.SerialController;

import java.io.IOException;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;

/**
 * This class is a server class that starts the server and awaits a connection from a
 * client. Once a client is connected a server thread is created with the client socket.
 */
public class Server {

    /**
     * This method is to start the server, get the server socket, and get the client socket.
     * once the client connects the socket is created and then a thread is created to run
     * the server.
     * @param serialController This method takes the Serial Controller as a parameter in order to
     *                         give the server access to the serial port for communication.
     */
    public void run(SerialController serialController) {
        ServerSocket serverSocket = null;
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
                Socket clientSocket = serverSocket.accept();
                System.out.println(serverSocket.getInetAddress());
                System.out.println("Client: " + clientSocket.getInetAddress());
                ServerThread server = new ServerThread(clientSocket, serialController);
                server.start();
            } catch (IOException ioException) {
                System.out.println("I/O Exception couldn't begin accepting.\n" + ioException.getMessage());
            }
        }
    }
}
