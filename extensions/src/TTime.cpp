/*
    Author: Alexander Sholohov <ra9yer@yahoo.com>
*/

#include "TTime.h"
#include "utils.h"

//-----------------------------------------------------------------------------
TTime::TTime()
{
    m_julianDate = 0;
}

//-----------------------------------------------------------------------------
TTime::~TTime()
{
}

//-----------------------------------------------------------------------------
void TTime::initFromJulianDate( double value )
{
    m_julianDate = value;
}

//-----------------------------------------------------------------------------
void TTime::initFromTTime( TTime const& time )
{
    m_julianDate = time.m_julianDate;
}

//-----------------------------------------------------------------------------
void TTime::initFromNow()
{
    struct tm utc;
    UTC_Calendar_Now(&utc);

    double daynum = Julian_Date(&utc);

    //// microseconds correction
    //GTimeVal tmval;
    //g_get_current_time (&tmval);
    //daynum = daynum + (double)tmval.tv_usec/8.64e+10;

    m_julianDate = daynum;
}

//-----------------------------------------------------------------------------
bool TTime::initFromStringUTC( const char* datetime )
{
    // we are expecting 2015-10-12 13:45:01

    char buf[80];
    size_t pos = 0;
    strncpy(buf, datetime+pos, 4); buf[4] = 0;
    int year = atoi(buf);

    pos += 4;
    if( datetime[pos] != '-' )
        return false;
    pos += 1;
    strncpy(buf, datetime+pos, 2); buf[2] = 0;
    int month = atoi(buf);
    
    pos += 2;
    if( datetime[pos] != '-' )
        return false;
    pos += 1;
    strncpy(buf, datetime+pos, 2); buf[2] = 0;
    int day = atoi(buf);


    pos += 2;
    if( datetime[pos] != ' ' )
        return false;
    pos += 1;
    strncpy(buf, datetime+pos, 2); buf[2] = 0;
    int hours = atoi(buf);

    pos += 2;
    if( datetime[pos] != ':' )
        return false;
    pos += 1;
    strncpy(buf, datetime+pos, 2); buf[2] = 0;
    int minutes = atoi(buf);

    pos += 2;
    if( datetime[pos] != ':' )
        return false;
    pos += 1;
    strncpy(buf, datetime+pos, 2); buf[2] = 0;
    int seconds = atoi(buf);

    pos += 2;
    if( datetime[pos] != 0 )
        return false;

    struct tm utc;
    utc.tm_year = year; // 1900
    utc.tm_mon = month;  // 1
    utc.tm_mday = day;
    utc.tm_hour = hours;
    utc.tm_min = minutes;
    utc.tm_sec = seconds;


    double d = Julian_Date(&utc);


    m_julianDate = d;
    return true;
}

//-----------------------------------------------------------------------------
char* TTime::asString() const
{
    struct tm utc;
    Date_Time(m_julianDate, &utc);

    char buf[80];
    sprintf(buf, "%04d-%02d-%02d %02d:%02d:%02d", utc.tm_year+1900, utc.tm_mon+1, utc.tm_mday, utc.tm_hour, utc.tm_min, utc.tm_sec);
    return mystrdup(buf);
}


//-----------------------------------------------------------------------------
void TTime::initFromUnixStamp( unsigned value )
{
    time_t epoch = (time_t)value;
    struct tm utc = *gmtime(&epoch);
    utc.tm_year += 1900;
    utc.tm_mon += 1;
    double d = Julian_Date(&utc);
    m_julianDate = d;
}

//-----------------------------------------------------------------------------
unsigned TTime::toUnixStamp() const
{
    struct tm utc;
    Date_Time(m_julianDate, &utc);

#if defined(_WIN32)
    time_t epoch = _mkgmtime(&utc);
#else
    time_t epoch = timegm(&utc);
#endif

    return (unsigned)epoch;
}


//-----------------------------------------------------------------------------
void TTime::addSeconds( double value )
{
    double d = m_julianDate + value / 86400.0;
    m_julianDate = d;
}

//-----------------------------------------------------------------------------
char* TTime::diffAsString( TTime const& losTime ) const
{
    int diff = diffInSeconds(losTime);
    if( diff < 0 )
        return mystrdup("");

    int hours = diff / (60 * 60);
    int minutes = (diff - hours * 60 * 60) / 60;
    int seconds = diff - hours * 60 * 60 - minutes * 60;

    char buf[20];
    sprintf(buf, "%02d:%02d:%02d", hours, minutes, seconds);
    return mystrdup(buf);
}

//-----------------------------------------------------------------------------
int TTime::diffInSeconds( TTime const& losTime) const
{
    unsigned t2 = losTime.toUnixStamp();
    unsigned t1 = this->toUnixStamp();
    int diff = t2 - t1;
    return diff;
}
