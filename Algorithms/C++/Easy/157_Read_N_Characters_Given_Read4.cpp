// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int counter = 0;

        int readCharacterNumber;
        while (n > 0 && (readCharacterNumber = read4(buf + counter)) != 0) {
            if (n >= readCharacterNumber) {
                counter += readCharacterNumber;
                n -= readCharacterNumber;
            } else {
                for (int i = 0; i < readCharacterNumber - n; i++) {
                    buf[counter + readCharacterNumber - 1 - i] = '\0';
                }

                counter += n;
                n = 0;
            }
        }

        return counter;
    }
};
