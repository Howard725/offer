//
// Created by Administrator on 2016/3/2.
//

#include <string.h>
#include <stdlib.h>
#include "CMyString.h"

CMyString::CMyString( char* pData )
{
    m_pData = pData;
}

CMyString::CMyString(const CMyString &str)
{
    if ( this != &str )
    {
        int _cnt = strlen( str.m_pData );
        char *temp = (char *) malloc( _cnt * sizeof(char) + 1 );

        for ( int i = 0; i <= _cnt; ++i )
            temp[i] = str.m_pData[i];

        m_pData = temp;
    }
}

CMyString::~CMyString()
{
    delete []m_pData;
}

CMyString& CMyString::operator=( const CMyString& str )
{
    if ( this != &str )
    {
        CMyString temp(str);
        char* tempPtr = temp.m_pData;
        temp.m_pData = m_pData;
        m_pData = tempPtr;
    }
    return *this;
}
































