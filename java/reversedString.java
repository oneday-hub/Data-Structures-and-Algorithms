
//import java.util.*;

public class reversedString {

    public static void main(String[] args) {
        StringBuilder sb = new StringBuilder("hello");

        for (int i = sb.length() - 1; i >= 0; i--) {
            System.out.print(sb.charAt(i));
        }
    }
}


