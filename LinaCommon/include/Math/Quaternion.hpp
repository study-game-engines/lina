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
Class: Quaternion

m_data structure for representing quaternions, glm wrapper.

Timestamp: 10/14/2018 10:42:21 PM

*/

#pragma once

#ifndef Quaternion_HPP
#define Quaternion_HPP

#include "Vector.hpp"

namespace Lina
{

    class Quaternion : public glm::quat
    {

    public:
        Quaternion() : glm::quat(1, 0, 0, 0){};
        Quaternion(const Vector4& v) : glm::quat(v.w, v.x, v.y, v.z){};
        Quaternion(float x, float y, float z, float w) : glm::quat(w, x, y, z){};
        Quaternion(glm::quat q) : glm::quat(q){};
        Quaternion(const Vector3& axis, float angle);

        Quaternion operator+(const Quaternion& other) const
        {
            return *this + other;
        }
        Quaternion operator-(const Quaternion& other) const
        {
            return *this - other;
        }
        Quaternion operator*(const Quaternion& other) const
        {
            return glm::quat(*this) * glm::quat(other);
        }
        Quaternion operator*(float amt) const
        {
            return *this * amt;
        }
        Quaternion operator/(float amt) const
        {
            return *this / amt;
        }
        Quaternion operator+=(const Quaternion& other)
        {
            *this += other;
            return *this;
        }
        Quaternion operator-=(const Quaternion& other)
        {
            *this -= other;
            return *this;
        }
        Quaternion operator*=(const Quaternion& other)
        {
            *this *= other;
            return *this;
        }
        Quaternion operator*=(float amt)
        {
            *this *= amt;
            return *this;
        }
        Quaternion operator/=(float amt)
        {
            *this /= amt;
            return *this;
        }
        Quaternion operator=(const Quaternion& other)
        {
            x = other.x;
            y = other.y;
            z = other.z;
            w = other.w;
            return *this;
        }
        bool operator==(const Quaternion& other) const
        {
            return *this == other;
        }
        bool operator!=(const Quaternion& other) const
        {
            return *this != other;
        }

        Vector3           GetRight() const;
        Vector3           GetUp() const;
        Vector3           GetForward() const;
        Vector3           GetEuler() const;
        Vector3           GetAxis() const;
        Vector3           GetRotated(const Vector3& other) const;
        Quaternion        Conjugate() const;
        Quaternion        Inverse() const;
        Quaternion        Normalized() const;
        static Quaternion FromVector(glm::vec3& rot)
        {
            return glm::quat(rot);
        }
        static Quaternion Euler(const Vector3& v);
        static Quaternion Euler(float x, float y, float z);
        static Quaternion AxisAngle(const Vector3& axis, float angle);
        static Quaternion Slerp(const Quaternion& from, const Quaternion& dest, float t);
        static Quaternion LookAt(const Vector3& from, const Vector3& to, const Vector3& up);
        bool              IsNormalized() const;
        float             GetAngle() const;
        float             Dot(const Quaternion& other) const;
        float             Length() const;
        float             LengthSquared() const;
        Vector4           ToVector() const
        {
            return Vector4(x, y, z, w);
        }

        std::string ToStringEuler() const
        {
            std::stringstream ss;
            ss << "X:" << x << "   Y:" << y << "   Z:" << z;
            return ss.str();
        }

        std::string ToString() const
        {
            std::stringstream ss;
            ss << "X:" << x << "   Y:" << y << "   Z:" << z << "   W:" << w;
            return ss.str();
        }

        template <class Archive> void serialize(Archive& archive)
        {
            archive(x, y, z, w); // serialize things by passing them to the archive
        }
    };

} // namespace Lina

#endif
