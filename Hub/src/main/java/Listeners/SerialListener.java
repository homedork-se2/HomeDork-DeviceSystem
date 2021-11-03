package Listeners;

import Client.ServerClient;
import com.fazecast.jSerialComm.SerialPort;
import com.fazecast.jSerialComm.SerialPortDataListener;
import com.fazecast.jSerialComm.SerialPortEvent;

public class SerialListener implements SerialPortDataListener {
    public static SerialPort serialPort;
    public static String stringBuffer;
    public ServerClient serverClient;

    public SerialListener(ServerClient serverClient) {
        this.serverClient = serverClient;
    }
    @Override
    public int getListeningEvents() {
        return SerialPort.LISTENING_EVENT_DATA_AVAILABLE;
    }

    @Override
    public void serialEvent(SerialPortEvent serialPortEvent) {
        if (serialPortEvent.getEventType() != SerialPort.LISTENING_EVENT_DATA_AVAILABLE)
            return;

        byte[] newData = new byte[serialPort.bytesAvailable()];
        int numRead = serialPort.readBytes(newData, newData.length);
        stringBuffer = new String(newData,0,numRead);

        System.out.print(stringBuffer.trim());
//        serverClient.sendMessage(stringBuffer.trim());
    }

    public void setSerialPort(SerialPort serialPort) {
        this.serialPort = serialPort;
    }

    public void setStringBuffer(String stringBuffer) {
        this.stringBuffer = stringBuffer;
    }

    public SerialPort getSerialPort() {
        return serialPort;
    }

    public String getStringBuffer() {
        return stringBuffer;
    }
}
