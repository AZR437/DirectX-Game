
struct PS_INPUT
{
    float4 position : SV_POSITION;
    float3 colour : COLOUR;
    float3 colour1 : COLOUR1;
};

cbuffer constant : register(b0)
{
    row_major float4x4 world;
    row_major float4x4 view;
    row_major float4x4 proj;
    float angle;
};

float4 psmain(PS_INPUT input) : SV_TARGET
{
    return float4(lerp(input.colour, input.colour1, (sin(angle) + 1.0f) / 2.0f), 1.0f);
}