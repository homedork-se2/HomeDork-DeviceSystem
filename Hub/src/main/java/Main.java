import Controllers.SerialController;
import Server.Server;

import Util.HashTable;
import com.fazecast.jSerialComm.SerialPort;

/**
 * The Main class that starts the server and the listener.
 */
public class Main {

    public static void main(String[] args) {
        HashTable main = HashTable.getInstance();
        main.printHashtable();
        Server server = new Server();
        server.run();
    }
}