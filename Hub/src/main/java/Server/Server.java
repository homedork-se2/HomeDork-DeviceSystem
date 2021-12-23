package Server;

import Controllers.SerialController;
import com.fazecast.jSerialComm.SerialPort;

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
     */
    public void run() {
        ServerSocket serverSocket = null;
        SerialController serialController = null;
        try {
            serverSocket = new ServerSocket(1234);
            InetAddress localAddress = InetAddress.getLocalHost();

            System.out.println(localAddress);
            System.out.println(serverSocket.getLocalPort());

            serialController = new SerialController();
            serialController.setSerialPort(SerialPort.getCommPorts()[0]);
            SerialPort serialPort = serialController.getSerialPort();
            serialPort.setBaudRate(9600);
            serialPort.setComPortTimeouts(SerialPort.TIMEOUT_SCANNER, 0,0 );
            serialPort.openPort();

            Thread.sleep(100);

            System.out.println("Com port open: " + serialPort.getDescriptivePortName());
            serialPort.addDataListener(serialController);

        } catch (IOException | InterruptedException ioException) {
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
