#ifndef ENTITIES_ENTITY_H
#define ENTITIES_ENTITY_H

#include <Entities/Types.h>

namespace SonicMania {
    struct Entity {
        /* 0x00000000 */ Vector2 Position;
        /* 0x00000008 */ Vector2 Scale;             // NOTE: 512-based (512 = 0, 1024 = 2, 256 = 1/2)
        /* 0x00000010 */ Vector2 Speed;
        /* 0x00000018 */ Vector2 UpdateRange;       // NOTE: Half of the size of the Update area
        /* 0x00000020 */ Sint32 Angle;              // NOTE: In most cases, angle of ground, or just general use in others
        /* 0x00000024 */ Sint32 TransparencyValue;
        /* 0x00000028 */ Sint32 Rotation;           // NOTE: In range of 0x0 - 0x200 in most cases
        /* 0x0000002C */ Sint32 GroundSpeed;
        /* 0x00000030 */ Uint32 Unk_0x30;
        /* 0x00000034 */ Uint16 Unk_0x34;
        /* 0x00000036 */ Uint16 ObjectID;
        /* 0x00000038 */ Uint32 CanUpdate;          // NOTE: Object sprite does not always need to be on screen to update
        /* 0x0000003C */ Uint32 Unk_0x3C;
        /* 0x00000040 */ Uint32 UseTileCollision;
        /* 0x00000044 */ Uint32 Unk_0x44;
        /* 0x00000048 */ Uint32 Grounded;
        /* 0x0000004C */ Uint8 Priority;            // NOTE: Active State
        /* 0x0000004D */ Uint8 Filter;
        /* 0x0000004E */ Uint8 FlipFlag;
        /* 0x0000004F */ Uint8 DrawGroup;           // NOTE: The layer the Sprite Draws on (0-14)
        /* 0x00000050 */ Uint8 LayerCollisionFlag;
        /* 0x00000051 */ Uint8 PlaneIndex;
        /* 0x00000052 */ Uint8 AngleMode;
        /* 0x00000053 */ Uint8 TransformFlag;       // NOTE: 1: Can Flip, 2: Can Rotate, 4: Can Scale, 8: ???
        /* 0x00000054 */ Uint8 TransparencyFlag;
        /* 0x00000055 */ Uint8 VisibilityFlag;
        /* 0x00000056 */ Uint8 SpriteOnScreenFlag;
        /* 0x00000057 */ Uint8 Unk_0x57;

        // Helper Functions
        void Move(Sint32 x, Sint32 y) {
            Position.X = x;
            Position.Y = y;
        }
        void AddVelocity(Sint32 x, Sint32 y) {
            Speed.X += x;
            Speed.Y += y;
            GroundSpeed += x;
        }
        void SetVelocity(Sint32 x, Sint32 y) {
            Speed.X = x;
            Speed.Y = y;
            GroundSpeed = x;
        }
        void MultiplyVelocity(float x, float y) {
            Speed.X = (int)(Speed.X * x);
            Speed.Y = (int)(Speed.Y * y);
            GroundSpeed = (int)(GroundSpeed * x);
        }
    };
};

#endif /* ENTITIES_ENTITY_H */
