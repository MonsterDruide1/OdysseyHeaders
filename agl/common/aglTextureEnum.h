#pragma once

namespace agl {

enum class TextureType {
    cTextureType_1D,
    cTextureType_2D,
    cTextureType_3D,
    cTextureType_CubeMap,
    cTextureType_1D_Array,
    cTextureType_2D_Array,
    cTextureType_2D_MSAA,
    cTextureType_2D_MSAA_Array,
};

enum class TextureFormat {
    cTextureFormat_Invalid,
    cTextureFormat_R8_uNorm,
    cTextureFormat_R8_uInt,
    cTextureFormat_R8_sNorm,
    cTextureFormat_R8_sInt,
    cTextureFormat_R16_uNorm,
    cTextureFormat_R16_uInt,
    cTextureFormat_R16_sNorm,
    cTextureFormat_R16_sInt,
    cTextureFormat_R16_float,
    cTextureFormat_R8_G8_uNorm,
    cTextureFormat_R8_G8_uInt,
    cTextureFormat_R8_G8_sNorm,
    cTextureFormat_R8_G8_sInt,
    cTextureFormat_R5_G6_B5_uNorm,
    cTextureFormat_A1_B5_G5_R5_uNorm,
    cTextureFormat_R4_G4_B4_A4_uNorm,
    cTextureFormat_R5_G5_B5_A1_uNorm,
    cTextureFormat_R32_uInt,
    cTextureFormat_R32_sInt,
    cTextureFormat_R32_float,
    cTextureFormat_R16_G16_uNorm,
    cTextureFormat_R16_G16_uInt,
    cTextureFormat_R16_G16_sNorm,
    cTextureFormat_R16_G16_sInt,
    cTextureFormat_R16_G16_float,
    cTextureFormat_R11_G11_B10_float,
    cTextureFormat_A2_B10_G10_R10_uNorm,
    cTextureFormat_A2_B10_G10_R10_uInt,
    cTextureFormat_R8_G8_B8_A8_uNorm,
    cTextureFormat_R8_G8_B8_A8_uInt,
    cTextureFormat_R8_G8_B8_A8_sNorm,
    cTextureFormat_R8_G8_B8_A8_sInt,
    cTextureFormat_R8_G8_B8_A8_SRGB,
    cTextureFormat_R10_G10_B10_A2_uNorm,
    cTextureFormat_R10_G10_B10_A2_uInt,
    cTextureFormat_R32_G32_uInt,
    cTextureFormat_R32_G32_sInt,
    cTextureFormat_R32_G32_float,
    cTextureFormat_R16_G16_B16_A16_uNorm,
    cTextureFormat_R16_G16_B16_A16_uInt,
    cTextureFormat_R16_G16_B16_A16_sNorm,
    cTextureFormat_R16_G16_B16_A16_sInt,
    cTextureFormat_R16_G16_B16_A16_float,
    cTextureFormat_R32_G32_B32_A32_uInt,
    cTextureFormat_R32_G32_B32_A32_sInt,
    cTextureFormat_R32_G32_B32_A32_float,
    cTextureFormat_BC1_uNorm,
    cTextureFormat_BC1_SRGB,
    cTextureFormat_BC2_uNorm,
    cTextureFormat_BC2_SRGB,
    cTextureFormat_BC3_uNorm,
    cTextureFormat_BC3_SRGB,
    cTextureFormat_BC4_uNorm,
    cTextureFormat_BC4_sNorm,
    cTextureFormat_BC5_uNorm,
    cTextureFormat_BC5_sNorm,
    cTextureFormat_BC7_uNorm,
    cTextureFormat_BC7_SRGB,
    cTextureFormat_Depth_16,
    cTextureFormat_Depth_32,
    cTextureFormat_Depth_24_uNorm_Stencil_8,
    cTextureFormat_Depth_32_float_Stencil_8,
    cTextureFormat_Num,
};

enum class TextureAttribute {};

enum class MultiSampleType {};

}  // namespace agl
