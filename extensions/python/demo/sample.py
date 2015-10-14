import satpredict

sat = satpredict.TSat()
sat.initFromTLELines("LILACSAT 2",
        "1 40908U 15049K   15281.15284003  .00001254  00000-0  77246-4 0  9992",
        "2 40908  97.4637 288.9015 0016672 177.9835 247.3756 15.11679566  2748")

qth = satpredict.TQth()
qth.initFromMaidenheadLocator( "NO13ui", 0.0 )

time = satpredict.TTime()
time.initFromNow()

passItem = satpredict.PassItem()
sc = satpredict.SatCalc()

res = sc.findFirst( sat, qth, time, 10, passItem )
while( res ):
    print "aos={0} los={1} max_elevation={2} duration={3}".format(passItem.aos().asString(), passItem.los().asString(), passItem.max_el(), passItem.aos().diffAsString( passItem.los())  )
    res = sc.findNext(passItem)
