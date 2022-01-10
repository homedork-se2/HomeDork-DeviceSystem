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
        if (message.contains("FAN")) {
            if (message.contains("ON")) {
                message = "FAN:10:MEDIUM";
            } else if (message.contains("OFF")) {
                message = "FAN:10:OFF";
            } else {
                message.replace("'", "").trim();
                String[] strings = message.split(":");
                float value = Float.parseFloat(strings[2]);
                if (value == 0) {
                    message = "FAN:10:OFF";
                } else if (value > 0 && value < 25) {
                    message = "FAN:10:LOW";
                } else if (value > 25 && value < 70) {
                    message = "FAN:10:MEDIUM";
                } else {
                    message = "FAN:10:HIGH";
                }
            }
        }
        byte outMessage = HashTable.getInstance().get(message.replace("'", "").trim());
        System.out.println(outMessage);

        Logger.writeToLog("src/logs/command.txt", message.trim() + "\r\n");
        SerialController.getInstance().setResponse(true);
        out = SerialController.getInstance().getSerialPort().getOutputStream();
        try {
            out.write(outMessage);
            out.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
        SerialController.getInstance().sendRequest(message.trim());
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