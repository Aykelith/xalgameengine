#include <XALGameEngine/Object/Object.hpp>
#include <XALGameEngine/Tag/TagsManager.hpp>
#include <XALGameEngine/GlobalTagsManager.hpp>

namespace XALGE {
	namespace Object {
		Object::Object(const ObjectType& objectType)
			: tag{ XALGE::GlobalTagsManager.generateTag(objectType, this) } {

		}
	}
}