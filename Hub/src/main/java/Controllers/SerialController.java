package Controllers;

import Client.ServerClient;
import Util.Logger;
import Util.ReaderWriter;
import com.fazecast.jSerialComm.SerialPort;
import com.fazecast.jSerialComm.SerialPortDataListener;
import com.fazecast.jSerialComm.SerialPortEvent;

import java.io.IOException;
import java.io.InputStream;
import java.nio.BufferOverflowException;
import java.util.HashMap;

/**
 * The Serial Controller class is a class for sending data to the Arduino
 * and receiving data from the Arduino on the serial port. This class implements
 * the SerialPortDataListener interface to handle listening for data from the
 * Arduino in the background.
 * <p>
 * Attributes:
 * serialPort: An instance of the SerialPort class is the port that the
 * Arduino is connected to.
 * stringBuffer: A String that acts as the buffer for the data to be written
 * into.
 * isResponse: A Boolean that is for establishing whether the incoming data
 * from the listener is a response to a command or an event that occurred
 * locally on the Arduino.
 */
public class SerialController implements SerialPortDataListener {
    private static SerialController serialController = null;
    private SerialPort serialPort;
    private String stringBuffer;
    private boolean isResponse;
    private HashMap<Integer, String> sensorDevices = null;

    private SerialController() {
        this.setSerialPort(SerialPort.getCommPorts()[0]);
        this.serialPort = this.getSerialPort();
        this.serialPort.openPort();
        this.serialPort.setBaudRate(9600);

        System.out.println("Com port open: " + serialPort.getDescriptivePortName());
        this.serialPort.addDataListener(this);
        sensorDevices = new HashMap<>();
        initializeHashMap();
    }

    public static SerialController getInstance() {
        if (serialController == null) {
            serialController = new SerialController();
        }
        return serialController;
    }

    /**
     * A method that sends a request from the server to the Arduino, the response is
     * set to true because a response is expected the message is sent via bytes.
     */
    public void sendRequest(String message) {
        ReaderWriter readerWriter = new ReaderWriter();

        this.stringBuffer = message;
        this.setResponse(true);
        this.serialPort.openPort();
        readerWriter.writer(this.getStringBuffer(), this.serialPort.getOutputStream());
        this.setResponse(false);
        this.stringBuffer = "";
    }

    /**
     * This method is an override method that is implemented by the interface.
     *
     * @return An int is returned that will determine if there is data available to read,
     * if data is available it returns a 1 else it will return a 0.
     */
    @Override
    public int getListeningEvents() {
        return SerialPort.LISTENING_EVENT_DATA_AVAILABLE;
    }

    /**
     * This method is and override method that in implemented by the interface,
     * the method handles an event from the arduino if data is not available it will
     * return otherwise the data will be received and placed in the string buffer.
     * If the isResponse boolean is true it will just print the data otherwise it will
     * send the data to the client to send to the server.
     *
     * @param serialPortEvent: The parameter that this method takes is the serial port event
     *                         which will be called by the listener.
     */
    @Override
    public void serialEvent(SerialPortEvent serialPortEvent) {
        new Thread(() -> {
            if (serialPortEvent.getEventType() != SerialPort.LISTENING_EVENT_DATA_AVAILABLE)
                return;
            try {
                if (!this.serialPort.isOpen()) {
                    this.serialPort.openPort();
                }
                InputStream in = this.serialPort.getInputStream();
                ReaderWriter readerWriter = new ReaderWriter();
                String message = readerWriter.read(in).replace(" ", "");
                String[] responses = message.split(";");
                for (int i = 0; i < responses.length; i++) {
                    responses[i].replace("\\s", "");
                    if (responses[i].length() < 3 || responses[i].contains(" ")) {
                        continue;
                    }
                    String[] bytes = responses[i].split(":");
                    if (bytes.length == 2) {
                        try {
                            if (bytes[1].length() == 1) {
                                if (Integer.parseInt(bytes[1]) == 1) {
                                    bytes[1] = "ON";
                                } else if (Integer.parseInt(bytes[1]) == 0) {
                                    bytes[1] = "OFF";
                                }
                            }
                            if (bytes[0].length() <= 2) {
                                stringBuffer = this.sensorDevices.get(Integer.parseInt(bytes[0]));
                                stringBuffer += bytes[1].trim();

                                Logger.writeToLog("src/logs/returns.txt", this.getStringBuffer().trim() + "\r\n");
                                //ServerClient serverClient = new ServerClient();
                                //serverClient.sendMessage(stringBuffer);
                            }
                        } catch (NumberFormatException e) {
                            System.out.println(bytes[0]);
                            System.out.println(bytes[1]);
                            System.out.println("ser" + e.getMessage());
                        }
                    }
                }
            } catch (BufferOverflowException e) {
                e.printStackTrace();
            }
        }).start();
    }

    /**
     * This method sets the serial port.
     *
     * @param serialPort: Will take the serialport as the parameter to set.
     */
    public void setSerialPort(SerialPort serialPort) {
        this.serialPort = serialPort;
    }

    /**
     * This method sets the string buffer.
     *
     * @param stringBuffer: Will take the string buffer as the parameter to set.
     */
    public void setStringBuffer(String stringBuffer) {
        this.stringBuffer = stringBuffer;
    }

    /**
     * This method is a get method for the serial port.
     *
     * @return This method returns the serial port.
     */
    public SerialPort getSerialPort() {
        return serialPort;
    }

    /**
     * This method is a get method for the string buffer.
     *
     * @return This method returns the string buffer.
     */
    public String getStringBuffer() {
        return stringBuffer;
    }

    /**
     * This is a get method for isResponse which is a boolean that designates if the
     * event from the arduino is a response to something.
     *
     * @return This method returns a boolean isResponse.
     */
    public boolean isResponse() {
        return isResponse;
    }

    /**
     * This method is a set method for the isResponse boolean.
     *
     * @param response This method takes a boolean as a parameter
     */
    public void setResponse(boolean response) {
        isResponse = response;
    }

    public void initializeHashMap() {
        sensorDevices.put(28, "CURTAIN:28:");
        sensorDevices.put(29, "CURTAIN:29:");
        sensorDevices.put(99, "ELECTRIC:A0:");
        sensorDevices.put(10, "FAN:10:");
        sensorDevices.put(38, "FAN:38:");
        sensorDevices.put(11, "LAMP:11:");
        sensorDevices.put(20, "LAMP:20:");
        sensorDevices.put(22, "LAMP:22:");
        sensorDevices.put(7, "POWERCUTOFF:7:");
        sensorDevices.put(25, "RADIATOR:1:");
        sensorDevices.put(23, "RADIATOR:2:");
        sensorDevices.put(21, "SIREN:21:");
        sensorDevices.put(3, "DOOR:3:");
        sensorDevices.put(70, "TWILIGHT:");
        sensorDevices.put(2, "FIREALARM:");
        sensorDevices.put(69, "SECURITYALARM:");
        sensorDevices.put(100, "TEMP:1:");
        sensorDevices.put(101, "TEMP:2:");
        sensorDevices.put(5, "Stove:5:");
        sensorDevices.put(6, "WINDOW:6:");
        sensorDevices.put(9, "TEMP:OUT:");
        sensorDevices.put(18, "TIMER:1:");
        sensorDevices.put(19, "TIMER:2:");
        sensorDevices.put(4, "WATERLEAK:4:");


    }
}