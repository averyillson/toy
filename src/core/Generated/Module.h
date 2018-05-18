
#pragma once

#include <obj/System/System.h>

#include <obj/Generated/Module.h>
#include <math/Generated/Module.h>
#include <geom/Generated/Module.h>
#include <util/Generated/Module.h>
        
#include <core/Generated/Forward.h>
#include <core/Generated/Types.h>

#include <core/Action.h>
#include <core/Bullet.h>
#include <core/Core.h>
#include <core/Generator.h>
#include <core/Active/Active.h>
#include <core/Active/Effect.h>
#include <core/Actor/Actor.h>
#include <core/Area/Area.h>
#include <core/Bullet/BulletCollider.h>
#include <core/Bullet/BulletMotionState.h>
#include <core/Bullet/BulletSolid.h>
#include <core/Bullet/BulletWorld.h>
#include <core/Camera/Camera.h>
#include <core/Camera/CameraObserver.h>
#include <core/Disq/Disq.h>
#include <core/Entity/Entity.h>
#include <core/Entity/EntityObserver.h>
#include <core/Event/Event.h>
#include <core/Event/EventFilter.h>
#include <core/Event/EventHandler.h>
#include <core/Event/EventRelay.h>
#include <core/Event/EventSignal.h>
#include <core/Event/EventTube.h>
#include <core/Light/Light.h>
#include <core/Manoeuvrable/GroundMotion.h>
#include <core/Manoeuvrable/Manoeuvrable.h>
#include <core/Medium/SoundMedium.h>
#include <core/Medium/VisualMedium.h>
#include <core/Movable/MotionState.h>
#include <core/Movable/MotionStateObserver.h>
#include <core/Movable/Movable.h>
#include <core/Navmesh/ChunkyTriMesh.h>
#include <core/Navmesh/NavGeom.h>
#include <core/Navmesh/Navmesh.h>
#include <core/Navmesh/rcTileMesh.h>
#include <core/Path/DetourPath.h>
#include <core/Path/Pathfinder.h>
#include <core/Physic/Collider.h>
#include <core/Physic/CollisionGroup.h>
#include <core/Physic/CollisionShape.h>
#include <core/Physic/Medium.h>
#include <core/Physic/Obstacle.h>
#include <core/Physic/Physic.h>
#include <core/Physic/PhysicWorld.h>
#include <core/Physic/Scope.h>
#include <core/Physic/Signal.h>
#include <core/Physic/Solid.h>
#include <core/Player/Player.h>
#include <core/Reactive/Reactive.h>
#include <core/Selector/Selection.h>
#include <core/Selector/Selector.h>
#include <core/Store/Array.h>
#include <core/Store/CountStore.h>
#include <core/Store/Store.h>
#include <core/Store/StoreObserver.h>
#include <core/Store/VectorObserver.h>
#include <core/Symbolic/Symbolic.h>
#include <core/View/View.h>
#include <core/View/Vision.h>
#include <core/World/Origin.h>
#include <core/World/Section.h>
#include <core/World/World.h>
#include <core/World/WorldClock.h>
#include <core/WorldPage/BufferPage.h>
#include <core/WorldPage/WorldPage.h>

namespace toy
{
	class TOY_CORE_EXPORT toycore : public Module
	{
	private:
		toycore();

	public:
		static toycore& module() { static toycore instance; return instance; }
	};
}

#ifdef TOY_CORE_MODULE
extern "C"
TOY_CORE_EXPORT Module& getModule();
#endif
