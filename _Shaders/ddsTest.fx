Texture2D TextureMap;

struct VertexOutput
{
    float4 position : SV_Position;
    float2 uv : UV0;
};

float dx[4] = { -1, 1, 1, -1 };
float dy[4] = { 1, 1, -1, -1 };
float du[4] = { 0, 1, 1, 0 };
float dv[4] = { 0, 0, 1, 1 };

VertexOutput VS(uint id : SV_VertexID)
{
    VertexOutput output;
    
    output.position = float4(dx[id], dy[id], 0, 1);
    output.uv = float2(du[id], dv[id]);    
    return output;
}

SamplerState samplerState
{
    Filter = MIN_MAG_MIP_LINEAR;
    
    AddressU = Wrap;
    AddressV = Wrap;
};

SamplerState MipLinearSampler
{
    Filter = MIN_MAG_MIP_LINEAR;

    AddressU = Wrap;
    AddressV = Wrap;
    MinLod = 0;
    MaxLod = 5;
};


float4 PS(VertexOutput input) : SV_Target
{
    float4 color = TextureMap.Sample(samplerState, input.uv);
    return color;
}

technique11 T0
{
    pass P0
    {
        SetVertexShader(CompileShader(vs_5_0, VS()));
        SetPixelShader(CompileShader(ps_5_0, PS()));
    }
}