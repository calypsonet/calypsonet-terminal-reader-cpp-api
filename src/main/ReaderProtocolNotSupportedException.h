/**************************************************************************************************
 * Copyright (c) 2021 Calypso Networks Association                                                *
 * https://www.calypsonet-asso.org/                                                               *
 *                                                                                                *
 * See the NOTICE file(s) distributed with this work for additional information regarding         *
 * copyright ownership.                                                                           *
 *                                                                                                *
 * This program and the accompanying materials are made available under the terms of the Eclipse  *
 * Public License 2.0 which is available at http://www.eclipse.org/legal/epl-2.0                  *
 *                                                                                                *
 * SPDX-License-Identifier: EPL-2.0                                                               *
 **************************************************************************************************/

#pragma once

/* Keyple Core Util */
#include "RuntimeException.h"

namespace calypsonet {
namespace terminal {
namespace reader {

using namespace keyple::core::util::cpp::exception;

/**
 * Indicates that the current card protocol is not supported by the reader.
 *
 * @since 1.0.0
 */
class ReaderProtocolNotSupportedException final : public RuntimeException {
public:
    /**
     * @param cardProtocol The identification data used to identify the card.
     * @since 1.0.0
     */
    ReaderProtocolNotSupportedException(const std::string& cardProtocol)
    : RuntimeException("The card protocol " +
                       cardProtocol +
                       " is not supported.") {}
};

}
}
}
