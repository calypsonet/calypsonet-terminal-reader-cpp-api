/**************************************************************************************************
 * Copyright (c) 2021 Calypso Networks Association *
 * https://www.calypsonet-asso.org/ *
 *                                                                                                *
 * See the NOTICE file(s) distributed with this work for additional information
 *regarding         * copyright ownership. *
 *                                                                                                *
 * This program and the accompanying materials are made available under the
 *terms of the Eclipse  * Public License 2.0 which is available at
 *http://www.eclipse.org/legal/epl-2.0                  *
 *                                                                                                *
 * SPDX-License-Identifier: EPL-2.0 *
 **************************************************************************************************/

#pragma once

#include <map>
#include <memory>

/* Calypsonet Terminal Reader */
#include "SmartCard.h"

namespace calypsonet {
namespace terminal {
namespace reader {
namespace selection {

using namespace calypsonet::terminal::reader::selection::spi;

/**
 * Result of a selection process.
 *
 * <p>Each selection case prepared with the card selection manager is associated
 * with an index corresponding to its rank in the order of preparation.<br> The
 * same index is used here to find out which selection cases were
 * successful.<br> However, only one case will correspond to the selected card
 * state. The getters of this interface allow to make use of these results
 * according to the configurations and the needs of the application.
 *
 * @since 1.0.0
 */
class CardSelectionResult {
 public:
  /**
   * Gets all SmartCard corresponding to all successful selection cases in a map
   * for which the key is the selection index provided by the
   * CardSelectionManager#prepareSelection(CardSelection) method.
   *
   * @return A not null but possibly empty map.
   * @since 1.0.0
   */
  virtual const std::map<int, std::shared_ptr<SmartCard>>& getSmartCards()
      const = 0;

  /**
   * Gets the active matching card. I.e. the card that has been selected.
   *
   * @return Null if there is no active card.
   * @since 1.0.0
   */
  virtual const std::shared_ptr<SmartCard> getActiveSmartCard() const = 0;

  /**
   * Gets the index of the active selection if any.
   *
   * @return A positive value if there is an active selection, -1 if there is no
   * active selection.
   * @since 1.0.0
   */
  virtual int getActiveSelectionIndex() const = 0;
};

}  // namespace selection
}  // namespace reader
}  // namespace terminal
}  // namespace calypsonet
