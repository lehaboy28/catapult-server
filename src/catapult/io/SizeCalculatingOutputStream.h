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

#pragma once
#include "Stream.h"

namespace catapult { namespace io {

	/// Stream implementation for calculating the stream size.
	struct SizeCalculatingOutputStream : public io::OutputStream {
	public:
		/// Gets the size.
		size_t size() const {
			return m_size;
		}

	public:
		void write(const RawBuffer& buffer) override {
			m_size += buffer.Size;
		}

		void flush() override
		{}

	private:
		size_t m_size = 0;
	};
}}
