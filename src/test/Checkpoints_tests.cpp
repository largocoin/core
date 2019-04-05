// Copyright (c) 2011-2013 The Bitcoin Core developers
// Copyright (c) 2017 The PIVX developers
// Copyright (c) 2019 The Largo Coin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

//
// Unit tests for block-chain checkpoints
//

#include "checkpoints.h"

#include "uint256.h"

#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_SUITE(Checkpoints_tests)

BOOST_AUTO_TEST_CASE(sanity)
{
    uint256 p0 = uint256("0x00000812e3d4074e06ca53c61403d60185377d76d8b6576609a106f59ffc31cd");
    //! \todo These checkpoints are from PIVX. Change it when we'll have enough data.
    uint256 p259201 = uint256("0x1c9121bf9329a6234bfd1ea2d91515f19cd96990725265253f4b164283ade5dd");
    uint256 p623933 = uint256("0xc7aafa648a0f1450157dc93bd4d7448913a85b7448f803b4ab970d91fc2a7da7");
#if 0 //! \todo reenable these tests and  when we'll have checkpoints and enough blocks
    BOOST_CHECK(Checkpoints::CheckBlock(259201, p259201));
    BOOST_CHECK(Checkpoints::CheckBlock(623933, p623933));
#else
    BOOST_CHECK(Checkpoints::CheckBlock(0, p0));
#endif

    // Wrong hashes at checkpoints should fail:
#if 0 //! \todo reenable these tests and  when we'll have checkpoints and enough blocks
    BOOST_CHECK(!Checkpoints::CheckBlock(259201, p623933));
    BOOST_CHECK(!Checkpoints::CheckBlock(623933, p259201));
#else
    BOOST_CHECK(!Checkpoints::CheckBlock(0, p623933));
#endif

    // ... but any hash not at a checkpoint should succeed:
    BOOST_CHECK(Checkpoints::CheckBlock(259201+1, p623933));
    BOOST_CHECK(Checkpoints::CheckBlock(623933+1, p259201));

#if 0 //! \todo reenable these tests and  when we'll have checkpoints
    BOOST_CHECK(Checkpoints::GetTotalBlocksEstimate() >= 623933);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
