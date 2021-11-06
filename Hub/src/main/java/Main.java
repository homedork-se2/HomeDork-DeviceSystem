import Controllers.SerialController;
import Server.Server;

import com.fazecast.jSerialComm.SerialPort;

/**
 * The Main class that starts the server and the listener.
 */
public class Main {

    public static void main(String[] args) {
        SerialController serialController = new SerialController();
        serialController.setSerialPort(SerialPort.getCommPorts()[0]);

        SerialPort serialPort = serialController.getSerialPort();
        serialPort.openPort();

        System.out.println("Com port open: " + serialPort.getDescriptivePortName());
        serialPort.addDataListener(serialController);

        Server server = new Server();
        Thread serverThread = new Thread() {
            @Override
            public void run() {
                server.run(serialController);
            }
        };
        serverThread.start();

    }
}
