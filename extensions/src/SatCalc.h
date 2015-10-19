#pragma once

#include "sgp4sdp4.h"
#include "qth-data.h"

#include "TSat.h"
#include "TQth.h"
#include "TTime.h"

#include "PassItem.h"
#include "SatPosition.h"


class SatCalc
{
public:
    SatCalc();
    ~SatCalc();

    bool findFirst(TSat const& sat, TQth const& qth, TTime const& statTime, unsigned limiter, PassItem* passItem); 
    bool findNext(PassItem* passItem);

    bool getCurrentPass(TSat const& sat, TQth const& qth, PassItem* passItem);
    void getSatPosition(TSat const& sat, TQth const& qth, TTime const& satTime, SatPosition* satPosition );

    double maxDaysLookAhead() const;
    void set_maxDaysLookAhead( double value );

    double minElevation() const;
    void set_minElevation( double value );

#ifndef SWIG
#endif


private:
    GSList *m_first;
    GSList *m_next;
    double m_maxDaysLookAhead;
    double m_minElevation;

    void listFree();
    

};

