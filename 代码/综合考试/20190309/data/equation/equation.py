#!/usr/bin/python

from random import *

prob = "equation"

cases = [   #(n,m,p,q)
            (6,(100000007,1),(100000007,1),1),
            (6,(100000007,1),(100000007,1),1),
            (6,(100000007,1),(100000007,1),1),
            (1000,(100000007,1),(198469,1),100),
            (1000,(100000007,1),(198469,1),100),
            (1000,(100000007,1),(198469,1),100),
            (1000,(100000007,1),(198469,1),100),
            (1000,(2179,2333),(3529,2179),1000),
            (1000,(2179,2333),(3529,2179),1000),
            (1000,(2179,2333),(3529,2179),1000),
        ]
cur = 0
for (tp,p,q,T) in cases :
    cur += 1
    print "make %d..." % cur
##-----
#TODO generate the data
    cout = "%d\n" % T
    for t in range(T) :
        cout += "%d %d " % (randint(1,tp), randint(1,tp))
        if randint(0,1) == 0 :
            cout += "%d\n" % (p[0] * p[1])
        else :
            cout += "%d\n" % (q[0] * q[1])
##-----
    f = file( prob + str(cur) + ".in", "w" )
    f.write( cout )
    f.close()

