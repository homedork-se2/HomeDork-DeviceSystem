package Client;

import java.io.*;
import java.net.Socket;
import java.net.UnknownHostException;
import java.nio.charset.StandardCharsets;
import java.util.Arrays;

import static Listeners.SerialListener.*;
public class ServerClient {
    private final String hostname = "194.47.32.227";
    private Socket serverSocket;
    private InputStream in;
    private OutputStream out;

    public void runListener() {

        try {
            Thread.sleep(1000);
            serverSocket = new Socket(hostname, 1234);
//            serverSocket = new Socket("localhost", 5777);
            in = serverSocket.getInputStream();
            out = serverSocket.getOutputStream();
            System.out.println("Started Server Client Listening for Commands..");
            Thread.sleep(1000);
            while (true) {
                byte[] bytes = new byte[1024];
                int length;

                while ((length = in.read(bytes)) != -1) {
                    String stringBuffer = new String(bytes).trim();
                    System.out.println(stringBuffer);

                }

//                String[] strings = stringBuffer.split(":");
//
//                for (int i = 0; i < strings.length; i++) {
//                    System.out.println(strings[i]);
////                    length = strings[i].getBytes().length;
////                    bytes = new byte[length];
////                    bytes = strings[i].getBytes();
////                    serialPort.writeBytes(bytes, length);
//                }


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
        message = "HUB-" + message;
        try {
            serverSocket = new Socket(hostname, 1234);
            out = serverSocket.getOutputStream();
            byte[] bytes = message.getBytes();
            out.write(bytes, 0, bytes.length);
            out.flush();
        } catch (IOException ioException) {
            System.out.println("I/O exception: " + ioException.getMessage());
        }
    }
}
