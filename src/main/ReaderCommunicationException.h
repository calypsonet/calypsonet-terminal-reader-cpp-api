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
 * Indicates that the communication with the reader failed.
 *
 * <p>The most likely reason is a physical disconnection of the reader, but other technical problems
 * may also be the origin of the failure.
 *
 * @since 1.0
 */
class ReaderCommunicationException final : public RuntimeException {
public:
    /**
     * @param message The message to identify the exception context.
     * @since 1.0
     */
    ReaderCommunicationException(const std::string& message) : RuntimeException(message) {}

    /**
     * @param message The message to identify the exception context.
     * @param cause The cause.
     * @since 1.0
     */
    ReaderCommunicationException(const std::string& message, const std::exception& cause)
    : RuntimeException(message, cause) {}
};

}
}
}
