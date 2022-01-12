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
        put("LAMP:11", (byte) 11);
        put("LAMP:20", (byte) 20);
        put("FAN:10", (byte) 10);
        put("ALARM:69", (byte) 69);
        put("TWILIGHT:70", (byte) 70);
        put("TEMP:1", (byte) 100);
    }
}
