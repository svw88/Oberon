#include "obpch.h"
#include "Entity.h"

namespace Oberon {

	Entity::Entity(entt::entity handle, Scene* scene)
		: m_EntityHandle(handle), m_Scene(scene)
	{
	}

}