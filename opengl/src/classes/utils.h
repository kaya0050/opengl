#pragma once
#include <random>
class utils
{
	public:
		struct Vector3
		{
			float x, y, z;

			float distanceTo(const Vector3& other) const {
				float dx = x - other.x;
				float dy = y - other.y;
				float dz = z - other.z;
				return std::sqrt(dx * dx + dy * dy + dz * dz);
			}
		};
		float randomFloat(float min, float max) 
		{
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_real_distribution<> dis(min, max);
			return static_cast<float>(dis(gen));
		}
};