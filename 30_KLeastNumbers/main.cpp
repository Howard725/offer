#include <iostream>
#include <vector>
#include <set>
#include <stdlib.h>

using namespace std;

typedef multiset< int, greater<int> > intSet;
typedef multiset< int, greater<int> >::iterator setIterator;

void GetLeastNumbers( const vector<int>& array, intSet &leastNumbers, int k )
{
    if ( k > array.size() || k <= 0 )
        return;

    //遍历array
    vector<int>::const_iterator arrayIter = array.begin();
    setIterator setIter;
    for ( ; arrayIter != array.end(); ++arrayIter )
    {
        //如果leastNumbers未满，则插入
        if ( leastNumbers.size() < k )
            leastNumbers.insert( *arrayIter );
        else
        {
            //如果leastNumbers已满，则于最大值对比
            //若比最大值大，抛弃；若比最大值小，删除最大值，插入该值
            setIter = leastNumbers.begin();
            if ( *arrayIter < *setIter )
            {
                leastNumbers.erase( *setIter );
                leastNumbers.insert( *arrayIter );
            }
        }
    }
}

void print( const intSet& set )
{
    setIterator iter = set.begin();
    for ( ; iter != set.end(); ++iter )
        cout << *iter << '\t';
    cout << endl;
}

int main() {
    cout << "Hello, World!" << endl;

    vector<int> data;
    intSet leastNumbers;
    for ( int i = 0; i < 100; ++i )
        data.push_back( i );

    GetLeastNumbers( data, leastNumbers, 0 );

    print( leastNumbers );

    system("PAUSE");
    return 0;
}