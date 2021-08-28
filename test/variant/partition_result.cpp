//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/tuple/object_fwd.hpp>
#include <fcppt/variant/object_fwd.hpp>
#include <fcppt/variant/partition_result_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <vector>
#include <fcppt/config/external_end.hpp>

int main()
{
  static_assert(std::is_same_v<
    fcppt::variant::partition_result<std::vector<fcppt::variant::object<int,float>>>,
    fcppt::tuple::object<std::vector<int>,std::vector<float>>>);
}
