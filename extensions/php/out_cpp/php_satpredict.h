/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.11
 *
 * This file is not intended to be easily readable and contains a number of
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG
 * interface file instead.
 * ----------------------------------------------------------------------------- */

#ifndef PHP_SATPREDICT_H
#define PHP_SATPREDICT_H

extern zend_module_entry satpredict_module_entry;
#define phpext_satpredict_ptr &satpredict_module_entry

#ifdef PHP_WIN32
# define PHP_SATPREDICT_API __declspec(dllexport)
#else
# define PHP_SATPREDICT_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(satpredict);
PHP_MSHUTDOWN_FUNCTION(satpredict);
PHP_RINIT_FUNCTION(satpredict);
PHP_RSHUTDOWN_FUNCTION(satpredict);
PHP_MINFO_FUNCTION(satpredict);

ZEND_NAMED_FUNCTION(_wrap_new_SatCalc);
ZEND_NAMED_FUNCTION(_wrap_SatCalc_findFirst);
ZEND_NAMED_FUNCTION(_wrap_SatCalc_findNext);
ZEND_NAMED_FUNCTION(_wrap_SatCalc_getCurrentPass);
ZEND_NAMED_FUNCTION(_wrap_SatCalc_getSatPosition);
ZEND_NAMED_FUNCTION(_wrap_SatCalc_maxDaysLookAhead);
ZEND_NAMED_FUNCTION(_wrap_SatCalc_set_maxDaysLookAhead);
ZEND_NAMED_FUNCTION(_wrap_SatCalc_minElevation);
ZEND_NAMED_FUNCTION(_wrap_SatCalc_set_minElevation);
ZEND_NAMED_FUNCTION(_wrap_new_PassItem);
ZEND_NAMED_FUNCTION(_wrap_PassItem_aos);
ZEND_NAMED_FUNCTION(_wrap_PassItem_los);
ZEND_NAMED_FUNCTION(_wrap_PassItem_tca);
ZEND_NAMED_FUNCTION(_wrap_PassItem_max_el);
ZEND_NAMED_FUNCTION(_wrap_PassItem_aos_az);
ZEND_NAMED_FUNCTION(_wrap_PassItem_los_az);
ZEND_NAMED_FUNCTION(_wrap_PassItem_orbit);
ZEND_NAMED_FUNCTION(_wrap_PassItem_maxel_az);
ZEND_NAMED_FUNCTION(_wrap_PassItem_vis);
ZEND_NAMED_FUNCTION(_wrap_new_SatPosition);
ZEND_NAMED_FUNCTION(_wrap_SatPosition_lat);
ZEND_NAMED_FUNCTION(_wrap_SatPosition_lon);
ZEND_NAMED_FUNCTION(_wrap_SatPosition_azimuth);
ZEND_NAMED_FUNCTION(_wrap_SatPosition_elevation);
ZEND_NAMED_FUNCTION(_wrap_SatPosition_footprint);
ZEND_NAMED_FUNCTION(_wrap_SatPosition_altitude);
ZEND_NAMED_FUNCTION(_wrap_SatPosition_velocity);
ZEND_NAMED_FUNCTION(_wrap_SatPosition_range);
ZEND_NAMED_FUNCTION(_wrap_SatPosition_rangeRate);
ZEND_NAMED_FUNCTION(_wrap_SatPosition_dopplerInHz);
ZEND_NAMED_FUNCTION(_wrap_new_TQth);
ZEND_NAMED_FUNCTION(_wrap_TQth_initFromLatLon);
ZEND_NAMED_FUNCTION(_wrap_TQth_initFromMaidenheadLocator);
ZEND_NAMED_FUNCTION(_wrap_TQth_convertToMaidenheadLocator);
ZEND_NAMED_FUNCTION(_wrap_TQth_lat);
ZEND_NAMED_FUNCTION(_wrap_TQth_lon);
ZEND_NAMED_FUNCTION(_wrap_TQth_alt);
ZEND_NAMED_FUNCTION(_wrap_TQth_distanceBetween);
ZEND_NAMED_FUNCTION(_wrap_new_TSat);
ZEND_NAMED_FUNCTION(_wrap_TSat_initFromTLELines);
ZEND_NAMED_FUNCTION(_wrap_TSat_satName);
ZEND_NAMED_FUNCTION(_wrap_new_TTime);
ZEND_NAMED_FUNCTION(_wrap_TTime_initFromNow);
ZEND_NAMED_FUNCTION(_wrap_TTime_initFromStringUTC);
ZEND_NAMED_FUNCTION(_wrap_TTime_initFromUnixStamp);
ZEND_NAMED_FUNCTION(_wrap_TTime_initFromTTime);
ZEND_NAMED_FUNCTION(_wrap_TTime_addSeconds);
ZEND_NAMED_FUNCTION(_wrap_TTime_asString);
ZEND_NAMED_FUNCTION(_wrap_TTime_toUnixStamp);
ZEND_NAMED_FUNCTION(_wrap_TTime_diffAsString);
ZEND_NAMED_FUNCTION(_wrap_TTime_diffInSeconds);
#endif /* PHP_SATPREDICT_H */
