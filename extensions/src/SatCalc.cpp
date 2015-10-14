/*
    Author: Alexander Sholohov <ra9yer@yahoo.com>
*/


#include "SatCalc.h"

#include "PassItem.h"
#include "SatPosition.h"

#include "predict-tools.h"

//-----------------------------------------------------------------------------
SatCalc::SatCalc()
{
    m_first = NULL;
    m_next = NULL;
    m_maxDaysLookAhead = 5;
}

//-----------------------------------------------------------------------------
SatCalc::~SatCalc()
{
    listFree();
}

//-----------------------------------------------------------------------------
void SatCalc::listFree()
{
    if( m_first )
    {
        free_passes(m_first);
        m_first = NULL;
    }
}

//-----------------------------------------------------------------------------
bool SatCalc::getCurrentPass(TSat const& sat, TQth const& qth, PassItem* passItem)
{
    TTime time;
    time.initFromNow();
    pass_t *pass = get_current_pass (sat.cget(), qth.cget(), time.getJulianUTC());
    if( !pass )
        return false;

    passItem->initFromPass( pass );
    free_pass(pass);
    return true;
}

//-----------------------------------------------------------------------------
void SatCalc::getSatPosition(TSat const& sat, TQth const& qth, TTime const& satTime, SatPosition* satPosition )
{
    predict_calc(sat.cget(), qth.cget(), satTime.getJulianUTC() );
    satPosition->initFromSat( sat );
}

//-----------------------------------------------------------------------------
bool SatCalc::findFirst(TSat const& sat, TQth const& qth, TTime const& statTime, unsigned limiter, PassItem* passItem)
{
    listFree();

    m_first = NULL;
    m_next = NULL;

    GSList *list = get_passes(sat.cget(), qth.cget(), statTime.getJulianUTC(), m_maxDaysLookAhead, limiter);
    if( !list )
        return false;

    m_next = m_first = list;
    passItem->initFromPass( (pass_t*)(m_next->data) );
    m_next = g_slist_next(m_next);
    return true;
}

//-----------------------------------------------------------------------------
bool SatCalc::findNext(PassItem* passItem)
{
    if( !m_next )
        return false;

    passItem->initFromPass( (pass_t*)(m_next->data) );
    m_next = g_slist_next(m_next);

    return true;
}

//-----------------------------------------------------------------------------
double SatCalc::maxDaysLookAhead() const
{
    return m_maxDaysLookAhead;
}

//-----------------------------------------------------------------------------
void SatCalc::set_maxDaysLookAhead( double value )
{
    m_maxDaysLookAhead = value;
}
