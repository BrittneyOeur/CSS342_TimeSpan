#include <iostream>
#include <sstream>
#include <cassert>
#include "timespan.h"
#include "timespan.cpp"

void test1() {
    TimeSpan ts(1,20,30);
    stringstream ss;
    ss << ts;
    assert(ss.str() == "1:20:30");

    TimeSpan ts2(4, -20, -90);
    ss.str(""); ss << ts2;
    assert(ss.str() == "3:38:30");

    TimeSpan ts3(1.5, 30.5, -90);
    ss.str(""); ss << ts3;
    assert(ss.str() == "1:59:00");


    TimeSpan ts4(0,0.07, 0);
    ss.str("");
    ss << ts4;
    assert(ss.str() == "0:00:04");
}


void test2() {
    TimeSpan ts(1, 20, 30);
    TimeSpan ts2(1, 20, 30);
    TimeSpan ts3(0, 0, 0);

    assert(ts == ts2);
    assert(!(ts != ts2));
    assert(ts != ts3);
    assert((ts + ts + ts) == (ts2 * 3));
    assert((ts * 5) == (ts2 * 4) + ts2);
    assert((ts * 5) == (ts2 * 6) - ts2);
    assert((ts + ts - ts) == ((ts2 * 2) - ts));
    assert((ts - ts2) == ts3);
    assert((ts3 * 5) == ts3);
}


void testAll() {
    test1();
    test2();
}

int main() {
    testAll();
    cout << "Finished." << endl;
    return 0;
}