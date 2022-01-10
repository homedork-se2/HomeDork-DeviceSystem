package Util;
public class HashTable {
    private static HashTable hash = null;
    private StoredCommand[] hashtable;

    private HashTable() {
        hashtable = new StoredCommand[30];
        createHashTable();
        printHashtable();
    }

    public static HashTable getInstance() {
        if (hash == null) {
            hash = new HashTable();
        }
        return hash;
    }

    public void put(String key, byte binary) {
        int hashedKey = hashKey(key);
        if(occupied(hashedKey)) {
            int stopIndex = hashedKey;
            if(hashedKey == hashtable.length - 1) {
                hashedKey = 0;
            } else {
                hashedKey++;
            }

            while(occupied(hashedKey) && hashedKey != stopIndex) {
                hashedKey = (hashedKey + 1) % hashtable.length;
            }
        }
        if (occupied(hashedKey)) {
            System.out.println("Sorry the hashtable is full");
        } else {
            hashtable[hashedKey] = new StoredCommand(key, binary);
        }
    }

    public Byte get(String key) {
        int hashedKey = findKey(key);
        if (hashedKey == -1) {
            return null;
        }
        return hashtable[hashedKey].binary;
    }

    public Byte remove(String key) {
        int hashedKey = findKey(key);
        if(hashedKey == -1) {
            return null;
        }
        Byte binary = hashtable[hashedKey].binary;
        hashtable[hashedKey] = null;
        StoredCommand[] oldHashTable = hashtable;
        hashtable = new StoredCommand[oldHashTable.length];
        for (int i = 0; i < oldHashTable.length; i++) {
            if(oldHashTable[i] != null) {
                put(oldHashTable[i].key, oldHashTable[i].binary);
            }
        }
        return binary;
    }

    private int hashKey(String key) {
        return key.length() % hashtable.length;
    }

    private int findKey(String key) {
        int hashedKey = hashKey(key);
        if(hashtable[hashedKey] != null && hashtable[hashedKey].key.equals(key)) {
            return hashedKey;
        }

        int stopIndex = hashedKey;
        if(hashedKey == hashtable.length - 1) {
            hashedKey = 0;
        } else {
            hashedKey++;
        }

        while(hashtable[hashedKey] != null && !hashtable[hashedKey].key.equals(key) && hashedKey != stopIndex) {
            hashedKey = (hashedKey + 1) % hashtable.length;
        }

        if (hashtable[hashedKey] != null && hashtable[hashedKey].key.equals(key)) {
            return hashedKey;
        } else {
            return -1;
        }

    }

    private boolean occupied(int index) {
        return hashtable[index] != null;
    }

    public void printHashtable() {
        for (int i = 0; i < hashtable.length; i++) {
            if(hashtable[i] == null) {
                System.out.println("empty");
            } else {
                System.out.println("Position " + i + ": " + hashtable[i].binary);
            }

        }
    }

    private void createHashTable() {
        put("LAMP:11:ON", (byte) 11);
        put("LAMP:11:OFF", (byte) 33);
        put("LAMP:20:ON", (byte) 20);
        put("LAMP:20:OFF", (byte) 60);
        put("FAN:10:OFF", (byte) 10);
        put("FAN:10:LOW", (byte) 30);
        put("FAN:10:MEDIUM", (byte) 90);
        put("FAN:10:HIGH", (byte) 120);
        put("ALARM:69:ON", (byte) 69);
        put("ALARM:69:OFF", (byte) 68);
        put("TWILIGHT:ON", (byte) 70);
        put("TWILIGHT:OFF", (byte) 71);
    }
}
