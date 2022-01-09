package Controllers;

import Util.Logger;
import Util.ReaderWriter;
import com.fazecast.jSerialComm.SerialPort;
import com.fazecast.jSerialComm.SerialPortDataListener;
import com.fazecast.jSerialComm.SerialPortEvent;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.nio.BufferOverflowException;
import java.util.Scanner;

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
    private boolean commandFlag;
    private Scanner scanner;

    private SerialController() {
        this.setSerialPort(SerialPort.getCommPorts()[0]);
        serialPort = this.getSerialPort();
        serialPort.openPort();
        serialPort.setBaudRate(9600);
        System.out.println("Com port open: " + serialPort.getDescriptivePortName());
        serialPort.addDataListener(this);
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
        this.stringBuffer = message.replace("'", "").trim();
        this.setResponse(true);
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
                InputStream in = this.serialPort.getInputStream();
                ReaderWriter readerWriter = new ReaderWriter();
                this.stringBuffer = readerWriter.read(in);
                System.out.println(this.stringBuffer);
                setStringBuffer(this.stringBuffer.trim());
                if (!isResponse()) {
                    //            ServerClient serverClient = new ServerClient();
                    Logger.writeToLog("src/logs/sensor.txt", this.getStringBuffer().trim() + "\r\n");
                    //            serverClient.sendMessage(stringBuffer);
                } else {
                    Logger.writeToLog("./src/logs/arduinoResponse.txt", this.getStringBuffer().trim() + "\r\n");
                }



                if (!isResponse()) {
//            ServerClient serverClient = new ServerClient();
                    Logger.writeToLog("src/logs/sensor.txt", serialController.getStringBuffer().trim() + "\r\n");
//            serverClient.sendMessage(stringBuffer);
                } else {
                    Logger.writeToLog("./src/logs/arduinoResponse.txt", "Response: " + serialController.getStringBuffer().trim() + "\r\n");
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
}