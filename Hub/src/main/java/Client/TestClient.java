package Client;

import Controllers.SerialController;
import com.fazecast.jSerialComm.SerialPort;
import com.sun.tools.javac.Main;

import java.util.Scanner;

public class TestClient {
    public static void main(String[] args) {
        TestClient testClient = new TestClient();

        SerialController serialController = new SerialController();
        serialController.setSerialPort(SerialPort.getCommPorts()[0]);

        SerialPort serialPort = serialController.getSerialPort();
        serialPort.openPort();

        System.out.println("Com port open: " + serialPort.getDescriptivePortName());
        serialPort.addDataListener(serialController);

        testClient.runTestClient(serialController);
    }

    public void runTestClient(SerialController serialController) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.println("Enter the command:(devicetype:id:state)");
            String message = scanner.nextLine();
            serialController.setStringBuffer(message);
            serialController.sendRequest();
        }

    }
}
