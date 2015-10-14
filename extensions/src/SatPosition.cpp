/*
    Author: Alexander Sholohov <ra9yer@yahoo.com>
*/


#include "SatPosition.h"

#include "TSat.h"

//-----------------------------------------------------------------------------
SatPosition::SatPosition()
{
}

//-----------------------------------------------------------------------------
SatPosition::~SatPosition()
{
}

//-----------------------------------------------------------------------------
void SatPosition::initFromSat(TSat const& sInfo)
{
    sat_t* sat = sInfo.cget();

    m_lat = sat->ssplat;
    m_lon = sat->ssplon;

    m_footprint = sat->footprint;
    m_azimuth = sat->az;
    m_elevation = sat->el;
    m_altitude = sat->alt;
    m_velocity = sat->velo;
    m_range = sat->range;
    m_rangeRate = sat->range_rate;

    // calc
    m_doppler = -100.0e06 * (sat->range_rate / 299792.4580); // Hz

}

