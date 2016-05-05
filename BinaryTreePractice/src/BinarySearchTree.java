import java.util.Stack;

/**
 * Created by Administrator on 2016/4/27.
 */
public class BinarySearchTree<T extends Comparable< ? super T > > {

    private static class BinaryTreeNode<T> {
        public T element;
        public BinaryTreeNode<T> leftChild;
        public BinaryTreeNode<T> rightChild;

        public BinaryTreeNode(T element) {
            this( element, null, null );
        }

        public BinaryTreeNode(T element, BinaryTreeNode<T> leftChild, BinaryTreeNode<T> rightChild) {
            this.element = element;
            this.leftChild = leftChild;
            this.rightChild = rightChild;
        }
    }

    private BinaryTreeNode<T> root;

    public void insert( T value ) {
        root = insert( root, value );
    }

    public void printTree( ) {
        System.out.println("\n-------------printTreePreRecursively----------------");
        printTreePreRecursively( root );
        System.out.println("\n-------------printTreePreLoop---------------------");
        printTreePreLoop( root );
        System.out.println("\n-------------printTreeMidRecursively---------------");
        printTreeMidRecursively( root );
        System.out.println("\n-------------printTreeMidLoop-----------------------");
        printTreeMidLoop( root );
        System.out.println("\n-------------printTreePostRecursively---------------");
        printTreePostRecursively( root );
        System.out.println("\n-------------printTreePostLoop-----------------------");
        printTreePostLoop( root );
    }

    private void printTreeMidRecursively(BinaryTreeNode<T> root) {
        if ( root == null ) return;
        printTreeMidRecursively( root.leftChild );
        System.out.print( root.element.toString() + '\t' );
        printTreeMidRecursively( root.rightChild );
    }

    private void printTreeMidLoop(final BinaryTreeNode<T> root) {
        Stack< BinaryTreeNode<T> > stack = new Stack<>();
        BinaryTreeNode<T> current = root;

        //当前节点为空并且堆栈为空时结束循环
        while ( current != null || !stack.isEmpty() ) {
            //首先一直向左找到最左的节点
            if ( current.leftChild != null ) {
                stack.push(current);
                current = current.leftChild;
            } else {
                //没有左儿子，就先打印自己，尝试寻找右儿子
                System.out.print( current.element.toString() + '\t' );
                current = current.rightChild;
                while ( current == null && !stack.isEmpty() ) {
                    //右儿子为空，则打印父节点，并尝试寻找父节点的右儿子
                    current = stack.pop();
                    System.out.print( current.element.toString() + '\t' );
                    current = current.rightChild;
                }
            }
        }
    }

    private void printTreePreLoopByMyself( final BinaryTreeNode<T> root) {
        Stack< BinaryTreeNode<T> > stack = new Stack<>();
        stack.push( root );
        while ( ! stack.isEmpty() ){
            //从栈中取出节点
            BinaryTreeNode<T> current = stack.pop();
            //打印当前节点的内容
            System.out.print( current.element.toString() + '\t' );
            //查看是否有右、左节点，有则入站
            if ( current.rightChild != null )
                stack.push( current.rightChild );
            if ( current.leftChild != null )
                stack.push( current.leftChild );
        }
    }

    private void printTreePreLoop(final BinaryTreeNode<T> root ) {
        Stack< BinaryTreeNode<T> > stack = new Stack<>();
        BinaryTreeNode<T> current = root;

        while ( current != null ) {
            //对于当前节点，先打印，再入站，再过渡到左子节点
            System.out.print( current.element.toString() + '\t' );
            stack.push( current );
            current = current.leftChild;
            //左子节点为空时，尝试寻找未遍历过的右子节点
            while ( ( current == null ) && ( !stack.isEmpty() )) {
                //未遍历过的右子节点一定是栈中节点的右子节点，找到后设置为当前节点
                current = stack.pop();
                current = current.rightChild;
            }
        }
    }

    private BinaryTreeNode<T> insert(BinaryTreeNode<T> root, T value ) {

        if ( root == null ) {
            return new BinaryTreeNode<T>( value );
        } else {
            int result = value.compareTo( root.element );
            if ( result < 0 ) {
                root.leftChild = insert( root.leftChild, value );
            } else if ( result > 0 ) {
                root.rightChild = insert( root.rightChild, value );
            } else {

            }
            return root;
        }
    }

    private void printTreePreRecursively(BinaryTreeNode<T> root ) {
        if ( root != null ) {
            System.out.print( root.element.toString() + '\t' );
            printTreePreRecursively(root.leftChild);
            printTreePreRecursively(root.rightChild);
        }
    }

    private void printTreePostRecursively( BinaryTreeNode<T> root ) {
        if ( root != null ) {
            printTreePostRecursively(root.leftChild);
            printTreePostRecursively(root.rightChild);
            System.out.print( root.element.toString() + '\t' );
        }
    }

    private void printTreePostLoop( BinaryTreeNode<T> root ) {
        if ( root != null ) {
            Stack<BinaryTreeNode<T> > stack = new Stack<>();
            BinaryTreeNode<T> pre = null;
            BinaryTreeNode<T> current = null;

            stack.push( root );

            while ( !stack.isEmpty() ) {

                //将当前节点指向站顶。（本句放在循环末尾会导致异常）
                current = stack.peek();

                //在没有左右孩子或者左右孩子其中有一个已经输出的情况下，输出本节点并出栈
                if ( ( current.rightChild == null && current.leftChild == null )
                        || ( pre != null && ( current.rightChild == pre || current.leftChild == pre ) )){
                    System.out.print( current.element.toString() + '\t' );
                    pre = current;
                    stack.pop();
                } else {
                    //除上述两种情况，将右左孩子存在的前提的下入栈
                    if (current.rightChild != null) {
                        stack.push(current.rightChild);
                    }
                    if (current.leftChild != null) {
                        stack.push(current.leftChild);
                    }
                }
            }
        }
    }
}





















