//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/noncopyable.hpp>
#include <fcppt/cast/dynamic_cross.hpp>
#include <fcppt/cast/dynamic_cross_exn.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

struct derived1
{
	FCPPT_NONCOPYABLE(
		derived1
	);
public:
	derived1()
	{
	}

	virtual
	~derived1()
	{
	}
};

struct derived2
{
	FCPPT_NONCOPYABLE(
		derived2
	);
public:
	virtual
	~derived2()
	{
	}
};

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	cast_dynamic_cross
)
{
FCPPT_PP_POP_WARNING

	derived1 d1{};

	BOOST_CHECK(
		!fcppt::cast::dynamic_cross<
			derived2
		>(
			d1
		).has_value()
	);

	BOOST_CHECK_THROW(
		fcppt::cast::dynamic_cross_exn<
			derived2 &
		>(
			d1
		),
		fcppt::cast::bad_dynamic
	);
}
