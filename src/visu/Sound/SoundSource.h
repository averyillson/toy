//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <proto/Complex.h>
#include <core/Store/StoreObserver.h>
#include <core/Entity/EntityObserver.h>
#include <visu/Forward.h>

#ifdef TOY_SOUND
#include <snd/Forward.h>
#endif

#ifndef MUD_CPP_20
#include <map>
#endif

using namespace mud; namespace toy
{
	class refl_ TOY_VISU_EXPORT SoundSource : public StoreObserver<State>
	{
	public:
#ifdef TOY_SOUND
		SoundSource(Entity& entity, SoundManager& soundManager);
#else
		SoundSource(Entity& entity);
#endif

		attr_ Entity& m_entity;

#ifdef TOY_SOUND
		void soundDestroyed(Sound& sound);
#endif

		void handle_add(State& effect);
		void handle_remove(State& effect);

	private:
		Active& m_active;

#ifdef TOY_SOUND
		SoundManager& m_soundManager;
		std::map<State*, Sound*> m_sounds;
#endif

		size_t m_updated;
	};
}