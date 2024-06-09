#include <XALGameEngine/Log.hpp>
#include <XALGameEngine/Tag/TagsManager.hpp>

#ifndef UNUSED_TAGS_INITIAL_RESERVE
#define UNUSED_TAGS_INITIAL_RESERVE 1000
#endif

#ifndef USED_TAGS_INITIAL_RESERVE
#define USED_TAGS_INITIAL_RESERVE 10000
#endif

namespace XALGE { namespace Tag {
	TagsManager::TagsManager() {
		this->unusedTags.reserve(UNUSED_TAGS_INITIAL_RESERVE);
		this->usedTags.reserve(USED_TAGS_INITIAL_RESERVE);
	}

	const Tag TagsManager::generateTag(const XALGE::Object::ObjectType& objectType, void* const object) {
		const auto tag = nextTag;
		VERBOSE("New tag " << tag << " for object of type " << objectType << " at address " << object);
		nextTag += 1;

		this->usedTags.insert({ tag, { objectType, object } });

		return tag;
	}
} }