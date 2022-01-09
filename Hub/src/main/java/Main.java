import Controllers.SerialController;
import Server.Server;

import com.fazecast.jSerialComm.SerialPort;

/**
 * The Main class that starts the server and the listener.
 */
public class Main {

    public static void main(String[] args) {
        Server server = new Server();
        server.run();
    }
}