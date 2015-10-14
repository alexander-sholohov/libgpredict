#pragma once 

#include "sgp4sdp4.h"

class TTime
{
public:
    TTime();
    ~TTime();

    void initFromNow();
    bool initFromStringUTC( const char* datetime );
    void initFromUnixStamp( unsigned value );
    void initFromTTime( TTime const& time );

    void addSeconds( double value );

    char* asString() const;
    unsigned toUnixStamp() const;
    
    char* diffAsString( TTime const& losTime ) const;
    int diffInSeconds( TTime const& losTime) const;

#ifndef SWIG
    void initFromJulianDate( double value );
    double getJulianUTC() const { return m_julianDate; }
#endif


private:
    double m_julianDate;
    

};

