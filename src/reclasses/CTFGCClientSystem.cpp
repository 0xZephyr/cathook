/*
 * CTFGCClientSystem.cpp
 *
 *  Created on: Dec 7, 2017
 *      Author: nullifiedcat
 */

#include "common.hpp"
#include "e8call.hpp"

using namespace re;

CTFGCClientSystem *CTFGCClientSystem::GTFGCClientSystem()
{
    typedef CTFGCClientSystem *(*GTFGCClientSystem_t)();
    static uintptr_t addr1 = gSignatures.GetClientSignature(
        "E8 ? ? ? ? 84 C0 0F 85 ? ? ? ? E8 ? ? ? ? 89 04 24 E8 ? ? ? ? 85 C0");
    static GTFGCClientSystem_t GTFGCClientSystem_fn =
        GTFGCClientSystem_t(e8call((void *) (addr1 + 14)));

    return GTFGCClientSystem_fn();
}

void CTFGCClientSystem::AbandonCurrentMatch()
{
    typedef void *(*AbandonCurrentMatch_t)(CTFGCClientSystem *);
    static uintptr_t addr1 = gSignatures.GetClientSignature(
        "55 89 E5 57 56 8D 75 C8 53 81 EC 8C 00 00 00 C7 04 24");
    static AbandonCurrentMatch_t AbandonCurrentMatch_fn =
        AbandonCurrentMatch_t(addr1);
    if (AbandonCurrentMatch_fn == nullptr)
    {
        logging::Info("calling NULL!");
    }
    AbandonCurrentMatch_fn(this);
}

bool CTFGCClientSystem::BConnectedToMatchServer(bool flag)
{
    typedef bool (*BConnectedToMatchServer_t)(CTFGCClientSystem *, bool);
    static uintptr_t addr = gSignatures.GetClientSignature(
        "55 89 E5 53 80 7D ? ? 8B 55 ? 75 ?");
    static BConnectedToMatchServer_t BConnectedToMatchServer_fn =
        BConnectedToMatchServer_t(addr);

    return BConnectedToMatchServer_fn(this, flag);
}

bool CTFGCClientSystem::BHaveLiveMatch()
{
    typedef int (*BHaveLiveMatch_t)(CTFGCClientSystem *);
    static uintptr_t addr = gSignatures.GetClientSignature("55 31 C0 89 E5 53 8B 4D ? 0F B6 91 ? ? ? ?");
    static BHaveLiveMatch_t BHaveLiveMatch_fn = BHaveLiveMatch_t(addr);
    if (BHaveLiveMatch_fn == nullptr)
    {
        logging::Info("calling NULL!");
    }
    return BHaveLiveMatch_fn(this);
}

CTFParty *CTFGCClientSystem::GetParty()
{
    // TODO
    return nullptr;
}

int CTFGCClientSystem::JoinMMMatch()
{
    // TODO
    return 0;
}
