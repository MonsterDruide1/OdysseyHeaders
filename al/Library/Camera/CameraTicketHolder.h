#pragma once

namespace al {
class CameraTicket;
class PlacementId;

class CameraTicketHolder {
public:
    CameraTicketHolder(s32 maxTickets);

    void endInit();
    void registerTicket(CameraTicket* ticket);
    void registerDefaultTicket(CameraTicket* ticket);
    CameraTicket* tryFindEntranceTicket(const PlacementId* placementId, const char* suffix) const;

public:
    CameraTicket** mTickets;
    s32 mNumTickets = 0;
    s32 mMaxTickets;
    CameraTicket* mDefaultTicket = nullptr;
};

}  // namespace al
