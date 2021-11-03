package Server;

import Client.ServerClient;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;

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

        try {
            while (true) {
                byte[] bytes = new byte[1024];
                int length;
                while((length = in.read(bytes)) != -1) {
                    message = new String(bytes).trim();
                    System.out.println(message);
                }
            }

        } catch (IOException ioException) {
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
