#pragma once

#include "TTime.h"

#include "predict-tools.h"

class PassItem
{
public:
    PassItem();
    ~PassItem();

    TTime aos() const;
    TTime los() const;
    TTime tca() const;

    double max_el() const;
    double aos_az() const;
    double los_az() const;
    unsigned orbit() const;
    double maxel_az() const;
    char* vis() const;



#ifndef SWIG
    void initFromPass(pass_t* pass);
#endif


private:
    pass_t m_pass;

};

