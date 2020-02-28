#ifndef ENTITIES_TYPES_H
#define ENTITIES_TYPES_H

namespace SonicMania {
    typedef unsigned char  Uint8;
    typedef signed char    Sint8;
    typedef unsigned short Uint16;
    typedef signed short   Sint16;
    typedef unsigned int   Uint32;
    typedef signed int     Sint32;

    typedef void(__cdecl *StatusFunc)();
    
    struct AnimationData {
        void*  AnimationPtr;
        Uint32 FrameIndex;
        Uint16 AnimationIndex;
        Uint16 PrevAnimationIndex;
        Uint16 FrameDuration;
        Uint16 PrevFrameIndex;
        Uint16 Unk_0x10;
        Uint16 FrameCount;
        Uint8  Unk_0x14;
        Uint8  Unk_0x15;
        Uint8  Unk_0x16;
        Uint8  Unk_0x17;
    };

    enum AttributeType {
        AttributeType_UINT8 = 0x0,
        AttributeType_UINT16 = 0x1,
        AttributeType_UINT32 = 0x2,
        AttributeType_INT8 = 0x3,
        AttributeType_INT16 = 0x4,
        AttributeType_INT32 = 0x5,
        AttributeType_VAR = 0x6,
        AttributeType_BOOL = 0x7,
        AttributeType_STRING = 0x8,
        AttributeType_POSITION = 0x9,
        AttributeType_COLOR = 0xB,
    };
};


#endif /* ENTITIES_TYPES_H */
