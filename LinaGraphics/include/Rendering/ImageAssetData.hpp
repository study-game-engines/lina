/* 
This file is a part of: Lina Engine
https://github.com/inanevin/LinaEngine

Author: Inan Evin
http://www.inanevin.com

Copyright (c) [2018-2020] [Inan Evin]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/*
Class: ImageAssetData



Timestamp: 12/31/2021 8:18:02 PM
*/

#pragma once

#ifndef ImageAssetData_HPP
#define ImageAssetData_HPP

// Headers here.
#include "Resources/IResource.hpp"
#include "Rendering/RenderingCommon.hpp"

namespace Lina::Graphics
{
    class ImageAssetData : public Resources::IResource
    {

    public:
        ImageAssetData()  = default;
        ~ImageAssetData() = default;

        virtual void* LoadFromMemory(const std::string& path, unsigned char* data, size_t dataSize) override;
        virtual void* LoadFromFile(const std::string& path) override;

        SamplerParameters m_samplerParameters;

        template <class Archive>
        void serialize(Archive& archive)
        {
            archive(m_samplerParameters);
        }
    };
} // namespace Lina::Graphics

#endif
