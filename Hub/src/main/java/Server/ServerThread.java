package Server;

import java.io.*;
import java.net.Socket;

import static Listeners.SerialListener.serialPort;
import static Listeners.SerialListener.stringBuffer;

public class ServerThread extends Thread{
    Socket clientSocket = null;


    public ServerThread(Socket clientSocket) {
        this.clientSocket = clientSocket;
    }

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
                    stringBuffer = new String(bytes).trim();
                    System.out.println(stringBuffer);
                    String[] strings = stringBuffer.split(":");

                    for (int i = 0; i < strings.length; i++) {
                        strings[i] = strings[i].replace("'","");
                        System.out.println("Inside loop for serial");
                        System.out.println(strings[i]);
                        length = strings[i].getBytes().length;
                        bytes = new byte[length];
                        bytes = strings[i].getBytes();
                        serialPort.writeBytes(bytes, length);
                    }
                }


                Thread.sleep(2000);
            }

        } catch (IOException | InterruptedException ioException) {
            System.out.println("I/O Exception in reading and/or writing...\n" + ioException.getMessage());
        }

        try {
            clientSocket.close();
            in.close();
            if (out != null) {
                out.close();
            }
        } catch (IOException ioException) {
            System.out.println("I/O Exception couldn't close\n" + ioException.getMessage());
        }

    }
}
