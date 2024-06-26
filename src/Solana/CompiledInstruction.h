// SPDX-License-Identifier: Apache-2.0
//
// Copyright © 2017 Trust Wallet.

#pragma once

#include "Solana/Instruction.h"

namespace TW::Solana {

// A compiled instruction
struct CompiledInstruction {
    // Index into the transaction keys array indicating the program account that executes this instruction
    uint8_t programIdIndex;
    // Ordered indices into the transaction keys array indicating which accounts
    // to pass to the program
    std::vector<uint8_t> accounts;
    // The program input data
    Data data;

    // Reference to the address vector
    const std::vector<Address>& addresses;

    /// Supplied address vector is expected to contain all addresses and programId from the instruction; they are replaced by index into the address vector.
    CompiledInstruction(const Instruction& instruction, const std::vector<Address>& addresses): addresses(addresses) {
        programIdIndex = findAccount(instruction.programId);
        accounts.reserve(instruction.accounts.size());
        for (auto&& account: instruction.accounts) {
            accounts.emplace_back(findAccount(account.account));
        }
        data = instruction.data;
    }

    uint8_t findAccount(const Address& address);
};

}
