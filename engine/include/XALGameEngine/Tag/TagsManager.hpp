#ifndef XALGE_TAG_TAGS_MANAGER_HPP
#define XALGE_TAG_TAGS_MANAGER_HPP

#include "Tag.hpp"
#include "TagData.hpp"
#include "../Object/ObjectType.hpp"

#include <unordered_map>
#include <unordered_set>

namespace XALGE {
	namespace Tag {
		class TagsManager {
		public:
			TagsManager();

			const Tag generateTag(const XALGE::Object::ObjectType& objectType, void* const object);

			template <typename T>
			T* getObjectWithTag(const Tag& tag) const;
		private:
			std::unordered_set<Tag> unusedTags;
			std::unordered_map<Tag, TagData> usedTags;
			Tag nextTag = 0;
		};

		template <typename T>
		T* TagsManager::getObjectWithTag(const Tag& tag) const {
			return static_cast<T*>(this->usedTags.at(tag).object);
		}
	}
}

#endif // XALGE_TAG_TAGS_MANAGER_HPP