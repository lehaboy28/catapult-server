/**
*** Copyright (c) 2016-present,
*** Jaguar0625, gimre, BloodyRookie, Tech Bureau, Corp. All rights reserved.
***
*** This file is part of Catapult.
***
*** Catapult is free software: you can redistribute it and/or modify
*** it under the terms of the GNU Lesser General Public License as published by
*** the Free Software Foundation, either version 3 of the License, or
*** (at your option) any later version.
***
*** Catapult is distributed in the hope that it will be useful,
*** but WITHOUT ANY WARRANTY; without even the implied warranty of
*** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
*** GNU Lesser General Public License for more details.
***
*** You should have received a copy of the GNU Lesser General Public License
*** along with Catapult. If not, see <http://www.gnu.org/licenses/>.
**/

#include "AccountLinkBuilder.h"

namespace catapult { namespace builders {

	AccountLinkBuilder::AccountLinkBuilder(model::NetworkIdentifier networkIdentifier, const Key& signer)
			: TransactionBuilder(networkIdentifier, signer)
			, m_remotePublicKey()
			, m_linkAction()
	{}

	void AccountLinkBuilder::setRemotePublicKey(const Key& remotePublicKey) {
		m_remotePublicKey = remotePublicKey;
	}

	void AccountLinkBuilder::setLinkAction(model::AccountLinkAction linkAction) {
		m_linkAction = linkAction;
	}

	size_t AccountLinkBuilder::size() const {
		return sizeImpl<Transaction>();
	}

	std::unique_ptr<AccountLinkBuilder::Transaction> AccountLinkBuilder::build() const {
		return buildImpl<Transaction>();
	}

	std::unique_ptr<AccountLinkBuilder::EmbeddedTransaction> AccountLinkBuilder::buildEmbedded() const {
		return buildImpl<EmbeddedTransaction>();
	}

	template<typename TransactionType>
	size_t AccountLinkBuilder::sizeImpl() const {
		// calculate transaction size
		auto size = sizeof(TransactionType);
		return size;
	}

	template<typename TransactionType>
	std::unique_ptr<TransactionType> AccountLinkBuilder::buildImpl() const {
		// 1. allocate, zero (header), set model::Transaction fields
		auto pTransaction = createTransaction<TransactionType>(sizeImpl<TransactionType>());

		// 2. set fixed transaction fields
		pTransaction->RemotePublicKey = m_remotePublicKey;
		pTransaction->LinkAction = m_linkAction;

		return pTransaction;
	}
}}
