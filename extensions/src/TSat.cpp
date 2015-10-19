/*
    Author: Alexander Sholohov <ra9yer@yahoo.com>
*/


#include "TSat.h"
#include "gtk-sat-data.h"

//-----------------------------------------------------------------------------
TSat::TSat()
{
    memset(&m_sat, 0, sizeof(m_sat));
}

//-----------------------------------------------------------------------------
TSat::~TSat()
{
}

//-----------------------------------------------------------------------------
static size_t limitedStrLength( const char* str, size_t limiter )
{
    size_t len = strlen(str) + 1;
    return (len < limiter)? len : limiter;
}

//-----------------------------------------------------------------------------
bool TSat::initFromTLELines( const char* satName, const char* line1, const char* line2 )
{
    memset(&m_sat, 0, sizeof(m_sat));

    char  tle_str[3][80];
    strncpy(tle_str[0], satName, limitedStrLength(satName, 80) );
    strncpy(tle_str[1], line1, limitedStrLength(line1, 80));
    strncpy(tle_str[2], line2, limitedStrLength(line2, 80));

    int res = Get_Next_Tle_Set (tle_str, &(m_sat.tle) );

    m_sat.flags = 0;
    ::select_ephemeris(&m_sat);

    /* calculate satellite data at epoch */
    ::gtk_sat_data_init_sat(&m_sat, NULL);

    return res == 1;
}

