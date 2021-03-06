package homedork.code.hdapi.security;

import javax.crypto.BadPaddingException;
import javax.crypto.Cipher;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.NoSuchPaddingException;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.security.*;
import java.security.cert.CertificateException;
import java.util.Base64;

/**
 * Houses cipher setup, encryption and decryption methods
 * Uses key from @KeyLoader
 */
public class CryptoHandler {


	public CryptoHandler() throws Exception {
		setUpCipher();
	}

	// test
	public static void main(String[] args) throws Exception {
		CryptoHandler cryptoHandler = new CryptoHandler();
		cryptoHandler.setUpCipher();

		String enc = cryptoHandler.aesEncrypt("hello");
		System.out.println(enc);

		String message = cryptoHandler.aesDecrypt(enc.getBytes(StandardCharsets.UTF_8));
		System.out.println(message);
	}

	Cipher cipher = null;
	Key key = null;
	SecretKeySpec secretKey;
	byte[] iv = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	IvParameterSpec ivParameterSpec = new IvParameterSpec(iv);


	private void setUpCipher() throws Exception{
		cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");
	}

	public String aesEncrypt(String message) throws Exception {
		byte[] encryptText = message.getBytes();

		cipher.init(Cipher.ENCRYPT_MODE, KeyLoader.loader(), ivParameterSpec);
		byte[] encryptedBytes = cipher.doFinal(encryptText);

		return Base64.getEncoder().encodeToString(encryptedBytes);
	}

	public String aesDecrypt(byte[] cipherText) throws Exception {
		String encryptedString;
		byte[] encryptText = null;

		encryptText = Base64.getDecoder().decode(cipherText);
		cipher.init(Cipher.DECRYPT_MODE, KeyLoader.loader(), ivParameterSpec);
		encryptedString = new String(cipher.doFinal(encryptText));

		return encryptedString;
	}

}
