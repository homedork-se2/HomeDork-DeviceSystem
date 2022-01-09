package Server;

import Controllers.SerialController;
import Util.Logger;
import Util.ReaderWriter;
import com.fazecast.jSerialComm.SerialPort;

import java.io.*;
import java.net.Socket;

/**
 * The server thread class takes its inheritance from the Thread class, the class
 * runs a thread of the server handles the communication between the client and
 * server.
 */
public class ServerThread extends Thread {
    Socket clientSocket;
    InputStream in = null;
    OutputStream out = null;

    /**
     * This is the constructor of the ServerThread class is takes the serialController
     * to handle serial port communication of the arduino and the clientSocket to handle
     * communication between the server client.
     * @param clientSocket the client socket
     *  the serial controller for the Arduino.
     */
    public ServerThread(Socket clientSocket) {
        this.clientSocket = clientSocket;
    }


    /**
     * This method is an override method of the Thread class method which runs the
     * thread, this method in particular handles the communication of the client server.
     */
    public void run() {
        try {

            in = clientSocket.getInputStream();
            out = clientSocket.getOutputStream();
        } catch (IOException ioException) {
            System.out.println("I/O Exception connecting the streams to the client...\n" + ioException.getMessage());
        }
        SerialController.getInstance().setStringBuffer("");
        ReaderWriter readerWriter = new ReaderWriter();
        String message = readerWriter.read(in);
        System.out.println(message.trim());
        Logger.writeToLog("src/logs/command.txt", message.trim() + "\r\n");
        SerialController.getInstance().setResponse(true);
        SerialController.getInstance().sendRequest(message.trim());
        readerWriter.writer(SerialController.getInstance().getStringBuffer().trim(), out);
        SerialController.getInstance().setResponse(false);
        try {
            if (in != null) {
                in.close();
            }
            if (out != null) {
                out.close();
            }
            if (clientSocket != null) {
                clientSocket.close();
            }
        } catch (IOException ioException) {
            System.out.println(ioException.getMessage());
        }
    }
}