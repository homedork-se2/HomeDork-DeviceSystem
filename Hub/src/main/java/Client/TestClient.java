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
            try {
                Thread.sleep(2000);
                System.out.println("Enter the command:(devicetype:id:state)");
                String message = scanner.nextLine();
                serialController.setStringBuffer(message);
                serialController.sendRequest();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

        }

    }
}
