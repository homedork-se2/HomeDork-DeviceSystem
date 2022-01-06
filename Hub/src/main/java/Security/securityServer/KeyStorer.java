package homedork.code.hdapi.security;

import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import javax.crypto.spec.SecretKeySpec;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.security.Key;
import java.security.KeyStore;
import java.security.KeyStoreException;
import java.security.NoSuchAlgorithmException;
import java.security.cert.CertificateException;

public class KeyStorer {

	// keystore file already created! - on my machine
	/**
	 * public static void main(String[] args) throws CertificateException, NoSuchAlgorithmException, IOException, KeyStoreException {
		storeKey();
	}*/

	static void storeKey() throws NoSuchAlgorithmException, IOException, CertificateException, KeyStoreException {
		// initialize keyStore
		KeyStore keyStore = null;
		try {
			keyStore = KeyStore.getInstance("JCEKS");
		} catch (KeyStoreException e) {
			e.printStackTrace();
		}

		// load keystore from cacerts file
		char[] password = "changeit".toCharArray();
		String path = "C:\\Program Files\\Java\\jdk-15.0.1\\lib\\security\\cacerts";
		try {
			FileInputStream fileInputStream = new FileInputStream(path);
			assert keyStore != null;
			keyStore.load(fileInputStream, password);
		} catch (IOException | NoSuchAlgorithmException | CertificateException e) {
			e.printStackTrace();
		}

		//Creating the KeyStore.ProtectionParameter object
		KeyStore.ProtectionParameter protectionParameter = new KeyStore.PasswordProtection(password);

		// Secret key object
		KeyGenerator keyGenerator = KeyGenerator.getInstance("AES");
		keyGenerator.init(256);
		Key key = keyGenerator.generateKey();
		SecretKey secretKey = new SecretKeySpec(key.getEncoded(), "AES");

		// Secret key entry
		KeyStore.SecretKeyEntry secretKeyEntry = new KeyStore.SecretKeyEntry(secretKey);

		// set an entry to the key store
		try {
			assert keyStore != null;
			keyStore.setEntry("secretKeyAlias", secretKeyEntry, protectionParameter);
		} catch (KeyStoreException e) {
			e.printStackTrace();
		}

		// store key store
		FileOutputStream fileOutputStream = new FileOutputStream("NewKeyStore.jks");
		keyStore.store(fileOutputStream, password);

		System.out.println("Key stored");
	}
}
