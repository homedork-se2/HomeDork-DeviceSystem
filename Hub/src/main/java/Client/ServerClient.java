package Client;

import java.io.*;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Arrays;

import static Listeners.SerialListener.*;
public class ServerClient {
    private String hostname = "localhost";
    private Socket serverSocket;
    private InputStream in;
    private OutputStream out;

    public void runListener() {

        try {
            Thread.sleep(1000);
            serverSocket = new Socket(hostname, 1234);
            in = serverSocket.getInputStream();
            System.out.println("Started ServerClient Listening for Commands..");
            while (true) {
                byte[] bytes = new byte[1024];
                int length;
                while ((length = in.read(bytes)) != -1) {
                    stringBuffer = Arrays.toString(bytes).trim();
                    System.out.println(stringBuffer);

                }

                String[] strings = stringBuffer.split(":");

                for (int i = 0; i < strings.length; i++) {
                    length = strings[i].getBytes().length;
                    bytes = new byte[length];
                    bytes = strings[i].getBytes();
                    serialPort.writeBytes(bytes, length);
                }


            }

        } catch (
                UnknownHostException unknownHostException) {
            System.out.println("UnknownHost exception" + unknownHostException.getMessage());
        } catch (
                IOException ioException) {
            System.out.println("I/O exception: " + ioException.getMessage());
        } catch (InterruptedException interruptedException) {
            interruptedException.printStackTrace();
        }
    }

    public void sendMessage(String message) {
        System.out.println(message);
        try {
            out = serverSocket.getOutputStream();
            byte[] bytes = message.getBytes();
            out.write(bytes, 0, bytes.length);
        } catch (IOException ioException) {
            System.out.println("I/O exception: " + ioException.getMessage());
        }
    }
}
