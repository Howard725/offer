//
// Created by Administrator on 2016/3/2.
//

#include <string.h>
#include <stdlib.h>
#include "CMyString.h"

CMyString::CMyString( char* pData )
{
    if ( pData == NULL )
    {
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
    else
    {
        int len = strlen( pData );
        m_pData = new char[len + 1];
        strcpy( m_pData, pData );
    }
}

CMyString::CMyString(const CMyString &str)
{
    int len = strlen( str.m_pData );
    m_pData = new char[len + 1];
    strcpy( m_pData, str.m_pData );
}

CMyString::~CMyString()
{
    delete[] m_pData;
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
































