//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLPixelFormat.hpp
//
// Copyright 2020-2021 Apple Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// Modifications copyright (C) 2022 Carlos Arauz.
//
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#pragma once

#include "MTLDefines.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"

#ifndef SINGLE_METAL_HEADER
#include <Foundation/Foundation.hpp>
#endif

namespace MTL
{
_MTL_ENUM(NS::UInteger, PixelFormat) {
    PixelFormatInvalid = 0,
    PixelFormatA8Unorm = 1,
    PixelFormatR8Unorm = 10,
    PixelFormatR8Unorm_sRGB = 11,
    PixelFormatR8Snorm = 12,
    PixelFormatR8Uint = 13,
    PixelFormatR8Sint = 14,
    PixelFormatR16Unorm = 20,
    PixelFormatR16Snorm = 22,
    PixelFormatR16Uint = 23,
    PixelFormatR16Sint = 24,
    PixelFormatR16Float = 25,
    PixelFormatRG8Unorm = 30,
    PixelFormatRG8Unorm_sRGB = 31,
    PixelFormatRG8Snorm = 32,
    PixelFormatRG8Uint = 33,
    PixelFormatRG8Sint = 34,
    PixelFormatB5G6R5Unorm = 40,
    PixelFormatA1BGR5Unorm = 41,
    PixelFormatABGR4Unorm = 42,
    PixelFormatBGR5A1Unorm = 43,
    PixelFormatR32Uint = 53,
    PixelFormatR32Sint = 54,
    PixelFormatR32Float = 55,
    PixelFormatRG16Unorm = 60,
    PixelFormatRG16Snorm = 62,
    PixelFormatRG16Uint = 63,
    PixelFormatRG16Sint = 64,
    PixelFormatRG16Float = 65,
    PixelFormatRGBA8Unorm = 70,
    PixelFormatRGBA8Unorm_sRGB = 71,
    PixelFormatRGBA8Snorm = 72,
    PixelFormatRGBA8Uint = 73,
    PixelFormatRGBA8Sint = 74,
    PixelFormatBGRA8Unorm = 80,
    PixelFormatBGRA8Unorm_sRGB = 81,
    PixelFormatRGB10A2Unorm = 90,
    PixelFormatRGB10A2Uint = 91,
    PixelFormatRG11B10Float = 92,
    PixelFormatRGB9E5Float = 93,
    PixelFormatBGR10A2Unorm = 94,
    PixelFormatRG32Uint = 103,
    PixelFormatRG32Sint = 104,
    PixelFormatRG32Float = 105,
    PixelFormatRGBA16Unorm = 110,
    PixelFormatRGBA16Snorm = 112,
    PixelFormatRGBA16Uint = 113,
    PixelFormatRGBA16Sint = 114,
    PixelFormatRGBA16Float = 115,
    PixelFormatRGBA32Uint = 123,
    PixelFormatRGBA32Sint = 124,
    PixelFormatRGBA32Float = 125,
    PixelFormatBC1_RGBA = 130,
    PixelFormatBC1_RGBA_sRGB = 131,
    PixelFormatBC2_RGBA = 132,
    PixelFormatBC2_RGBA_sRGB = 133,
    PixelFormatBC3_RGBA = 134,
    PixelFormatBC3_RGBA_sRGB = 135,
    PixelFormatBC4_RUnorm = 140,
    PixelFormatBC4_RSnorm = 141,
    PixelFormatBC5_RGUnorm = 142,
    PixelFormatBC5_RGSnorm = 143,
    PixelFormatBC6H_RGBFloat = 150,
    PixelFormatBC6H_RGBUfloat = 151,
    PixelFormatBC7_RGBAUnorm = 152,
    PixelFormatBC7_RGBAUnorm_sRGB = 153,
    PixelFormatPVRTC_RGB_2BPP = 160,
    PixelFormatPVRTC_RGB_2BPP_sRGB = 161,
    PixelFormatPVRTC_RGB_4BPP = 162,
    PixelFormatPVRTC_RGB_4BPP_sRGB = 163,
    PixelFormatPVRTC_RGBA_2BPP = 164,
    PixelFormatPVRTC_RGBA_2BPP_sRGB = 165,
    PixelFormatPVRTC_RGBA_4BPP = 166,
    PixelFormatPVRTC_RGBA_4BPP_sRGB = 167,
    PixelFormatEAC_R11Unorm = 170,
    PixelFormatEAC_R11Snorm = 172,
    PixelFormatEAC_RG11Unorm = 174,
    PixelFormatEAC_RG11Snorm = 176,
    PixelFormatEAC_RGBA8 = 178,
    PixelFormatEAC_RGBA8_sRGB = 179,
    PixelFormatETC2_RGB8 = 180,
    PixelFormatETC2_RGB8_sRGB = 181,
    PixelFormatETC2_RGB8A1 = 182,
    PixelFormatETC2_RGB8A1_sRGB = 183,
    PixelFormatASTC_4x4_sRGB = 186,
    PixelFormatASTC_5x4_sRGB = 187,
    PixelFormatASTC_5x5_sRGB = 188,
    PixelFormatASTC_6x5_sRGB = 189,
    PixelFormatASTC_6x6_sRGB = 190,
    PixelFormatASTC_8x5_sRGB = 192,
    PixelFormatASTC_8x6_sRGB = 193,
    PixelFormatASTC_8x8_sRGB = 194,
    PixelFormatASTC_10x5_sRGB = 195,
    PixelFormatASTC_10x6_sRGB = 196,
    PixelFormatASTC_10x8_sRGB = 197,
    PixelFormatASTC_10x10_sRGB = 198,
    PixelFormatASTC_12x10_sRGB = 199,
    PixelFormatASTC_12x12_sRGB = 200,
    PixelFormatASTC_4x4_LDR = 204,
    PixelFormatASTC_5x4_LDR = 205,
    PixelFormatASTC_5x5_LDR = 206,
    PixelFormatASTC_6x5_LDR = 207,
    PixelFormatASTC_6x6_LDR = 208,
    PixelFormatASTC_8x5_LDR = 210,
    PixelFormatASTC_8x6_LDR = 211,
    PixelFormatASTC_8x8_LDR = 212,
    PixelFormatASTC_10x5_LDR = 213,
    PixelFormatASTC_10x6_LDR = 214,
    PixelFormatASTC_10x8_LDR = 215,
    PixelFormatASTC_10x10_LDR = 216,
    PixelFormatASTC_12x10_LDR = 217,
    PixelFormatASTC_12x12_LDR = 218,
    PixelFormatASTC_4x4_HDR = 222,
    PixelFormatASTC_5x4_HDR = 223,
    PixelFormatASTC_5x5_HDR = 224,
    PixelFormatASTC_6x5_HDR = 225,
    PixelFormatASTC_6x6_HDR = 226,
    PixelFormatASTC_8x5_HDR = 228,
    PixelFormatASTC_8x6_HDR = 229,
    PixelFormatASTC_8x8_HDR = 230,
    PixelFormatASTC_10x5_HDR = 231,
    PixelFormatASTC_10x6_HDR = 232,
    PixelFormatASTC_10x8_HDR = 233,
    PixelFormatASTC_10x10_HDR = 234,
    PixelFormatASTC_12x10_HDR = 235,
    PixelFormatASTC_12x12_HDR = 236,
    PixelFormatGBGR422 = 240,
    PixelFormatBGRG422 = 241,
    PixelFormatDepth16Unorm = 250,
    PixelFormatDepth32Float = 252,
    PixelFormatStencil8 = 253,
    PixelFormatDepth24Unorm_Stencil8 = 255,
    PixelFormatDepth32Float_Stencil8 = 260,
    PixelFormatX32_Stencil8 = 261,
    PixelFormatX24_Stencil8 = 262,
    PixelFormatBGRA10_XR = 552,
    PixelFormatBGRA10_XR_sRGB = 553,
    PixelFormatBGR10_XR = 554,
    PixelFormatBGR10_XR_sRGB = 555,
};

}
