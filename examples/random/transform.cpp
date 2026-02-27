//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

namespace
{
// ![random_transform_my_type]
namespace mine
{
template <typename Type>
class my_type
{
public:
  explicit my_type(Type const _value) : value_(_value) {}

  [[nodiscard]] Type value() const { return this->value_; }

private:
  Type value_;
};

}
// ![random_transform_my_type]
}

//![random_transform_specialization]
#include <fcppt/type_iso/transform.hpp>

namespace fcppt::type_iso
{
template <typename Type>
struct transform<mine::my_type<Type>>
{
  using decorated_type = mine::my_type<Type>;

  using undecorated_type = Type;

  // A static function that converts to the base type
  static undecorated_type undecorate(decorated_type const &_value) { return _value.value(); }

  // A static function that converts from the base type
  static decorated_type decorated_value(undecorated_type const &_value)
  {
    return decorated_type(_value);
  }
};

}
//![random_transform_specialization]

#include <fcppt/random/distribution/basic.hpp>
#include <fcppt/random/distribution/parameters/uniform_int.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <fcppt/config/external_end.hpp>

int main()
{
  using my_int_type = mine::my_type<int>;

  using distribution = fcppt::random::distribution::basic<
      fcppt::random::distribution::parameters::uniform_int<my_int_type>>;

  std::cout << distribution(
                   distribution::param_type::min(my_int_type(0)),
                   distribution::param_type::max(my_int_type(10)))
            << '\n';
}
