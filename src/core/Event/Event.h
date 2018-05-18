//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

/* toy */
#include <obj/Var.h>
#include <obj/Unique.h>
#include <core/Generated/Forward.h>
#include <core/Event/EventHandler.h>

/* std */
#include <map>

using namespace mud; namespace toy
{
	using string = std::string;
	using VarDict = std::map<string, Var>;

	class TOY_CORE_EXPORT Event
	{
	public:
		Event(Type& eventType, Entity& source);

	public:
		const Type& m_eventType;
		const EventRelay& m_source;

		typedef std::map<Medium*, float> IntensityMap;
		IntensityMap m_intensity;

		VarDict m_attributes;

		// @ todo : to allow for more than just discrete instance mask checking (area, space, receptor, etc...), use an EventMask interface subclassed with type map dispatching based on subclass
		// std::map<string, EventMask*>
	};

	class TOY_CORE_EXPORT EventSubscriber
	{
	public:
		EventSubscriber(Type& eventType, object_ptr<EventHandler_> handler);

		void call(Event& event);

	public:
		Type& m_eventType;
		object_ptr<EventHandler_> m_handler;

		VarDict m_filters;
	};
}
