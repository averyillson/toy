//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <block/Forward.h>
#include <block/Element.h>

using namespace mud; namespace toy
{
	class TOY_BLOCK_EXPORT Earth : public Element, public LazyGlobal<Earth>
	{
	public:
		Earth() : Element("earth", MatterState::Solid, Colour(0.4f, 0.3f, 0.3f)) {}
	};

	class TOY_BLOCK_EXPORT Stone : public Element, public LazyGlobal<Stone>
	{
	public:
		Stone() : Element("stone", MatterState::Solid, Colour(0.6f, 0.6f, 0.65f)) {}
	};

	class TOY_BLOCK_EXPORT Sand : public Element, public LazyGlobal<Sand>
	{
	public:
		Sand() : Element("sand", MatterState::Solid, Colour(0.55f, 0.5f, 0.2f)) {}
	};

	class TOY_BLOCK_EXPORT Air : public Element, public LazyGlobal<Air>
	{
	public:
		Air() : Element("air", MatterState::Gas, Colour(1.f, 1.f, 1.f)) {}
	};

	class TOY_BLOCK_EXPORT Gas : public Element, public LazyGlobal<Gas>
	{
	public:
		Gas() : Element("gas", MatterState::Gas, Colour(1.f, 0.1f, 0.f)) {}
	};

	class TOY_BLOCK_EXPORT Minerals : public Element, public LazyGlobal<Minerals>
	{
	public:
		Minerals() : Element("minerals", MatterState::Solid, Colour(0.1f, 0.2f, 1.f)) {}
	};

	class TOY_BLOCK_EXPORT Fungus : public Element, public LazyGlobal<Fungus>
	{
	public:
		Fungus() : Element("mushrooms", MatterState::Solid, Colour(0.f, 1.f, 0.1f)) {}
	};

	class TOY_BLOCK_EXPORT Water : public Element, public LazyGlobal<Water>
	{
	public:
		Water() : Element("water", MatterState::Liquid, Colour(0.f, 0.3f, 1.f)) {}
	};
}