#pragma once
#define _USE_MATH_DEFINES
#include <MemAccess.h>
#include <cmath>


#pragma region PreprocessorDefines

    #define BitFlag(type, enumType) inline type operator|(type a, type b) { return (type)((enumType)a | (enumType)b); }
    #define ALIGN(x) __declspec(align(x))

#pragma endregion

typedef unsigned char byte;
typedef unsigned short ushort;

namespace SonicMania
{
#pragma region TypesDefs

    typedef void(__cdecl *Ability)();
    typedef void(__cdecl *PlayerStatus)();
    typedef void(__cdecl *InputStatus)();

#pragma endregion

#pragma region Declares
    // Entities
    struct Entity;
    struct EntityPlayer;
    struct EntityItemBox;
    struct EntityRing;
    struct EntityUIText;

    struct Hitbox;

#pragma endregion



#pragma region Enums
    // Enum
    enum Scene : short
    {
        Scene_NONE = -1,
        // Presentation 
        Scene_Logo,
        Scene_Title,
        Scene_MainMenu,
        Scene_ThanksForPlaying,
        Scene_LevelSelect,
        Scene_Credits,
        Scene_Continue,
        Scene_Summary,
        Scene_Summary_e,
        // Mania Mode
        Scene_GHZ1,
        Scene_GHZ2,
        Scene_CPZ1,
        Scene_CPZ2,
        Scene_SPZ1,
        Scene_SPZ2,
        Scene_FBZ1,
        Scene_FBZ2,
        Scene_PSZ1,
        Scene_PSZ2,
        Scene_SSZ1,
        Scene_SSZ2,
        Scene_SSZ2M,
        Scene_HCZ1,
        Scene_HCZ2,
        Scene_MSZ1,
        Scene_MSZ1K,
        Scene_MSZ2,
        Scene_OOZ1,
        Scene_OOZ2,
        Scene_LRZ1,
        Scene_LRZ2,
        Scene_LRZ3,
        Scene_LFZ1 = 29, //hi!
        Scene_LFZ2,
        Scene_LFZ3,
        Scene_MMZ1,
        Scene_MMZ2,
        Scene_TMZ1,
        Scene_TMZ2,
        Scene_TMZ3,
        Scene_ERZ,
        // Encore Mode
        Scene_GHZ1_e,
        Scene_GHZ2_e,
        Scene_CPZ1_e,
        Scene_CPZ2_e,
        Scene_SPZ1_e,
        Scene_SPZ2_e,
        Scene_FBZ1_e,
        Scene_FBZ2_e,
        Scene_PSZ1_e,
        Scene_PSZ2_e,
        Scene_SSZ1_e,
        Scene_SSZ2_e,
        Scene_SSZ2M_e,
        Scene_HCZ1_e,
        Scene_HCZ2_e,
        Scene_MSZ1_e,
        Scene_MSZ2_e,
        Scene_OOZ1_e,
        Scene_OOZ2_e,
        Scene_LRZ1_e,
        Scene_LRZ2_e,
        Scene_LRZ3_e,
        Scene_LFZ1_e = 57, //hello!
        Scene_LFZ2_e,
        Scene_LFZ3_e,
        Scene_MMZ1_e,
        Scene_MMZ2_e,
        Scene_TMZ1_e,
        Scene_TMZ2_e,
        Scene_TMZ3_e,
        // Special Stage
        Scene_SpecialStage1,
        Scene_SpecialStage2,
        Scene_SpecialStage3,
        Scene_SpecialStage4,
        Scene_SpecialStage5,
        Scene_SpecialStage6,
        Scene_SpecialStage7,
        Scene_SpecialStage1_e,
        Scene_SpecialStage2_e,
        Scene_SpecialStage3_e,
        Scene_SpecialStage4_e,
        Scene_SpecialStage5_e,
        Scene_SpecialStage6_e,
        Scene_SpecialStage7_e,
        // Blue Sphere (+0 - +31)
        Scene_BlueSphere,
        Scene_BlueSphere_Random = Scene_BlueSphere + 32,
        Scene_BlueSphere_Random2,
        // Pinball
        Scene_Pinball,
        // Extras
        Scene_PuyoPuyo,
        Scene_DAGarden,
        Scene_DAGarden_e,
        // Cutscene
        Scene_Cutscene_AngelIsland,
        Scene_Cutscene_AngelIsland_e,
        Scene_Cutscene_GreenHillZone,
        Scene_Cutscene_GreenHillZone2,
        Scene_Cutscene_MirageSaloonKnucklesIntro,
        Scene_Cutscene_StardustSpeedwayTimeTravel,
        Scene_TryAgain,
        Scene_Cutscene_MirageSaloonEnd_e,
        Scene_TryAgain_e,
        // Video
        Scene_BadEnd_Sonic,
        Scene_BadEnd_Sonic2,
        Scene_BadEnd_Tails,
        Scene_BadEnd_Knux,
        Scene_BadEnd_Mighty,
        Scene_BadEnd_Ray,
        Scene_GoodEnd,
        Scene_TrueEnd
    };
    
    enum Category : byte
    {
        Presentation,
        ManiaMode,
        EncoreMode,
        SpecialStage,
        BlueSpheres,
        Pinball,
        Extras,
        Cutscenes,
        Videos
    };

    enum ShieldType
    {
        ShieldType_None,
        ShieldType_Normal,
        ShieldType_Water,
        ShieldType_Flame,
        ShieldType_Lightning
    };

    enum Character : int
    {
        Character_None   = 0b00000,
        Character_Sonic  = 0b00001,  // 1 << 0
        Character_Tails  = 0b00010,  // 1 << 1
        Character_Knux   = 0b00100,   // 1 << 2
        Character_Mighty = 0b01000, // 1 << 3
        Character_Ray    = 0b10000     // 1 << 4
    };

    enum GameMode : int
    {
        GameMode_ManiaMode,
        GameMode_EncoreMode,
        GameMode_TimeAttack,
        GameMode_Competition
    };

    enum Filter : byte
    {
        Filter_None       = 0b0000,
        Filter_ManiaMode  = 0b0001,
        Filter_Unknown    = 0b0010,
        Filter_EncoreMode = 0b0100
    };
    BitFlag(Filter, byte)

    enum GameStates : byte
    {
        GameState_NotRunning = 0b0000,
        GameState_Running    = 0b0001,
        GameState_SoftPause  = 0b0010,
        GameState_HardPause  = 0b0100,
        GameState_DevMenu    = 0b1000
    };
    BitFlag(GameStates, byte)

    enum DrawingFX : byte
    {
        FX_None   = 0b0000,
        FX_Flip   = 0b0001,
        FX_Rotate = 0b0010,
        FX_Scale  = 0b0100,
    };
    BitFlag(DrawingFX, byte)

    enum Scope : byte
    {
        Scope_None,
        Scope_Global,
        Scope_Stage
    };


    enum ItemBoxItem : byte
    {
        ItemBoxItem_Ring,
        ItemBoxItem_ShieldNormal,
        ItemBoxItem_ShieldWater,
        ItemBoxItem_ShieldFlame,
        ItemBoxItem_ShieldLightning,
        ItemBoxItem_Invincibility,
        ItemBoxItem_SpeedShoes,
        ItemBoxItem_LifeSonic,
        ItemBoxItem_LifeTails,
        ItemBoxItem_LifeKnuckles,
        ItemBoxItem_Eggman,
        ItemBoxItem_CombineRing,
        ItemBoxItem_TeamSwap,
        ItemBoxItem_Random,
        ItemBoxItem_Super,
        ItemBoxItem_LifeMighty,
        ItemBoxItem_LifeRay
    };
    
    enum CollisionModes
    {
        CollisionMode_Floor,
        CollisionMode_LeftWall,
        CollisionMode_Roof,
        CollisionMode_RightWall
    };

    // TODO: needs updating
    enum ObjectType
    {
        //ObjectType_SmogHandle       = 0x00E48CE8,
        //ObjectType_OctusB           = 0x00E48E1C,
        //ObjectType_MechaBu          = 0x00E48FDC,
        //ObjectType_Iwamodoki        = 0x00EBB5D0,
        //ObjectType_Grabber          = 0x00EBB5E0,
        //ObjectType_Woodrow          = 0x00EBB60C,
        //ObjectType_BallHog          = 0x00EBB610,
        //ObjectType_Jugglesaw        = 0x00EBB620,
        //ObjectType_Bumpalo          = 0x00EBB63C,
        //ObjectType_Blastoid         = 0x00EBB68C,
        //ObjectType_Spiny            = 0x00EBB69C,
        //ObjectType_FlasherMkII      = 0x00EBB6A4,
        //ObjectType_Bulb             = 0x00EBB6B0, // TODO: Find proper name
        //ObjectType_Buggernaut       = 0x00EBB6C0,
        //ObjectType_CheckPoint       = 0x00EBB6C4,
        //ObjectType_Rattlekiller     = 0x00EBB6E0,
        //ObjectType_MonkeyDude       = 0x00EBB71C,
        //ObjectType_CatakillerJR     = 0x00EBB730,
        //ObjectType_Sol              = 0x00EBB744,
        //ObjectType_Vultron          = 0x00EBB764,
        //ObjectType_Ring             = 0x00EBB778,
        //ObjectType_DDWrecker        = 0x00EBB788,
        //ObjectType_TurboTurtle      = 0x00EBB7D4,
        //ObjectType_SSRing           = 0x00EBB804,
        //ObjectType_Sweep            = 0x00EBB808,
        //ObjectType_Turtloid         = 0x00EBB83C,
        //ObjectType_FlameThrower     = 0x00EBB840,
        //ObjectType_DoorSwitch       = 0x00EBB854,
        //ObjectType_Splats           = 0x00EBB898,
        //ObjectType_Dragonfly        = 0x00EBB8C0,
        //ObjectType_PohBee           = 0x00EBB8E8,
        //ObjectType_Roller           = 0x00EBB938,
        //ObjectType_Scarab           = 0x00EBB940,
        //ObjectType_LightBulb        = 0x00EBB94C,
        //ObjectType_Rhinobot         = 0x00EBB954,
        //ObjectType_RockDrill        = 0x00EBB960,
        //ObjectType_TechnoSqueek     = 0x00EBB994,
        //ObjectType_Pointdexter      = 0x00EBB9C4,
        //ObjectType_Fireworm         = 0x00EBB9D8,
        //ObjectType_Blaster          = 0x00EBBA04,
        //ObjectType_Chopper          = 0x00EBBA24,
        //ObjectType_Kabasira         = 0x00EBBA30,
        //ObjectType_Tubinaut         = 0x00EBBA68,
        //ObjectType_WallCrawl        = 0x00EBBAAC,
        //ObjectType_Motobug          = 0x00EBBAF8,
        //ObjectType_Jellygnite       = 0x00EBBB34,
        //ObjectType_Act1SkyBoss      = 0x00EBBB44, // TODO: Find proper name
        //ObjectType_Spring           = 0x00EBBB70,
        //ObjectType_Effect           = 0x00EBBB8C,
        //ObjectType_MatryoshkaBom    = 0x00EBBBC8,
        //ObjectType_DrillerDroidB    = 0x00EBBBD4,
        //ObjectType_MeterDroidB      = 0x00EBBBF0,
        //ObjectType_Clucker          = 0x00EBBC20,
        //ObjectType_Pinata           = 0x00EBBC94,
        //ObjectType_Jawz             = 0x00EBBCA8,
        //ObjectType_Hotaru           = 0x00EBBCC0,
        //ObjectType_DERobot          = 0x00EBBD08,
        //ObjectType_Animal           = 0x00EBBD10,
        //ObjectType_ScoreOnHitNumber = 0x00EBBD18,
        //ObjectType_Explosion        = 0x00EBBD1C,
        //ObjectType_MicDrop          = 0x00EBBD40,
        //ObjectType_MegaChopper      = 0x00EBBD50,
        //ObjectType_Octus            = 0x00EBBD5C,
        //ObjectType_Kanabun          = 0x00EBBD64,
        //ObjectType_Rexon            = 0x00EBBD6C,
        //ObjectType_TurboSpiker      = 0x00EBBD88,
        //ObjectType_ShutterBug       = 0x00EBBDF0,
        //ObjectType_IceBomba         = 0x00EBBDF4,
        //ObjectType_SentryBug        = 0x00EBBE08,
        //ObjectType_Cactula          = 0x00EBBE5C,
        //ObjectType_Aquis            = 0x00EBBE7C,
        //ObjectType_ItemBox          = 0x00EBBE98,
        //ObjectType_BuzzBomber       = 0x00EBBEC4,
        //ObjectType_Dango            = 0x00EBBECC,
        //ObjectType_Bloominator      = 0x00EBBEE0,
        //ObjectType_NewTron          = 0x00EBBF1C,
        //ObjectType_CaveBat          = 0x00EBBF28,
        //ObjectType_CrabMeat         = 0x00EBBF34,
        //ObjectType_Toxomister       = 0x00EBBF38
        //General
        ObjectType_Ring             = 0x00AC67E0,
        ObjectType_SSRing           = 0x00AC686C,
        ObjectType_ItemBox          = 0x00AC6F00,
        ObjectType_Spring           = 0x00AC6BD8,
        ObjectType_Animal           = 0x00AC6D78,
        ObjectType_ScoreOnHitNumber = 0x00AC6D80,
        ObjectType_Explosion        = 0x00AC6D84,
        // Green Hill Zone
        ObjectType_Motobug          = 0x00AC6B60,
        ObjectType_CrabMeat         = 0x00AC6F9C,
        ObjectType_Chopper          = 0x00AC6A8C,
        ObjectType_BuzzBomber       = 0x00AC6F2C,
        ObjectType_NewTron          = 0x00AC6F84,
        ObjectType_BatBrain         = 0x00AC6F90,
        ObjectType_Splats           = 0x00AC6900,
        ObjectType_DDWrecker        = 0x00AC67F0,
        ObjectType_DERobot          = 0x00AC6D70,
        // Chemical Plant Zone
        ObjectType_Grabber          = 0x00AC6C18,
        ObjectType_Spiny            = 0x00AC6DAC,
        ObjectType_AmoebaDroid      = 0x00AC67F0,
        ObjectType_CatakillerJR     = 0x00AC6798,
        // Studiopolis Zone
        ObjectType_MicDrop          = 0x00AC6DA8,
        ObjectType_ShutterBug       = 0x00AC6E58,
        ObjectType_Tubinaut         = 0x00AC6AD0,
        ObjectType_WallCrawl        = 0x00AC6B14,
        ObjectType_HeavyGunner      = 0x00AC6C2C,
        ObjectType_WeatherMobile    = 0x00AC6A80,
        // Flying Battery
        ObjectType_TechnoSqueek     = 0x00AC69FC,
        ObjectType_Blaster          = 0x00AC6A6C,
        ObjectType_Clucker          = 0x00AC6C88,
        // Press Garden Zone
        ObjectType_Dragonfly        = 0x00AC6928,
        ObjectType_Jugglesaw        = 0x00AC6688,
        ObjectType_SplatsJar        = 0x00AC6CB4,
        ObjectType_Woodrow          = 0x00AC67FC,
        ObjectType_IceBomba         = 0x00AC66EC,
        ObjectType_HeavyShinobi     = 0x00AC6E18,
        // StarDust Speed Way
        ObjectType_Hotaru           = 0x00AC6808,
        ObjectType_Dango            = 0x00AC6F34,
        ObjectType_Kanabun          = 0x00AC67FC,
        ObjectType_Kabasira         = 0x00AC6CB4,
        ObjectType_SilverSonic      = 0x00AC679C,
        // HydroCity Zone
        ObjectType_Jellygnite       = 0x00AC6B9C,
        ObjectType_Pointdexter      = 0x00AC6A2C,
        ObjectType_Blastoid         = 0x00AC66F4,
        ObjectType_Jawz             = 0x00AC6D10,
        ObjectType_MegaChopper      = 0x00AC6DB8,
        ObjectType_TurboSpiker      = 0x00AC6DF0,
        ObjectType_Buggernaut       = 0x00AC6728,
        //MirageSaloonZone
        ObjectType_Vultron          = 0x00AC67CC,
        ObjectType_Cactula          = 0x00AC6EC4,
        ObjectType_Bumpalo          = 0x00AC66A4,
        ObjectType_Rattlekiller     = 0x00AC6748,
        ObjectType_BallHog          = 0x00AC69A0,
        ObjectType_Armadiloid       = 0x00AC68A4,
        //Oil Ocean Zone
        ObjectType_Aquis            = 0x00AC6EE4,
        ObjectType_Octus            = 0x00AC6DC4,
        ObjectType_Sol              = 0x00AC6778,
        // Lave Reef Zone
        ObjectType_Toxomister       = 0x00AC6FA0,
        ObjectType_Fireworm         = 0x00AC6A40,
        ObjectType_Iwamodoki        = 0x00AC6638,
        ObjectType_Rexon            = 0x00AC6DD4,
        // Metallic Madness Zone
        ObjectType_MechaBu          = 0x00AC6888,
        ObjectType_MatryoshkaBom    = 0x00AC6C30,
        ObjectType_Scarab           = 0x00AC69A8,
        ObjectType_PohBee           = 0x00AC6950,
        // Titanic Monarch Zone
        ObjectType_SentryBug        = 0x00AC6E70,
        ObjectType_TurboTurtle      = 0x00AC683C,
        ObjectType_FlasherMkII      = 0x00AC670C,
        ObjectType_BallHog2         = 0x00AC6678,
        
        // Angel Island Zone 
        ObjectType_MonkeyDude       = 0x00AC6784,
        ObjectType_Rhinobot         = 0x00AC6C24,
        ObjectType_Bloominator      = 0x00AC6F48,

        //Unused - Other
        ObjectType_S1Orbinaught        = 0x00AC6A00,
        ObjectType_S1Catakiller        = 0x00AC6B78,

        //Service Objects 
        ObjectType_FXFade            = 0x00AC6810
    };

    enum TransparencyFlag : byte
    {
        TransparencyFlag_Opaque,
        TransparencyFlag_HalfTransparent,
        TransparencyFlag_Transparent
    };

    enum SuperState : int
    {
        SuperState_NotActive,
        SuperState_Activate,
        SuperState_Active,
        SuperState_Deactive
    };

#pragma endregion

    // TODO: needs updating
#pragma region Constents

    // Player Status
#define CONTROL_NONE                    (SonicMania::PlayerStatus)(0x00000000)
#define CONTROL_NORMAL                  (SonicMania::PlayerStatus)(baseAddress + 0x000C3E00)
#define CONTROL_P2                      (SonicMania::PlayerStatus)(baseAddress + 0x000C4340)


// Player Status
#define PLAYERSTATE_NONE                    (SonicMania::PlayerStatus)(0x00000000)
#define PLAYERSTATE_GROUND                  (SonicMania::PlayerStatus)(baseAddress + 0x000CAD80)
#define PLAYERSTATE_AIR                     (SonicMania::PlayerStatus)(baseAddress + 0x000CB6C0)
#define PLAYERSTATE_JUMP                    (SonicMania::PlayerStatus)(baseAddress + 0x000CB6C0)
#define PLAYERSTATE_LOOKDOWN                (SonicMania::PlayerStatus)(baseAddress + 0x000CBBD0)
#define PLAYERSTATE_LOOKUP                  (SonicMania::PlayerStatus)(baseAddress + 0x000CBAA0)
#define PLAYERSTATE_SPINDASH                (SonicMania::PlayerStatus)(baseAddress + 0x000CBD80)
#define PLAYERSTATE_Roll                    (SonicMania::PlayerStatus)(baseAddress + 0x000CB850)
#define PLAYERSTATE_HURT                    (SonicMania::PlayerStatus)(baseAddress + 0x004CCA00)
#define PLAYERSTATE_DIE                     (SonicMania::PlayerStatus)(baseAddress + 0x000CCAC0)
#define PLAYERSTATE_OUTTAHERE               (SonicMania::PlayerStatus)(baseAddress + 0x000CCE90)
#define PLAYERSTATE_Gimmick                 (SonicMania::PlayerStatus)(baseAddress + 0x000CAD70)
#define PLAYERSTATE_Gimmick2                (SonicMania::PlayerStatus)(baseAddress + 0x004CBA90) // TODO: needs updating
#define PLAYERSTATE_Hanging                 (SonicMania::PlayerStatus)(baseAddress + 0x004CAD70) // TODO: needs updating
#define PLAYERSTATE_SpiningTube_PGZ         (SonicMania::PlayerStatus)(baseAddress + 0x0041F7F0) // TODO: needs updating
#define PLAYERSTATE_Frozen_PGZ              (SonicMania::PlayerStatus)(baseAddress + 0x004A3410) // TODO: needs updating
#define PLAYERSTATE_Sliding_OOZ             (SonicMania::PlayerStatus)(baseAddress + 0x0042EB10) // TODO: needs updating
#define PLAYERSTATE_SwitchingToBG_MMZ       (SonicMania::PlayerStatus)(baseAddress + 0x004304A0) // TODO: needs updating
#define PLAYERSTATE_SwitchingToFG_MMZ       (SonicMania::PlayerStatus)(baseAddress + 0x004305B0) // TODO: needs updating
#define PLAYERSTATE_TurningSmall_MMZ        (SonicMania::PlayerStatus)(baseAddress + 0x00431560) // TODO: needs updating
#define PLAYERSTATE_TurningBig_MMZ          (SonicMania::PlayerStatus)(baseAddress + 0x00431690) // TODO: needs updating
#define PLAYERSTATE_P2FLYIN                 (SonicMania::PlayerStatus)(baseAddress + 0x004CD150)
#define PLAYERSTATE_P2JUMPIN                (SonicMania::PlayerStatus)(baseAddress + 0x004CD560) 
#define PLAYERSTATE_SpringBasic             (SonicMania::PlayerStatus)(baseAddress + 0x000CB6C0)
#define PLAYERSTATE_ScoreCard               (SonicMania::PlayerStatus)(baseAddress + 0x000CCD30)
#define PLAYERSTATE_TransportTube_CPZ       (SonicMania::PlayerStatus)(baseAddress + 0x000CBA90)

// Move Sets
#define PLAYERSTATE_NOJUMPABILITY           (SonicMania::Ability)(0x00000000)
#define PLAYERSTATE_SONICJUMPABILITY        (SonicMania::Ability)(baseAddress + 0x000C8630)
#define PLAYERSTATE_TAILSJUMPABILITY        (SonicMania::Ability)(baseAddress + 0x000C8990)
#define PLAYERSTATE_KNUXJUMPABILITY         (SonicMania::Ability)(baseAddress + 0x000C8A70)
#define PLAYERSTATE_MIGHTYJUMPABILITY       (SonicMania::Ability)(baseAddress + 0x000C8B70)
#define PLAYERSTATE_RAYJUMPABILITY          (SonicMania::Ability)(baseAddress + 0x000C8DF0)
#define PLAYERSTATE_ERZSJUMPABILITY         (SonicMania::Ability)(baseAddress + 0x000C2340) // Egg Reverie Super Sonic

// Sonic
#define PLAYERSTATE_DROPDASH                (SonicMania::PlayerStatus)(baseAddress + 0x004CC1F0)
#define PLAYERSTATE_PEELOUT                 (SonicMania::PlayerStatus)(baseAddress + 0x004CBF70)

// Tails
#define PLAYERSTATE_FLYING                  (SonicMania::PlayerStatus)(baseAddress + 0x000CCF30)
#define PLAYERSTATE_FLYCARRIED              (SonicMania::PlayerStatus)(baseAddress + 0x004CDA60)

// Knuckles
#define PLAYERSTATE_GLIDELEFT               (SonicMania::PlayerStatus)(baseAddress + 0x000CDB10)
#define PLAYERSTATE_GLIDERIGHT              (SonicMania::PlayerStatus)(baseAddress + 0x000CDE10)
#define PLAYERSTATE_GLIDESLIDE              (SonicMania::PlayerStatus)(baseAddress + 0x004CE230)
#define PLAYERSTATE_CLIMB                   (SonicMania::PlayerStatus)(baseAddress + 0x000CE380)
#define PLAYERSTATE_LEDGEPULLUP             (SonicMania::PlayerStatus)(baseAddress + 0x004CE6F0)
#define PLAYERSTATE_GLIDEDROP               (SonicMania::PlayerStatus)(baseAddress + 0x000CE110)

// Mighty
#define PLAYERSTATE_HAMMERDROP              (SonicMania::PlayerStatus)(baseAddress + 0x000CC580)
#define PLAYERSTATE_UNSPIN                  (SonicMania::PlayerStatus)(baseAddress + 0x000CC990) //Unspin after bouncing on hazard

// Ray
#define PLAYERSTATE_RAYGLIDE                (SonicMania::PlayerStatus)(baseAddress + 0x000CD660)

// Move Sets
#define MOVESET_NONE    (SonicMania::Ability)(0x00000000)
#define MOVESET_SONIC   (SonicMania::Ability)(baseAddress + 0x000C8630)
#define MOVESET_TAILS   (SonicMania::Ability)(baseAddress + 0x000C8990)
#define MOVESET_KNUX    (SonicMania::Ability)(baseAddress + 0x000C8A70)
#define MOVESET_MIGHTY  (SonicMania::Ability)(baseAddress + 0x000C8B70)
#define MOVESET_RAY     (SonicMania::Ability)(baseAddress + 0x000C8DF0)
#define MOVESET_ERSS    (SonicMania::Ability)(baseAddress + 0x000C2340) // Egg Reverie Super Sonic


#define PLAYERID1 0
#define PLAYERID2 1
#define PLAYERID3 2
#define PLAYERID4 3

#pragma endregion

#pragma region Structs

    struct Vector2
    {
        Vector2()
        {

        }
        
        Vector2(int x, int y) : Vector2()
        {
            X = x;
            Y = y;
        }

        Vector2(int x) : Vector2()
        {
            X = x;
            Y = x;
        }

        Vector2* Add(Vector2 &vec)
        {
            X += vec.X;
            Y += vec.Y;
            return this;
        }

        Vector2* Sub(Vector2 &vec)
        {
            X -= vec.X;
            Y -= vec.Y;
            return this;
        }

        Vector2* Mul(Vector2 &vec)
        {
            X *= vec.X;
            Y *= vec.Y;
            return this;
        }

        Vector2* Div(Vector2 &vec)
        {
            X /= vec.X;
            Y /= vec.Y;
            return this;
        }

        Vector2* Abs()
        {
            if (X < 0)
                X *= -1;
            if (Y < 0)
                Y *= -1;
        }

        Vector2 operator+(const Vector2& vec2)
        {
            Vector2 vec;
            vec.Add(*this);
            vec.Add(*(Vector2*)&vec2);
            return vec;
        }

        Vector2 operator+=(const Vector2& vec2)
        {
            Add(*(Vector2*)&vec2);
            return *this;
        }

        Vector2 operator-(const Vector2& vec2)
        {
            Vector2 vec;
            vec.Add(*this);
            vec.Sub(*(Vector2*)&vec2);
            return vec;
        }

        Vector2 operator-=(const Vector2& vec2)
        {
            Sub(*(Vector2*)&vec2);
            return *this;
        }

        Vector2 operator*(const Vector2& vec2)
        {
            Vector2 vec;
            vec.Add(*this);
            vec.Mul(*(Vector2*)&vec2);
            return vec;
        }

        Vector2 operator*=(const Vector2& vec2)
        {
            Mul(*(Vector2*)&vec2);
            return *this;
        }

        Vector2 operator/(const Vector2& vec2)
        {
            Vector2 vec;
            vec.Add(*this);
            vec.Div(*(Vector2*)&vec2);
            return vec;
        }

        Vector2 operator/=(const Vector2& vec2)
        {
            Div(*(Vector2*)&vec2);
            return *this;
        }

        /** Calculates the Angle to the target vector
            Vector2 target: Location to the target.
            double Return: Angle between the main and target in Radians.
        **/
        double CalculateAngle(Vector2 target)
        {
            double theta = atan2(target.X - X, Y - target.Y);
            if (theta < 0.0)
                theta += 6.2831853071795865;
            return theta;
        }

        /** Calculates the Distance between to the target vector and the main vector
            Vector2 target: Location to the target.
            double Return: The Distance between the main and target.
        **/
        double inline CalculateDistance(Vector2 target)
        {
            return sqrt(pow(X - target.X, 2) + pow(Y - target.Y, 2));
        }

        bool inline IsNull()
        {
            return X == 0 && Y == 0;
        }



    private:
        WORD SubX;
    public:
        short X = 0;
    private:
        WORD SubY;
    public:
        short Y = 0;
    };
    struct Color
    {
        byte Red;
        byte Green;
        byte Blue;

        Color()
        {

        }

        Color(int rgb)
        {
            Red = (rgb >> 16) & 0xFF;
            Green = (rgb >> 8) & 0xFF;
            Blue = rgb & 0xFF;
        }

        inline SHORT ToRGB565()
        {
            //return ((Red & 0b11111000) << 8) | ((Green & 0b11111100) << 3) | (Blue >> 3);
            return (Blue >> 3) | 32 * (Green >> 2) | ((Red >> 3) << 11);
        }
        
        inline int ToRGB888()
        {
            return ((Red & 0xFF) << 16) + ((Green & 0xFF) << 16) + (Blue & 0xFF);
        }

        inline void FromRGB565(SHORT RGB565)
        {
            Red   = (RGB565 & 0b1111100000000000) >> 8;
            Green = (RGB565 & 0b0000011111100000) >> 3;
            Blue  = (RGB565 & 0b0000000000011111) << 3;
        }

        inline void FromINT(int rgb)
        {
            Red   = (rgb >> 16) & 0xFF;
            Green = (rgb >> 8) & 0xFF;
            Blue  = rgb & 0xFF;
        }

        inline void Tint(float tint)
        {
            Red   *= tint;
            Green *= tint;
            Blue  *= tint;
        }

        inline void Blend(byte r, byte g, byte b, float a)
        {
            Red   = a * r + (1 - a) * Red;
            Green = a * g + (1 - a) * Green;
            Blue  = a * b + (1 - a) * Blue;
        }

        inline void Blend(Color color, float a)
        {
            Red   = a * color.Red   + (1 - a) * Red;
            Green = a * color.Green + (1 - a) * Green;
            Blue  = a * color.Blue  + (1 - a) * Blue;
        }



    };
    struct ControllerInput
    {
        /* 0x00000000 */ ALIGN(4) bool Down;
        /* 0x00000004 */ ALIGN(4) bool Press;
        /* 0x00000008 */ ALIGN(4) bool Unknown;
    };
    struct Controller
    {
        /* 0x00000000 */ ControllerInput Up;
        /* 0x0000000C */ ControllerInput Down;
        /* 0x00000018 */ ControllerInput Left;
        /* 0x00000024 */ ControllerInput Right;
        /* 0x00000030 */ ControllerInput A;
        /* 0x0000003C */ ControllerInput B;
        /* 0x00000048 */ ControllerInput C;
        /* 0x00000054 */ ControllerInput X;
        /* 0x00000060 */ ControllerInput Y;
        /* 0x0000006C */ ControllerInput Z;
        /* 0x00000078 */ ControllerInput Start;
        /* 0x00000084 */ ControllerInput Select;
    };
    struct __declspec(align(4)) EntityAnimationData
    {
        /* 0x00000000 */ void* Animationptr;
        /* 0x00000004 */ int CurrentFrame;
        /* 0x00000008 */ short CurrentAnimation;
        /* 0x0000000A */ short LastAnimation;
        /* 0x0000000C */ short Speed;
        /* 0x0000000E */ short Unknown0E;
        /* 0x00000010 */ short Duration;
        /* 0x00000012 */ short FrameCount; // Frame count + 1?
        /* 0x00000014 */ BYTE unknown14;
        /* 0x00000015 */ BYTE UserFrameCount; //I Added This Normally Unknown
    };
    struct struct_Timer
    { // Not a proper struct, I just want the timer
        /* 0x00000000 */ bool Enabled;
        /* 0x00000001 */ byte Other[7];
        /* 0x00000008 */ byte TimerCentisecond;
        /* 0x00000009 */ byte TimerSecond;
        /* 0x0000000A */ byte TimerMinute;

        void ResetTimer()
        {
            TimerMinute = TimerSecond = TimerCentisecond = 0;
        }

        void AddTime(byte centiseconds = 0, byte seconds = 0, byte minutes = 0)
        {
            TimerMinute += minutes;
            TimerSecond += seconds;
            TimerCentisecond += centiseconds;
            while (TimerCentisecond > 100)
            {
                TimerCentisecond -= 100;
                ++TimerSecond;
            }
            while (TimerSecond > 60)
            {
                TimerSecond -= 60;
                ++TimerMinute;
            }
        }
    };

#pragma endregion

#pragma region Functions

    // Audio
    FastcallFunctionPointer(void, SetupMusic, (int slot, const char* filePath, int loopStart), 0x00002AD0);
    FunctionPointer(int, PlayMusic, (const char* filePath, int slot, int a3, int loopstart, bool loop), 0x001BC640);
    FunctionPointer(int, PlaySoundFX, (short SoundFXID, signed int a2, unsigned __int8 a3), 0x001BC390);
    FunctionPointer(short, GetSoundFXID, (const char *path), 0x001BC2F0);
    FunctionPointer(void, ChangeMusicSpeed, (int slot, float volume, float Channelbalance, float PlaybackSpeed), 0x001BC830);
    
    // Entity
    FunctionPointer(bool, SetSpriteAnimation, (short spriteIndex, short animationID, EntityAnimationData* animationData, bool forceApply, short frameID), 0x001B35E0);
    FastcallFunctionPointer(void, FastChangeCharacter, (EntityPlayer* player, Character character), 0x000C7920);
    FastcallFunctionPointer(void, ApplyShieldEffect, (Entity* entity), 0x000C5910);
    FunctionPointer(Entity*, SpawnObject_Internal, (short objectID, short subObject, DWORD x, DWORD y), 0x001D3E00);
    FunctionPointer(void, DespawnEntity_Internal, (Entity* entity, DWORD a2, DWORD a3), 0x001D3CF0);
    FunctionPointer(FILE*, LoadStaticObject, (int ObjStruct, int a2, Scope scope), 0x001D32B0);
    //Collision
    FunctionPointer(int, ObjectTileCollision, (Entity* Entity, unsigned __int16 SolidityFilter, char CollisionMode, char CollisionPlane, int XOffset, int YOffset, int a7), 0x001BF5F0); //Check Collision at a certain point
    FunctionPointer(int, ObjectPathGrip, (Entity* Entity, unsigned __int16 SolidityFilter, char CollisionMode, char CollisionPlane, int XOffset, int YOffset, int a7), 0x001BFB40); //Check Collision around a certain point
    FunctionPointer(void, ProcessPlayerTileCollisions, (EntityPlayer* Player, Hitbox* OuterBox, Hitbox* InnerBox), 0x001C0060);
    
    // Graphics
    FunctionPointer(void, DrawRect, (short XPos, short YPos, short SizeY, short SizeX, byte R, byte G, byte B, byte Alpha), 0x00001DAC10);
    FunctionPointer(void*, LoadAniTiles, (const char* FilePath, Scope scope), 0x001D4CE0);
    FunctionPointer(void*, SetAniTiles, (ushort SheetID, ushort TileIndex, ushort SrcX, ushort SrcY, ushort FrameWidth, ushort FrameHeight), 0x00BDC4B0);
    FunctionPointer(void*, LoadMesh, (const char* filepath, Scope scope), 0x00BDE080);
    FunctionPointer(void*, DrawSprite, (EntityAnimationData* animationData, signed __int16* a2, int a3), 0x001B3B00);
    FunctionPointer(void*, DrawSpriteRotoZoom, (int XPos, int YPos, int PivotX, int PivotY, int Width, int Height, int SprX, int SprY, signed int ScaleX, signed int ScaleY, int Direction, __int16 Rotation, int InkEffect, signed int Alpha, int SheetID), 0x001D7260); //Internal Call From "DrawSprite"
    FunctionPointer(void*, DrawMesh, (ushort a1, ushort a2, char a3, DWORD* a4, DWORD* a5, int a6), 0x001DEF00);
    FunctionPointer(short, LoadAnimation, (const char* filename, Scope scope), 0x001B1FA0);
    FunctionPointer(char, LoadGif, (int a1, char* filepath, int buffer), 0x001CBA90);
    //Palettes
    FunctionPointer(int, SetPaletteEntry, (char PaletteID, unsigned char Index, int Color), 0x001D5020);
    FunctionPointer(int, GetPaletteEntry, (char PaletteID, unsigned char Index), 0x001D5070);
    FunctionPointer(void, BlendFromPalettes, (byte DestPaletteID, byte SourcePalA, byte SourcePalB, signed int AlphaPerFrame, int StartIndex, int EndIndex), 0x001D54E0);
    FunctionPointer(void*, SetActivePalette, (byte PaletteID, int StartLine, int EndLine), 0x001D50B0);
    FunctionPointer(void*, CopyPaletteColors, (byte SourcePalID, byte SourceIndex, byte DestPalID, byte DestIndex, byte ColorCount), 0x001D50F0);
    FunctionPointer(void*, LoadPalette, (byte PaletteID, const char* Filename, unsigned short ColorCount), 0x001D5150);

    // Utility
    FunctionPointer(int, Rand, (int Min, int Max), 0x00BDC4B0); //ADDRESS COULD BE 0x008DC4B0
    FunctionPointer(int, GetSettingsValue, (int ValueID), 0x001E3270);
    FunctionPointer(void*, SetSettingsValue, (int ValueID, signed int Value), 0x001E33A0);
    FunctionPointer(void, LoadSettings, (), 0x001CD690);
    FunctionPointer(void, SaveSettings, (bool writeToFile), 0x005E4780);
    FunctionPointer(void*, SetPresence, (int a1, const char* message), 0x002016D0);

    // Scenes
    FunctionPointer(int, LoadSceneFile, (int a1), 0x001EF0C0);
    FunctionPointer(void, LoadScene, (int a1), 0x001EF0C0);
    FunctionPointer(int, LoadGameScene, (char* CategoryName, char* SceneName), 0x001F23C0);
    FunctionPointer(char, LoadTileconfig, (), 0x001BE440);
    FunctionPointer(void, LoadGameconfig, (int ths), 0x001C6510);

    // MATRICIES - DO NOT UNCOMMENT UNTIL AN EQUIVALENT TO RSDK_MATRIX IS ADDED
    /*
    FunctionPointer(void*, MatrixTranslateXYZ, (RSDK_MATRIX *Matrix, int X, int Y, int Z), 0x001DD3F0);
    FunctionPointer(void*, MatrixRotateX, (RSDK_MATRIX *Matrix, ushort RotationX), 0x001DD470);
    FunctionPointer(void*, MatrixRotateY, (RSDK_MATRIX *Matrix, ushort RotationY), 0x001DD500);
    FunctionPointer(void*, MatrixRotateZ, (RSDK_MATRIX *RSDK_MATRIX, ushort RotationZ), 0x001DD590);
    FunctionPointer(void*, MatrixInvert, (unsigned int a1, RSDK_MATRIX *Matrix), 0x001DD770);
    FunctionPointer(void*, MatrixMultiply, (RSDK_MATRIX *Matrix1, RSDK_MATRIX *Matrix2), 0x001DE010);
    */


#pragma endregion

#pragma region DataPointers

    // Players
    DataPointer(EntityPlayer, Player1, 0x00469A10);
    DataPointer(EntityPlayer, Player2, 0x00469E68);
    DataPointer(EntityPlayer, Player3, 0x0046A2C0);
    DataPointer(EntityPlayer, Player4, 0x0046A718);

    //Currently Running Entity
    DataPointer(Entity*, CurrentEntity, 0x00AA7634);

    // Other
    DataPointer(Scene, CurrentScene, 0x00A535C4);
    DataPointer(short, CurrentSceneInt, 0x00A535C4);
    DataPointer(Category, CurrentCategory, 0x00A535E0);
    DataPointer(byte, CurrentCategoryInt, 0x00A535E0);

    DataPointer(struct_Timer, Timer, 0x00A535DC);
    DataPointer(GameStates, GameState, 0x00A535E2);
    DataArray(Controller, PlayerControllers, 0x004416D8, 5);
    DataPointer(float, Controller1RStickX, 0x43E5C0);
    DataPointer(float, Controller1RStickY, 0x43E5C4);
    DataPointer(float, Controller1LStickX, 0x43E5C8);
    DataPointer(float, Controller1LStickY, 0x43E5CC);
    char* CurrentSceneName = (char*)(baseAddress + 0x00A5359C);
    
    // Palettes
    DataArray(SHORT, Palette0, 0x00945B58, 256);
    DataArray(SHORT, Palette1, 0x00945D58, 256);
    DataArray(SHORT, Palette2, 0x00945F58, 256);
    DataArray(SHORT, Palette3, 0x00946158, 256);
    DataArray(SHORT, Palette4, 0x00946358, 256);
    DataArray(SHORT, Palette5, 0x00946558, 256);
    DataArray(SHORT, Palette6, 0x00946758, 256);
    DataArray(SHORT, Palette7, 0x00946958, 256);
    
#pragma endregion

#pragma region Entity

    struct Hitbox {
        short Left;
        short Top;
        short Right;
        short Bottom;
    };

    struct CollisionSensor {
        int XPos;
        int YPos;
        int Collided;
        int Angle;
    };

    struct SensorInfo {
        CollisionSensor Sensors[5];
    };

    //A NOTE ON HOW TO GET ATTRIBUTE VALUES

    struct Entity
    {
#pragma region Data
        /* 0x00000000 */ Vector2 Position;
        /* 0x00000008 */ int ScaleX; //512-based (512 = 0, 1024 = 2, 256 = 1/2)
        /* 0x0000000C */ int ScaleY;
        /* 0x00000010 */ int XVelocity;
        /* 0x00000014 */ int YVelocity;
        /* 0x00000018 */ int UpdateRangeX; //How many pixels offscreen to keep the object updating
        /* 0x0000001C */ int UpdateRangeY;
        /* 0x00000020 */ int Angle;
        /* 0x00000024 */ int Alpha; //Transparency
        /* 0x00000028 */ int Rotation;
        /* 0x0000002C */ int Speed;
        /* 0x00000030 */ DWORD field_30;
        /* 0x00000034 */ WORD field_34;
        /* 0x00000036 */ short ObjectID;
        /* 0x00000038 */ bool OnScreen;
        /* 0x0000003C */ DWORD field_3C;
        /* 0x00000040 */ bool TileCollisions;
        /* 0x00000044 */ DWORD field_44;
        /* 0x00000048 */ bool Grounded;
        /* 0x0000004C */ BYTE Priority; //Active State
        /* 0x0000004D */ BYTE Filter;
        /* 0x0000004E */ bool Direction;
        /* 0x0000004F */ BYTE DrawOrder;                // The layer the Sprite Draws on (0-14)
        /* 0x00000050 */ BYTE field_50;
        /* 0x00000050 */ BYTE CollisionMode;
        /* 0x00000052 */ BYTE CollisionPlane;
        /* 0x00000053 */ DrawingFX DrawFX;
        /* 0x00000054 */ BYTE InkEffect;
        /* 0x00000055 */ BYTE field_55;
        /* 0x00000055 */ BYTE field_56;
        /* 0x00000055 */ BYTE field_57;
        /* 0x00000058 */ void* State;
        ///* 0x0000005C */ void* StateDraw;
#pragma endregion

        void Move(short x, short y)
        {
            Position.X = x;
            Position.Y = y;
        }
        void AddVelocity(int x, int y)
        {
            XVelocity += x;
            YVelocity += y;
            Speed += x;
        }
        void SetVelocity(int x, int y)
        {
            XVelocity = x;
            YVelocity = y;
            Speed = x;
        }
        void MultiplyVelocity(float x, float y)
        {
            XVelocity = (int)(XVelocity * x);
            YVelocity = (int)(YVelocity * y);
            Speed = (int)(Speed * x);
        }
    };
    struct EntityPlayer : Entity
    {
        /* 0x00000060 */ DWORD dword60;
        /* 0x00000064 */ DWORD dword64;
        /* 0x00000068 */ EntityAnimationData Animation;
        /* 0x00000080 */ DWORD dword80;
        /* 0x00000084 */ DWORD dword84;
        /* 0x00000088 */ DWORD dword88;
        /* 0x0000008C */ DWORD dword8C;
        /* 0x00000090 */ DWORD dword90;
        /* 0x00000094 */ DWORD dword94;
        /* 0x00000098 */ DWORD dword98;
        /* 0x0000009C */ DWORD dword9C;
        /* 0x000000A0 */ DWORD dwordA0;
        /* 0x000000A4 */ char field_A4[12];
        /* 0x000000B0 */ short SpriteIndex;
        /* 0x000000B2 */ short SpriteIndexTails;
        /* 0x000000B4 */ WORD wordB4;
        /* 0x000000B6 */ unsigned short PlayerID;
        /* 0x000000B8 */ short HitBoxLeft; // TODO: Check if its a pointer to a Hitbox or the Hitbox Struct itself
        /* 0x000000BA */ short HitBoxRight;
        /* 0x000000BC */ short HitBoxTop;
        /* 0x000000BE */ short HitBoxBottom;
        /* 0x000000C0 */ Character Character;
        /* 0x000000C4 */ int RingCount;
        /* 0x000000C8 */ int RingsToNextLife;
        /* 0x000000CC */ ShieldType Shield;
        /* 0x000000D0 */ int LifeCount;
        /* 0x000000D4 */ int Score;
        /* 0x000000D8 */ DWORD dwordD8;
        /* 0x000000DC */ DWORD CombineRing;
        /* 0x000000E0 */ DWORD field_E0;
        /* 0x000000E4 */ DWORD field_E4;
        /* 0x000000E8 */ DWORD field_E8;
        /* 0x000000EC */ DWORD field_EC;
        /* 0x000000F0 */ DWORD field_F0;
        /* 0x000000F4 */ DWORD AirLeft;
        /* 0x000000F8 */ DWORD Invincibility;
        /* 0x000000FC */ DWORD SpeedShoesTTL;
        /* 0x00000100 */ DWORD InvincibilityFrames;
        /* 0x00000104 */ DWORD field_104;
        /* 0x00000108 */ DWORD field_108;
        /* 0x0000010C */ DWORD field_10C;
        /* 0x00000110 */ DWORD field_110;
        /* 0x00000114 */ DWORD field_114;
        /* 0x00000118 */ DWORD IsUpSideDown; // Bool?
        /* 0x0000011C */ DWORD field_11C;
        /* 0x00000120 */ DWORD field_120;
        /* 0x00000124 */ SuperState SuperState;
        /* 0x00000128 */ DWORD field_128;
        /* 0x0000012C */ DWORD GroundSpeed2;
        /* 0x00000130 */ DWORD field_130;
        /* 0x00000134 */ DWORD InteractStatus; // TODO: Work out all the Statuses
        /* 0x00000138 */ BYTE gap138[4];
        /* 0x0000013C */ DWORD dword13C;
        /* 0x00000140 */ DWORD dword140;
        /* 0x00000144 */ DWORD dword144;
        /* 0x00000148 */ DWORD dword148;
        /* 0x0000014C */ int physicsAcceleration;
        /* 0x00000150 */ int physicsDeacceleration;
        /* 0x00000154 */ int physicsAirAcceleration;
        /* 0x00000158 */ int physicsAirDeacceleration;
        /* 0x0000015C */ int physicsUnknown15C;
        /* 0x00000160 */ int physicsUnknown160; // AirDeacceleration?
        /* 0x00000164 */ int physicsUnknown164;
        /* 0x00000168 */ int physicsJumpGravity;
        /* 0x0000016C */ int physicsUnknown16C;
        /* 0x00000170 */ int physicsJumpSpeed;
        /* 0x00000174 */ DWORD dword174;
        /* 0x00000178 */ DWORD dword178;
        /* 0x0000017C */ DWORD dword17C;
        /* 0x00000180 */ DWORD dword180;
        /* 0x00000184 */ DWORD dword184;
        /* 0x00000188 */ DWORD dword188;
        /* 0x0000018C */ DWORD dword18C;
        /* 0x00000190 */ DWORD dword190;
        /* 0x00000194 */ BYTE gap194[8];
        /* 0x0000019C */ DWORD dword19C;
        /* 0x000001A0 */ InputStatus InputStatus;
        /* 0x000001A4 */ int ControllerID;
        /* 0x000001A8 */ DWORD dword1A8;
        /* 0x000001AC */ ALIGN(4) bool Up;
        /* 0x000001B0 */ ALIGN(4) bool Down;
        /* 0x000001B4 */ ALIGN(4) bool Left;
        /* 0x000001B8 */ ALIGN(4) bool Right;
        /* 0x000001BC */ ALIGN(4) bool Jump;
        /* 0x000001C0 */ ALIGN(4) int JumpAbilityFlag;
        /* 0x000001C4 */ int JumpAbility;
        /* 0x000001C8 */ int AbilityTimer;
        /* 0x000001CC */ Ability Moveset;
        /* 0x000001D0 */ Ability UpAbility;
        /* 0x000001D4 */ DWORD dword1D4;
        /* 0x000001D8 */ DWORD dword1D8;
        /* 0x000001DC */ DWORD dword1DC;
        /* 0x000001E0 */ DWORD dword1E0;
        /* 0x000001E4 */ DWORD dword1E4;
        /* 0x000001E8 */ DWORD KillFlag;
        /* 0x000001EC */ DWORD dword1EC;
        /* 0x000001F0 */ DWORD dword1F0;
        /* 0x000001F4 */ DWORD dword1F4;
        /* 0x000001F8 */ DWORD dword1F8;
        /* 0x000001FC */ DWORD dword1FC;
        /* 0x00000200 */ DWORD dword200;
        /* 0x00000204 */ DWORD dword204;
        /* 0x00000208 */ DWORD dword208;
        /* 0x0000020C */ DWORD dword20C;
        /* 0x00000210 */ DWORD dword210;
        /* 0x00000214 */ DWORD dword214;
        /* 0x00000218 */ DWORD dword218;
        /* 0x0000021C */ DWORD dword21C;

        void Kill()
        {
            KillFlag = 1;
        }

        Controller& GetController()
        {
            if (ControllerID < 0 && ControllerID > 4)
                return PlayerControllers[0];
            return PlayerControllers[ControllerID];
        }
    };
    struct EntityItemBox : Entity
    {
        /* 0x0000005C */ int Type;
        /* 0x00000060 */ DWORD dword60;
        /* 0x00000064 */ DWORD dword64;
        /* 0x00000068 */ DWORD dword68;
        /* 0x0000006C */ DWORD dword6C;
        /* 0x00000070 */ DWORD dword70;
        /* 0x00000074 */ DWORD dword74;
        /* 0x00000078 */ DWORD dword78;
        /* 0x0000007C */ DWORD dword7C;
        /* 0x00000080 */ DWORD dword80;
        /* 0x00000084 */ DWORD dword84;
        /* 0x00000088 */ DWORD dword88;
        /* 0x0000008C */ DWORD dword8C;
        /* 0x00000090 */ EntityAnimationData Animation;
        /* 0x000000A8 */ EntityAnimationData AnimationInner;
        /* 0x000000C0 */ byte gapC0[128];

    };
    struct EntityRing : Entity
    {
        /* 0x0000005C */ DWORD dword5C;
        /* 0x00000060 */ int Type;
        /* 0x00000064 */ DWORD dword64;
        /* 0x00000068 */ int RingsToReward;
        /* 0x0000006C */ DWORD dword6C;
        /* 0x00000070 */ DWORD dword70;
        /* 0x00000074 */ DWORD dword74;
        /* 0x00000078 */ DWORD dword78;
        /* 0x0000007C */ DWORD MoveType;
        /* 0x00000080 */ DWORD dword80;
        /* 0x00000084 */ DWORD dword84;
        /* 0x00000088 */ DWORD Speed;
        /* 0x0000008C */ DWORD dword8C;
        /* 0x00000090 */ DWORD dword90;
        /* 0x00000094 */ EntityAnimationData Animation;
    };
    struct EntityFXFade : Entity
    {
        /* 0x0000005C */ int Time;
        /* 0x00000060 */ int SpeedIn;
        /* 0x00000064 */ int Wait;
        /* 0x00000068 */ int SpeedOut;
        /* 0x0000006C */ DWORD Color;
        /* 0x00000070 */ bool OneWay;
        /* 0x00000074 */ bool EventOnly;
        /* 0x00000078 */ bool Overhud;
        /* 0x0000007C */ bool FadeOutBlack;
        /* 0x00000080 */ DWORD dword80;
        /* 0x00000084 */ DWORD dword84;
        /* 0x00000088 */ DWORD Speed;
        /* 0x0000008C */ DWORD dword8C;
        /* 0x00000090 */ DWORD dword90;
        /* 0x00000094 */ EntityAnimationData Animation;
    };
    struct EntityUIText : Entity
    {
        /* 0x0000005C */ DWORD dword5C;
        /* 0x00000060 */ char* Text;
        /* 0x00000064 */ DWORD dword64;
        /* 0x00000068 */ DWORD dword68;
        /* 0x0000006C */ DWORD dword6C;
        /* 0x00000070 */ DWORD dword70;
        /* 0x00000074 */ DWORD dword74;
        /* 0x00000078 */ DWORD dword78;
        /* 0x0000007C */ DWORD dword7C;
        /* 0x00000080 */ DWORD dword80;
        /* 0x00000084 */ DWORD dword84;
        /* 0x00000088 */ DWORD dword88;
        /* 0x0000008C */ DWORD dword8C;
        /* 0x00000090 */ DWORD dword90;
    };
    struct EntityMotoBug : Entity
    {
        /* 0x0000005C */ DWORD dword5C;
        /* 0x00000060 */ DWORD Timer;
        /* 0x00000064 */ DWORD StartX;
        /* 0x00000068 */ DWORD StartY;
        /* 0x0000006C */ BYTE StartDirection;
        /* 0x0000006D */ BYTE field_6D;
        /* 0x0000006E */ BYTE field_6E;
        /* 0x0000006F */ BYTE field_6F;
        /* 0x00000070 */ DWORD dword70;
        /* 0x00000074 */ EntityAnimationData Animation;
        /* 0x00000088 */ DWORD dword88;
        /* 0x0000008C */ DWORD dword8C;
        /* 0x00000090 */ DWORD dword90;

    };

#pragma endregion

#pragma region Pointer Functions
    static byte GetChaosEmeraldBits()
    {
        int* pointer = (int*)(baseAddress + 0x00AC6A20);
        if (!*pointer)
            return 0;
        pointer = (int*)(*pointer + 0x10);
        if (!*pointer)
            return 0;
        pointer = (int*)(*pointer + 0x70);
        if (!*pointer)
            return 0;
        return *pointer;
    }

    static byte GetChaosEmeraldCount()
    {
        int CECount = 0;
        byte CE = GetChaosEmeraldBits();
        if (CE == 0)
            return 0;
        for (int i = 0; i < 7; ++i)
            if (CE & (1 << i))
                ++CECount;
        return CECount;
    }
#pragma endregion

#pragma region HelperFunctions
    // Written by Sajid
    inline SHORT ToRGB565(byte R, byte G, byte B)
    {
        //return ((R & 0b11111000) << 8) | ((G & 0b11111100) << 3) | (B >> 3);
        return (B >> 3) | ((G >> 2) << 5) | ((R >> 3) << 11);
    }

    inline SHORT ManiaRGB565(byte R, byte G, byte B)
    {
        int v9 = 0;
        SHORT result;
        do
        {
            R = (v9 & 0xFFF8) << 8;
            result = v9 >> 3;
            G = 8 * (v9 & 0xFFFC);
            B = v9 >> 3;
            ++v9;
        } while (v9 < 256);
        return result;
    }

    inline void ToRGB888(SHORT val, byte &R, byte &G, byte &B)
    {
        R = (val & 0b1111100000000000) >> 8;
        G = (val & 0b0000011111100000) >> 3;
        B = (val & 0b0000000000011111) << 3;
    }

    inline SHORT ToRGB565(int val)
    {
        return ToRGB565((val >> 16) & 0xFF, (val >> 8) & 0xFF, val & 0xFF);
    }

    inline int ToRGB888(SHORT val)
    {
        byte oR = (val & 0xF800) >> 11;
        byte oG = (val & 0x7E0) >> 5;
        byte oB = (val & 0x1F);

        byte R = (oR * 527 + 23) >> 6;
        byte G = (oG * 259 + 33) >> 6;
        byte B = (oB * 527 + 23) >> 6;
        return ((R & 0xFF) << 16) | ((G & 0xFF) << 8) | (B & 0xFF);
    }

    inline int Blend(int blended, int overlay, float a)
    {

        byte OR = (blended >> 16) & 0xFF;
        byte OG = (blended >> 8) & 0xFF;
        byte OB = blended & 0xFF;

        byte NR = (overlay >> 16) & 0xFF;
        byte NG = (overlay >> 8) & 0xFF;
        byte NB = overlay & 0xFF;

        byte R = (byte)(a * NR + (1 - a) * OR);
        byte G = (byte)(a * NG + (1 - a) * OG);
        byte B = (byte)(a * NB + (1 - a) * OB);

        return ((R & 0xFF) << 16) | ((G & 0xFF) << 8) | (B & 0xFF);
    }

    inline void WriteRGB888ToRGB565Array(SHORT* writeAddress, byte* colors, int colorCount)
    {
        for (int i = 0; i < colorCount; ++i)
            writeAddress[i] = ToRGB565(colors[(i * 3) + 0], colors[(i * 3) + 1], colors[(i * 3) + 2]);
    }

    inline SHORT* GetColour(SHORT* Palette, int x, int y)
    {
        return Palette + x + 16 * y;
    }

    inline int* GetAddress(int baseAddress, int offset1)
    {
        return (int*)((*(int*)baseAddress) + offset1);
    }
    inline int* GetAddress(int baseAddress, int offset1, int offset2)
    {
        return (int*)(*(int*)GetAddress(baseAddress, offset1) + offset2);
    }
    static byte GetSpritePointer(int SpritePointer, int offset)
    {
        int* pointer = (int*)(baseAddress + SpritePointer);
        if (!*pointer)
            return 0;
        pointer = (int*)(*pointer + offset);
        if (!*pointer)
            return 0;
        return *pointer;
    }
#pragma endregion

#pragma region ManiaHelperFunctions

    inline Character GetCharacter(int playerId)
    {
        return *((Character*)GetAddress((baseAddress + 0x00AA763C), 4 + playerId));
    }

    inline Character* GetCharacter_ptr(int playerId)
    {
        return ((Character*)GetAddress((baseAddress + 0x00AA763C), 4 + playerId));
    }

    template <typename T>
    inline T* GetActiveEntity()
    {
        return (T*)CurrentEntity;
    }

    template <typename T>
    inline T* GetEntityFromSceneSlot(int slot)
    {
        return (T*)((baseAddress + 0x0047B010) + (slot * 0x458));
    }

    template <typename T>
    static T* GetAbsAddress(int jmp)
    {
        int r = *(int*)(jmp + 1);
        int abs = jmp + r + 5;
        return (T*)abs;
    }
    
    inline short GetObjectIDFromType(ObjectType type)
    {
        if (*((int*)(baseAddress + type)) == 0)
            return 0;
        return *(short*)GetAddress((int)(baseAddress + type), 0);
    }
    
    inline Ability GetMoveSetByCharacter(Character character)
    {
        switch (character)
        {
        case Character_Sonic:
            return MOVESET_SONIC;
        case Character_Tails:
            return MOVESET_TAILS;
        case Character_Knux:
            return MOVESET_KNUX;
        case Character_Mighty:
            return MOVESET_MIGHTY;
        case Character_Ray:
            return MOVESET_RAY;
        default:
            return MOVESET_SONIC;
        }
    }
    
    inline void RestartScene()
    {
        // Setting GameState to NotRunning restarts the scene
        GameState = GameState_NotRunning;
    }
    
    inline void ChangeScene(Scene scene)
    {
        CurrentScene = scene;
        GameState = GameState_NotRunning;
    }
    
    inline Entity* SpawnObject(short objectID, short subObject, short x, short y)
    {
        return SpawnObject_Internal(objectID, subObject, ((int)x) << 16, ((int)y) << 16);
    }
    
    inline Entity* SpawnObject(short objectID, short subObject, Vector2 position)
    {
        return SpawnObject(objectID, subObject, position.X, position.Y);
    }
    
    inline void DespawnEntity(Entity* entity)
    {
        DespawnEntity_Internal(entity, 0, 0);
    }
    
    inline void PlaySong(const char* filePath, int loopstart, bool loop)
    {
        int* addr = GetAddress(0x00AC6E08, 0x248);
        if ((int)addr > 0x248)
            *addr = PlayMusic(filePath, 0, 0, loopstart, loop ? 1 : 0);
        else
            PlayMusic(filePath, 0, 0, loopstart, loop ? 1 : 0);

    }
    
    inline int PlaySoundFXS(const char *path)
    {
        return PlaySoundFX(GetSoundFXID(path), 0, 0xFF);
    }

    static int loc_LoadSoundFX = baseAddress + 0x001BBA00;
    static _declspec(naked) short LoadSoundFX(const char* path, Scope scope)
    {
        __asm
        {
            mov dl, 1
            mov ecx, [ESP + 4]
            push[ESP + 8]
            call loc_LoadSoundFX
            add esp, 4
            ret
        }
    }

    static short TryLoadSoundFX(const char* path, Scope scope)
    {
        if (GetSoundFXID(path) == (short)-1)
            return LoadSoundFX(path, scope);
        return -1;
    }


    static int loc_HitEntity = (baseAddress + 0x001C9380);
    inline __declspec(naked) bool HitEntity(Entity* attacker, Entity* target, DWORD a3)
    {
        __asm
        {
            mov edx, [ESP + 4]
            mov ecx, [ESP + 8]
            push[ESP + 12]
            call loc_HitEntity
            add esp, 4
            ret
        }
    }
    static int loc_CallEffect = (baseAddress + 0x001D3CF0);
    inline __declspec(naked) bool CallEffect(EntityPlayer* Player, Entity* target)
    {
        __asm
        {
            mov edx, [ESP + 4]
            mov ecx, [ESP + 8]
            push[ESP + 12]

            mov edi, [ESP + 0x04]
            push edi

            push 0x12
            push eax

            call loc_HitEntity
            add esp, 4
            ret
        }
    }

#pragma endregion

#pragma region ManiaPatches
    
    inline void BindLBAndRB()
    {
        // LB
        byte LBPatch[6]{ (byte)0x09, (byte)0x42, (byte)0x4C, (byte)0x90, (byte)0x90, (byte)0x90 };
        WriteData((byte*)(baseAddress + 0x001E6358), LBPatch, 6);
        // RB
        byte RBPatch[6]{ (byte)0x09, (byte)0x42, (byte)0x70, (byte)0x90, (byte)0x90, (byte)0x90 };
        WriteData((byte*)(baseAddress + 0x001E6362), RBPatch, 6);
    }

#pragma endregion

#pragma region DevMenu

    enum DevMenu_Alignment : int
    {
        Alignment_Left,
        Alignment_Center,
        Alignment_Right
    };

    DataPointer(bool, DevMenu_Enabled, 0x002FC867);
    DataPointer(void*, DevMenu_Address, 0x002FBB40);
    DataPointer(int, DevMenu_Option, 0x002FBB44);
    DataPointer(int, DevMenu_Scroll, 0x002FBB48);
    FunctionPointer(int, DevMenu_DrawRect, (int x, int y, signed int width, int height, int color, signed int a6, int a7, int a8), 0x001D8870);
    FunctionPointer(int, DevMenu_DrawText, (int x, const char* text, int y, DevMenu_Alignment CenterText, int color), 0x1D58C0);
    DataPointer(DWORD, dword_D3CC00, 0x947C6C);

    FunctionPointer(char, Devmenu_MainMenu, (), 0x001C2500);
    FunctionPointer(char, Devmenu_StageSelect, (), 0x001C2B60);
    FunctionPointer(char, Devmenu_SceneSelect, (), 0x001C2DB0);
    FunctionPointer(char, Devmenu_Options, (), 0x001C3090);


    int DrawDevText(int x, int y, DevMenu_Alignment CenterText, int color, const char* format, ...) {
        return DevMenu_DrawText(x, format, y, CenterText, color);
    }

    static int loc_DrawText = baseAddress + 0x1D58C0;
    static __declspec(naked) WORD DevMenu_DrawTextASM(int XPosition, const char* text, int YPosition, DevMenu_Alignment alignment, int color)
    {
        __asm
        {
            mov edx, [ESP + 4]
            mov ecx, [ESP + 8]
            push[ESP + 20]
            push[ESP + 20]
            push[ESP + 20]
            call loc_DrawText
            add esp, 12
            ret
        }
    }

#pragma endregion

}