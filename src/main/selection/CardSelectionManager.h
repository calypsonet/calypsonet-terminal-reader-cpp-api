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

#include <memory>

/* Calypsonet Terminal Reader */
#include "CardReader.h"
#include "CardSelection.h"
#include "CardSelectionResult.h"
#include "ObservableCardReader.h"

namespace calypsonet {
namespace terminal {
namespace reader {
namespace selection {

using namespace calypsonet::terminal::reader;

using DetectionMode = ObservableCardReader::DetectionMode;
using NotificationMode = ObservableCardReader::NotificationMode;

/**
 * Service dedicated to card selection, based on the preparation of a card selection scenario.
 *
 * <p>A card selection scenario consists of one or more selection cases based on a {@link
 * CardSelection}.<br>
 * A card selection targets a specific card and defines optional commands to be executed after the
 * successful selection of the card. <br>
 * If a card selection case fails, the service will try with the next selection defined in the
 * scenario, if any. <br>
 * If a card selection case succeeds, the service will execute the next selection only if the
 * multiple selection mode is set (disabled by default).
 *
 * <p>This service allows to:
 *
 * <ul>
 *   <li>prepare the card selection scenario,
 *   <li>make an explicit selection of a card (when the card is already present),
 *   <li>to schedule the execution of the selection as soon as a card is presented to an observable
 *       reader.
 * </ul>
 *
 * <p>By default the selection process stops at the first successful selection. However, it is
 * possible to force the execution of all selection cases defined in the scenario using the
 * CardSelectionManager#setMultipleSelectionMode() method.
 *
 * <p>The logical channel established with the card can be left open (default) or closed after
 * selection.
 *
 * @since 1.0.0
 */
class CardSelectionManager {
public:
    /**
     * 
     */
    virtual ~CardSelectionManager() = default;
    
    /**
     * Sets the multiple selection mode to process all selection cases even in case of successful
     * selection.
     *
     * <p>The multiple selection mode is disabled by default.
     *
     * @since 1.0.0
     */
    virtual void setMultipleSelectionMode() = 0;

    /**
     * Appends a card selection case to the card selection scenario.
     *
     * <p>The method returns the index giving the current position of the selection in the selection
     * scenario (0 for the first application, 1 for the second, etc.). This index will be used to
     * retrieve the corresponding result in the {@link CardSelectionResult} object.
     *
     * @param cardSelection The card selection.
     * @return A positive int.
     * @throw IllegalArgumentException If the provided card selection is null.
     * @since 1.0.0
     */
    virtual int prepareSelection(const std::shared_ptr<CardSelection> cardSelection) = 0;

    /**
     * Requests the closing of the physical channel at the end of the execution of the card selection
     * request.
     *
     * <p>It is thus possible to chain several selections on the same card selection scenario by
     * restarting the card connection sequence.
     *
     * @since 1.0.0
     */
    virtual void prepareReleaseChannel() = 0;

    /**
     * Executes explicitly a previously prepared card selection scenario and returns the card
     * selection result.
     *
     * @param reader The reader to communicate with the card.
     * @return A not null reference.
     * @throw IllegalArgumentException If the provided reader is null.
     * @throw ReaderCommunicationException If the communication with the reader has failed.
     * @throw CardCommunicationException If communication with the card has failed or if the status
     *        word check is enabled in the card request and the card has returned an unexpected
     *        code.
     * @throw InvalidCardResponseException If the card returned invalid data during the selection
     *        process.
     * @since 1.0.0
     */
    virtual const std::shared_ptr<CardSelectionResult> processCardSelectionScenario(
        std::shared_ptr<CardReader> reader) = 0;

    /**
     * Schedules the execution of the prepared card selection scenario as soon as a card is
     * presented to the provided ObservableCardReader.
     *
     * <p>calypsonet::terminal::reader::CardReaderEvent are notified to the observer
     * according to the specified notification mode.
     *
     * <p>The reader's behavior at the end of the card processing is defined by the specified
     * ObservableCardReader::DetectionMode.
     *
     * <p>The result of the scenario execution will be analyzed by
     * parseScheduledCardSelectionsResponse(ScheduledCardSelectionsResponse).
     *
     * @param observableCardReader The reader with which the card communication is carried out.
     * @param detectionMode The card detection mode.
     * @param notificationMode The card notification mode.
     * @throw IllegalArgumentException If one of the parameters is null.
     * @since 1.0.0
     */
    virtual void scheduleCardSelectionScenario(
        std::shared_ptr<ObservableCardReader> observableCardReader,
        const DetectionMode detectionMode,
        const NotificationMode notificationMode) = 0;

    /**
     * Analyzes the responses provided by a {@link org.calypsonet.terminal.reader.CardReaderEvent}
     * following the insertion of a card and the execution of the selection scenario.
     *
     * @param scheduledCardSelectionsResponse The card selection scenario execution response.
     * @return A not null reference.
     * @throw IllegalArgumentException If the provided card selection response is null.
     * @throw InvalidCardResponseException If the data returned by the card could not be interpreted.
     * @since 1.0.0
     */
    virtual const std::shared_ptr<CardSelectionResult> parseScheduledCardSelectionsResponse(
        const std::shared_ptr<ScheduledCardSelectionsResponse> scheduledCardSelectionsResponse)
        const = 0;
};

}
}
}
}
