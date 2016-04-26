import java.io.*;
import java.util.NoSuchElementException;
import java.util.Scanner;

/**
 * Created by Administrator on 2016/4/26.
 */
public class StringToInt {

    public static void main( String[] args ) {

        Scanner scanner = new Scanner( new BufferedInputStream( System.in ) );
        String input = null;
        while ( ( input = scanner.nextLine() ) != null ) {
            Integer result = toInt( input );
            System.out.println( result );
        }

    }

    static Integer toInt( final String input ) {
        if ( input == null ) throw new IllegalArgumentException();
        char[] chars = null;
        boolean isMinus = false;
        if ( input.charAt( 0 ) == '-' ) {
            chars = input.substring( 1 ).toCharArray();
            isMinus = true;
        } else {
            chars = input.toCharArray();
            isMinus = false;
        }

        Integer result = null;
        try {
            result = toPositiveInt( chars );
            if ( isMinus ) result = -1 * result;
        } catch ( Exception e ) {
            e.printStackTrace();
            throw new IllegalArgumentException();
        } finally {
            return result;
        }
    }

    static Integer toPositiveInt(char[] chars) {
        if ( chars == null ) throw new IllegalArgumentException();
        Integer result = 0;
        for ( int i = 0; i < chars.length; ++i ) {
            char c = chars[i];
            if ( c - '0' > 9 || c - '0' < 0 ) {
                throw new IllegalArgumentException();
            } else {
                result = result * 10 + ( c - '0' );
            }
        }
        return result;
    }

}
