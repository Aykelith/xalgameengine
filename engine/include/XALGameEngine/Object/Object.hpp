#ifndef XALGE_OBJECT_OBJECT_HPP
#define XALGE_OBJECT_OBJECT_HPP

#include "ObjectType.hpp"
#include "../Tag/Tag.hpp"

namespace XALGE {
	namespace Object {
		class Object {
		public:
			Object(const ObjectType& objectType);

		public:
			const XALGE::Tag::Tag tag;
		};
	}
}

#endif // XALGE_OBJECT_OBJECT_HPP