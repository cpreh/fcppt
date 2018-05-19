//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/noncopyable.hpp>
#include <fcppt/cast/apply.hpp>
#include <fcppt/cast/dynamic_cross.hpp>
#include <fcppt/cast/dynamic_cross_exn.hpp>
#include <fcppt/cast/dynamic_cross_fun.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
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

TEST_CASE(
	"cast::dynamic_cross",
	"[cast]"
)
{
	derived1 d1{};

	CHECK_FALSE(
		fcppt::cast::dynamic_cross<
			derived2
		>(
			d1
		).has_value()
	);

	CHECK_FALSE(
		fcppt::cast::apply<
			fcppt::cast::dynamic_cross_fun,
			derived2
		>(
			d1
		).has_value()
	);

	CHECK_THROWS_AS(
		fcppt::cast::dynamic_cross_exn<
			derived2 &
		>(
			d1
		),
		fcppt::cast::bad_dynamic
	);
}
