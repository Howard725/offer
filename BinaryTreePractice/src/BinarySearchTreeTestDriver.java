import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.NoSuchElementException;
import java.util.Scanner;

/**
 * Created by Administrator on 2016/4/27.
 */
public class BinarySearchTreeTestDriver {

    public static void main(String[] args) {

        BinarySearchTree<Integer> binarySearchTree = new BinarySearchTree<>();

//        Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        Scanner scanner = null;
        try {
            scanner = new Scanner( new BufferedInputStream( new FileInputStream("input.txt") ));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            return;
        }
        try {
                while( true ) {
                    Integer input = scanner.nextInt();
                    binarySearchTree.insert(input);
                }
            } catch (NoSuchElementException e) {
//                e.printStackTrace();
            }

        binarySearchTree.printTree();
    }

}
