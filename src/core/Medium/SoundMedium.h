//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

/* toy */
#include <obj/Util/Global.h>
#include <core/Generated/Forward.h>
#include <core/Physic/Medium.h>

using namespace mud; namespace toy
{
	class _refl_ TOY_CORE_EXPORT SoundMedium : public Medium, public LazyGlobal<SoundMedium>
	{
	public:
		_constr_ SoundMedium();

	private:
		float m_ambientIntensity;
	};
}
