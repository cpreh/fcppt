//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

// ![decorate_simple_include]
#include <fcppt/declare_strong_typedef.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/type_iso/decorate.hpp>
#include <fcppt/type_iso/strong_typedef.hpp>
#include <fcppt/type_iso/undecorate.hpp>
// ![decorate_simple_include]

#include <fcppt/type_iso/transform_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <fcppt/config/external_end.hpp>

namespace
{
void f()
{
  // ![decorate_simple]
  FCPPT_DECLARE_STRONG_TYPEDEF(int, strong_int);

  auto const var(fcppt::type_iso::decorate<strong_int>(42));

  int const result(fcppt::type_iso::undecorate(var));

  std::cout << result << '\n';
  // ![decorate_simple]
}

}

//![decorate_custom]
namespace mine
{
class custom_int
{
  // This class has a private constructor ...
private:
  explicit custom_int(int const _val) : val_{_val} {}

public:
  // ... and a public factory function
  static custom_int make(int const _val) { return custom_int(_val); }

  [[nodiscard]] int get() const { return val_; }

private:
  int val_;
};

}

namespace fcppt::type_iso
{
template <>
struct transform<mine::custom_int>
{
  using undecorated_type = int;

  using decorated_type = mine::custom_int;

  static decorated_type decorate(undecorated_type const _val) { return decorated_type::make(_val); }

  static undecorated_type undecorate(decorated_type const _val) { return _val.get(); }
};

}
//![decorate_custom]

int main() { f(); }
