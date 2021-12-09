package Client;

import Controllers.SerialController;
import com.fazecast.jSerialComm.SerialPort;
import com.sun.tools.javac.Main;

import java.util.Scanner;

public class TestClient extends Thread {
    SerialController serialController;

    public TestClient(SerialController serialController) {
        this.serialController = serialController;
    }

    public void run() {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.println("Enter the command:(devicetype:id:state)");
            String message = scanner.nextLine();
            serialController.setStringBuffer(message);
            serialController.sendRequest();
        }

    }
}
