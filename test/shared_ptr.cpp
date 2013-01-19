//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/const_pointer_cast.hpp>
#include <fcppt/dynamic_pointer_cast.hpp>
#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/shared_ptr_impl.hpp>
#include <fcppt/static_pointer_cast.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
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

typedef fcppt::shared_ptr<
	base
> base_ptr;

typedef fcppt::shared_ptr<
	derived
> derived_ptr;

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	shared_ptr_dynamic_pointer_cast
)
{
FCPPT_PP_POP_WARNING

	base_ptr const ptr(
		fcppt::make_shared_ptr<
			derived
		>()
	);

	derived_ptr ptr2(
		fcppt::dynamic_pointer_cast<
			derived
		>(
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

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	shared_ptr_static_pointer_cast
)
{
FCPPT_PP_POP_WARNING

	base_ptr const ptr(
		fcppt::make_shared_ptr<
			derived
		>()
	);

	derived_ptr ptr2(
		fcppt::static_pointer_cast<
			derived
		>(
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

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	shared_ptr_const_pointer_cast
)
{
FCPPT_PP_POP_WARNING
	typedef fcppt::shared_ptr<
		base const
	> const_base_ptr;

	const_base_ptr const ptr(
		fcppt::make_shared_ptr<
			base
		>()
	);

	base_ptr ptr2(
		fcppt::const_pointer_cast<
			base
		>(
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
