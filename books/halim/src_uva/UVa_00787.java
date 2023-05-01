import java.util.LinkedList;
import java.util.Scanner; 
import java.util.*;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.math.BigInteger;

class Main {

    public static BigInteger result(BigInteger list[], int l) {
        BigInteger max_ = list[0];
        BigInteger cNeg = list[0];
        BigInteger cPos = list[0];

        for (int i = 1; i < l; ++i) {
            BigInteger oPos = cPos;
            BigInteger oNeg = cNeg;

            cPos = oNeg.multiply(list[i])
                    .max(
                        list[i].max(
                            cPos.multiply(list[i])
                        )
                    );
            cNeg = oPos.multiply(list[i])
            .min(
                list[i].min(
                    cNeg.multiply(list[i])
                )
            ); 
            max_ = max_.max(cPos);
        }

        return max_;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BigInteger[] array = new BigInteger[105];
        int l = 0;
        while (scanner.hasNextInt()) {
            int i = scanner.nextInt();
            if (i == -999999) {
                BigInteger r = result(array, l);
                System.out.println(r);
                l = 0;
            } else {
                array[l++] = new BigInteger(String.valueOf(i));
            }
        }
    }
}
