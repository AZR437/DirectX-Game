struct VS_INPUT
{
    float4 position : POSITION;
    float4 position1 : POSITION1;
    float3 colour : COLOUR;
    float3 colour1 : COLOUR1;
};

struct VS_OUTPUT
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


VS_OUTPUT vsmain(VS_INPUT input)
{
    VS_OUTPUT output = (VS_OUTPUT) 0;
	
    //output.position = lerp(input.position, input.position1, (sin(angle) + 1.0f) / 2.0f);
    //World Space
    output.position = mul(input.position, world);
    //View  Space
    output.position = mul(output.position, view);
    //Screen Space
    output.position = mul(output.position, proj);
    
    output.colour = input.colour;
    output.colour1 = input.colour1; 

    return output;
}