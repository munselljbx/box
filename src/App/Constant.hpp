#ifndef APP_CONSTANT_HPP
#define APP_CONSTANT_HPP

namespace app
{
namespace constant
{
const sf::Vector2f windowSize(800.f, 800.f);

const float chargeStrength = 10.f;

inline float v2fMag(const sf::Vector2f& r, float pow = 0.5)
{
	return powf(r.x * r.x + r.y * r.y, pow);
}
inline float v2fDist(const sf::Vector2f& v1, const sf::Vector2f& v2, float pow = 0.5)
{
	return v2fMag(v2 - v1, pow);
}
} // namespace constant
} // namespace app

#endif // APP_CONSTANT_HPP