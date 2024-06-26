// SPDX-License-Identifier: Apache-2.0
//
// Copyright © 2017 Trust Wallet.

use crate::{EncodingError, EncodingResult};
use serde::{Serialize, Serializer};
use tw_memory::Data;

pub fn encode(data: &[u8], is_url: bool) -> String {
    if is_url {
        data_encoding::BASE64URL.encode(data)
    } else {
        data_encoding::BASE64.encode(data)
    }
}

pub fn decode(data: &str, is_url: bool) -> EncodingResult<Vec<u8>> {
    if is_url {
        data_encoding::BASE64URL.decode(data.as_bytes())
    } else {
        data_encoding::BASE64.decode(data.as_bytes())
    }
    .map_err(|_| EncodingError::InvalidInput)
}

#[derive(Clone, Debug)]
pub struct Base64Encoded(pub Data);

impl Serialize for Base64Encoded {
    fn serialize<S>(&self, serializer: S) -> Result<S::Ok, S::Error>
    where
        S: Serializer,
    {
        let is_url = false;
        serializer.serialize_str(&encode(&self.0, is_url))
    }
}
