#pragma once 

#include "sgp4sdp4.h"

class TSat
{
public:
    TSat();
    ~TSat();

    bool initFromTLELines( const char* staName, const char* line1, const char* line2 );

#ifndef SWIG
    sat_t *get() { return &m_sat; }
    sat_t *cget() const { return const_cast<sat_t*>(&m_sat); }
    sat_t& ref() { return m_sat; }
#endif


private:
    sat_t m_sat;
    

};

