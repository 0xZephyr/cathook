/*
 * Aimbot.hpp
 *
 *  Created on: Oct 8, 2016
 *      Author: nullifiedcat
 */

#pragma once

#include "common.hpp"

class ConVar;
class IClientEntity;

namespace hacks::aimbot
{
extern settings::Boolean aim_sentrybuster;
extern settings::Boolean ignore_cloak;
extern unsigned last_target_ignore_timer;

// Functions used to calculate aimbot data, and if already calculated use it
Vector PredictEntity(CachedEntity *entity);

// Functions called by other functions for when certain game calls are run
void Reset();

// Stuff to make storing functions easy
bool isAiming();
CachedEntity *CurrentTarget();
bool ShouldAim();
CachedEntity *RetrieveBestTarget(bool aimkey_state);
bool IsTargetStateGood(CachedEntity *entity);
bool Aim(CachedEntity *entity);
void DoAutoshoot(CachedEntity *target = nullptr);
int notVisibleHitbox(CachedEntity *target, int preferred);
std::vector<Vector> getHitpointsVischeck(CachedEntity *ent, int hitbox);
float projectileHitboxSize(int projectile_size);
int autoHitbox(CachedEntity *target);
bool hitscanSpecialCases(CachedEntity *target_entity, int weapon_case);
bool projectileSpecialCases(CachedEntity *target_entity, int weapon_case);
int BestHitbox(CachedEntity *target);
bool isHitboxMedium(int hitbox);
int ClosestHitbox(CachedEntity *target);
void DoSlowAim(Vector &inputAngle);
bool UpdateAimkey();
} // namespace hacks::aimbot
