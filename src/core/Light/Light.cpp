//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.


#include <core/Generated/Types.h>
#include <core/Light/Light.h>

#include <core/World/World.h>
#include <core/Entity/Entity.h>
#include <core/Event/EventRelay.h>

#include <core/Physic/Collider.h>
#include <core/Physic/CollisionShape.h>

#include <core/Medium/VisualMedium.h>

#include <math/Colour.h>

using namespace mud; namespace toy
{
	LightReflector::LightReflector(Entity& entity)
		: m_entity(entity)
		, m_brightness(0.f)
		, m_sphere(m_entity.part<Receptor>().addSphere(VisualMedium::me(), 0.1f, CM_LIGHTREFLECTOR))
	{
		entity.add_part(type<LightReflector>(), this);
	}

	void LightReflector::handleMoved()
	{
		for(Entity* entity : m_sphere.m_scope.store())
			entity->part<LightSource>().visualTransformUpdated(*this);

		//printf("VisualEmitter::updated, m_brightness = " << m_brightness.getValue() << std::endl;
	}

    LightSource::LightSource(Entity& entity, Emitter& emitter, float range, float intensity, Colour colour, bool shadows)
        : m_entity(entity)
		, m_emitter(emitter)
		, m_range(range)
		, m_intensity(intensity)
		, m_colour(std::move(colour))
		, m_shadows(shadows)
		, m_sphere(emitter.addSphere(VisualMedium::me(), range, CM_LIGHT))
    {
		m_sphere.m_scope.observe(*this);
	}

	float LightSource::computeIntensity(float distance)
	{
		return (1.f - (distance / m_range)) * m_intensity; // @todo : falloff
	}

	void LightSource::visualTransformUpdated(LightReflector& reflector)
	{
		UNUSED(reflector);
		//vec3 pos = reflector.m_entity.absolutePosition();
		//float value = computeIntensity(distance(pos, m_entity.absolutePosition()));
		//reflector.m_brightness.updateModifier(this, value);
	}

	void LightSource::handleMoved()
	{
		for(Entity* entity : m_sphere.m_scope.store())
			visualTransformUpdated(entity->part<LightReflector>());
	}

	void LightSource::handleAdd(Entity& contact)
	{
		UNUSED(contact);
		//LightReflector& reflector = contact.part<LightReflector>();
		//float value = computeIntensity(0.f);
		//reflector.brightness().setModifier(this, value);
	}

	void LightSource::handleRemove(Entity& contact)
	{
		UNUSED(contact);
		//LightReflector& reflector = contact.part<LightReflector>();
		//reflector.brightness().removeModifier(this);
	}

	OLight::OLight(Id id, Entity& parent, const vec3& position, float range, float intensity, Colour colour, bool shadows)
		: Construct(m_entity, proto<OLight>())
		, m_entity(id, proto<OLight>(), parent, position, ZeroQuat)
		, m_emitter(m_entity)
		, m_light(m_entity, m_emitter, range, intensity, colour, shadows)
	{
		// @5603 : adding to nested only when object is finish -> in prototype
		this->index(m_emitter, m_light);
		m_entity.m_parent->m_contents.add(m_entity);
	}
}
