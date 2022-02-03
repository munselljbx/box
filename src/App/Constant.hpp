#ifndef APP_CONSTANT_HPP
#define APP_CONSTANT_HPP

namespace app
{
namespace constant
{
const sf::Vector2f windowSize(800.f, 800.f);

const float chargeStrength = 10.f; // pos for EM (likes repel), negative for gravity (likes attract)
const float dragStrength = 1.f; //

inline float v2fDot(const sf::Vector2f& v1, const sf::Vector2f& v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}
inline float v2fMag(const sf::Vector2f& r, float pow = 0.5)
{
	return powf(r.x * r.x + r.y * r.y, pow);
}
inline float v2fDist(const sf::Vector2f& v1, const sf::Vector2f& v2, float pow = 0.5)
{
	return v2fMag(v2 - v1, pow);
}

inline static const float DIST_PER_SIDE_CIRCLE = 3.f;
inline unsigned int circleNSides(float radius)
{
	return static_cast<unsigned int>(radius * 2.f * ((float)M_PI / DIST_PER_SIDE_CIRCLE));
}
} // namespace constant
} // namespace app

#endif // APP_CONSTANT_HPP