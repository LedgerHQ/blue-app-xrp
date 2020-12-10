/*******************************************************************************
 *   XRP Wallet
 *   (c) 2017 Ledger
 *   (c) 2020 Towo Labs
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ********************************************************************************/

#include <string.h>
#include "global.h"
#include "messages/signTransaction.h"

tmpCtx_t tmpCtx;
signState_e signState;
approvalStrings_t approvalStrings;
bool called_from_swap;

void resetTransactionContext() {
    explicit_bzero(&parseContext, sizeof(parseContext_t));
    explicit_bzero(&tmpCtx, sizeof(tmpCtx));

    signState = IDLE;

    if (!called_from_swap) {
        explicit_bzero(&approvalStrings, sizeof(approvalStrings));
    }
}
