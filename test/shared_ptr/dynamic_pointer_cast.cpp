//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/dynamic_pointer_cast.hpp>
#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/shared_ptr_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

struct base
{
	virtual ~base()
	{}
};

struct derived
:
	base
{
};

}

BOOST_AUTO_TEST_CASE(
	shared_ptr_dynamic_pointer_cast
)
{
	typedef fcppt::shared_ptr<
		base
	> base_ptr;

	typedef fcppt::shared_ptr<
		derived
	> derived_ptr;

	base_ptr const ptr(
		fcppt::make_shared_ptr<
			derived
		>()
	);

	derived_ptr ptr2(
		fcppt::dynamic_pointer_cast<
			derived
		>
		(
			ptr
		)
	);

	BOOST_REQUIRE(
		ptr2
	);

	BOOST_REQUIRE(
		ptr.use_count() == ptr2.use_count()
	);

	ptr2.reset();

	BOOST_REQUIRE(
		ptr.use_count() == 1
	);
}
