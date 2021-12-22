package Util;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.time.LocalDateTime;

public class Logger {
    public static void writeToLog(String fileName, String value) {
        OutputStream fos = null;
        LocalDateTime date = LocalDateTime.now();
        value = date.toString() + ": " + value + " ";
        try {
            fos = new FileOutputStream(fileName, true);
            fos.write(value.getBytes());
            fos.flush();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                if (fos != null) {
                    fos.close();
                }
            } catch (IOException exception) {
                exception.printStackTrace();
            }
        }
    }
}
