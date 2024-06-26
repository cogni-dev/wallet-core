// SPDX-License-Identifier: Apache-2.0
//
// Copyright © 2017 Trust Wallet.

#include "Solana/Address.h"
#include <TrustWalletCore/TWSolanaAddress.h>

using namespace TW;

struct TWSolanaAddress* _Nullable TWSolanaAddressCreateWithString(TWString* _Nonnull string) {
    auto& str = *reinterpret_cast<const std::string*>(string);
    return new TWSolanaAddress{Solana::Address(str)};
}

void TWSolanaAddressDelete(struct TWSolanaAddress* _Nonnull address) {
    delete address;
}

TWString* _Nullable TWSolanaAddressDefaultTokenAddress(struct TWSolanaAddress* _Nonnull address, TWString* _Nonnull tokenMintAddress) {
    try {
        if (address == nullptr || tokenMintAddress == nullptr) {
            return nullptr;
        }
        Solana::Address tokenMint = Solana::Address(TWStringUTF8Bytes(tokenMintAddress));
        std::string defaultAddress = address->impl.defaultTokenAddress(tokenMint).string();
        return TWStringCreateWithUTF8Bytes(defaultAddress.c_str());
    } catch (...) {
        return nullptr;
    }
}

TWString* _Nonnull TWSolanaAddressDescription(struct TWSolanaAddress* _Nonnull address) {
    return TWStringCreateWithUTF8Bytes(address->impl.string().c_str());
}
