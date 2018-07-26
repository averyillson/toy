//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <core/Forward.h>
#include <core/Physic/CollisionGroup.h>

#ifndef MUD_CPP_20
#include <string>
#include <map>
#include <vector>
#endif

using namespace mud; namespace toy
{
	using string = std::string;

	//@todo : cleanup, remove references to emitters and receptors since it's not supposed to be specific
	//			make_unique masks stored in a map based on the group
    class TOY_CORE_EXPORT Medium
	{
	public:
		Medium(const string& name, bool occlusions = false);

		string m_name;
		bool m_occlusions;
		bool m_solid;

		std::map<CollisionGroup, short int> m_masks;

		short int mask(CollisionGroup group);

		virtual float throughput(EmitterScope& emitter, ReceptorScope& receptor, std::vector<ObstacleBody*>& occluding);
	};
}