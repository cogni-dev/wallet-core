// SPDX-License-Identifier: Apache-2.0
//
// Copyright © 2017 Trust Wallet.

use crate::{EncodingError, EncodingResult};
use bs58::decode::Error;
pub use bs58::Alphabet;

impl From<Error> for EncodingError {
    fn from(_: Error) -> Self {
        EncodingError::InvalidInput
    }
}

pub fn encode(input: &[u8], alphabet: &Alphabet) -> String {
    bs58::encode(input).with_alphabet(alphabet).into_string()
}

pub fn decode(input: &str, alphabet: &Alphabet) -> EncodingResult<Vec<u8>> {
    bs58::decode(input)
        .with_alphabet(alphabet)
        .into_vec()
        .map_err(EncodingError::from)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_base58_encode() {
        let data = b"Hello, world!";
        let expected = "72k1xXWG59wUsYv7h2";

        let result = encode(data, Alphabet::BITCOIN);
        assert_eq!(result, expected);
    }

    #[test]
    fn test_base58_decode() {
        let data = "72k1xXWG59wUsYv7h2";
        let expected = b"Hello, world!";

        let result = decode(data, Alphabet::BITCOIN).unwrap();
        assert_eq!(result, expected.to_vec());
    }
}
