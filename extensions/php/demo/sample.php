<?php

require 'satpredict.php';

$sat = new TSat();


$res = $sat->initFromTLELines("LILACSAT 2",
        "1 40908U 15049K   15281.15284003  .00001254  00000-0  77246-4 0  9992",
        "2 40908  97.4637 288.9015 0016672 177.9835 247.3756 15.11679566  2748");



$qth = new TQth();
$qth->initFromMaidenheadLocator( "NO13ui", 0.0 );

$time = new TTime();
$time->initFromNow();

$passItem = new PassItem();
$sc = new SatCalc();

$res = $sc->findFirst( $sat, $qth, $time, 10, $passItem );
while( $res )
{

    print "aos=".$passItem->aos()->asString()." los=".$passItem->los()->asString(). "max_elevation=" . $passItem->max_el() . "duration=". $passItem->aos()->diffAsString( $passItem->los() ) ; 
    print "\n";

    $res = $sc->findNext($passItem);
}

?>
