import Client.ServerClient;
import Listeners.SerialListener;
import com.fazecast.jSerialComm.SerialPort;

import static Listeners.SerialListener.serialPort;

public class Main {

    public static void main(String[] args) throws Exception {
        ServerClient serverClient = new ServerClient();
        Thread clientListenerThread = new Thread() {
            @Override
            public void run() {
                serverClient.runListener();
            }
        };
        clientListenerThread.start();
        serialPort = SerialPort.getCommPorts()[0];
        serialPort.openPort();
        System.out.println("Com port open: " + serialPort.getDescriptivePortName());
        SerialListener listener = new SerialListener(serverClient);
        serialPort.addDataListener(listener);
        System.out.println();

    }
}
