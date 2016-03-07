#include <iostream>
#include <stdlib.h>
#include "List.h"

using namespace std;


int main() {
    cout << "Hello, World!" << endl;

/*    Node node = CreateNode(1);
    Node* head = &node;
    *head = NULL;*/
    Node node = NULL;
    Node* head = &node;
    int temp = 0;
    while( cin >> temp )
    {
        AddToTail( head, temp );
    }

    PrintReversinglyRecursively( *head );
    PrintReversinglyIteratively( *head );

    system("PAUSE");
    return 0;
}