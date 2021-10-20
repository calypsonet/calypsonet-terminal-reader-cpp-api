/**************************************************************************************************
 * Copyright (c) 2021 Calypso Networks Association https://calypsonet.org/                        *
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

#include <string>

namespace calypsonet {
namespace terminal {
namespace reader {

/**
 * Card reader driving the underlying hardware to manage the card detection.
 *
 * @since 1.0
 */
class CardReader {
public:
    /**
     * 
     */
    virtual ~CardReader() = default;

    /**
     * Gets the name of the reader.
     *
     * @return A not empty string.
     * @since 1.0
     */
    virtual const std::string& getName() const = 0;

    /**
     * Tells if the card communication mode is contactless.
     *
     * C++ note: this function cannot be set 'const' as some derived classes will set internal
     *           flags accordingly.
     *
     * @return True if the communication is contactless.
     * @since 1.0
     */
    virtual bool isContactless() = 0;

    /**
     * Checks if is the card present.
     *
     * @return True if a card is inserted in the reader.
     * @throws ReaderCommunicationException If the communication with the reader has failed.
     * @since 1.0
     */
    virtual bool isCardPresent() = 0;
};

}
}
}
