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
#include <typeinfo>

/* Calypsonet Terminal Reader */
#include "ScheduledCardSelectionsResponse.h"

namespace calypsonet {
namespace terminal {
namespace reader {

using namespace calypsonet::terminal::reader::selection;

/**
 * Card event data container indicating a change of state.
 *
 * <p>Contains the event origin (reader name), the event type and possibly the card selection
 * response in the case of Type::CARD_INSERTED or Type::CARD_MATCHED events.
 *
 * @since 1.0
 */
class CardReaderEvent {
public:
    /**
     * Possible card events.
     *
     * @since 1.0
     */
    enum Type {

        /**
         * A card has been inserted with or without specific selection.
         *
         * @since 1.0
         */
        CARD_INSERTED,

        /**
         * A card has been inserted and matched the selection.
         *
         * @since 1.0
         */
        CARD_MATCHED,

        /**
         * The card has been removed from the reader.
         *
         * @since 1.0
         */
        CARD_REMOVED,

        /**
         * The reader has become unavailable.
         *
         * @since 1.0
         */
        UNAVAILABLE
    };

    /**
     * Gets the name of the reader that generated the event.
     *
     * @return A not empty string.
     * @since 1.0
     */
    virtual const std::string& getReaderName() const = 0;

    /**
     * Gets the reader event type.
     *
     * @return A not null value.
     * @since 1.0
     */
    virtual Type getType() const = 0;

    /**
     * Gets the card selection responses that may be present when the event is Type::CARD_INSERTED},
     * always present when the event is Type::CARD_MATCHED and null in the others cases.
     *
     * <p>It is necessary to use the method {@link
     * calypsonet::terminal::reader::selection::CardSelectionManager
     *     ::parseScheduledCardSelectionsResponse(ScheduledCardSelectionsResponse)
     * to analyze the result.
     *
     * @return Null if the event is not carrying a {@link ScheduledCardSelectionsResponse}.
     * @since 1.0
     */
    virtual const std::shared_ptr<ScheduledCardSelectionsResponse>
        getScheduledCardSelectionsResponse() const = 0;
};

}
}
}
