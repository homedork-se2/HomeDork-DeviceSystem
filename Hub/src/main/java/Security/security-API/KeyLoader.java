package homedork.code.hdapi.security;

import javax.crypto.SecretKey;
import java.io.FileInputStream;
import java.io.IOException;
import java.security.KeyStore;
import java.security.KeyStoreException;
import java.security.NoSuchAlgorithmException;
import java.security.UnrecoverableEntryException;
import java.security.cert.CertificateException;

/**
 * Encryption and decryption key loader class
 * API and server exchange "messages +  resp. pub(key)"
 * This class loads the api pub. and private keys from a keystore.
 */
public class KeyLoader {

	static SecretKey loader() throws KeyStoreException, IOException, CertificateException, NoSuchAlgorithmException, UnrecoverableEntryException {
		KeyStore keyStore = KeyStore.getInstance("JCEKS");

		// load key store
		String path = "/Users/willz/IdeaProjects/hd-API/NewKeyStore.jks";
		char[] password = "changeit".toCharArray();

		FileInputStream fileInputStream = new FileInputStream(path);
		keyStore.load(fileInputStream, password);

		KeyStore.ProtectionParameter protectionParameter = new KeyStore.PasswordProtection(password);
		KeyStore.SecretKeyEntry secretKeyEntry = (KeyStore.SecretKeyEntry) keyStore.getEntry("secretKeyAlias", protectionParameter);

		SecretKey secretKey = secretKeyEntry.getSecretKey();
		// System.out.println(new String(secretKey.getEncoded()));

		fileInputStream.close();
		return secretKey;
	}
}
