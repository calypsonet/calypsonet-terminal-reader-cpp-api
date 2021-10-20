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

#include <memory>

/* Calypsonet Terminal Reader */
#include "CardReaderEvent.h"

namespace calypsonet {
namespace terminal {
namespace reader {
namespace spi {

/**
 * Reader observer to implement in order to receive {@link CardReaderEvent} from a
 * calypsonet::terminal::reader::ObservableCardReader.
 *
 * @since 1.0.0
 */
class CardReaderObserverSpi {
public:
    /**
     * Invoked when a reader event occurs.
     *
     * <p>The event notification should be done <b>sequentially</b> and <b>synchronously</b> but
     * this may depend on the implementation used.
     *
     * @param readerEvent The not null CardReaderEvent containing the event data.
     * @since 1.0.0
     */
    virtual void onReaderEvent(const std::shared_ptr<CardReaderEvent> readerEvent) = 0;
};

}
}
}
}
