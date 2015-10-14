/*
    Author: Alexander Sholohov <ra9yer@yahoo.com>
*/


#include "TQth.h"
#include "utils.h"

//-----------------------------------------------------------------------------
TQth::TQth()
{
    memset(&m_qth, 0, sizeof(m_qth));
}

//-----------------------------------------------------------------------------
TQth::~TQth()
{
}

//-----------------------------------------------------------------------------
bool TQth::initFromLatLon( double lat, double lon, double alt )
{
    if( lat < -90 || lat > 90 )
        return false;

    if( lon < -180 || lon > 180 )
        return false;

    m_qth.lat = lat;
    m_qth.lon = lon;
    m_qth.alt = alt;

    return true;
}

//-----------------------------------------------------------------------------
static bool isMajorCharOk(char ch)
{
    return (ch >= 'A' && ch <='R');
}

//-----------------------------------------------------------------------------
static bool isDigit(char ch)
{
    return (ch >= '0' && ch <='9');
}


//-----------------------------------------------------------------------------
static bool isMinorCharOk(char ch)
{
    return (ch >= 'A' && ch <='X');
}

//-----------------------------------------------------------------------------
static bool isSmallChar(char ch)
{
    return (ch >= 'a' && ch <= 'z');
}

//-----------------------------------------------------------------------------
bool TQth::initFromMaidenheadLocator( const char* locator, double alt )
{
    //('Munich', (48.14666,11.60833), 'JN58td'),
    //('Palo Alto (K6WRU)', (37.413708,-122.1073236), 'CM87wj'),

    size_t len = strlen(locator);
    if( len!= 4 && len!=6 )
        return false;

    char buf[10];
    // my uppercase
    for( size_t i=0; i<len+1; i++ )
    {
        buf[i] = isSmallChar( locator[i] )? locator[i] & ~0x20 : locator[i];
    }

    size_t pos=0;
    if( !isMajorCharOk(buf[pos]) )
        return false;
    double lon1 = -180.0 + 20.0 * (buf[pos] - 'A');

    pos += 1;
    if( !isMajorCharOk(buf[pos]) )
        return false;
    double lat1 = -90.0 + 10.0 * (buf[pos] - 'A');

    pos += 1;
    if( !isDigit(buf[pos]) )
        return false;
    lon1 += 2.0 * (buf[pos] - '0');

    pos += 1;
    if( !isDigit(buf[pos]) )
        return false;
    lat1 += 1.0 * (buf[pos] - '0');

    if( len == 6 )
    {
        pos += 1;
        if( !isMinorCharOk(buf[pos]) )
            return false;
        double doplon1 = 5.0 * (buf[pos] - 'A');
        lon1 += doplon1 / 60.0;

        pos += 1;
        if( !isMinorCharOk(buf[pos]) )
            return false;
        double doplat1 = 2.5 * (buf[pos] - 'A');
        lat1 += doplat1 / 60.0;
    }

    // move to center of square
    if( len == 6 )
    {
        lon1 += 5.0 / 2.0 / 60.0;
        lat1 += 2.5 / 2.0 / 60.0;
    }
    else
    {
        lon1 += 2.0 / 2.0;
        lat1 += 1.0 / 2.0;
    }


    m_qth.lat = lat1;
    m_qth.lon = lon1;
    m_qth.alt = alt;

    return true;

}

//-----------------------------------------------------------------------------
char* TQth::convertToMaidenheadLocator() const
{
    char buf[80];

    double lon = m_qth.lon;
    double lat = m_qth.lat;

    size_t pos = 0;
    int lonIdx1 = ( lon + 180.0 ) / 20.0;
    buf[pos] = 'A' + lonIdx1;
    lon = lon + 180 - lonIdx1 * 20.0;

    pos += 1;
    int latIdx1 = ( lat + 90.0 ) / 10.0;
    buf[pos] = 'A' + latIdx1;
    lat = lat + 90 - latIdx1 * 10;

    pos += 1;
    int lonIdx2 = lon / 2.0;
    buf[pos] = '0' + lonIdx2;
    lon = lon - lonIdx2 * 2.0;

    pos += 1;
    int lanIdx2 = lat / 1.0;
    buf[pos] = '0' + lanIdx2;
    lat = lat - lanIdx2 * 1.0;

    pos += 1;
    int lonIdx3 = lon / (5.0 / 60.0);
    buf[pos] = 'a' + lonIdx3;

    pos += 1;
    int lanIdx3 = lat / (2.5 / 60.0);
    buf[pos] = 'a' + lanIdx3;

    pos += 1;
    buf[pos] = 0;

    return mystrdup(buf);
}
