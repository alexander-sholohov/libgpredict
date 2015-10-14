/*
    Author: Alexander Sholohov <ra9yer@yahoo.com>
*/

#include "PassItem.h"
#include "utils.h"

//-----------------------------------------------------------------------------
PassItem::PassItem()
{
    memset(&m_pass, 0, sizeof(m_pass));
}

//-----------------------------------------------------------------------------
PassItem::~PassItem()
{
}

//-----------------------------------------------------------------------------
void PassItem::initFromPass(pass_t* pass)
{
    m_pass = *pass;
    m_pass.details = NULL; // we are not interested in details
}

//-----------------------------------------------------------------------------
TTime PassItem::aos() const
{
    TTime res;
    res.initFromJulianDate( m_pass.aos );
    return res;
}

//-----------------------------------------------------------------------------
TTime PassItem::los() const
{
    TTime res;
    res.initFromJulianDate( m_pass.los );
    return res;
}

//-----------------------------------------------------------------------------
TTime PassItem::tca() const
{
    TTime res;
    res.initFromJulianDate( m_pass.tca );
    return res;
}

//-----------------------------------------------------------------------------
double PassItem::max_el() const
{
    return m_pass.max_el;
}

//-----------------------------------------------------------------------------
double PassItem::aos_az() const
{
    return m_pass.aos_az;
}

//-----------------------------------------------------------------------------
double PassItem::los_az() const
{
    return m_pass.los_az;
}

//-----------------------------------------------------------------------------
unsigned PassItem::orbit() const
{
    return m_pass.orbit;
}

//-----------------------------------------------------------------------------
double PassItem::maxel_az() const
{
    return m_pass.maxel_az;
}

//-----------------------------------------------------------------------------
char* PassItem::vis() const
{
    return mystrdup(m_pass.vis);
}
