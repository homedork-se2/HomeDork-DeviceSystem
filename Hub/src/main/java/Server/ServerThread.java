package Server;

import Controllers.SerialController;
import Util.HashTable;
import Util.Logger;
import Util.ReaderWriter;
import com.fazecast.jSerialComm.SerialPort;

import java.io.*;
import java.net.Socket;
import java.util.List;

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
        SerialController.getInstance().getSerialPort().openPort();
        ReaderWriter readerWriter = new ReaderWriter();
        String message = readerWriter.read(in);
        message = message.replace("'", "").trim().replace(" ", "");
        Logger.writeToLog("src/logs/command.txt", message + "\r\n");
        String[] strings = message.split(":");
        byte messageValue = -1;
        if (message.contains("ON")) {
            messageValue = 1;
        } else if (message.contains("OFF")){
            messageValue = 0;
        } else {
            try {
                float value = Float.parseFloat(strings[2]);
                messageValue = (byte) Math.round(value);
                System.out.println("MESSAGE VALUE: " + messageValue);
            } catch (NumberFormatException e) {
                System.out.println("message value" + e.getMessage());
            }
        }
        message = strings[0] + ":" + strings[1];

        byte outMessage = HashTable.getInstance().get(message);
        System.out.println("logged: " + message);
        System.out.print("sent: " + outMessage);
        System.out.println(", " + messageValue);

        SerialController.getInstance().setResponse(true);
        out = SerialController.getInstance().getSerialPort().getOutputStream();
        try {
            out.write(new byte[]{outMessage, messageValue}, 0 ,2);
            out.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }

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