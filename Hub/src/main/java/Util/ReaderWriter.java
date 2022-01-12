package Util;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;

public class ReaderWriter {
    public String read(InputStream in) {
        String message = "";
        try {
            byte[] bytes = new byte[8*1024];
            int length = in.read(bytes);
            message = new String(bytes);
            in.close();
            //System.out.println(message);
        } catch (IOException exception) {
            exception.printStackTrace();
        }
        return message;
    }

    public void writer(String message, OutputStream out) {
        try {
            byte[] bytes;
            bytes = message.getBytes();
            out.write(bytes, 0, message.length());
            out.flush();
            out.close();
        } catch (IOException ioException) {
            System.out.println(ioException.getMessage());
        }
    }
}