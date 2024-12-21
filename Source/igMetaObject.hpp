#pragma once

#include "igBaseMeta.hpp"
#include "igObjectList.hpp"
#include "igVector.hpp"

namespace Core
{
	class igMetaField;

	class igMetaObject : public igBaseMeta
	{
	public:
		igTVector<igMetaField*> _metaFields;
		int32_t _instanceCount;
		void** _vTablePointer;
		igMetaObject* _parent;
		igObject* _lastChild;
		igObject* _nextSibling;
		uint16_t _index;
		uint16_t _sizeofSize;
		uint16_t _properties;
		uint16_t _requiredAlignment;
		igTVector<void*> _metaFunctions;
		igObjectList* _attributes;
		int32_t _id;

		inline bool isOfType(const igMetaObject* other) const
		{
			return Core::igMetaObject_isOfType(this, other);
		}
	};
}