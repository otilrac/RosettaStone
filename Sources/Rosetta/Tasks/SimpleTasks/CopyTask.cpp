// This code is based on Sabberstone project.
// Copyright (c) 2017-2019 SabberStone Team, darkfriend77 & rnilva
// RosettaStone is hearthstone simulator using C++ with reinforcement learning.
// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

#include <Rosetta/Games/Game.hpp>
#include <Rosetta/Tasks/SimpleTasks/CopyTask.hpp>

namespace RosettaStone::SimpleTasks
{
CopyTask::CopyTask(EntityType entityType, int amount)
    : ITask(entityType), m_amount(amount)
{
    // Do nothing
}

TaskID CopyTask::GetTaskID() const
{
    return TaskID::COPY;
}

TaskStatus CopyTask::Impl(Player& player)
{
    std::vector<Entity*> result;

    switch (m_entityType)
    {
        case EntityType::STACK:
            for (auto& entity : player.GetGame()->taskStack.entities)
            {
                for (int i = 0; i < m_amount; ++i)
                {
                    result.emplace_back(entity);
                }
            }
            break;
        default:
            throw std::invalid_argument(
                "CopyTask::Impl() - Invalid entity type");
    }

    player.GetGame()->taskStack.entities = result;

    return TaskStatus::COMPLETE;
}
}  // namespace RosettaStone::SimpleTasks
