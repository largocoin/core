// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2017 The PIVX developers
// Copyright (c) 2019-2020 The Largo Coin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_AMOUNT_H
#define BITCOIN_AMOUNT_H

#include "serialize.h"

#include <stdlib.h>
#include <string>
#include "uint256.h"

typedef int64_t CAmount;

static const CAmount COIN = 100000000;
static const CAmount CENT = 1000000;

//! Largo Coin parameters
static const CAmount MASTERNODE_COLLATERAL = 7500000; //!< Masternode collateral amount (LRG)
static const time_t BLOCKS_CREATION_TIME = 2 * 60; //!< Time limit to create next block
static const time_t BLOCK_DIFFICULTY_RECALC = 16 * 60;
static const int BLOCKS_PER_YEAR = 365 * 24 * ( 60 * 60 ) / BLOCKS_CREATION_TIME; //!< Blocks count per year (precalculated for later use).
static const int MASTERNODE_REWARDS[] = { 120, 100, 80, 60 }; //!< Payments to masternodes by years 0-3 and after that.
static const double MINER_REWARD = 10000;
static const double STACKER_REWARD = 10000000;

static const uint256 PROOF_OF_WORK_LIMIT(~uint256(0) >> 20); //!<MIN POS difficulty
static const uint256 PROOF_OF_STAKE_LIMIT(~uint256(0) >> 24); //!<MIN POS difficulty

/** Type-safe wrapper class to for fee rates
 * (how much to pay based on transaction size)
 */
class CFeeRate
{
private:
    CAmount nSatoshisPerK; // unit is satoshis-per-1,000-bytes
public:
    CFeeRate() : nSatoshisPerK(0) {}
    explicit CFeeRate(const CAmount& _nSatoshisPerK) : nSatoshisPerK(_nSatoshisPerK) {}
    CFeeRate(const CAmount& nFeePaid, size_t nSize);
    CFeeRate(const CFeeRate& other) { nSatoshisPerK = other.nSatoshisPerK; }

    CAmount GetFee(size_t size) const;                  // unit returned is satoshis
    CAmount GetFeePerK() const { return GetFee(1000); } // satoshis-per-1000-bytes

    friend bool operator<(const CFeeRate& a, const CFeeRate& b) { return a.nSatoshisPerK < b.nSatoshisPerK; }
    friend bool operator>(const CFeeRate& a, const CFeeRate& b) { return a.nSatoshisPerK > b.nSatoshisPerK; }
    friend bool operator==(const CFeeRate& a, const CFeeRate& b) { return a.nSatoshisPerK == b.nSatoshisPerK; }
    friend bool operator<=(const CFeeRate& a, const CFeeRate& b) { return a.nSatoshisPerK <= b.nSatoshisPerK; }
    friend bool operator>=(const CFeeRate& a, const CFeeRate& b) { return a.nSatoshisPerK >= b.nSatoshisPerK; }
    std::string ToString() const;

    ADD_SERIALIZE_METHODS;

    template <typename Stream, typename Operation>
    inline void SerializationOp(Stream& s, Operation ser_action, int nType, int nVersion)
    {
        READWRITE(nSatoshisPerK);
    }
};

#endif //  BITCOIN_AMOUNT_H
