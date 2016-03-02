//
// Created by Administrator on 2016/3/2.
//

#ifndef INC_01_ASSIGNMENTOPERATOR_CMYSTRING_H
#define INC_01_ASSIGNMENTOPERATOR_CMYSTRING_H

#include <stddef.h>

class CMyString
{
public:
    CMyString( char* pData = NULL );
    CMyString( const CMyString& str );
    ~CMyString();

    CMyString& operator=( const CMyString& str );

private:
    char* m_pData;
};

#endif //INC_01_ASSIGNMENTOPERATOR_CMYSTRING_H
