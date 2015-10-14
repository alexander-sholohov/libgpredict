#pragma once


class TSat;

class SatPosition
{
public:
    SatPosition();
    ~SatPosition();

    double lat() const { return m_lat; }
    double lon() const { return m_lon; }
    double azimuth() const { return m_azimuth; }
    double elevation() const { return m_elevation; }
    double footprint() const { return m_footprint; }
    double altitude() const { return m_altitude; }
    double velocity() const { return m_velocity; }
    double range() const { return m_range; }
    double rangeRate() const { return m_rangeRate; }

    double dopplerInHz() const { return m_doppler; }



#ifndef SWIG
    void initFromSat(TSat const& sat);
#endif


private:
    double m_lat;
    double m_lon;
    double m_azimuth;
    double m_elevation;
    double m_footprint;
    double m_altitude;
    double m_velocity;
    double m_range;
    double m_rangeRate;

    // calculated
    double m_doppler;

};

