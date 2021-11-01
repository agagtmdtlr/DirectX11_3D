#include "00_Global.fx"
#include "00_Light.fx"

Texture2D DiffuseMap2;

cbuffer CB_Render2D
{
    matrix View2D;
    matrix Projection2D;
};

cbuffer CB_MipMapDesc
{
    float level;
    float3 padding;
};

SamplerState mipmapSST;

struct VertexOutput
{
    float4 Position : SV_Position0;
    float2 Uv : Uv0;
};

VertexOutput VS(VertexTexture input)
{
    VertexOutput output;

    output.Position = WorldPosition(input.Position);
    output.Position = mul(output.Position, View2D);
    output.Position = mul(output.Position, Projection2D);
    output.Uv = input.Uv;

    return output;
}

float4 PS(VertexOutput input) : SV_TARGET0
{
    return DiffuseMap.Sample(LinearSampler, input.Uv);
}

float4 PS2(VertexOutput input) : SV_TARGET0
{
    float3 color = DiffuseMap.Sample(LinearSampler, input.Uv).x;
    float3 color2 = DiffuseMap2.Sample(LinearSampler, input.Uv).x;
    
    float c = min(color.x , color2.x);
    //float c = color2.x;
    
    
    return float4(c,c,c, 1);
}

float4 PSMipMap(VertexOutput input) : SV_TARGET0
{
    return DiffuseMap.SampleLevel(mipmapSST, input.Uv, level);
}


technique11 T0
{
    // 깊이를 끄고 텍스처를 그립니다. 레이어를 쌓는 개념이다.
    P_DSS_VP(P0, DepthEnable_False, VS, PS)
    P_DSS_VP(P1, DepthEnable_False, VS, PS2)
    P_DSS_VP(P2, DepthEnable_False, VS, PSMipMap)
}