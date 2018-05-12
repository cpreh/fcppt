//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/noncopyable.hpp>
#include <fcppt/cast/apply.hpp>
#include <fcppt/cast/bad_dynamic.hpp>
#include <fcppt/cast/dynamic.hpp>
#include <fcppt/cast/dynamic_exn.hpp>
#include <fcppt/cast/dynamic_fun.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

struct base
{
	FCPPT_NONCOPYABLE(
		base
	);

	base()
	{
	}

	virtual
	~base()
	{
	}
};

struct derived1
:
	base
{
	FCPPT_NONCOPYABLE(
		derived1
	);

	derived1()
	{
	}

	~derived1()
	override
	{
	}
};

struct derived2
:
	base
{
	FCPPT_NONCOPYABLE(
		derived2
	);

	derived2()
	{
	}

	~derived2()
	override
	{
	}
};

}

BOOST_AUTO_TEST_CASE(
	cast_dynamic
)
{
	derived1 d1{};

	derived2 d2{};

	base &b1{
		d1
	};

	base &b2{
		d2
	};

	BOOST_CHECK(
		fcppt::cast::dynamic<
			derived1
		>(
			b1
		).has_value()
	);

	BOOST_CHECK((
		fcppt::cast::apply<
			fcppt::cast::dynamic_fun,
			derived1
		>(
			b1
		).has_value()
	));

	BOOST_CHECK(
		!fcppt::cast::dynamic<
			derived1
		>(
			b2
		).has_value()
	);

	BOOST_CHECK_EQUAL(
		&fcppt::cast::dynamic_exn<
			derived1 &
		>(
			b1
		),
		&d1
	);

	BOOST_CHECK_THROW(
		fcppt::cast::dynamic_exn<
			derived1 &
		>(
			b2
		),
		fcppt::cast::bad_dynamic
	);
}
