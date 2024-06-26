// SPDX-License-Identifier: Apache-2.0
//
// Copyright © 2017 Trust Wallet.

#pragma once

#include "VersionedTransaction.h"
#include "Data.h"
#include "../Hash.h"
#include "../PrivateKey.h"
#include "../proto/Solana.pb.h"

namespace TW::Solana {

/// Helper class that performs Solana transaction signing.
class Signer {
  public:
    Proto::SigningInput input;

    /// Initializes a transaction signer.
    explicit Signer(const Proto::SigningInput& input) : input(input) {}

    /// Signs the given transaction.
    static void sign(const std::vector<PrivateKey>& privateKeys, VersionedTransaction& transaction);

    /// Signs a json Proto::SigningInput with private key
    static std::string signJSON(const std::string& json, const Data& key);

    static void signUpdateBlockhash(const std::vector<PrivateKey>& privateKeys,
                                    VersionedTransaction& transaction, Data& recentBlockhash);
    static Data signRawMessage(const std::vector<PrivateKey>& privateKeys, const Data messageData);

    static Proto::SigningOutput sign(const Proto::SigningInput& input) noexcept;

    TW::Data preImageHash() const;
    Proto::SigningOutput compile(const std::vector<Data>& signatures,
                                 const std::vector<PublicKey>& publicKeys) const;
    std::vector<std::string> signers() const;
};
} // namespace TW::Solana
