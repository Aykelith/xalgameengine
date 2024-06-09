#include <XALGameEngine/Tag/TagData.hpp>

namespace XALGE {
	namespace Tag {
		TagData::TagData(const XALGE::Object::ObjectType& objectType, void* object)
			: objectType { objectType || XALGE::Object::XALGEObjectType::GENERIC_OBJECT }
			, object { object } {}
	}
}