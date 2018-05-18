//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Physic/Signal.h>

#include <core/Entity/Entity.h>
#include <core/Entity/Entity.h>

#include <core/Physic/Scope.h>
#include <core/Physic/Medium.h>
#include <core/Physic/PhysicWorld.h>
#include <core/Physic/Obstacle.h>

using namespace mud; namespace toy
{
	Signal::Signal(EmitterScope& emitter, ReceptorScope& receptor)
		: m_emitter(&emitter)
		, m_receptor(&receptor)
		, m_strength(0.f)
		, m_on(false)
		, m_occluding()
	{
		if(!m_emitter->m_medium.m_occlusions)
			this->on();

		update();
	}

	Signal::~Signal()
	{
		if(m_on)
			this->off();
	}

	void Signal::update()
	{
		if(m_emitter->m_medium.m_occlusions)
		{
			std::vector<Collider*> occluding;

			m_emitter->raycast(*m_receptor, occluding, CM_OBSTACLE);

			m_occluding.clear();

			for(Collider* coll : occluding)
				m_occluding.push_back(static_cast<ObstacleBody*>(coll));

			m_strength = m_emitter->m_medium.computeThroughput(*m_emitter, *m_receptor, m_occluding);

			if(m_strength > 0.f && !m_on)
				this->on();
			else if(m_strength == 0.f && m_on)
				this->off();
		}
	}

	void Signal::on()
	{
		m_on = true;
		m_receptor->m_scope.add(m_emitter->m_entity);
		m_emitter->m_scope.add(m_receptor->m_entity);
	}

	void Signal::off()
	{
		m_on = false;
		m_receptor->m_scope.remove(m_emitter->m_entity);
		m_emitter->m_scope.remove(m_receptor->m_entity);
	}
}
