import Client.ServerClient;
import Listeners.SerialListener;
import Server.Server;
import com.fazecast.jSerialComm.SerialPort;

import static Listeners.SerialListener.serialPort;

public class Main {

    public static void main(String[] args) throws Exception {
        serialPort = SerialPort.getCommPorts()[0];
        serialPort.openPort();
        System.out.println("Com port open: " + serialPort.getDescriptivePortName());
        SerialListener listener = new SerialListener();
        serialPort.addDataListener(listener);

        Server server = new Server();
        server.run();
        Thread serverThread = new Thread() {
            @Override
            public void run() {
                server.run();
            }
        };
        serverThread.start();

    }
}
