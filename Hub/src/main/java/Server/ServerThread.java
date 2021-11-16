package Server;

import Controllers.SerialController;

import java.io.*;
import java.net.Socket;

/**
 * The server thread class takes its inheritance from the Thread class, the class
 * runs a thread of the server handles the communication between the client and
 * server.
 */
public class ServerThread extends Thread {
    Socket clientSocket;
    SerialController serialController;

    /**
     * This is the constructor of the ServerThread class is takes the serialController
     * to handle serial port communication of the arduino and the clientSocket to handle
     * communication between the server client.
     * @param clientSocket the client socket
     * @param serialController the serial controller for the Arduino.
     */
    public ServerThread(Socket clientSocket, SerialController serialController) {
        this.clientSocket = clientSocket;
        this.serialController = serialController;
    }


    /**
     * This method is an override method of the Thread class method which runs the
     * thread, this method in particular handles the communication of the client server.
     */
    public void run() {

        InputStream in = null;
        OutputStream out = null;

        String message = "";
        try {
            in = clientSocket.getInputStream();
            out = clientSocket.getOutputStream();

        } catch (IOException ioException) {
            System.out.println("I/O Exception connecting the streams to the client...\n" + ioException.getMessage());
        }

        System.out.println(clientSocket);
        try {
            while (true) {
                byte[] bytes = new byte[1024];
                int length;

                while((length = in.read(bytes)) != -1) {
                    message = new String(bytes).trim();
                    System.out.println(message);

                    serialController.setStringBuffer(message);
                    serialController.sendRequest();
                }

                message = serialController.getStringBuffer().trim();
                bytes = message.getBytes();
                out.write(bytes, 0, bytes.length);

            }

        } catch (IOException ioException) {
            System.out.println("I/O Exception in reading and/or writing...\n" + ioException.getMessage());
        }

        try {
            if (clientSocket != null) {
                clientSocket.close();
            }
            if (in != null) {
                in.close();
            }
            if (out != null) {
                out.close();
            }
        } catch (IOException ioException) {
            System.out.println("I/O Exception couldn't close\n" + ioException.getMessage());
        }

    }
}
