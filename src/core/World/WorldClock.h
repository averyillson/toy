//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

/* toy */
#include <obj/Complex.h>
#include <obj/Util/Timer.h>
#include <core/Generated/Forward.h>

using namespace mud; namespace toy
{
    class _refl_ TOY_CORE_EXPORT WorldClock
    {
    public:
        WorldClock(World& world);
        ~WorldClock();

		double stepClock();

		void setSpeed(float speed);
        double stepClock(double realStep);
		double readClock();

		double readSymbolic();

    private:
		World& m_world;
		Clock m_clock;

		float m_speed;
		double m_time;
		double m_symbolicTime;
    };
}
