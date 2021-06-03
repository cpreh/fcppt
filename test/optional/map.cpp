//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_ref.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/reference.hpp>
#include <fcppt/reference_output.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/preprocessor/disable_clang_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

TEST_CASE("optional::map", "[optional]")
{
  using optional_size = fcppt::optional::object<std::string::size_type>;

  using optional_string = fcppt::optional::object<std::string>;

  auto const conversion([](std::string const &_val) { return _val.size(); });

  CHECK(fcppt::optional::map(optional_string(), conversion) == optional_size());

  CHECK(fcppt::optional::map(optional_string("test"), conversion) == optional_size(4U));
}

namespace
{
class noncopyable
{
  FCPPT_NONMOVABLE(noncopyable);

public:
  FCPPT_PP_PUSH_WARNING
  FCPPT_PP_DISABLE_CLANG_WARNING(-Wunused-member-function)
  noncopyable() = default;

  ~noncopyable() = default;
  FCPPT_PP_POP_WARNING
};

}

TEST_CASE("optional::map ref", "[optional]")
{
  using optional_string = fcppt::optional::object<std::string>;

  noncopyable test{};

  using optional_noncopyable_ref = fcppt::optional::reference<noncopyable>;

  CHECK(fcppt::optional::map(optional_string("42"), [&test](std::string const &) {
          return fcppt::make_ref(test);
        }) == optional_noncopyable_ref{fcppt::make_ref(test)});
}


TEST_CASE("optional::map to_ref", "[optional]")
{
  fcppt::optional::object<int> opt{0};

  CHECK(
      fcppt::optional::map(
          opt, [](int &_val) -> fcppt::reference<int> { return fcppt::make_ref(_val); }) ==
      fcppt::optional::reference<int>{fcppt::make_ref(opt.get_unsafe())});
}
