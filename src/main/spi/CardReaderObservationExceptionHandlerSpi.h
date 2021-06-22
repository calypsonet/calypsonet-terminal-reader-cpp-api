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

#include <exception>
#include <string>

namespace calypsonet {
namespace terminal {
namespace reader {
namespace spi {

/**
 * Reader observation error handler to implement in order to be notified of errors that may occur
 * during operations carried out by the card monitoring process.
 *
 * @since 1.0
 */
class CardReaderObservationExceptionHandlerSpi {
public:
    /**
     * Invoked when an error occurs in the observed reader.
     *
     * <p>When an error occurs, the observation process is stopped.
     *
     * @param contextInfo The context information.
     * @param readerName The reader name.
     * @param e The original exception.
     * @since 1.0
     */
    virtual void onReaderObservationError(const std::string& contextInfo,
                                          const std::string& readerName,
                                          const std::exception& e) = 0;
};

}
}
}
}
