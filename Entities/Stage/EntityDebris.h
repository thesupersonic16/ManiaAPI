#ifndef ENTITIES_STAGE_ENTITYDEBRIS_H
#define ENTITIES_STAGE_ENTITYDEBRIS_H

#include <Entities/Entity.h>

namespace SonicMania {
    struct EntityDebris : Entity {
        StatusFunc Status;
        Uint32 Life;
        Uint32 Gravity;
        Uint32 RotationSpeed;
        Position ScaleSpeed;
        Uint32 Wait;
        AnimationData Animation;
    };
};

#endif /* ENTITIES_STAGE_ENTITYDEBRIS_H */
