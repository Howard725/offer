#include <iostream>
#include <stdlib.h>
#include "BinaryTree.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;

/*    int preOrder[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
    int midOrder[] = { 4, 7, 2, 1, 5, 3, 8, 6 };*/
    int preOrder[] = { 1, 2, 3, 4, 5 };
    int midOrder[] = { 2, 1, 6, 4, 5 };
/*    int *preOrder = NULL;
    int *midOrder = NULL;*/

    BNode BinaryTree = Construct( preOrder, sizeof(preOrder)/sizeof(int), midOrder, sizeof(midOrder)/sizeof(int) );

    system("PAUSE");
    return 0;
}