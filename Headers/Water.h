#include <d3d9.h>
class Water{
public:
    struct WaterColumn{
        float TargetHeight;
        float Height;
        float Speed;
        void Update(float dampening, float tension){
            float x = TargetHeight - Height;
            Speed += tension * x - Speed*dampening;
            Height += Speed;
        }
    };
};
