package Client;

import Util.ReaderWriter;

import java.io.*;
import java.net.Socket;

/**
 * The Server Client class this class creates a TCP connection to the external servers
 * that deal with the front-end and backend connections, this class is used to send
 * messages of the change in states of the devices on the arduino
 *
 *   Attributes:
 *      hostname: The hostname a String is the address of the server.
 *      serverSocket: The server's socket a Socket that is used to get the input and output streams
 *          to establish a TCP connection.
 *      in: The input stream an Inputstream for the server so that data can be received by the
 *          server.
 *      out: The input stream an Outputstream for the server so that data can be sent to the
 *          server.
 */
public class ServerClient {

    private final String hostname = "194.47.32.227";
    private Socket serverSocket;
    private InputStream in;
    private OutputStream out;

    /**
     * This method is triggered by the Serial Controller to connect to the server in order to send a
     *  message due to a local state change in the arduino devices. The client connects to the server
     *  sends the message waits for a response, then it will close the connection.
     *
     * @param message : A string that contains the message received by the
     */
    public void sendMessage(String message) {
        message = "HUB-" + message;
        try {
            serverSocket = new Socket(hostname, 1234);
            out = serverSocket.getOutputStream();
            in = serverSocket.getInputStream();
            ReaderWriter readerWriter = new ReaderWriter();
            readerWriter.writer(message, out);

            message = readerWriter.read(in);
            System.out.println(message);
        } catch (IOException ioException) {
            System.out.println("I/O exception: " + ioException.getMessage());
        } finally {
            try {
                if (out != null) {
                    out.close();
                }
                if (in != null) {
                    in.close();
                }
            } catch (IOException ioException) {
                System.out.println("I/O exception: " + ioException.getMessage());
            }
        }
    }
}
