<?php

/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.11
 *
 * This file is not intended to be easily readable and contains a number of
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG
 * interface file instead.
 * ----------------------------------------------------------------------------- */

// Try to load our extension if it's not already loaded.
if (!extension_loaded('satpredict')) {
  if (strtolower(substr(PHP_OS, 0, 3)) === 'win') {
    if (!dl('php_satpredict.dll')) return;
  } else {
    // PHP_SHLIB_SUFFIX gives 'dylib' on MacOS X but modules are 'so'.
    if (PHP_SHLIB_SUFFIX === 'dylib') {
      if (!dl('satpredict.so')) return;
    } else {
      if (!dl('satpredict.'.PHP_SHLIB_SUFFIX)) return;
    }
  }
}



/* PHP Proxy Classes */
class SatCalc {
	public $_cPtr=null;
	protected $_pData=array();

	function __set($var,$value) {
		if ($var === 'thisown') return swig_satpredict_alter_newobject($this->_cPtr,$value);
		$this->_pData[$var] = $value;
	}

	function __isset($var) {
		if ($var === 'thisown') return true;
		return array_key_exists($var, $this->_pData);
	}

	function __get($var) {
		if ($var === 'thisown') return swig_satpredict_get_newobject($this->_cPtr);
		return $this->_pData[$var];
	}

	function __construct($res=null) {
		if (is_resource($res) && get_resource_type($res) === '_p_SatCalc') {
			$this->_cPtr=$res;
			return;
		}
		$this->_cPtr=new_SatCalc();
	}

	function findFirst($sat,$qth,$statTime,$limiter,$passItem) {
		return SatCalc_findFirst($this->_cPtr,$sat,$qth,$statTime,$limiter,$passItem);
	}

	function findNext($passItem) {
		return SatCalc_findNext($this->_cPtr,$passItem);
	}

	function getCurrentPass($sat,$qth,$passItem) {
		return SatCalc_getCurrentPass($this->_cPtr,$sat,$qth,$passItem);
	}

	function getSatPosition($sat,$qth,$satTime,$satPosition) {
		SatCalc_getSatPosition($this->_cPtr,$sat,$qth,$satTime,$satPosition);
	}

	function maxDaysLookAhead() {
		return SatCalc_maxDaysLookAhead($this->_cPtr);
	}

	function set_maxDaysLookAhead($value) {
		SatCalc_set_maxDaysLookAhead($this->_cPtr,$value);
	}

	function minElevation() {
		return SatCalc_minElevation($this->_cPtr);
	}

	function set_minElevation($value) {
		SatCalc_set_minElevation($this->_cPtr,$value);
	}
}

class PassItem {
	public $_cPtr=null;
	protected $_pData=array();

	function __set($var,$value) {
		if ($var === 'thisown') return swig_satpredict_alter_newobject($this->_cPtr,$value);
		$this->_pData[$var] = $value;
	}

	function __isset($var) {
		if ($var === 'thisown') return true;
		return array_key_exists($var, $this->_pData);
	}

	function __get($var) {
		if ($var === 'thisown') return swig_satpredict_get_newobject($this->_cPtr);
		return $this->_pData[$var];
	}

	function __construct($res=null) {
		if (is_resource($res) && get_resource_type($res) === '_p_PassItem') {
			$this->_cPtr=$res;
			return;
		}
		$this->_cPtr=new_PassItem();
	}

	function aos() {
		$r=PassItem_aos($this->_cPtr);
		if (is_resource($r)) {
			$c=substr(get_resource_type($r), (strpos(get_resource_type($r), '__') ? strpos(get_resource_type($r), '__') + 2 : 3));
			if (class_exists($c)) return new $c($r);
			return new TTime($r);
		}
		return $r;
	}

	function los() {
		$r=PassItem_los($this->_cPtr);
		if (is_resource($r)) {
			$c=substr(get_resource_type($r), (strpos(get_resource_type($r), '__') ? strpos(get_resource_type($r), '__') + 2 : 3));
			if (class_exists($c)) return new $c($r);
			return new TTime($r);
		}
		return $r;
	}

	function tca() {
		$r=PassItem_tca($this->_cPtr);
		if (is_resource($r)) {
			$c=substr(get_resource_type($r), (strpos(get_resource_type($r), '__') ? strpos(get_resource_type($r), '__') + 2 : 3));
			if (class_exists($c)) return new $c($r);
			return new TTime($r);
		}
		return $r;
	}

	function max_el() {
		return PassItem_max_el($this->_cPtr);
	}

	function aos_az() {
		return PassItem_aos_az($this->_cPtr);
	}

	function los_az() {
		return PassItem_los_az($this->_cPtr);
	}

	function orbit() {
		return PassItem_orbit($this->_cPtr);
	}

	function maxel_az() {
		return PassItem_maxel_az($this->_cPtr);
	}

	function vis() {
		return PassItem_vis($this->_cPtr);
	}
}

class SatPosition {
	public $_cPtr=null;
	protected $_pData=array();

	function __set($var,$value) {
		if ($var === 'thisown') return swig_satpredict_alter_newobject($this->_cPtr,$value);
		$this->_pData[$var] = $value;
	}

	function __isset($var) {
		if ($var === 'thisown') return true;
		return array_key_exists($var, $this->_pData);
	}

	function __get($var) {
		if ($var === 'thisown') return swig_satpredict_get_newobject($this->_cPtr);
		return $this->_pData[$var];
	}

	function __construct($res=null) {
		if (is_resource($res) && get_resource_type($res) === '_p_SatPosition') {
			$this->_cPtr=$res;
			return;
		}
		$this->_cPtr=new_SatPosition();
	}

	function lat() {
		return SatPosition_lat($this->_cPtr);
	}

	function lon() {
		return SatPosition_lon($this->_cPtr);
	}

	function azimuth() {
		return SatPosition_azimuth($this->_cPtr);
	}

	function elevation() {
		return SatPosition_elevation($this->_cPtr);
	}

	function footprint() {
		return SatPosition_footprint($this->_cPtr);
	}

	function altitude() {
		return SatPosition_altitude($this->_cPtr);
	}

	function velocity() {
		return SatPosition_velocity($this->_cPtr);
	}

	function range() {
		return SatPosition_range($this->_cPtr);
	}

	function rangeRate() {
		return SatPosition_rangeRate($this->_cPtr);
	}

	function dopplerInHz() {
		return SatPosition_dopplerInHz($this->_cPtr);
	}
}

class TQth {
	public $_cPtr=null;
	protected $_pData=array();

	function __set($var,$value) {
		if ($var === 'thisown') return swig_satpredict_alter_newobject($this->_cPtr,$value);
		$this->_pData[$var] = $value;
	}

	function __isset($var) {
		if ($var === 'thisown') return true;
		return array_key_exists($var, $this->_pData);
	}

	function __get($var) {
		if ($var === 'thisown') return swig_satpredict_get_newobject($this->_cPtr);
		return $this->_pData[$var];
	}

	function __construct($res=null) {
		if (is_resource($res) && get_resource_type($res) === '_p_TQth') {
			$this->_cPtr=$res;
			return;
		}
		$this->_cPtr=new_TQth();
	}

	function initFromLatLon($lat,$lon,$alt) {
		return TQth_initFromLatLon($this->_cPtr,$lat,$lon,$alt);
	}

	function initFromMaidenheadLocator($locator,$alt) {
		return TQth_initFromMaidenheadLocator($this->_cPtr,$locator,$alt);
	}

	function convertToMaidenheadLocator() {
		return TQth_convertToMaidenheadLocator($this->_cPtr);
	}

	function lat() {
		return TQth_lat($this->_cPtr);
	}

	function lon() {
		return TQth_lon($this->_cPtr);
	}

	function alt() {
		return TQth_alt($this->_cPtr);
	}

	function distanceBetween($other) {
		return TQth_distanceBetween($this->_cPtr,$other);
	}
}

class TSat {
	public $_cPtr=null;
	protected $_pData=array();

	function __set($var,$value) {
		if ($var === 'thisown') return swig_satpredict_alter_newobject($this->_cPtr,$value);
		$this->_pData[$var] = $value;
	}

	function __isset($var) {
		if ($var === 'thisown') return true;
		return array_key_exists($var, $this->_pData);
	}

	function __get($var) {
		if ($var === 'thisown') return swig_satpredict_get_newobject($this->_cPtr);
		return $this->_pData[$var];
	}

	function __construct($res=null) {
		if (is_resource($res) && get_resource_type($res) === '_p_TSat') {
			$this->_cPtr=$res;
			return;
		}
		$this->_cPtr=new_TSat();
	}

	function initFromTLELines($staName,$line1,$line2) {
		return TSat_initFromTLELines($this->_cPtr,$staName,$line1,$line2);
	}
}

class TTime {
	public $_cPtr=null;
	protected $_pData=array();

	function __set($var,$value) {
		if ($var === 'thisown') return swig_satpredict_alter_newobject($this->_cPtr,$value);
		$this->_pData[$var] = $value;
	}

	function __isset($var) {
		if ($var === 'thisown') return true;
		return array_key_exists($var, $this->_pData);
	}

	function __get($var) {
		if ($var === 'thisown') return swig_satpredict_get_newobject($this->_cPtr);
		return $this->_pData[$var];
	}

	function __construct($res=null) {
		if (is_resource($res) && get_resource_type($res) === '_p_TTime') {
			$this->_cPtr=$res;
			return;
		}
		$this->_cPtr=new_TTime();
	}

	function initFromNow() {
		TTime_initFromNow($this->_cPtr);
	}

	function initFromStringUTC($datetime) {
		return TTime_initFromStringUTC($this->_cPtr,$datetime);
	}

	function initFromUnixStamp($value) {
		TTime_initFromUnixStamp($this->_cPtr,$value);
	}

	function initFromTTime($time) {
		TTime_initFromTTime($this->_cPtr,$time);
	}

	function addSeconds($value) {
		TTime_addSeconds($this->_cPtr,$value);
	}

	function asString() {
		return TTime_asString($this->_cPtr);
	}

	function toUnixStamp() {
		return TTime_toUnixStamp($this->_cPtr);
	}

	function diffAsString($losTime) {
		return TTime_diffAsString($this->_cPtr,$losTime);
	}

	function diffInSeconds($losTime) {
		return TTime_diffInSeconds($this->_cPtr,$losTime);
	}
}


?>
