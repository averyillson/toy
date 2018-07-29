//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <core/Forward.h>
#include <core/Physic/Medium.h>

using namespace mud; namespace toy
{
	class refl_ TOY_CORE_EXPORT VisualMedium : public Medium
	{
	public:
		constr_ VisualMedium();
		attr_ static VisualMedium me;

		float m_ambient_intensity;
	};
}
