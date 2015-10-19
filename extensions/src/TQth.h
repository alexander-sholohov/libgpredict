#pragma once

#include "sgp4sdp4.h"
#include "qth-data.h"

class TQth
{
public:
    TQth();
    ~TQth();

    bool initFromLatLon( double lat, double lon, double alt );
    bool initFromMaidenheadLocator( const char* locator, double alt );

    char* convertToMaidenheadLocator() const;

    double lat() const;
    double lon() const;
    double alt() const;

    double distanceBetween( TQth const& other ) const;

#ifndef SWIG
    qth_t *get() { return &m_qth; }
    qth_t *cget() const { return const_cast<qth_t*>(&m_qth); }
    qth_t& ref() { return m_qth; }
#endif


private:
    qth_t m_qth;
    

};

