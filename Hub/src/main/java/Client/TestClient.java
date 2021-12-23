package Client;

import Util.Logger;
import Util.ReaderWriter;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

public class TestClient {
    private Scanner scanner;
    private String message = "";

    public static void main(String[] args) {
        TestClient run = new TestClient();
        run.scanner = new Scanner(System.in);
        while (true) {
            try {
                while (true) {
                    run.printMenu();
                    String choice = run.scanner.nextLine();
                    run.handleChoice(choice);
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

        }
    }

    private void printMenu() {
        System.out.println("======Menu======");
        System.out.println("1)Indoor Light ON");
        System.out.println("2)Indoor Light OFF");
        System.out.println("3)Outdoor Light ON");
        System.out.println("4)Outdoor Light OFF");
        System.out.println("5)Fan Low");
        System.out.println("6)Fan Medium");
        System.out.println("7)Fan High");
        System.out.println("8)Fan OFF");
        System.out.println("9)Arm Alarm");
        System.out.println("10)Disarm Alarm");
        System.out.println("11)Activate Twilight System");
        System.out.println("12)Deactivate Twilight System");
        System.out.println("13)Set Indoor Temperature");
        System.out.println("14)Window OPEN");
        System.out.println("15)window CLOSED");
        System.out.println("q)QUIT");
        System.out.print("ADMIN$:");

    }

    private void handleChoice(String choice) throws InterruptedException {
        boolean isLegit = false;
        switch (choice) {
            case "1" -> {
                message = "lamp:11:ON";
                isLegit = true;
            }
            case "2" -> {
                message = "lamp:11:OFF";
                isLegit = true;
            }
            case "3" -> {
                message = "lamp:20:ON";
                isLegit = true;
            }
            case "4" -> {
                message = "lamp:20:OFF";
                isLegit = true;
            }
            case "5" -> {
                message = "fan:10:26";
                isLegit = true;
            }
            case "6" -> {
                message = "fan:10:100";
                isLegit = true;
            }
            case "7" -> {
                message = "fan:10:200";
                isLegit = true;
            }
            case "8" -> {
                message = "fan:10:0";
                isLegit = true;
            }
            case "9" -> {
                message = "alarm:00:ARMED";
                isLegit = true;
            }
            case "10" -> {
                message = "alarm:00:DISARMED";
                isLegit = true;
            }
            case "11" -> {
                message = "twilight:00:ON";
                isLegit = true;
            }
            case "12" -> {
                message = "twillight:00:OFF";
                isLegit = true;
            }
            case "13" -> {
                double temp = 0;
                while (true) {
                    try {
                        System.out.print("ADMIN$:");
                        temp = Double.parseDouble(scanner.nextLine());
                        break;
                    } catch (NumberFormatException e) {
                        System.out.println("Please enter a valid number");
                    }
                }
                message = "temp:00:" + temp;
                isLegit = true;
            }
            case "14" -> {
                message = "window:6:OPEN";
                isLegit = true;
            }
            case "15" -> {
                message = "window:6:CLOSED";
                isLegit = true;
            }
            case "q" -> {
                System.out.println("Goodbye!");
                Thread.sleep(1000);
                System.exit(0);
            }
            default -> System.out.println("Please enter a valid option.");
        }

        if (isLegit) {
            OutputStream out = null;
            InputStream in = null;
            Socket socket = null;
            try {
                String hostname = "192.168.56.1";
                socket = new Socket(hostname, 1234);
                in = socket.getInputStream();
                out = socket.getOutputStream();

                ReaderWriter readerWriter = new ReaderWriter();
                readerWriter.writer(message, out);
                System.out.println(readerWriter.read(in));

            } catch (IOException e) {
                e.printStackTrace();
            } finally {
                try {
                    if (out != null) {
                        out.close();
                    }
                    if (in != null) {
                        in.close();
                    }
                    if (socket != null) {
                        socket.close();
                    }
                } catch (IOException ioException) {
                    ioException.printStackTrace();
                }
            }
        }
    }
}

