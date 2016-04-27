import java.io.BufferedInputStream;
import java.util.NoSuchElementException;
import java.util.Scanner;

/**
 * Created by Administrator on 2016/4/27.
 */
public class BinarySearchTreeTestDriver {

    public static void main(String[] args) {

        BinarySearchTree<Integer> binarySearchTree = new BinarySearchTree<>();

        Scanner scanner = new Scanner(new BufferedInputStream(System.in));
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
