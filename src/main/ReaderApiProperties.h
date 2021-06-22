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

#include <string>

namespace calypsonet {
namespace terminal {
namespace reader {

/**
 * API properties.
 *
 * @since 1.0
 */
class ReaderApiProperties final {
public:
    /**
     * API version: {@value}
     *
     * @since 1.0
     */
    static const std::string VERSION;

private:
    /**
     * Private constructor
     */
    ReaderApiProperties() {}
};

const std::string ReaderApiProperties::VERSION = "1.0";

}
}
}
