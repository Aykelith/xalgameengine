#ifndef XALGE_OBJECT_OBJECT_TYPE_HPP
#define XALGE_OBJECT_OBJECT_TYPE_HPP

#include <cstdint>

namespace XALGE {
	namespace Object {
		typedef uint64_t ObjectType;

		enum XALGEObjectType : ObjectType {
			GENERIC_OBJECT = 0,
			WINDOW = 1
		};
	}
}

#endif // XALGE_OBJECT_OBJECT_TYPE_HPP