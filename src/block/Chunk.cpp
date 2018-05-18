//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.


#include <block/Generated/Types.h>
#include <block/Chunk.h>

#include <block/Block.h>
#include <block/Sector.h>

#include <core/Entity/Entity.h>
#include <core/WorldPage/WorldPage.h>

using namespace mud; namespace toy
{
	Chunk::Chunk(Id id, Entity& parent, const vec3& position, size_t index, Element& element, float size)
		: Construct(m_entity, proto<Chunk>())
		, m_entity(id, proto<Chunk>(), parent, position, ZeroQuat)
		, m_index(index)
		, m_block(*sector().m_block)
		, m_element(element)
		, m_size(size)
	{
		this->index(*this); // @5603 : adding to nested only when object is finish -> in prototype
		m_entity.m_parent->m_contents.add(m_entity); // @5603 : adding to nested only when object is finish -> in prototype
	}

	Sector& Chunk::sector()
	{
		Entity* parent = m_entity.m_parent;
		for(size_t depth = 1; !parent->has_part(type<WorldPage>()); parent = parent->m_parent)
			++depth;

		return parent->part<Sector>();
	}

	Chunk* Chunk::neighbour(Side side)
	{
		UNUSED(side);
		return nullptr;
		//return m_block.neighbour(m_index, side);
	}

	bool Chunk::boundary(Side side)
	{
		Chunk* neighbour = this->neighbour(side);
		return (!neighbour || neighbour->m_element.m_matterState != this->m_element.m_matterState);
	}
}
