/**************************************************************************************************
 * Copyright (c) 2023 Calypso Networks Association https://calypsonet.org/                        *
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
#include "CardReaderObserverSpi.h"
#include "CardReaderObservationExceptionHandlerSpi.h"

namespace calypsonet {
namespace terminal {
namespace reader {

using namespace calypsonet::terminal::reader::spi;

/**
 * Card reader able to observe the insertion/removal of cards.
 *
 * @since 1.0.0
 */
class ObservableCardReader : virtual public CardReader {
public:
    /**
     * Card detection management options to be applied after processing a card.
     *
     * @since 1.0.0
     */
    enum DetectionMode {

        /**
         * Continue waiting for the insertion of a next card.
         *
         * @since 1.0.0
         */
        REPEATING,

        /**
         * Stop and wait for a restart signal.
         *
         * @since 1.0.0
         */
        SINGLESHOT
    };

    /**
     * The options that apply when a card is detected.
     *
     * @since 1.0.0
     */
    enum NotificationMode {

        /**
         * All cards presented to the readers are notified to the observers, regardless of the
         * result of the selection.
         *
         * @since 1.0.0
         */
        ALWAYS,
        /**
         * Only the cards that have been successfully selected will be notified to the observers.
         * The others will be ignored and the application will not be aware of their presence.
         *
         * @since 1.0.0
         */
        MATCHED_ONLY
    };

    /**
     * Sets the exception handler.
     *
     * <p>The invocation of this method is <b>mandatory</b> when the reader has to be observed.
     *
     * <p>In case of a fatal error during the observation, the handler will receive a notification.
     *
     * @param exceptionHandler The exception handler implemented by the application.
     * @throws IllegalArgumentException If the provided handler is null.
     * @since 1.0.0
     */
    virtual void setReaderObservationExceptionHandler(
        std::shared_ptr<CardReaderObservationExceptionHandlerSpi> exceptionHandler) = 0;

    /**
     * Registers a new observer to be notified when a reader event occurs.
     *
     * <p>The provided observer must implement the CardReaderObserverSpi interface to be able
     * to receive the events produced by this reader (card insertion, removal, etc.)
     *
     * @param observer An observer object implementing the required interface (should be not null).
     * @throw IllegalArgumentException If the provided observer is null.
     * @since 1.0.0
     */
    virtual void addObserver(std::shared_ptr<CardReaderObserverSpi> observer) = 0;

    /**
     * Unregisters a reader observer.
     *
     * <p>The observer will no longer receive any of the events produced by this reader.
     *
     * @param observer The observer object to be removed (should be not null).
     * @throw IllegalArgumentException If the provided observer is null.
     * @since 1.0.0
     */
    virtual void removeObserver(const std::shared_ptr<CardReaderObserverSpi> observer) = 0;

    /**
     * Unregisters all observers at once.
     *
     * @since 1.0.0
     */
    virtual void clearObservers() = 0;

    /**
     * Provides the current number of registered observers.
     *
     * @return An int.
     * @since 1.0.0
     */
    virtual int countObservers() const = 0;

    /**
     * Starts the card detection. Once activated, the application can be notified of the arrival of
     * a card.
     *
     * <p>The DetectionMode indicates the action to be followed after processing the card.
     *
     * @param detectionMode The card detection mode.
     * @throw IllegalArgumentException If the provided detection mode is null.
     * @since 1.0.0
     */
    virtual void startCardDetection(const DetectionMode detectionMode) = 0;

    /**
     * Stops the card detection.
     *
     * @since 1.0.0
     */
    virtual void stopCardDetection() = 0;

    /**
     * Notifies the observation process that the processing of the card has been completed in order
     * to ensure that the card monitoring cycle runs properly.
     *
     * <p>This method has no effect if the physical communication channel has already been closed.
     *
     * <p>It is <b>mandatory</b> to invoke this method when the physical communication channel with
     * the card could not be closed properly.<br>
     * The channel closing is nominally managed during the last transmission with the card. However,
     * there are cases where exchanges with the card are interrupted (e.g. by an exception), in
     * which case it is necessary to explicitly close the channel using this method.
     *
     * <p>In practice, it is recommended to invoke this method in all cases (e.g. in a "finally"
     * statement) at the end of a card processing whatever the result.
     *
     * @since 1.0.0
     */
    virtual void finalizeCardProcessing() = 0;
};

}
}
}
