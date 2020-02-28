#ifndef ENTITIES_STAGE_ENTITYPLATFORM_H
#define ENTITIES_STAGE_ENTITYPLATFORM_H

#include <Entities/Entity.h>

namespace SonicMania {
    struct EntityPlatform : Entity {
        StatusFunc    Status;
        StatusFunc    CollisionStatus;
        Uint32        Type;
        Position      Amplitude;
        Uint32        Speed;
        Uint32        HasTension;
        Uint8         FrameID;
        Uint8         Collision;
        Uint8         Unk_0x76;
        Uint8         Unk_0x77;
        Position      TileOrigin;
        Uint32        StartX;
        Uint32        StartY;
        Uint32        FinalX;
        Uint32        FinalY;
        Uint32        DeltaX;
        Uint32        DeltaY;
        Uint32        IsPlayerOnTop;
        Uint32        PossibleTimerUntilDrop;
        Uint32        TensionValue;
        Uint8         PlayersOnTopFlag;
        Uint8         PlayersOnLeftFlag;
        Uint8         PlayersOnRightFlag;
        Uint8         PlayersOnBottomFlag;
        Hitbox        Hitbox;
        AnimationData Animation;
        Uint32        ChildCount;
    };
};

#endif /* ENTITIES_STAGE_ENTITYPLATFORM_H */
