//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/enable_shared_from_this.hpp>
#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/shared_ptr_impl.hpp>
#include <fcppt/shared_ptr_output.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

namespace
{
class test_class;

using test_shared_ptr = fcppt::shared_ptr<test_class>;

using const_test_shared_ptr = fcppt::shared_ptr<test_class const>;

class test_class : public fcppt::enable_shared_from_this<test_class>
{
public:
  [[nodiscard]] test_shared_ptr get() { return this->fcppt_shared_from_this(); }

  [[nodiscard]] const_test_shared_ptr get() const { return this->fcppt_shared_from_this(); }
};

}

FCPPT_CATCH_BEGIN

TEST_CASE("enable_shared_from_this", "[smartptr]")
{
  test_shared_ptr const ptr{fcppt::make_shared_ptr<test_class>()};

  test_shared_ptr const ptr2{ptr->get()};

  CHECK(ptr == ptr2);

  const_test_shared_ptr const ptr3{ptr2};

  const_test_shared_ptr const ptr4{ptr3->get()};

  CHECK(ptr3 == ptr4);
}

FCPPT_CATCH_END
