#ifndef XALGE_TAG_TAGDATA_HPP
#define XALGE_TAG_TAGDATA_HPP

#include "../Object/ObjectType.hpp"

namespace XALGE {
	namespace Tag {
		class TagsManager;
	}
}

namespace XALGE {
	namespace Tag {
		class TagData {
		protected:
			TagData(const XALGE::Object::ObjectType& objectType, void* object);

			XALGE::Object::ObjectType objectType;
			void* object;

			friend TagsManager;
		};
	}
}

#endif // XALGE_TAG_TAGDATA_HPP