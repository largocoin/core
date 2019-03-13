// Copyright (c) 2014 The Bitcoin Core developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2017 The PIVX developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "primitives/transaction.h"
#include "main.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(main_tests)

CAmount nMoneySupplyPoWEnd = 43199500 * COIN;

BOOST_AUTO_TEST_CASE(subsidy_limit_test)
{
    CAmount nSum = 0;
    for (int nHeight = 0; nHeight < 1; nHeight += 1) {
        /* premine in block 1 (15,000,001 LRG) */
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy == 15100000 * COIN);
        nSum += nSubsidy;
    }

    for (int nHeight = 1; nHeight < 262800; nHeight += 1) {
        /* Year Zero & One */
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy == 120.0001 * COIN);
        nSum += nSubsidy;
    }

    for (int nHeight = 262800; nHeight < 525600; nHeight += 1) {
        /* Year Two */
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy == 100.0001 * COIN);
        nSum += nSubsidy;
    }

    for (int nHeight = 525600; nHeight < 788400; nHeight += 1) {
        /* Year Three */
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy == 80.0001 * COIN);
        nSum += nSubsidy;
    }

    for (int nHeight = 788400; nHeight < 1051200; nHeight += 1) {
        /* Year Four */
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy == 60.0001 * COIN);
        nSum += nSubsidy;
    }

#if 0 // REMOVE_LATER
    for (int nHeight = 151200; nHeight < 259200; nHeight += 1) {
        /* PoW Phase Two */
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 45 * COIN);
        BOOST_CHECK(MoneyRange(nSubsidy));
        nSum += nSubsidy;
        BOOST_CHECK(nSum > 0 && nSum <= nMoneySupplyPoWEnd);
    }
#endif
    cout << "nSum: " << nSum << endl;
    BOOST_CHECK(MoneyRange(nSum));
    BOOST_CHECK(nSum == 10970798511990000ULL);
}

BOOST_AUTO_TEST_SUITE_END()
